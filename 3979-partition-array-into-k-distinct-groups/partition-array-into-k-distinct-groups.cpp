class Solution {
public:
    bool partitionArray(vector<int>& a, int k) {
        int n = a.size() ;
        if ( n % k != 0 ) return false ;

        int gp = n / k ;

        unordered_map<int,int> mp ;
        for ( int x : a ) mp[x]++ ;

        for ( auto p : mp ) {
            if ( p.second > gp ) {
                return false ;
            }
        }
        
        return true ;
    }
};