class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int m = sandwiches.size();
        queue<int> q;

        for (int i = 0; i < n; i++) {
            q.push(students[i]);
        }

        int i = 0;
        int attempts = 0;

        while (attempts!=q.size() && !q.empty()) {

            if (q.front() == sandwiches[i]) {
                q.pop();
                i++;
                attempts = 0;      // 🔹 RESET attempts when someone eats
            }
            else {
                int x = q.front();
                q.pop();
                q.push(x);
                attempts++;       // 🔹 COUNT failed attempt
            }
        }

        return q.size();
    }
};
