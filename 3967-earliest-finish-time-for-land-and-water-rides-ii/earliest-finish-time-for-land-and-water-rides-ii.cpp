class Solution {
public:
    int helper(vector<int>& s1 , vector<int>& d1 , vector<int>& s2 , vector<int>& d2) {
        int n = s1.size() , m = s2.size() ;
        int minn = INT_MAX ;
        for ( int i = 0 ; i < n ; i++ ) {
            minn = min ( minn , s1[i] + d1[i] ) ;
        }
        int ans = INT_MAX ;
        for ( int i = 0 ; i < m ; i++ ) {
            ans = min ( ans , max(minn , s2[i]) + d2[i] ) ;
        }
        return ans ;
    }
    int earliestFinishTime(vector<int>& a1, vector<int>& b1, vector<int>& a2, vector<int>& b2) {
        int landfirst = helper(a1,b1,a2,b2) ;
        int waterfirst = helper(a2,b2,a1,b1) ;
        return min ( landfirst , waterfirst ) ;
    }
};