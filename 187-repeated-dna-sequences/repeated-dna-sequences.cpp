class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans ;
        unordered_map<string,int> mp ;

        for ( int i = 0 ; i + 9 < s.size() ; i++ ) {
            string t = s.substr(i , 10) ;
            mp[t]++ ;

            if ( mp[t] == 2 ) {
                ans.push_back(t) ;
            }
        }

        return ans ;
    }
};