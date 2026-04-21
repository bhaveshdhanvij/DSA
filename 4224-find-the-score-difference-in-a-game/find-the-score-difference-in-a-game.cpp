class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int a = 0 , b = 0 , curr = 0 ;
        bool flag = true ;

        for ( int x : nums ) {
            curr++ ;

            if ( x % 2 ) {
                flag = !flag ;
            }
            if ( curr % 6 == 0 ) {
                flag = !flag ;
            }

            if ( flag ) a += x ;
            else b += x ;
        }
        
        return a - b ;
    }
};