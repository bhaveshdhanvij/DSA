class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0 ;
        unordered_map<int,int> umap ;
        int sum = 0 ;
        umap[0] = 1 ;
        for ( int x : nums ) {
            sum += x ;

            int r = (sum % k + k) % k ;
            ans += umap[r] ;
            umap[r]++ ;
        }
        return ans ;
    }
};