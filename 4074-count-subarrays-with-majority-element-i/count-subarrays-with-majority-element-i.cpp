class Solution {
public:
    int countMajoritySubarrays(vector<int>& a, int target) {
        int ans = 0 ;
        for ( int i = 0 ; i < a.size() ; i++ ) {
            int count = 0 ;
            for ( int j = i ; j < a.size() ; j++ ) {
                if ( a[j] == target ) count++ ;
                if ( 2 * count > (j - i + 1) ) ans++ ;
            }
        }
        return ans ;
    }
};