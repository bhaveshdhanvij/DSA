class Solution {
public:
    // blinkit
    // Flipkart
    // Apple
    // Meta
    // Google
    // Microsoft
    // Infosys
    // TCS
    int singleNonDuplicate(vector<int>& a) {
        // Approach 1 : Linear Scan (brute force)
        // TC : O(N) , SC : O(1)

        // Approach 2 : Using XOR property , duplicates cancels out each other and only single element remains which gives us our required ans 
        // TC : O(N) , SC : O(1) 

        // Approach 3 : Using Hashing : counting the occurences of each element 
        // TC : O(N) , SC : O(N) 

        // Optimal Approach : Custom binary search 
        // before the single element occurs every pair is found on even indices , afterwards it 
        // shifts to odd indices 
        // TC : O(log(N)) , SC : O(1) 

        int n = a.size() ;
        int l = 0 , r = n - 1 ;

        while ( l < r ) {
            int mid = l + (r - l) / 2 ;
            
            if ( mid % 2 == 1 ) mid-- ;

            if ( a[mid] == a[mid + 1] ) {
                l = mid + 2 ;
            }else {
                r = mid ;
            }
        }

        return a[l] ;
    }
};