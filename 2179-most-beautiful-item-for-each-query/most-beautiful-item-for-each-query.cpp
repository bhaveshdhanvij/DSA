class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size() ;
        int m = queries.size() ;
        sort(items.begin() , items.end()) ;
        vector<pair<int,int>> q ;
        for ( int i = 0 ; i < m ; i++ ) {
            q.push_back({queries[i], i}) ;
        }
        vector<int> ans(m , 0) ;
        sort(q.begin() , q.end()) ;
        int i = 0 , maxb = 0 ;
        for ( int j = 0 ; j < m ; j++ ) {
            int price = q[j].first ;
            int idx = q[j].second ;
            while ( i < n && items[i][0] <= price ) {
                maxb = max ( maxb , items[i][1] ) ;
                i++ ;
            }
            ans[idx] = maxb ;
        }
        return ans ;
    }
};