class Solution {
public:
    vector<int> getStrongest(vector<int>& a, int k) {
        int n = a.size() ;
        sort ( a.begin() , a.end() ) ;
        
        int m = a[(n - 1) / 2] ;

        sort ( a.begin() , a.end() , [m](const int& x , const int& y) {
            if (abs(x - m) == abs(y - m)) return x > y ;
            return abs(x - m) > abs(y - m) ;
        });

        vector<int> ans ;
        for ( int i = 0 ; i < k && i < n ; i++ ) {
            ans.push_back(a[i]) ;
        }

        return ans ;
    }
};