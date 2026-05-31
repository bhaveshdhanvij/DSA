class Solution {
public:
    // MakeMyTrip
    // Flipkart
    // Google
    // Amazon
    // Airbnb
    // Atlassian
    // Microsoft
    string minWindow(string s, string t) {
        // Optimal Approach : Two pointer + Sliding window 
        // TC : O(N) , SC : O(1)

        int target[256] = {0} ;
        for ( char ch : t ) {
            target[ch]++ ;
        }

        int n = s.length() ;
        int i = 0 , j = 0 ;
        int count = 0 ;
        int req = t.length() ;
        int st = 0 ;
        int minn = INT_MAX ;
        
        while ( j < n ) {
            if ( target[s[j]] > 0 ) {
                count++ ;
            }
            target[s[j]]-- ;

            while ( count == req ) {
                if ( minn > j - i + 1 ) {
                    minn = j - i + 1 ;
                    st = i ;
                }

                target[s[i]]++ ;

                if ( target[s[i]] > 0 ) {
                    count-- ;
                }

                i++ ;
            }
            j++ ;
        }
        return minn == INT_MAX ? "" : s.substr(st , minn) ;
    }
};