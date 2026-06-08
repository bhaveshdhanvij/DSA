class Solution {
public:
    // Salesforce
    // Adobe
    // Oracle
    // Google
    // Microsoft
    // Amazon
    // Meta
    // Cisco
    // Bank of Newyork
    // Infosys
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Optimal Approach : Greedy index eliminaton technique by calculating rem gas after the move 
        // TC : O(N) , SC : O(1) 

        int n = gas.size() ;
        int c = 0 , g = 0 , curr = 0 , st = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {
            c += cost[i] ;
            g += gas[i] ;

            curr += (gas[i] - cost[i]) ;

            if ( curr < 0 ) { // existing starting index is invalid to start 
                st = i + 1 ;
                curr = 0 ;
            }
        }

        return g < c ? -1 : st ; // ensuring total gas is always >= total cost 
    }
};