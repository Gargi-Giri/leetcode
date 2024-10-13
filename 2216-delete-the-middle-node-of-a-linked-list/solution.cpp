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
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // If the list has only one node, return nullptr (since we are deleting it)
        if (!head || !head->next) return nullptr;
        
        // Initialize slow and fast pointers, and a previous pointer
        ListNode *slow = head, *fast = head, *prev = nullptr;
        
        // Move the slow pointer by 1 step and fast pointer by 2 steps
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Now 'slow' is pointing to the middle node, and 'prev' is the node before it
        // Remove the middle node by skipping it in the linked list
        prev->next = slow->next;
        
        // Return the modified list
        return head;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


