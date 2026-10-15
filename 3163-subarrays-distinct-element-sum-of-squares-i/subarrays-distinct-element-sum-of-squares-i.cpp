class Solution {
public:
    int sumCounts(vector<int>& nums) {
        vector<int> a ;
        int n = nums.size() ;
        for (int i = 0 ; i < n ; i++) {
            unordered_set<int> uset ;
            for ( int j = i ; j < n ; j++ ) {
                uset.insert(nums[j]) ;
                a.push_back(uset.size()) ;
            }
        }
        int ans = 0 ;
        for ( int i = 0 ; i < a.size() ; i++ ) {
            ans += a[i] * a[i] ;
        }
        return ans ;
    }
};