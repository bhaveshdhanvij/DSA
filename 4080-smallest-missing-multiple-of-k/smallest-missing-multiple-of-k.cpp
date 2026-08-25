class Solution {
public:
    int missingMultiple(vector<int>& a, int k) {
        unordered_map<int,int> mp ;
        for (int x : a) mp[x]++ ;
        for (int i = k ; ; i += k) {
            if ( !mp.count(i) ) return i ;
        }
        return -1 ;
    }
};