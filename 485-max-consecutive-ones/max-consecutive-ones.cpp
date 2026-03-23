class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int mx = 0 , c = 0 ;
        for ( int x : a ) {
            if ( x == 1 ) c++ ;
            else c = 0 ;
            mx = max ( mx , c ) ;
        }
        return mx ;
    }
};