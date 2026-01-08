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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        if(n==len){
            ListNode* newHead = head->next;
            delete head; // optional cleanup
            return newHead;
        }
        // nth from end =(len-n+1)from start
        int m=(len-n-1);
    //  int idx=m-1;
      temp=head;
      for(int i=0;i<m;i++){
        temp=temp->next;
      }
      temp->next=temp->next->next;
      return head;
    }
};