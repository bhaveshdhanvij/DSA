class Solution {
public:
    vector<int> numberOfLines(vector<int>& w, string s) {
        int a = 1 , b = 0 ;
        for ( char c : s ) {
            int idx = c - 'a' ;
            int val = w[idx] ;
            
            if ( b + val <= 100 ) {
                b += val ;
            }else {
                a++ ;
                b = val ;
            }
        }

        return {a , b} ;
    }
};