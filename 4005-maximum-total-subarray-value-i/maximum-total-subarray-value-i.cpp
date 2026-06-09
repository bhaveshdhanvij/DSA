class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxx = *max_element(nums.begin() , nums.end() ) ;
        int minn = *min_element(nums.begin() , nums.end() ) ;

        return (long long)k * (maxx - minn) ;
    }
};