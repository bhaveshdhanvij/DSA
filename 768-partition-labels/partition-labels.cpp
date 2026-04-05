class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size() ;
        vector<int> last(26) ;
        vector<int> ans ;
        
        for ( int i = 0 ; i < n ; i++ ) {
            last[s[i] - 'a'] = i ;
        }
        int st = 0 , end = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            end = max ( end , last[s[i] - 'a'] ) ;
            if ( i == end ) {
                ans.push_back(end - st + 1) ;
                st = i + 1 ;
            }
        }
        return ans ;
    }
};