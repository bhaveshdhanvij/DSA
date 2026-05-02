class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& a) {
        sort ( a.begin() , a.end() ) ;
        int curr = 1 ;
        for ( int i = 1 ; i < a.size() ; i++ ) {
            curr = min ( a[i] , curr + 1 ) ;
        }
        return curr ;
    }
};