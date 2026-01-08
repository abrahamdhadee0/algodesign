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
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) {
            return true;
        }  
        else if (head->next->next == nullptr) {
            return (head->val == head->next->val);
        }
        else {
            // Step 1: Find the middle
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }

            // Step 2: Reverse second half
            ListNode* prev = nullptr;
            ListNode* curr = slow->next;
            while (curr) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Step 3: Compare first and second half
            ListNode* first = head;
            ListNode* second = prev;
            bool flag = true;
            while (second) {
                if (first->val != second->val) {
                    flag = false;
                    break;
                }
                first = first->next;
                second = second->next;
            }

            // Step 4 (optional): Restore the list
            curr = prev;
            prev = nullptr;
            while (curr) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            slow->next = prev;

            return flag;
        }
    }
};
