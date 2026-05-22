class Solution {
public:
    // Linkedin
    // Amazon
    // Meta
    // citadel
    // JP morgan
    // Oracle
    // Microsoft
    // Google
    // Salesforce
    double myPow(double x, int n) {
        // Brute force approach : multiply x n times with itself directly 
        // TC : O(N) , SC : O(1) 
        // long long power = n ;
        // if ( power < 0 ) {
        //     x = 1 / x ;
        //     power = -power ;
        // }
        // double ans = 1 ;
        // for ( int i = 0 ; i < power ; i++ ) {
        //     ans *= x ;
        // }
        // return ans ;

        // Optimal approach : binary exponentiation / fast power 
        // divide exp by half and multiply x by 2 
        // TC : O(Log(N)) , SC : O(1) 

        long long power = n ;
        if ( power < 0 ) {
            x = 1 / x ;
            power = -power ;
        }

        double ans = 1 ;
        while ( power > 0 ) {
            if ( power % 2 == 1 ) {
                ans *= x ;
            }
            x *= x ;
            power /= 2 ;
        }
        
        return ans ;
    }
};