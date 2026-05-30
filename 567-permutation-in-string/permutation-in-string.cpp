class Solution {
public:
    // Adobe
    // Goldman Sachs
    // Uber
    bool helper( string& a , string& b ) {
        int count[26] = {0} ;
        for ( char c : a ) count[c - 'a']++ ;
        for ( char c : b ) count[c - 'a']-- ;
        for ( int i = 0 ; i < 26 ; i++ ) {
            if ( count[i] != 0 ) {
                return false ;
            }
        }
        return true ;
    }
    bool checkInclusion(string s1, string s2) {
        // Approach 1 : Using sorting and comparison 
        // TC O((m - n)*Nlog(N)) , SC : O(N) 

        // int n = s1.size() ;
        // int m = s2.size() ;
        // if ( n > m ) return false ;
        // sort ( s1.begin() , s1.end() ) ;
        // for ( int i = 0 ; i <= m - n ; i++ ) {
        //     string t = s2.substr(i , n) ;
        //     sort ( t.begin() , t.end() ) ;
        //     if ( s1 == t ) {
        //         return true ;
        //     }
        // }
        // return false ;


        // Approach 2 : Anagram check using character frequency 
        // TC : O(N * M) , SC : O(M) 
        
        // int n = s1.size() , m = s2.size() ;
        // if ( n > m ) return false ;
        // for ( int i = 0 ; i <= m - n ; i++ ) {
        //     string t = s2.substr(i , n) ;
        //     if ( helper(t , s1) ) {
        //         return true ;
        //     }
        // }
        // return false ;


        // Optimal Approach : Sliding window + character frequency matching 
        // 
        
        int n = s1.size() , m = s2.size() ;
        if ( n > m ) return false ;

        vector<int> count1(26 , 0) ;
        vector<int> count2(26 , 0) ;

        for ( int i = 0 ; i < n ; i++ ) {
            count1[s1[i] - 'a']++ ;
            count2[s2[i] - 'a']++ ;
        } 

        if ( count1 == count2 ) return true ;

        int j = 0 ;
        for ( int i = n ; i < m ; i++ ) {
            count2[s2[i] - 'a']++ ;
            count2[s2[j] - 'a']-- ;
            if ( count1 == count2 ) {
                return true ;
            }
            j++ ;
        }
        return false ;
    }
};