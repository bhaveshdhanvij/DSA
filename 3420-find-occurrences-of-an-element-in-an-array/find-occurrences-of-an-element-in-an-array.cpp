class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& a, vector<int>& queries, int x) {
        vector<int> idx ;

        for ( int i = 0 ; i < a.size() ; i++ ) {
            if ( a[i] == x ) {
                idx.push_back(i) ;
            }
        }

        vector<int> ans ;

        for ( int i = 0 ; i < queries.size() ; i++ ) {
            int j = queries[i] ;
            if ( j > idx.size() ) {
                ans.push_back(-1) ;
            }else {
                ans.push_back(idx[j - 1]) ;
            }
        }

        return ans ;
    }
};