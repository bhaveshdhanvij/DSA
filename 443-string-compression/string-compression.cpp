class Solution {
public:
    // GoDaddy
    // Amazon
    // Salesforce
    // Yandex
    // Pinterest
    // Meta
    int compress(vector<char>& a) {
        // Optimal Approach : Using 2 pointer string compression 
        // TC : O(N), SC : O(1) 

        a.push_back('/') ;
        int n = a.size() ;
        int i = 0 , j = 1 , c = 1 ;
        
        while ( j < n ) {
            if ( a[j] == a[j - 1] ) c++ ;
            else {
                a[i] = a[j - 1] ;
                i++ ;
                if ( c >= 2 ) {
                    string t = to_string(c) ;
                    for ( char ch : t ) {
                        a[i] = ch ;
                        i++ ;
                    }
                    c = 1 ;
                }
            }
            j++ ;
        }
        return i ;
    }
};