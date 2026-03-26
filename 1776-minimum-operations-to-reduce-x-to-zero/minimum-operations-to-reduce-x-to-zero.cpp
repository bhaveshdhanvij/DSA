class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        // Optimal Approach : try to find the subarray with sum sum(array) - k (window)
        // since operations on array is done on the ends .
        // try to maximize the subarray with the sum target 

        unordered_map<int,int> mp ;
        int mx = -1 ;
        int s = 0 ;
        for ( int val : a ) s += val ;
        int t = s - x , sum = 0 ;

        if ( t == 0 ) return a.size() ; // all the elements must be removed in that case 
        mp[0] = -1 ;
        for ( int i = 0 ; i < a.size() ; i++ ) {
            sum += a[i] ;
            if ( mp.count(sum - t) ) {
                mx = max ( mx , i - mp[sum - t] ) ;
            }

            if ( !mp.count(sum) ) mp[sum] = i ;
        }

        return mx == -1 ? -1 : a.size() - mx ;
    }
};