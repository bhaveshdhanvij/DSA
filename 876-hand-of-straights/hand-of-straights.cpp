class Solution {
public:
    bool isNStraightHand(vector<int>& a, int s) {
        int n = a.size() ;
        map<int,int> mp ;

        for (int x : a ) mp[x]++ ;

        while ( !mp.empty() ) {
            int st = mp.begin()->first ;

            for ( int i = 0 ; i < s ; i++ ) {
                int curr = st + i ;

                if ( !mp.count(curr) ) return false ;

                mp[curr]-- ;
                if ( mp[curr] == 0 ) {
                    mp.erase(curr) ;
                }
            }
        }
        return true ;
    }
};