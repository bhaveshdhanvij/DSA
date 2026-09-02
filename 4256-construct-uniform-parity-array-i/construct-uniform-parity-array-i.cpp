class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool flag = true , odd = false ;
        for (int x : nums1 ) {
            if ( x % 2 != 0 ) {
                flag = false ;
                odd = true ;
            }
        }
        return flag || odd ;
    }
};