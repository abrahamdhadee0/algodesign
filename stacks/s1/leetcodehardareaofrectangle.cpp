class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();

        vector<int> nsi(n), psi(n);
        stack<int> st;

        // -------- Next Smaller Index (NSI) --------
        nsi[n - 1] = n;
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }
            if (st.empty()) nsi[i] = n;
            else nsi[i] = st.top();
            st.push(i);
        }

        // clear stack
        while (!st.empty()) st.pop();

        // -------- Previous Smaller Index (PSI) --------
        psi[0] = -1;
        st.push(0);

        for (int i = 1; i < n; i++) {
            while (!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }
            if (st.empty()) psi[i] = -1;
            else psi[i] = st.top();
            st.push(i);
        }

        // -------- Area Calculation --------
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int height = h[i];
            int breadth = nsi[i] - psi[i] - 1;
            int area = height * breadth;
            maxi = max(maxi, area);
        }

        return maxi;
    }
};
