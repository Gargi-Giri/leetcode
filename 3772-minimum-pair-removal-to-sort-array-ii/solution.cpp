#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    long long val;
    int pos;
    Node* prev;
    Node* next;
    bool alive;
};
 
struct Candidate {
    long long sum;
    int pos;
    Node* left;
    Node* right;
};
 
struct CandComp {
    bool operator()(const Candidate &a, const Candidate &b) const {
        if(a.sum == b.sum)
            return a.pos > b.pos;
        return a.sum > b.sum;
    }
};
 
bool isNonDecreasing(Node* head) {
    Node* cur = head;
    while(cur && cur->next) {
        if(cur->val > cur->next->val) return false;
        cur = cur->next;
    }
    return true;
}
 
int minimumPairRemoval(vector<int>& nums) {
    int n = nums.size();
    vector<Node*> nodes(n);
    Node* head = nullptr;
    Node* prev = nullptr;
    for (int i = 0; i < n; i++){
        Node* node = new Node();
        node->val = nums[i];
        node->pos = i;
        node->prev = prev;
        node->next = nullptr;
        node->alive = true;
        if(prev) prev->next = node;
        else head = node;
        prev = node;
        nodes[i] = node;
    }
    int violations = 0;
    Node* cur = head;
    while(cur && cur->next){
        if(cur->val > cur->next->val) violations++;
        cur = cur->next;
    }
    if(violations == 0) return 0;
    priority_queue<Candidate, vector<Candidate>, CandComp> pq;
    cur = head;
    while(cur && cur->next){
        Candidate candid;
        candid.sum = cur->val + cur->next->val;
        candid.pos = cur->pos;
        candid.left = cur;
        candid.right = cur->next;
        pq.push(candid);
        cur = cur->next;
    }
    int ops = 0;
    while(violations > 0 && !pq.empty()){
        Candidate candid = pq.top();
        pq.pop();
        if(!candid.left->alive || !candid.right->alive) continue;
        if(candid.left->next != candid.right) continue;
        Node* L = candid.left->prev;
        Node* R = candid.right->next;
        if(candid.left->val > candid.right->val) {
            violations--;
        }
        if(L && L->alive){
            if(L->val > candid.left->val) violations--;
        }
        if(R && R->alive){
            if(candid.right->val > R->val) violations--;
        }
        Node* newNode = new Node();
        newNode->val = candid.left->val + candid.right->val;
        newNode->pos = candid.left->pos;
        newNode->prev = L;
        newNode->next = R;
        newNode->alive = true;
        if(L && L->alive){
            L->next = newNode;
            if(L->val > newNode->val) violations++;
        }
        if(R && R->alive){
            R->prev = newNode;
            if(newNode->val > R->val) violations++;
        }
        candid.left->alive = false;
        candid.right->alive = false;
        if(L){
            Candidate nc;
            nc.sum = L->val + newNode->val;
            nc.pos = L->pos;
            nc.left = L;
            nc.right = newNode;
            pq.push(nc);
        }
        if(R){
            Candidate nc;
            nc.sum = newNode->val + R->val;
            nc.pos = newNode->pos;
            nc.left = newNode;
            nc.right = R;
            pq.push(nc);
        }
        ops++;
    }
    return ops;
}
 
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> remove = nums;
        return ::minimumPairRemoval(nums);
    }
};

