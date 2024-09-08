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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
                int totalNodes = 0;
        ListNode* temp = head;
        while (temp) {
            totalNodes++;
            temp = temp->next;
        }
        
        // Step 2: Determine the base size of each part and how many parts need an extra node
        int baseSize = totalNodes / k;
        int extraNodes = totalNodes % k; // the first 'extraNodes' parts will have one additional node
        
        // Step 3: Create the result array with k parts
        vector<ListNode*> result(k, nullptr);
        
        ListNode* current = head;
        ListNode* prev = nullptr;
        
        // Step 4: Split the list into k parts
        for (int i = 0; i < k; ++i) {
            result[i] = current;  // the start of the i-th part
            int currentPartSize = baseSize + (i < extraNodes ? 1 : 0); // Add 1 if this part needs an extra node
            
            // Move the pointer currentPartSize steps forward
            for (int j = 0; j < currentPartSize; ++j) {
                prev = current;
                current = current->next;
            }
            
        if (prev) prev->next = nullptr;
        }
        
        return result;

    }
};
