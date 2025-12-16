class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int c = 0 , g = 0 ;
        int n = gas.size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            c += cost[i] ;
            g += gas[i] ;
        }
        if ( c > g ) return -1 ;
        int st = 0 , x = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            x += gas[i] - cost[i] ;
            if (x < 0) {
                x = 0 ;
                st = i + 1 ;
            }
        }
        return st ;
    }
};