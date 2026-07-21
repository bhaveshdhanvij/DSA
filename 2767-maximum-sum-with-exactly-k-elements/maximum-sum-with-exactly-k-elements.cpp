class Solution {
public:
    int maximizeSum(vector<int>& a, int k) {
        int maxx = *max_element(a.begin() , a.end()) ;
        
        int l = maxx + k - 1 ;
        int right = l * (l + 1) / 2 ;
        int left = (maxx - 1) * (maxx) / 2 ;

        return right - left ;
    }
};