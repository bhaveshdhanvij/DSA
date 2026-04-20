class Solution {
public:
    long long calculateScore(string s) {
        long long ans = 0 ;
        unordered_map<int,vector<int>> mp ;

        int n = s.size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            char m = 'a' + ('z' - s[i]) ;
            
            if ( !mp.count(m) ) {
                mp[s[i]].push_back(i) ;
            }else {
                vector<int> &v = mp[m] ;
                ans += i - v.back() ;
                v.pop_back() ;
                if ( v.size() == 0 ) {
                    mp.erase(m) ;
                }
            }
        }

        return ans ;
    }
};