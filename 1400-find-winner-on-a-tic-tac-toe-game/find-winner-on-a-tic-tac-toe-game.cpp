class Solution {
public:
    bool allsame(string s) {
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( s[i] == ' ' ) return false ;
            if ( i > 0 && s[i] != s[i - 1] ) return false ;
        }
        return true ;
    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> a(3 , vector<char>(3 , ' ')) ;
        
        bool flag = true ;
        for ( auto move : moves ) {
            int x = move[0] , y = move[1] ;
            if ( flag ) {
                a[x][y] = 'X' ;
            }else {
                a[x][y] = 'O' ;
            }
            flag = !flag ;
        }

        for ( int i = 0 ; i < 3 ; i++ ) {
            string t = "" ;
            for ( int j = 0 ; j < 3 ; j++ ) {
                t += a[i][j] ;
            }
            if ( allsame(t) ) {
                return t[0] == 'X' ? "A" : "B" ;
            }
        }

        for ( int i = 0 ; i < 3 ; i++ ) {
            string t = "" ;
            for ( int j = 0 ; j < 3 ; j++ ) {
                t += a[j][i] ;
            }
            if ( allsame(t) ) {
                return t[0] == 'X' ? "A" : "B" ;
            }
        }

        string temp1 = "" ;
        string temp2 = "" ;

        temp1 += a[0][0] ; temp1 += a[1][1] ; temp1 += a[2][2] ;
        temp2 += a[0][2] ; temp2 += a[1][1] ; temp2 += a[2][0] ;
        
        if ( allsame(temp1) ) {
            return temp1[0] == 'X' ? "A" : "B" ;
        }
        if ( allsame(temp2) ) {
            return temp2[0] == 'X' ? "A" : "B" ;
        }

        for ( int i = 0 ; i < 3 ; i++ ) {
            for ( int j = 0 ; j < 3 ; j++ ) {
                if ( a[i][j] == ' ' ) {
                    return "Pending" ;
                }
            }
        }

        return "Draw" ;
    }
};