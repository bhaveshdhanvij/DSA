class Solution {
public:
    int distanceTraveled(int m, int add) {
        int ans = 0 ;
        while ( m >= 5 && add > 0 ) {
            ans += 5 ;
            m -= 4 ;
            add-- ;
        }
        ans += m ;
        return ans * 10 ;
    }
};