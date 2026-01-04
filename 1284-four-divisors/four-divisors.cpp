class Solution {
public:
    vector<int> helper(int n) {
        vector<int> ans ;
        for ( int i = 1 ; i * i <= n ; i++ ) {
            if (n % i == 0) {
                ans.push_back(i) ;
                if ( i != n / i ) {
                    ans.push_back(n / i) ;
                }
            }
        }
        return ans ;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0 ;
        for ( int x : nums ) {
            vector<int> a = helper(x) ;
            if ( a.size() == 4 ) {
                for ( int p : a ) {
                    ans += p ;
                }
            }
        }
        return ans ;
    }
};