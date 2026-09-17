class Solution {
public:
    int minSumOfLengths(vector<int>& a, int t) {
        unordered_map<int,int> mp ;
        mp[0] = -1 ;
        int n = a.size() ;
        int s = 0 ;
        int ans = n + 1 ;
        int minn = n ;
        for ( int i = 0 ; i < n ; i++ ) {
            s += a[i] ;
            if ( mp.count(s - t) ) {
                int j = mp[s - t] ;
                int l = i - j ;
                ans = min ( ans , l + (j == -1   ? n : a[j])) ;
                minn = min ( minn , l) ;
            } 
            a[i] = minn ;
            mp[s] = i ;
        }

        return ans == n + 1 ? -1 : ans ;
    }
};