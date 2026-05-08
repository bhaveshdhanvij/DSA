class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort ( a.begin() , a.end() ,[&](const auto x , const auto y){
            return x[1] < y[1] ;
        }) ;

        int ans = 0 ;
        int last = a[0][1] ;
        for ( int i = 1 ; i < a.size() ; i++ ) {
            int st = a[i][0] ;
            int end = a[i][1] ;
            
            if ( st >= last ) {
                last = end ;
            }else {
                ans++ ;
            }
        }

        return ans ;
    }
};