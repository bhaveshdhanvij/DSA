class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& a, int t) {
        int n = a.size() ;

        vector<int> p(n , 0) ;
        vector<int> s(n , 0) ;
        int c = 0 ;

        for ( int i = 1 ; i < n ; i++ ) {
            if ( a[i] <= a[i - 1] ) c++ ;
            else c = 0 ;

            p[i] = c ;
        }

        c = 0 ;
        for ( int i = n - 2 ; i >= 0 ; i-- ) {
            if ( a[i] <= a[i + 1] ) c++ ;
            else c = 0 ;

            s[i] = c ;
        }

        vector<int> ans ;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( s[i] >= t && p[i] >= t ) {
                ans.push_back(i) ;
            }
        }

        return ans ;
    }
};