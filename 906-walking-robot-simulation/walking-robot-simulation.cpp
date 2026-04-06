class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> s ; 
        
        for ( auto &t : obstacles ) {
            string temp = to_string(t[0]) + "," + to_string(t[1]) ;
            s.insert(temp) ;
        }

        int delx[4] = { 0 , 1 , 0 , -1 } ;
        int dely[4] = { 1 , 0 , -1 , 0} ;

        int d = 0 ; // current is north 
        int ans = 0 , x = 0 , y = 0 ;

        for ( int curr : commands ) {
            if ( curr == -1 ) {
                d = (d + 1) % 4 ;
            }else if ( curr == -2 ) {
                d = (d + 3) % 4 ;
            }else {
                for ( int i = 0 ; i < curr ; i++ ) {
                    int nx = x + delx[d] ;
                    int ny = y + dely[d] ;
                    
                    string temp = to_string(nx) + "," + to_string(ny) ;
                    if ( s.count(temp) ) break ;

                    x = nx ;
                    y = ny ;

                    ans = max ( ans , x * x + y * y ) ;
                }
            }
        }

        return ans ;
    }
};