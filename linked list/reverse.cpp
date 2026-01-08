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
ListNode* get(ListNode*head,int idx){
    int n=0;
        ListNode* temp=head;
        for(int i=1;i<=idx;i++){
            temp=temp->next;
        }
        return temp;
}
    ListNode* reverseList(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            n++;
        }
        int i=0;
        int j=n-1;
        while(i<j){
            ListNode* left=get(head,i);
            ListNode* right=get(head,j);
            int t=left->val;
            left->val=right->val;
            right->val=t;
            i++;
            j--;
        }
        return head;
    }
};