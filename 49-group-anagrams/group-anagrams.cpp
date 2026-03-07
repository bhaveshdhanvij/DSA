class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& vec) {
        unordered_map<string,vector<string>> mp ;
        for ( string s : vec ) {
            string t = s ;
            sort ( t.begin() , t.end() ) ;

            mp[t].push_back(s) ;
        }

        vector<vector<string>> ans ;
        for ( auto p : mp ) {
            ans.push_back(p.second) ;
        }

        return ans ;
    }
};