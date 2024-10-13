/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return 0;
        }
        
        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* temp = slow;
        while (temp != nullptr) {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        
        // Step 3: Calculate the pair sums and find the maximum sum
        int maxSum = 0;
        ListNode* first = head;
        ListNode* second = prev; // Second half (reversed)
        while (second != nullptr) {
            int sum = first->val + second->val;
            maxSum = std::max(maxSum, sum);
            first = first->next;
            second = second->next;
        }
        
        return maxSum;
    }
};

