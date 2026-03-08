class Solution {
public:
    int minimumIndex(vector<int>& a, int t) {
        int minn = INT_MAX , ans = -1 ;
        
        for ( int i = 0 ; i < a.size() ; i++ ) {
            if ( a[i] >= t && a[i] < minn ) {
                ans = i ;
                minn = a[i] ;
            }
        }

        return ans ;
    }
};