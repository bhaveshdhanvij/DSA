class Solution {
public:
    int maxIceCream(vector<int>& a, int coins) {
        int n = a.size() ;

        sort ( a.begin() , a.end() ) ;
        
        int i = 0 ;

        while ( i < n && a[i] <= coins ) {
            coins -= a[i] ;
            i++ ;
        }

        return i ;
    }
};