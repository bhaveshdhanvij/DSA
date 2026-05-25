class Solution {
public:
    bool canReach(string s, int minn, int maxx) {
        int n = s.size() ;
        if ( s[n - 1] == '1' ) return false ;
        
        vector<int> vis(n , false) ;
        queue<int> q ;
        
        q.push(0) ;
        vis[0] = true ;

        int f = 0 ;
        
        while (!q.empty()) {
            int idx = q.front() ;
            q.pop() ;
            
            if ( idx == n - 1 ) {
                return true ;
            }

            int st = max ( idx + minn , f ) ;
            int end = min ( idx + maxx , n - 1 ) ;

            for ( int i = st ; i <= end ; i++ ) {
                if ( s[i] == '0' && !vis[i] ) {
                    q.push(i) ;
                    vis[i] = true ;
                }
            }
            f = end ;
        }
        return false ;
    }
};