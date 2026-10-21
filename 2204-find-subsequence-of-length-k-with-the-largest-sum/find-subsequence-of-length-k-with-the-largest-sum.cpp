class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> a ;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            a.push_back({nums[i] , i}) ;
        }        
        vector<pair<int,int>> v ;
        sort(a.rbegin() , a.rend()) ;
        for ( int i = 0 ; i < k ; i++ ) v.push_back(a[i]) ;
        sort(v.begin() , v.end() , [&](const auto x , const auto y){
            return x.second < y.second ;
        });
        vector<int> ans ;
        for ( int i = 0 ; i < v.size() ; i++ ) ans.push_back(v[i].first) ;
        return ans ; 
    }
};