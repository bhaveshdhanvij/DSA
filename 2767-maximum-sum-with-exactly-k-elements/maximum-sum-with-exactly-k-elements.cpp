class Solution {
public:
    int maximizeSum(vector<int>& a, int k) {
        int maxx = *max_element(a.begin() , a.end()) ;
        
        int t = k - 1 ;
        
        return ( maxx * k ) + ( ( t * (t + 1) ) / 2 ) ;
    }
};