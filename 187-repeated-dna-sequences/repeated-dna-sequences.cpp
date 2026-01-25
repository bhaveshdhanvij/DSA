class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> a ;
        
        vector<string> ans ;
        for ( int i = 0 ; i + 9 < s.size() ; i++ ) {
            string t = s.substr(i , 10) ;
            a[t]++ ;
            if ( a[t] == 2 ) ans.push_back(t) ;
        }

        return ans ;
    }
};