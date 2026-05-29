class Solution {
public:
    // Flipkart
    // Google
    // Microsoft
    // Directi
    // Amazon
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        // Naive Approach : Simple Sliding Window by checking windown one by one 
        // TC : O(N * N) , SC : O(1) 

        // int n = a.size() ;
        // vector<int> ans ;
        // for ( int i = 0 ; i <= n - k ; i++ ) {
        //     int maxx = INT_MIN ;
        //     for ( int j = i ; j < k + i ; j++ ) {
        //         maxx = max ( maxx , a[j] ) ;
        //     }
        //     ans.push_back(maxx) ;
        // }
        // return ans ;


        // Approach 2 : Using max-heap 
        // TC : O(Nlog(N)) , SC : O(N) 

        // int n = a.size() ;
        // vector<int> ans ;
        // priority_queue<pair<int,int>> pq ;

        // for ( int i = 0 ; i < k ; i++ ) {
        //     pq.push({a[i] , i}) ;
        // }
        // ans.push_back(pq.top().first) ;

        // for ( int i = k ; i < n ; i++ ) {
        //     pq.push({a[i] , i}) ;

        //     while ( pq.top().second <= i - k ) {
        //         pq.pop() ;
        //     }

        //     ans.push_back(pq.top().first) ;
        // }
        // return ans ;


        // Optimal Approach : Optimized Sliding using Monotonic deque(double ended queue)
        int n = a.size() ;
        vector<int> ans ;
        deque<int> dq ;
        dq.push_back(0) ;

        for ( int i = 1 ; i < k ; i++ ) {
            while ( !dq.empty() && a[i] >= a[dq.back()] ) {
                dq.pop_back() ;
            }
            dq.push_back(i) ;
        }

        ans.push_back(a[dq.front()]) ;

        for ( int i = k ; i < n ; i++ ) {
            if ( !dq.empty() && dq.front() <= i - k ) {
                dq.pop_front() ;
            }

            while ( !dq.empty() && a[i] >= a[dq.back()] ) {
                dq.pop_back() ;
            }

            dq.push_back(i) ;
            ans.push_back(a[dq.front()]) ;
        }

        return ans ;
    }
};

        