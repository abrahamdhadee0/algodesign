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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* temp2=head->next;
        while(temp2!=NULL){
        while(temp2!=NULL && temp2->val==temp->val){
            temp2=temp2->next;
        }
         temp->next=temp2;
         temp=temp2;
        if(temp2!=NULL) temp2=temp->next;
            }
        
      return head;
}
};