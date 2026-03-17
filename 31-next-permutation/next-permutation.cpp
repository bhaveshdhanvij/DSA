class Solution {
public:
    void s( vector<int>& a , int i , int j ) {
        int temp = a[i] ;
        a[i] = a[j] ;
        a[j] = temp ;
    }
    void rev( vector<int>& a , int i , int j ) {
        while ( i <= j ) {
            swap(a[i] , a[j]) ;
            i++ ;
            j-- ;
        }
    }
    void nextPermutation(vector<int>& a) {
        int n = a.size() ;
        int i = n - 2 ;
        while ( i >= 0 && a[i] >= a[i + 1] ) i-- ;

        if ( i < 0 ) {
            rev(a , 0 , n - 1) ;
        }else {
            int j = n - 1 ;
            while ( a[j] <= a[i] ) j-- ;
            s( a , i , j ) ;
            rev(a , i + 1 , n - 1) ;
        }
    }
};