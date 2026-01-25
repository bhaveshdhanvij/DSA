class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> a , b ;
        for ( int x : nums1 ) a[x]++ ;
        for ( int x : nums2 ) b[x]++ ;

        vector<int> ans ;
        for ( auto p : a ) {
            if ( b.count(p.first) ) {
                int curr = min ( p.second , b[p.first] ) ;
                for ( int i = 0 ; i < curr ; i++ ) {
                    ans.push_back(p.first) ;
                } 
            }
        }

        return ans ;
    }
};