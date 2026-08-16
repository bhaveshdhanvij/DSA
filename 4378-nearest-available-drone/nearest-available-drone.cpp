class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int minn = INT_MAX ;
        int ans = -1 ;
        for ( int i = 0 ; i < drones.size() ; i++ ) {
            int d = abs(target[0] - drones[i][0]) + abs(target[1] - drones[i][1]) ;
            if (d <= drones[i][2] && d < minn) {
                minn = d ;
                ans = i ;
            }
        }
        return ans ;
    }
};