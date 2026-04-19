class Solution {
public:
    int maxOperations(vector<int>& a) {
        int n = a.size() ;
        int ans = 1 , sum = a[0] + a[1] , curr ;

        for ( int i = 2 ; i + 1 < n ; i += 2 ) {
            curr = a[i] + a[i + 1] ;
            if ( curr != sum ) break ;
            ans++ ;    
        }

        return ans ;
    }
};