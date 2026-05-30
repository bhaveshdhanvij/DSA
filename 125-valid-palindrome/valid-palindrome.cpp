class Solution {
public:
    // Amazon
    // DE Shaw
    // Facebook
    // Cisco
    // FactSet
    // Paytm
    // Zoho
    // Morgan Stanley
    bool isPalindrome(string s) {
        // Approach 1 : Using clean and then compare method 
        // TC : O(N) , SC : O(N)
 
        // int n = s.length() ;
        // string a = "" ;
        // for ( char c : s ) {
        //     if ( isalnum(c) ) {
        //         a += tolower(c) ;
        //     }
        // }
        // string b = a ;
        // reverse(b.begin() , b.end()) ;
        // return a == b ;


        // Optimal Approach : Using 2 - pointer approach 
        // TC : O(N) , SC : O(1) 

        int n = s.length() ;
        int i = 0 , j = n - 1 ;
        while ( i < j ) {
            if ( !isalnum(s[i]) ) i++ ;
            else if ( !isalnum(s[j]) ) j-- ;
            else if ( tolower(s[i]) != tolower(s[j]) ) return false ;
            else {
                i++ ;
                j-- ;
            }
        }
        return true ;
    }
};