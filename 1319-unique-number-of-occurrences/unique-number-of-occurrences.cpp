class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp , mpp ;
        for ( int x : arr ) mp[x]++ ;
        for ( auto p : mp ) {
            if ( mpp.count(p.second) ) return false ;
            mpp[p.second]++ ;
        }
        return true ;
    }
};