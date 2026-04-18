class Solution {
public:
    bool equalFrequency(string s) {
        vector<int> f(26 , 0) ;
        for ( char c : s ) {
            f[c - 'a']++ ;
        }
        
        for ( char c : s ) {
            f[c - 'a']-- ;
            int temp = -1 ;
            bool flag = true ;
            for ( int i = 0 ; i < 26 ; i++ ) {
                if ( f[i] != 0 ) {
                    if ( temp == -1 ) {
                        temp = f[i] ;
                    }else if ( temp != f[i] ) {
                        flag = false ;
                        break ;
                    }
                }
            }
            if ( flag ) return true ;
            f[c - 'a']++ ;
        }

        return false ;
    }
};