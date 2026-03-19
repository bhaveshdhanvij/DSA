class Solution {
public:
    long long continuousSubarrays(vector<int>& a) {
        int l = 0 ;
        long long ans = 0 ;
        multiset<int> s ;
        
        for ( int r = 0 ; r < a.size() ; r++ ) {
            s.insert(a[r]) ;

            while ( *s.rbegin() - *s.begin() > 2 ) {
                s.erase(s.find(a[l])) ;
                l++ ;
            }

            ans += (r - l + 1) ;
        }

        return ans ;
    }
};