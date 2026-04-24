class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<pair<int,int>> q ;
        q.push({start , 0}) ;

        vector<bool> vis(1001 , false) ;
        vis[start] = 1 ;

        while (!q.empty()) {
            auto [x , count] = q.front() ;
            q.pop() ;

            for ( int num : nums ) {
                vector<int> temp = { x + num , x - num , x ^ num } ;

                for ( int it : temp ) {
                    if ( it == goal ) return count + 1 ;

                    if ( it >= 0 && it <= 1000 && !vis[it] ) {
                        q.push({it , count + 1}) ;
                        vis[it] = 1 ;
                    }
                }
            }
        }

        return -1 ;
    }
};