class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) 
            return {-1, -1};
        int idx = 1; // middle node index (b)
        int firstIdx = -1, lastIdx = -1, prevIdx = -1;
        int minDist = INT_MAX;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;
        while (c) {
            // check if b is a critical point
            if ((b->val > a->val && b->val > c->val) || (b->val < a->val && b->val < c->val)) {
                if (firstIdx == -1) {
                    firstIdx = idx;
                } else {
                    minDist = min(minDist, idx - prevIdx);
                    lastIdx = idx;
                }
                prevIdx = idx;
            }
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        if (lastIdx == -1) 
            return {-1, -1};

        return {minDist, lastIdx - firstIdx};
    }
};
