class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& a) {
        int ans = 0 ;

        unordered_map<int,vector<int>> mp ;
        for ( int i = 0 ; i < a.size() ; i++ ) {
            mp[a[i][0]].push_back(a[i][1]) ;
        }

        for ( auto &p : mp ) {
            auto b = p.second ; 

            sort ( b.begin() , b.end() ) ;
            int maxx = 1 , curr = 1 ;

            for ( int i = 1 ; i < b.size() ; i++ ) {
                if ( b[i] == b[i - 1] ) curr++ ;
                else curr = 1 ;
                maxx = max ( maxx , curr ) ;
            }

            if ( maxx > p.first ) ans++ ;
        }

        return ans ;
    }
};