class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        int n = a.size() ;
        vector<vector<string>> ans ;
        map<string,vector<string>> mp ;
        for ( auto s : a ) {
            string t = s ;
            sort ( t.begin() , t.end() ) ;
            mp[t].push_back(s) ;
        }
        for ( auto p : mp ) {
            ans.push_back(p.second) ;
        }
        return ans ;
    }
};