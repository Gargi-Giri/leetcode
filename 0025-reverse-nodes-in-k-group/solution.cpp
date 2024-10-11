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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Count if there are at least k nodes left to reverse
        ListNode* node = head;
        int count = 0;
        while (node != nullptr && count < k) {
            node = node->next;
            count++;
        }
        
        // If we have k nodes, we reverse them
        if (count == k) {
            // Step 2: Reverse k nodes
            ListNode* prev = nullptr;
            ListNode* curr = head;
            ListNode* next = nullptr;
            int n = 0;
            while (n < k) {
                next = curr->next;  // Keep track of the next node
                curr->next = prev;  // Reverse the current node
                prev = curr;        // Move prev and curr one step forward
                curr = next;
                n++;
            }
            
            // Step 3: Recursively reverse the remaining list and connect it
            head->next = reverseKGroup(curr, k);
            
            // Step 4: Return the new head after reversing
            return prev;
        }
        
        // If there are fewer than k nodes, return the head as is
        return head;
    }
};
