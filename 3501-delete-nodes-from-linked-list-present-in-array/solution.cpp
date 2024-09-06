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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        // Create a dummy node to simplify edge case handling.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        // Traverse the linked list
        while (curr != nullptr) {
            if (numSet.count(curr->val)) {
                // If the current node's value is in numSet, skip it.
                prev->next = curr->next;
            } else {
                // Move prev pointer forward if the current node is not deleted.
                prev = curr;
            }
            curr = curr->next; // Move current pointer forward.
        }

        // Return the head of the modified list (dummy->next)
        return dummy->next;
    }
};
