class Solution {
public:
    vector<long long> minOperations(vector<int>& a, vector<int>& queries) {
        int n = a.size() ;
        sort(a.begin() , a.end()) ;
        vector<long long> p(n , 0) ;
        p[0] = a[0] ;
        for ( int i = 1 ; i < n ; i++ ) {
            p[i] = p[i - 1] + a[i] ;
        }
        vector<long long> ans ;
        for ( auto q : queries ) {
            int idx = upper_bound(a.begin() , a.end() , q) - a.begin() ;

            long long lsum = (idx == 0) ? 0 : p[idx - 1] ;
            long long rsum = p[n - 1] - lsum ;
            
            long long lcost = 1LL * q * idx - lsum ;
            long long rcost = rsum - q * 1LL * (n - idx) ;

            ans.push_back(lcost + rcost) ;
        }

        return ans ;
    }
};