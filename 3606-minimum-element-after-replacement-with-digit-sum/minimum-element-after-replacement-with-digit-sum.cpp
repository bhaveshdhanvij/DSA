class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX ;
        for ( int x : nums ) {
            int temp = x , sum = 0 ;
            while ( temp ) {
                int r = temp % 10 ;
                sum += r ;
                temp /= 10 ;
            }
            if ( sum < ans ) {
                ans = sum ;
            }
        }
        return ans ;
    }
};