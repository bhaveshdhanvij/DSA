class Solution {
public:
    long long getDescentPeriods(vector<int>& a) {
        long long ans = 0 ;
        long long curr = 1 ;
        int n = a.size() ;
        for ( int i = 1 ; i < n ; i++ ) {
            if ( a[i] == a[i - 1] - 1 ) curr++ ;
            else {
                ans += (curr * (curr + 1)) / 2 ;
                curr = 1 ;
            }
        }
        ans += (curr * (curr + 1)) / 2 ;
        return ans ;
    }
};