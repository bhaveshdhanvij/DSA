class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        int maxx = 0 , ans = 0 ;
        for ( int i = 0 ; i < a.size() ; i++ ) {
            maxx = max ( maxx , a[i] ) ;
            if ( maxx == i ) {
                ans++ ;
            }
        }
        return ans ;
    }
};