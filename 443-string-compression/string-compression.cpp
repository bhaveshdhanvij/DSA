class Solution {
public:
    int compress(vector<char>& a) {
        int n = a.size() ;
        int idx = 0 , i = 0 ;
        while ( i < n ) {
            int curr = a[i] ;
            int count = 0 ;
            while ( i < n && a[i] == curr ) {
                i++ ;
                count++ ;
            }
            a[idx++] = curr ;
            if ( count > 1 ) {
                string temp = to_string(count) ;
                for ( char ch : temp ) {
                    a[idx++] = ch ;
                }
            }
        }
        return idx ;
    }
};