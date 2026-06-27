class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mp ;
        for ( int x : nums ) mp[x]++ ;
        int ans = 0 ;

        if ( mp[1] % 2 == 0 ) {
            ans = mp[1] - 1 ;
        }else {
            ans = mp[1] ;
        }

        mp.erase(1) ;

        for ( auto [num , _] : mp ) {
            int curr = 0 ;
            long long x = num ;

            while ( mp.count(x) && mp[x] > 1 ) {
                curr += 2 ;
                x *= x ;
            }

            if ( mp.count(x) ) curr++ ;
            else curr-- ;

            ans = max ( ans , curr ) ;
        }

        return ans ;
    }
};