class Solution {
public:
    bool canReach(vector<int>& a, int s) {
        // bfs basic 
        int n = a.size() ;
        vector<bool> vis(n , false) ;
        vis[s] = true ;
        queue<int> q ;
        q.push(s) ;
        
        while (!q.empty()) {
            int idx = q.front() ;
            q.pop() ;

            if ( a[idx] == 0 ) {
                return true ;
            }

            int j = idx - a[idx] ;
            int k = idx + a[idx] ;
            
            if ( j >= 0 && !vis[j] ) {
                q.push(j) ;
                vis[j] = true ;
            }

            if ( k < n && !vis[k] ) {
                q.push(k) ;
                vis[k] = true ;
            }
        }
        return false ;
    }
};