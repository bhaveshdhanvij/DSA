class Solution {
public:
    int minJumps(vector<int>& a) {
        int n = a.size() ;
        if ( n == 1 ) return 0 ; // bc 

        unordered_map<int,vector<int>> mp ;
        for ( int i = 0 ; i < n ; i++ ) {
            mp[a[i]].push_back(i) ;
        }

        queue<int> q ;
        vector<bool> vis(n , false) ;

        q.push(0) ;
        vis[0] = true ;

        int ans = 0 ;

        while (!q.empty()) {
            int s = q.size() ;
            while (s--) {
                int idx = q.front() ;
                q.pop() ;

                if ( idx == n - 1 ) {
                    return ans ;
                }

                if ( idx - 1 >= 0 && !vis[idx - 1] ) {
                    q.push(idx - 1) ;
                    vis[idx - 1] = true ;
                }

                if ( idx + 1 < n && !vis[idx + 1] ) {
                    q.push(idx + 1) ;
                    vis[idx + 1] = true ;
                }

                for ( int x : mp[a[idx]] ) {
                    if (!vis[x] ) {
                        q.push(x) ;
                        vis[x] = true ;
                    }
                } 

                mp[a[idx]].clear() ;
            }
            ans++ ;
        }
        return -1 ;
    }
};