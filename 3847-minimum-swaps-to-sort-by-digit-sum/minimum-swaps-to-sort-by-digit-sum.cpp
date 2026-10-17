class Solution {
public:
    int helper(int n) {
        int ans = 0 ;
        while ( n > 0 ) {
            ans += n % 10 ;
            n /= 10 ;
        }
        return ans ;
    }
    int minSwaps(vector<int>& a) {
        int n = a.size() ;
        vector<pair<int,int>> b ;
        for ( int i = 0 ; i < n ; i++ ) {
            b.push_back({a[i] , i}) ;
        }
        sort(b.begin() , b.end() , [&](const auto x , const auto y){
            int sumx = helper(x.first) ;
            int sumy = helper(y.first) ;
            if ( sumx == sumy ) return x < y ;
            return sumx < sumy ; 
        });
        vector<bool> vis(n , false) ;
        int ans = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( vis[i] || b[i].second == i ) continue ;

            int c = 0 , j = i ;
            while ( !vis[j] ) {
                vis[j] = true ;
                j = b[j].second ;
                c++ ;
            }
            if ( c > 1 ) ans += c - 1 ;
        }
        return ans ;
    }
};