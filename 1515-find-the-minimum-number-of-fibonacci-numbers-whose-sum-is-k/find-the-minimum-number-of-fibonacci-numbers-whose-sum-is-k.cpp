class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if ( k == 1 || k == 2 || k == 3 ) return 1 ;
        vector<long long> a ;
        a.push_back(1) ;
        a.push_back(1) ;
        int ans = 0 , c = 2 ;
        while ( c <= k ) {
            c = a[a.size() - 1] + a[a.size() - 2] ;
            a.push_back(c) ;
        }       
        int i = a.size() - 1 ;
        while ( k > 0 ) {
            if ( a[i] <= k ) {
                k -= a[i] ;
                ans++ ;
            }else i-- ;
        }
        return ans ;
    }
};