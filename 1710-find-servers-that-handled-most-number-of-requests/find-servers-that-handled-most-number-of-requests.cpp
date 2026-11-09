class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& a, vector<int>& l) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q ;
        int n = a.size() ;
        set<int> s ;
        for ( int i = 0 ; i < k ; i++ ) s.insert(i) ;
        vector<int> c(k , 0) ;
        for ( int i = 0 ; i < n ; i++ ) {
            long long t = a[i] ;
            while(!q.empty() && q.top().first <= t ) {
                s.insert(q.top().second) ;
                q.pop() ;
            }
            if ( s.empty() ) continue ;
            auto it = s.lower_bound(i % k) ;
            if ( it == s.end() ) it = s.begin() ;
            int id = *it ;
            s.erase(id) ;
            q.push({t + l[i] , id}) ;
            c[id]++ ;
        }
        int maxx = 0 ;
        for ( int i = 0 ; i < k ; i++ ) maxx = max ( maxx , c[i] ) ;
        vector<int> ans ;
        for ( int i = 0 ; i < k ; i++ ) {
            if ( c[i] == maxx ) {
                ans.push_back(i) ;
            }
        }
        return ans ;
    }
};