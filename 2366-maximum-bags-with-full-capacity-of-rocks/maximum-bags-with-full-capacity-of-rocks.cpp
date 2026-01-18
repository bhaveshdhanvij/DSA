class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int a) {
        vector<int> t ;
        int ans = 0 ;

        for ( int i = 0 ; i < c.size() ; i++ ) {
            int curr = c[i] - r[i] ;
            if ( curr == 0 ) ans++ ;
            else t.push_back(curr) ;
        }

        sort ( t.begin() , t.end() ) ;
        
        int i = 0 ;

        while ( i < t.size() && t[i] <= a ) {
            ans++ ;
            a -= t[i] ;
            i++ ;
        }

        return ans ;
    }
};