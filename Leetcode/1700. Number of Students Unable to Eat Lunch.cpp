class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>stud;
        stack<int>but;
        for (int i = 0; i < students.size(); i++) {
            stud.push(students[i]);
            but.push(sandwiches[sandwiches.size() - 1 - i]);
        }
        int ans = students.size();
        int k = 0;
        while (true) {
            bool b = false;
            if (stud.front() == but.top()) {
                //cout << stud.top() << " " << but.front() << endl;
                ans--;
                stud.pop();
                but.pop();
                b = true;
            } else {
                int cur = stud.front();
                stud.pop();
                stud.push(cur);
            }
            if (stud.empty())
                return 0;
            if (!b)
                k++;
            else 
                k = 0;
            if (k == 200)
                return ans;
        }
        return 0;
    }
};
