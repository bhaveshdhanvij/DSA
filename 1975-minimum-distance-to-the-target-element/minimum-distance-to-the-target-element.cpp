class Solution {
public:
    int getMinDistance(vector<int>& a, int t, int st) {
        int minn = INT_MAX ;

        int n = a.size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( a[i] == t ) {
                int curr = abs(i - st) ;
                if ( curr < minn ) {
                    minn = curr ;
                }
            }
        }
        
        return minn ;
    }
};