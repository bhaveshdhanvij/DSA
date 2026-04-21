class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int delRow[8] = { -1 , -1 , -1 , 0 , 1 , 1 , 1 , 0 } ;
        int delCol[8] = { -1 , 0 , 1 , 1 , 1 , 0 , -1 , -1 } ;

        int kr = king[0] , kc = king[1] ;

        unordered_map<string,int> mp ;
        for ( auto q : queens ) {
            int r = q[0] ;
            int c = q[1] ;
            
            string t = to_string(r) + "," + to_string(c) ;
            mp[t]++ ;
        }

        vector<vector<int>> ans ;
        for ( int i = 0 ; i < queens.size() ; i++ ) {
            auto v = queens[i] ;
            int r = v[0] , c = v[1] ;
            bool flag = false ;

            for ( int d = 0 ; d < 8 ; d++ ) {
                int nr = r + delRow[d] ;
                int nc = c + delCol[d] ;
                
                while ( nr >= 0 && nr < 8 && nc >= 0 && nc < 8 ) {
                    if ( nr == kr && nc == kc ) {
                        flag = true ;
                        break ;
                    }
                    string s = to_string(nr) + "," + to_string(nc) ;
                    if ( mp.count(s) ) break ;
                    nr += delRow[d] ;
                    nc += delCol[d] ;
                }
                
                if ( flag ) break ;
            }
            if ( flag ) {
                ans.push_back(v) ;
            }
        }

        return ans ;
    }
};