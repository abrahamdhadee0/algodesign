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
    ListNode* sortList(ListNode* head) {
        vector<int> v1;
        ListNode* temp=head;
        int size=0;
        while(temp){
            v1.push_back(temp->val);
            temp=temp->next;
            size++;
        }
        sort(v1.begin(),v1.end());
        temp=head;
        int i=0;
        while(size>0){
            temp->val=v1[i];
            temp=temp->next;
            i++;
            size--;
        }
        return head;
    }
};