class Solution {
public:
    int minElements(vector<int>& a, int l, int target) {
        long long sum = 0 ;
        for ( int x : a ) sum += x ;
        if ( sum == target ) return 0 ;
        long long diff = abs(sum - target) ;
        return ( diff + l - 1 ) / l ;
    }
};