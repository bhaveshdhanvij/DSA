class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxx = *max_element(nums.begin() , nums.end()) ;
        vector<int> f(maxx + 1, 0) ;
        for ( int x : nums ) f[x]++ ;

        vector<long long> c(maxx + 1 , 0) ;
        for ( int d = 1 ; d <= maxx ; d++ ) {
            for ( int j = d ; j <= maxx ; j += d ) {
                c[d] += f[j] ;
            }
        }

        vector<long long> e(maxx + 1, 0) ;
        for ( int d = maxx ; d >= 1 ; d-- ) {
            e[d] = c[d] * (c[d] - 1) / 2 ;
            for ( int j = d * 2 ; j <= maxx ; j += d ) {
                e[d] -= e[j] ;
            }
        }

        vector<long long> p ;
        vector<int> val ;
        long long sum = 0 ;

        for ( int d = 1 ; d <= maxx ; d++ ) {
            if ( e[d] > 0 ) {
                sum += e[d] ;
                p.push_back(sum) ;
                val.push_back(d) ;
            }
        }

        vector<int> ans ;
        for ( long long q : queries ) {
            int idx = upper_bound(p.begin() , p.end() , q) - p.begin() ;
            ans.push_back(val[idx]) ;
        }

        return ans ;
    }
};