class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        
        // safety checks
        if (k <= 0 || k > q.size()) return q;

        stack<int> st;

        for (int i = 1; i <= k; i++) {
            st.push(q.front());
            q.pop();
        }

        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        int m = q.size();
        for (int i = 1; i <= m - k; i++) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};
