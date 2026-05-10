class Solution {
public:
    vector<int> concatWithReverse(vector<int>& a) {
        vector<int> ans = a ;
        for ( int i = a.size() - 1 ; i >= 0 ; i-- ) {
            ans.push_back(a[i]) ;
        }
        return ans ;
    }
};