class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> umap ;

        for ( int x : nums ) umap[x]++ ;

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