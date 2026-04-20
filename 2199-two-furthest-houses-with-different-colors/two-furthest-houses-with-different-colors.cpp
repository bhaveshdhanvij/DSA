class Solution {
public:
    int maxDistance(vector<int>& a) {
        int i = 0 , j = a.size() - 1 ;
        while ( j >= 0 && a[j] == a[i] ) j-- ;  

        int ans = j >= 0 ? j - i : 0 ;

        i = 0 , j = a.size() - 1 ;
        while ( i < a.size() && a[i] == a[j] ) i++ ;

        ans = max ( ans , j - i ) ;
        
        return ans ;
    }
};