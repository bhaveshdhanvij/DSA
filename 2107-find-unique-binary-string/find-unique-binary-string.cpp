class Solution {
public:
    unordered_set<string> a ;
    void helper(string s , int n) {
        if ( s.length() == n ) {
            a.insert(s) ;
            return ;
        }

        helper(s + "0" , n) ;
        helper(s + "1" , n) ;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int> mp ;
        for ( string s : nums ) mp[s]++ ;

        int t = nums[0].size() ;
        string s = "" ;
        helper(s , t) ;

        for ( auto p : a ) {
            if ( !mp.count(p) ) return p ;
        }

        return s ;
    }
};