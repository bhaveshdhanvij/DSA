class Solution {
public:
    int countPairs(vector<int>& a, int t) {
        int n = a.size() ;
        int ans = 0 ;
        sort(a.begin() , a.end()) ;
        for ( int i = 0 ; i < n ; i++ ) {
            auto r = lower_bound(a.begin() + i + 1 , a.end() , t - a[i]) ;
            ans += r - (a.begin() + i + 1) ;
        }
        return ans ;
    }
};