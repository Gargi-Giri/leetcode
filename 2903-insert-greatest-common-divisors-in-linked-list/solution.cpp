

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) {
            // If there's only one node or the list is empty, return it as is.
            return head;
        }
        
        ListNode* curr = head;
        
        // Traverse the list until you reach the last node
        while (curr && curr->next) {
            // Calculate GCD of the current node and the next node
            int gcdVal = std::gcd(curr->val, curr->next->val);
            
            // Create a new node with the GCD value
            ListNode* gcdNode = new ListNode(gcdVal);
            
            // Insert the GCD node between curr and curr->next
            gcdNode->next = curr->next;
            curr->next = gcdNode;
            
            // Move two steps forward (to skip the newly inserted node)
            curr = gcdNode->next;
        }
        
        return head;
    }
};

