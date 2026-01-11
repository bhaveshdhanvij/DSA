class Solution {
public:
    int helper(int n) {
        int ans = 0 ;
        while ( n > 0 ) {
            int r = n % 10 ;
            ans += r * r ;
            n /= 10 ;
        }
        return ans ;
    }
    bool isHappy(int n) {
        unordered_set<int> uset ;
        
        while ( n != 1 ) {
            int t = helper(n) ;
            if ( uset.count(t) ) return false ;
            uset.insert(t) ;
            n = t ;
        }
        
        return true ;
    }
};