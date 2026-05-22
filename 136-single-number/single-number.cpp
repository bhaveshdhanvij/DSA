class Solution {
public:
    // Product Based:-
    // Apple
    // Amazon
    // Microsoft
    // Adobe
    // Zoho
    // Airbnb
    // Qualcomm
    // Uber
    // Google
    // Meta
    // Service Based :-
    // TCS
    int singleNumber(vector<int>& a) {
        // Approach 1 : for every number , calculate how many times it appeared in the array
        // TC : O(N**2) 

        // Approach 2 : Use hashMap for storing occurence of all numbers and traverse again for ans
        // TC : O(N) , SC : O(N) 

        // unordered_map<int,int> mp ;
        // for ( int x : a ) mp[x]++ ;
        // for ( auto it : mp ) {
        //     if ( it.second == 1 ) {
        //         return it.first ;
        //     }
        // }
        // return -1 ;

        // Optimal Approach : Use XOR property , duplicates cancels out each other and single number remains after applying XOR all over the array 
        // TC : O(N) , SC : O(1) ;

        int ans = 0 ;
        for ( int x : a ) {
            ans ^= x ;
        }
        return ans ;
    }
};