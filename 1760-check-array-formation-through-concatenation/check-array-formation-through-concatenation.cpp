class Solution {
public:
    bool canFormArray(vector<int>& a, vector<vector<int>>& pieces) {
        int n = a.size() ;
        unordered_map<int,vector<int>> mp ;
        for ( auto p : pieces ) {
            mp[p[0]] = p ;
        }
        int i = 0 ;
        while ( i < n ) {
            if ( !mp.count(a[i]) ) return false ;

            vector<int> vec = mp[a[i]] ;
            for ( int x : vec ) {
                if ( i >= n || a[i] != x ) {
                    return false ;
                }else{
                    i++ ;
                }
            }
        }

        return true ;
    }
};