class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size() ;
        int i = 0 , j = 0 ;
        while ( i < n ) {
            if ( a[i] != 0 ) {
                swap(a[i] , a[j++]) ;
            }
            i++ ;
        }
    }
};