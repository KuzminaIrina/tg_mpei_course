https://leetcode.com/problems/employee-importance/
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> c;

        for (int i = 0; i < employees.size(); i++) {
            c.insert(pair<int, Employee*>(employees[i]->id, employees[i]));
        }

        queue<Employee*> q;
        q.push(c[id]);
        int sz = 0;
        int importance = 0;
        Employee* e;

        while(!q.empty()) {
            sz = q.size();

            for (int i = 0; i < sz; i++) {
                e = q.front();

                importance += e->importance;

                if (!e->subordinates.empty()) {
                    for (int j = 0; j < e->subordinates.size(); j++) {
                        q.push(c[e->subordinates[j]]);
                    }
                }
                q.pop();
            }
        }
        return importance;
    }
};
