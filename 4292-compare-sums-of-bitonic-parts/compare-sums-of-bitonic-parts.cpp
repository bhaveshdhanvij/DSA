class Solution {
public:
    int compareBitonicSums(vector<int>& a) {
        int maxx = INT_MIN , idx = -1 ;
        for ( int i = 0 ; i < a.size() ; i++ ) {
            if ( a[i] > maxx ) {
                maxx = a[i] ;
                idx = i ;
            }
        }
        long long left = 0 , right = 0 ;
        
        for ( int i = 0 ; i <= idx ; i++ ) left += a[i] ;
        for ( int i = idx ; i < a.size() ; i++ ) right += a[i] ;

        if ( left == right ) return -1 ;

        return left > right ? 0 : 1 ;
    }
};