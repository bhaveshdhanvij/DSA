class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int,int>> a ;

        for ( int i = 0 ; i < values.size() ; i++ ) {
            a.push_back({values[i] , labels[i]}) ;
        }

        sort ( a.rbegin() , a.rend() ) ;

        unordered_map<int,int> umap ;

        int ans = 0 ;
        int i = 0 ;
        while ( i < values.size() && numWanted > 0 ) {
            auto p = a[i] ;

            if ( umap.count(p.second) && umap[p.second] == useLimit ) {
                i++ ;
                continue ;
            }

            ans += p.first ;

            umap[p.second]++ ;
            numWanted-- ;
            i++ ;
        }

        return ans++ ;
    }
};