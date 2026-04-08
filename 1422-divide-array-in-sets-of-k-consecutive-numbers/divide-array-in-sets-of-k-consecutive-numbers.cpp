class Solution {
public:
    bool isPossibleDivide(vector<int>& a, int k) {
        unordered_map<int,int> mp ;
        for ( int x : a ) mp[x]++ ;

        sort ( a.begin() , a.end() ) ;

        for ( int i = 0 ; i < a.size() ; i++ ) {
            if ( !mp.count(a[i]) ) continue ;

            int st = a[i] ;
            
            for ( int i = 0 ; i < k ; i++ ) {
                if ( !mp.count(st) ) return false ;

                --mp[st] ;
                if ( mp[st] == 0 ) mp.erase(st) ;
                st++ ;
            }
        }

        return true ;
    }
};