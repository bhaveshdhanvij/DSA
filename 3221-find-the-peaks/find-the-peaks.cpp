class Solution {
public:
    vector<int> findPeaks(vector<int>& a) {
        int n = a.size() ;
        vector<int> ans ;
        
        for ( int i = 1 ; i < n - 1 ; i++ ) {
            if ( a[i] > a[i - 1] && a[i] > a[i + 1] ) {
                ans.push_back(i) ;
            }
        }

        return ans ;
    }
};