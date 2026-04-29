class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int a = red , b = blue ;
        bool flag = true ;

        int ans1 = 0 , curr = 1 ;
        while ( true ) {
            if ( flag ) {
                if ( curr > b ) break ;
                b -= curr ;
            }else {
                if ( curr > a ) break ;
                a -= curr ;
            }
            flag = !flag ;
            curr++ , ans1++ ;
        }

        int ans2 = 0 ;
        curr = 1 ;
        a = red , b = blue ;
        flag = true ;
        
        while ( true ) {
            if ( flag ) {
                if ( curr > a ) break ;
                a -= curr ;
            }else {
                if ( curr > b ) break ;
                b -= curr ;
            }
            curr++ ;
            ans2++ ;
            flag = !flag ;
        }

        return max(ans1 , ans2) ;
    }
};