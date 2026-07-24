class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
        int n = a.size() ;
        unordered_set<int> s , ans ;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = i ; j < n ; j++ ) {
                s.insert(a[i] ^ a[j]) ;
            }
        }

        for (int x : s) {
            for (int val : a) {
                ans.insert(val ^ x) ;
            }
        }

        return ans.size() ;
    }
};