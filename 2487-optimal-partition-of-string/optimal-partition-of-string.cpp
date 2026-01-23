class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> umap ;
        
        int ans = 1 ;
        for ( char c : s ) {
            if ( umap.count(c) ) {
                ans++ ;
                umap.clear() ;
            }

            umap[c]++ ;
        }

        return ans ;
    }
};