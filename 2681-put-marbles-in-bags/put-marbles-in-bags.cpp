class Solution {
public:
    long long putMarbles(vector<int>& nums , int k) {
        int n = nums.size() ;
        priority_queue<long long> a ;
        priority_queue<long long , vector<long long>,greater<long long>> b ;

        for ( int i = 0 ; i < n - 1 ; i++ ) {
            long long x = nums[i] + nums[i + 1] ;
            a.push(x) ;
            b.push(x) ;
            if ( a.size() > k - 1 ) a.pop() ;
            if ( b.size() > k - 1 ) b.pop() ;
        }

        long long maxx = 0 , minn = 0 ;
        while ( !a.empty() ) {
            minn += a.top() ;
            a.pop() ;
        }

        while ( !b.empty() ) {
            maxx += b.top() ;
            b.pop() ;
        }

        return maxx - minn ;
    }
};