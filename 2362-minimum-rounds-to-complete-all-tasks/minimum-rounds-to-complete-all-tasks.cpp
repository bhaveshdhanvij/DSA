class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> umap ;

        for ( int i = 0 ; i < tasks.size() ; i++ ) {
            umap[tasks[i]]++ ; 
        }

        int ans = 0 ;

        for ( auto p : umap ) {
            int x = p.second ;

            if ( x <= 1 ) return -1 ;

            ans += x / 3 ;

            if ( x % 3 != 0 ) ans++ ;
        }

        return ans ;
    }
};