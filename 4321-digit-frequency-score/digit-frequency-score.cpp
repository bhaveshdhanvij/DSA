class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int> mp ;
        while ( n ) {
            int r = n % 10 ;
            mp[r]++ ;
            n /= 10 ;
        }
        int ans = 0 ;
        for ( auto p : mp ) {
            ans += (p.second * p.first) ;
        }
        return ans ;
    }
};