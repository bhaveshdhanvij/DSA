class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size() ;
        vector<int> a = colors ;
        for ( int x : colors ) a.push_back(x) ;
        int curr = 1 , ans = 0 ;
        for ( int i = 1 ; i < n + k - 1 ; i++ ) {
            if ( a[i] != a[i - 1] ) curr++ ;
            else curr = 1 ;
            if ( curr >= k ) ans++ ;
        }
        return ans ;
    }
};