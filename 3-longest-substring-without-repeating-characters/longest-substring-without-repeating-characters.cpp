class Solution {
public:
    // Amazon
    // Morgan Stanley
    int lengthOfLongestSubstring(string s) {
        // Approach 1 : Checking all substrings with HashSet 
        // TC : O(N * N) , SC : O(1) 

        // int n = s.size() ;
        // int ans = 0 ;
        // for ( int i = 0 ; i < n ; i++ ) {
        //     unordered_set<char> uset ;
        //     for ( int j = i ; j < n ; j++ ) {
        //         if ( uset.count(s[j]) ) break ; // this means duplicate found 
        //         uset.insert(s[j]) ;
        //         ans = max ( ans , j - i + 1 ) ;
        //     }
        // }
        // return ans ;

        // Approach 2 : Sliding Window + HashSet 
        // TC : O(N) , SC : O(1) 

        int n = s.size() ;
        int l = 0 , ans = 0 ;
        unordered_set<char> uset ;
        for ( int r = 0 ; r < n ; r++ ) {
            while ( uset.count(s[r]) ) {
                uset.erase(s[l]) ;
                l++ ;
            }
            uset.insert(s[r]) ;
            ans = max ( ans , r - l + 1 ) ;
        }
        return ans ;
    }
};