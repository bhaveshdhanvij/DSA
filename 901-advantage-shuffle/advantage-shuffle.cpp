class Solution {
public:
    vector<int> advantageCount(vector<int>& a, vector<int>& nums) {
        int n = a.size() ;
        vector<pair<int,int>> b ;
        for ( int i = 0 ; i < n ; i++ ) {
            b.push_back({nums[i] , i}) ;
        }
        sort(a.begin() , a.end()) ;
        sort(b.begin() , b.end()) ;
        vector<int> ans(n) ;
        int l = 0 , r = n - 1 ;
        for ( int x : a ) {
            if ( x > b[l].first ) {
                ans[b[l].second] = x ;
                l++ ;
            }else {
                ans[b[r].second] = x ;
                r-- ;
            }
        }
        return ans ;
    }
};