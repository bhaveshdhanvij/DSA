class Solution {
public:
    vector<int> a ;
    unordered_map<int,vector<int>> umap ;
    Solution(vector<int>& nums) {
        a = nums ;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            umap[a[i]].push_back(i) ;
        }
    }
    
    int pick(int target) {
        vector<int> t = umap[target] ;
        int n = t.size() ;
        return t[rand() % n] ;  
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */