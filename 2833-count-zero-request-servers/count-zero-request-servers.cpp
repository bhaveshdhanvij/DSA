class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin() , logs.end() , [&](auto x , auto y){
            return x[1] < y[1] ;
        }) ;
        vector<pair<int,int>> q ;
        for ( int i = 0 ; i < queries.size() ; i++ ) {
            q.push_back({queries[i] , i}) ;
        }
        sort(q.begin() , q.end()) ;
        vector<int> f(n + 1 , 0) ;
        vector<int> ans(queries.size()) ;

        int left = 0 , right = 0 ;
        int curr = 0 ;

        for ( auto [time , idx] : q ) {
            while ( right < logs.size() && logs[right][1] <= time ) {
                int server = logs[right][0] ;
                if ( f[server] == 0 ) {
                    curr++ ;
                }
                f[server]++ ;
                right++ ;
            }
            while ( left < right && logs[left][1] < time - x ) {
                int server = logs[left][0] ;
                f[server]-- ;
                if ( f[server] == 0 ) {
                    curr-- ;
                }
                left++ ;
            }
            ans[idx] = n - curr ;
        }
        return ans ;
    }
};