class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int> mp ;
        int temp = n ;
        while ( temp ) {
            int r = temp % 10 ;
            mp[r]++ ;
            temp /= 10 ;
        }
        int ans = 0 ;
        for ( auto p : mp ) {
            ans += (p.first * p.second) ;
        }
        return ans ;
    }
};