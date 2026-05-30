class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Brute Force Approach : keep searching and deleting until found 
        // TC : O(N * N) , SC : O(N) 

        // int k = part.size() ;
        // while ( s.find(part) != string::npos ) {
        //     s.erase(s.find(part) , k) ;
        // }
        // return s ;


        // Optimal Approach : Stack based searching 
        // TC : O(N + M) , SC : O(N) 

        string ans ;
        int m = part.size() ;
        for ( char c : s ) {
            ans.push_back(c) ;
            if ( ans.size() >= m && ans.substr(ans.size() - m) == part ) {
                ans.erase(ans.size() - m) ;
            }
        }        
        return ans ;
    }
};