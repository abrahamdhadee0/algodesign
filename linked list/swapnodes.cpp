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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        vector<int> v1;
        while(temp){
                v1.push_back(temp->val);
                temp=temp->next;
        }

         int n = v1.size();
        int idx1 = k - 1;       // k-th node from start (1-based to 0-based)
        int idx2 = n - k;       // k-th node from end

        // Swap values safely
        if (idx1 < n && idx2 < n) {
            int tempo = v1[idx1];
            v1[idx1] = v1[idx2];
            v1[idx2] = tempo;
        }
    temp=head;
    for(int i=0;i<v1.size();i++){
        temp->val=v1[i];
        temp=temp->next;
    }
    return head;
    }
};