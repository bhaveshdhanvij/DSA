class Solution {
public:
    // Flipkart
    // Directi
    // Media.Net
    // Google
    // Adobe
    // Nagarro
    bool isAnagram(string s, string t) {
        // Approach 1 : Using Sorting and then comparing 
        // TC : O(Nlog(N)) , SC : O(1) 

        // sort ( s.begin() , s.end() ) ;
        // sort ( t.begin() , t.end() ) ;
        // return s == t ;

        // Approach 2 :  Using HashMap 
        // TC : O(N) , SC : O(N) 

        // if ( s.length() != t.length() ) return false ;
        // unordered_map<char,int> a , b ;
        // for ( char c : s ) a[c]++ ;
        // for ( char c : t ) b[c]++ ;
        // return a == b ;

        // Optimal Approach : Using alphabet frequency counting 
        // TC : O(N) , SC : O(1) 

        if ( s.length() != t.length() ) return false ;
        int count[26] = {0} ;

        for ( int i = 0 ; i < s.length() ; i++ ) {
            count[s[i] - 'a']++ ;
            count[t[i] - 'a']-- ;
        }  

        for ( int i = 0 ; i < 26 ; i++ ) {
            if ( count[i] != 0 ) {
                return false ;
            }
        }
        return true ;
    }
};