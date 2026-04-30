class Solution {
public:
    int brokenCalc(int st, int t) {
        int ans = 0 ;

        while ( t > st ) {
            if ( t % 2 == 0 ) t /= 2 ;
            else t++ ;

            ans++ ;
        }

        ans += (st - t) ;

        return ans ;
    }
};