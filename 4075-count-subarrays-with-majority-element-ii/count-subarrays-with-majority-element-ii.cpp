class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size() ;
        int s = n + 1 ;
        vector<long long> cnt(2 * n + 2 , 0) ;
        vector<long long> p(2 * n + 2 , 0) ;

        int curr = s ;
        cnt[curr] = 1 ;
        p[curr] = 1 ;

        long long ans = 0 ;
        
        for ( int x : nums ) {
            curr += (x == target) ? 1 : -1 ;

            ans += p[curr - 1] ;

            cnt[curr]++ ;

            p[curr] = p[curr - 1] + cnt[curr] ;
        }

        return ans ;
    }
};