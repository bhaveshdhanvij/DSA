class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& c) {
        int total = 0 ;
        for ( int x : a ) total += x ;
        sort ( c.rbegin()  , c.rend() ) ;
        int ans = 0 ;
        int i = 0 ;
        int curr = 0 ; 
        while ( i < c.size() && curr < total ) {
            curr += c[i++] ;
            ans++ ;
        }
        return ans ;
    }
};