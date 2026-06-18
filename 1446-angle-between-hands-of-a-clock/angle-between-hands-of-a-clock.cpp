class Solution {
public:
    double angleClock(int hour, int minutes) {
        // formula based 
        double ans = abs((30 * hour * 1.0) - (5.5 * minutes)) ;
        if ( ans > 180 ) ans = 360 - ans ;
        return ans ;
    }
};