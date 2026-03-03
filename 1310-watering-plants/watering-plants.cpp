class Solution {
public:
    int wateringPlants(vector<int>& a, int c) {
        int curr = c ;
        int ans = 0 ;
        for ( int i = 0 ; i < a.size() ; i++ ) {
            if ( a[i] > curr ) {
                ans += 2 * i ;
                curr = c ;
            }

            curr -= a[i] ;
            ans++ ;
        }

        return ans ;
    }
};