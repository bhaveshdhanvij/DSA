class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z" } ;

        unordered_map<char,pair<int,int>> mp ;
        for ( int r = 0 ; r < board.size() ; r++ ) {
            for ( int c = 0 ; c < board[r].size() ; c++ ) {
                mp[board[r][c]] = {r , c} ;
            }
        }

        int r = 0 , c = 0 ;
        string ans = "" ;
        for ( char ch : target ) {
            auto [nr , nc] = mp[ch] ;
            
            if ( ch == 'z' ) {
                while ( nc < c ) ans += 'L' , c-- ;
                while ( c < nc ) ans += 'R' , c++ ;
                while ( nr < r ) ans += 'U' , r-- ;
                while ( r < nr ) ans += 'D' , r++ ;
            }else {
                while ( nr < r ) ans += 'U' , r-- ;
                while ( r < nr ) ans += 'D' , r++ ;
                while ( nc < c ) ans += 'L' , c-- ;
                while ( c < nc ) ans += 'R' , c++ ;
            }

            ans += '!' ;
        }

        return ans ;
    }
};