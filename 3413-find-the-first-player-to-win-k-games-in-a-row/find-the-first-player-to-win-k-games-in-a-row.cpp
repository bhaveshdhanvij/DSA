class Solution {
public:
    int findWinningPlayer(vector<int>& s, int k) {
        int n = s.size() ;
        if ( k >= n ) {
            return max_element(s.begin() , s.end()) - s.begin() ;
        }
        
        deque<int> a ;
        for ( int i = 0 ; i < n ; i++ ) {
            a.push_back(i) ;
        }

        int prev = -1 , curr = 0 ;
        while ( true ) {
            int x = a.front() ;
            a.pop_front() ;

            int y = a.front() ;
            a.pop_front() ;

            if ( s[x] > s[y] ) {
                if ( prev == x ) curr++ ;
                else curr = 1 ;

                prev = x ;

                a.push_front(x) ;
                a.push_back(y) ;
            }else {
                if ( prev == y ) curr++ ;
                else curr = 1 ;

                prev = y ;

                a.push_front(y) ;
                a.push_back(x) ;
            }

            if ( curr == k ) return prev ;
        }
        return -1 ;
    }
};