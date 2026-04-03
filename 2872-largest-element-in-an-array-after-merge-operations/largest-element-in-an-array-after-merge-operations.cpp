class Solution {
public:
    long long maxArrayValue(vector<int>& a) {
        int n = a.size() ;
        long long sum = 0 ;
        for ( int i = n - 1 ; i >= 0 ; i-- ) {
            if ( a[i] <= sum ) sum += a[i] ;
            else sum = a[i] ;
        }
        return sum ;
    }
};