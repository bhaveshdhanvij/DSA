class Solution {
public:
    int absDifference(vector<int>& a, int k) {
        sort(a.begin() , a.end()) ;
        int ans1 = 0 , ans2 = 0 ;
        int t = k ;
        int i = 0 , n = a.size() ;
        while (i < n && t) {
            t-- ;
            ans1 += a[i] ;
            i++ ;
        }
        i = n - 1 ;
        t = k ;
        while (i >= 0 && t) {
            ans2 += a[i] ;
            i-- ;
            t-- ;
        }
        return abs(ans1 - ans2) ;
    }
};