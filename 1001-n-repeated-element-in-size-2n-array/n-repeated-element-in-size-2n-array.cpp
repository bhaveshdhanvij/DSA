class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() ;
        map<int,int> mp ;
        for ( int x : nums ) mp[x]++ ;
        for ( auto p : mp ) {
            if( p.second == n / 2 ) return p.first ;
        }
        return -1 ;
    }
};