class Solution {
public:
    int helper( int n ) {
        int temp = n , maxx = -1 ;
        int count = 0 ;
        while ( temp > 0 ) {
            int r = temp % 10 ;
            maxx = max ( maxx , r ) ;
            temp /= 10 ;
            count++ ;
        }
        string s ;
        s.append( count , maxx + '0' ) ;
        return stoi(s) ;
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0 ;
        for ( int x : nums ) {
            ans += helper(x) ;
        }
        return ans ;
    }
};