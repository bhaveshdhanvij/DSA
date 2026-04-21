class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_map<string,int> mp ;
        
        vector<string> ans ;
        string t = "" ;
        
        for ( char c : s ) {
            t += c ;
            if ( !mp.count(t) ) {
                ans.push_back(t) ;
                mp[t]++ ;
                t.clear() ;
            }
        }

        return ans ;
    }
};