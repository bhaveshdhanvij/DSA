class Solution {
public:
    bool isRobotBounded(string s) {
        int x = 0 , y = 0 ;
        int delx[4] = { 0 , 1 , 0 , -1 } ;
        int dely[4] = { 1 , 0 , -1 , 0 } ;

        int d = 0 ;
        
        for ( char c : s ) {
            if ( c == 'G' ) {
                x += delx[d] ;
                y += dely[d] ;
            }else if ( c == 'R' ) {
                d = (d + 1) % 4 ;
            }else {
                d = (d + 3) % 4 ;
            }
        }

        return ( x == 0 && y == 0 ) || d != 0 ;
    }
};