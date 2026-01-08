/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         if(head==nullptr||head->next==nullptr) return nullptr;
       ListNode* temp=head;

        ListNode* slow=head;
        ListNode* fast=head;
        bool flag=false;
        while(fast && fast->next){
            slow=slow->next;
        fast=fast->next->next;
            if(slow==fast){
                flag=true;
                break;
            }
        }
        if(!flag){
            return nullptr;
        }
        else{
             slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        }

        // Both meet at the start of the cycle
   return slow;    
    }
};