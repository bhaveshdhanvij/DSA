class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "" ;
        for ( string s : words ) {
            int curr = 0 ;
            for ( char c : s ) {
                curr += weights[c - 'a'] ;
            }
            int t = curr % 26 ;
            ans += 'a' + (25 - t) ;
        }
        return ans ;
    }
};