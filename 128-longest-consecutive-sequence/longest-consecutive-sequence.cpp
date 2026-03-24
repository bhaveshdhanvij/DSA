class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        // TC : O(N) , SC : O(N) 
        // Optimal Approach : Use concept of setting the start so that we do not repeat searching for same sequence 

        int n = a.size() ;
        unordered_set<int> s ( a.begin() , a.end() ) ;
        int ans = 0 ;
        for ( int x : s ) {
            if ( s.count(x - 1) ) continue ;
            int st = x ;
            int c = 0 ;
            while ( s.count(st) ) {
                st++ ;
                c++ ;
            }
            ans = max ( ans , c ) ;
        }
        return ans ;
    }
};