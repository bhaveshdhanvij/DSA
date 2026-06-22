class Solution {
public:
    int maxNumberOfBalloons(string s) {
        int ans = INT_MAX ;
        unordered_map<char,int> mp ;
        for ( char c : s ) mp[c]++ ;
        ans = min ({mp['b'] , mp['a'] , mp['l'] / 2 , mp['o'] / 2 , mp['n']}) ;
        return ans ;
    }
};