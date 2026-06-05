class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<long long> a , b , c , d ;
        for ( int x : nums ) {
            if ( x & 1 ) a.push_back(x) ;
            else b.push_back(x) ;
        }
        for ( int x : target ) {
            if ( x & 1 ) c.push_back(x) ;
            else d.push_back(x) ;
        }

        sort ( a.begin() , a.end() ) ;
        sort ( b.begin() , b.end() ) ;
        sort ( c.begin() , c.end() ) ;
        sort ( d.begin() , d.end() ) ;

        long long ans = 0 ;
        for ( int i = 0 ; i < a.size() ; i++ ) {
            if ( a[i] > c[i] ) {
                ans += (a[i] - c[i]) / 2 ;
            }
        }

        for ( int i = 0 ; i < b.size() ; i++ ) {
            if ( b[i] > d[i] ) {
                ans += (b[i] - d[i]) / 2 ;
            }
        }

        return ans ;
    }
};