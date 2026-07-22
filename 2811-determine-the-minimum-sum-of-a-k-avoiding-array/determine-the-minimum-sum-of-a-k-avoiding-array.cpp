class Solution {
public:
    int minimumSum(int n, int k) {
        int i = 1 ; // iterator 
        int sum = 0 ;
        unordered_map<int,int> mp ; // for tracking 
        int len = 0 ;
        while ( len < n ) {
            int temp = k - i ;
            if ( !mp.count(temp) ) {
                mp[i]++ ;
                sum += i ;
                len++ ;
            }
            i++ ;
        }
        return sum ;
    }
};