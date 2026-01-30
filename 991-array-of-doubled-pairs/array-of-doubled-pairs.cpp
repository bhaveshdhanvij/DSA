class Solution {
public:
    bool canReorderDoubled(vector<int>& a) {
        unordered_map<int,int> umap ;
        
        sort ( a.begin() , a.end() , [&](int a , int b) {
            return abs(a) < abs(b) ;
        });

        for ( int x : a ) umap[x]++ ;

        for ( int x : a ) {
            if ( umap[x] == 0 ) continue ;

            if ( umap[2 * x] == 0 ) {
                return false ;
            }

            umap[x]-- ;
            umap[2 * x]-- ;
        }

        return true ;
    }
};