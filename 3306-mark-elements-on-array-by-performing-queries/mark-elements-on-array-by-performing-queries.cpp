class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& a, vector<vector<int>>& q) {
        long long sum = 0 ;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;

        for ( int i = 0 ; i < a.size() ; i++ ) {
            pq.push({a[i] , i}) ;
            sum += a[i] ;
        }

        vector<long long> ans ;
        unordered_map<int,int> mp ;

        for ( auto e : q ) {
            int idx = e[0] ;
            int k = e[1] ;

            if ( !mp.count(idx) ) {
                sum -= a[idx] ;
                mp[idx]++ ;
            } 

            while ( !pq.empty() && k > 0 ) {
                auto p = pq.top() ;
                pq.pop() ;

                if ( mp.count(p.second) ) continue ;

                int j = p.second ;
                int val = p.first ;

                sum -= val ;
                mp[j]++ ;
                k-- ;
            }

            ans.push_back(sum) ;
        } 

        return ans ;
    }
};