class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int c = 0 ;
        vector<int> a , b , ans ;
        
        for (int x : nums) {
            if ( x == pivot ) c++ ;
            else if ( x < pivot ) a.push_back(x) ;
            else b.push_back(x) ;
        }

        for (int x : a) ans.push_back(x) ;
        while(c--) ans.push_back(pivot) ;
        for (int x : b) ans.push_back(x) ;

        return ans ;
    }
};