class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp ;
        for (int x : arr) mp[x]++ ;
        vector<pair<int,int>> nums ;
        for ( auto p : mp ) nums.push_back(make_pair(p.second , p.first)) ;
        sort( nums.begin() , nums.end() ) ;
        int count = 0 ;
        int sum = 0 ;
        int n = arr.size() ;
        for ( int i = nums.size() - 1 ; i >= 0 ; i-- ) {
            sum += nums[i].first ;
            count++ ;
            if ( sum >= n / 2 ) break ;
        }
        return count ;
    }
};