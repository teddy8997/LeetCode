/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
/*  
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;
        for(auto e : employees){
            m.emplace(e->id, e);
        }
        return dfs(id, m);
    }
private:
    int dfs(int id, const unordered_map<int, Employee*> &m){
        auto e = m.at(id);
        int sum = e->importance;
        for(int rid : e->subordinates){
            sum += dfs(rid, m);
        }
        return sum;
    }
};