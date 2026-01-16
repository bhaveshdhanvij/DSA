/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int , Employee*> mp ;
    
    int helper( Employee* e ) {
        int ans = e->importance ;

        for ( int x : e->subordinates ) {
            ans += helper(mp[x]) ;
        }

        return ans ;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for ( auto e : employees ) {
            mp[e->id] = e ;
        }

        return helper(mp[id]) ; 
    }
};