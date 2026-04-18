class Solution {
public:
    int minDeletions(string s) {
        vector<int> a ;
        unordered_map<char,int> mp ;
        for ( char c : s ) mp[c]++ ;

        for ( auto p : mp ) {
            a.push_back(p.second) ;
        }

        sort ( a.rbegin() , a.rend() ) ;

        int ans = 0 ;

        for ( int i = 1 ; i < a.size() ; i++ ) {
            while ( a[i] > 0 && a[i] >= a[i - 1] ) {
                ans++ ;
                a[i]-- ;
            }
        }

        return ans ;
    }
};