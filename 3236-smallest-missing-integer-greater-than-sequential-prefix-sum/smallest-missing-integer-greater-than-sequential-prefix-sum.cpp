class Solution {
public:
    int missingInteger(vector<int>& a) {
        unordered_map<int,int> mp ;
        for ( int x : a ) mp[x]++ ;
        int sum = a[0] , n = a.size() ;
        int i = 1 ;
        while ( i < n && a[i] == a[i - 1] + 1 ) {
            sum += a[i] ;
            i++ ;
        }
        while ( mp.count(sum) ) sum++ ;
        return sum ;
    }
};