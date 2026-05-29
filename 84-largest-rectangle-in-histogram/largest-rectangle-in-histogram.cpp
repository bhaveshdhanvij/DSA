class Solution {
public:
    // Meta
    // Doordash
    // Google
    // Myntra
    // DE Shaw
    // Adobe
    // TCS
    int largestRectangleArea(vector<int>& a) {
        // Approach 1 : Using brute force expansion around each bar 
        // TC : O(N * N) , SC : O(1) 

        // int n = a.size() ;
        // int maxx = INT_MIN ;
        
        // for ( int i = 0 ; i < n ; i++ ) {
        //     int area = a[i] ;
        //     int h = a[i] ;

        //     for ( int j = i - 1 ; j >= 0 ; j-- ) {
        //         if ( a[j] < h ) break ;
        //         area += h ;
        //     }

        //     for ( int j = i + 1 ; j < n ; j++ ) {
        //         if ( a[j] < h ) break ;
        //         area += h ;
        //     }
        //     maxx = max ( maxx , area ) ;
        // }
        // return maxx ;


        // Approach 2 : Using monotonic stack to find the smaller elements on both sides 
        // TC : O(N) , SC : O(2 * N) 

        // int n = a.size() ;
        // vector<int> l(n) ;

        // l[0] = -1 ;
        // stack<int> st ;
        // st.push(0) ;

        // for ( int i = 1 ; i < n ; i++ ) {
        //     while (!st.empty() && a[i] <= a[st.top()] ) {
        //         st.pop() ;
        //     }
        //     l[i] = st.empty() ? -1 : st.top() ;
        //     st.push(i) ;
        // }

        // vector<int> r(n) ;
        // r[n - 1] = n ;

        // st = stack<int>() ;
        // st.push(n - 1) ;

        // for ( int i = n - 2 ; i >= 0 ; i-- ) {
        //     while (!st.empty() && a[i] <= a[st.top()]) {
        //         st.pop() ;
        //     }
        //     r[i] = st.empty() ? n : st.top() ;
        //     st.push(i) ;
        // }

        // int maxx = 0 ;
        // for ( int i = 0 ; i < n ; i++ ) {
        //     int w = ( r[i] - l[i] ) - 1 ;
        //     int curr = w * a[i] ;
        //     if ( curr > maxx ) {
        //         maxx = curr ;
        //     }
        // }
        // return maxx ;


        // Optimal Approach : Using monotonic increasing stack
        // TC : O(N) , SC : O(N) 
        
        int n = a.size() ;
        stack<int> st ;
        int maxx = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {
            while (!st.empty() && a[i] < a[st.top()] ) {
                int idx = st.top() ;
                st.pop() ;

                int h = a[idx] ;
                
                int w = st.empty() ? i : (i - st.top() - 1) ;
                int area = h * w ;

                maxx = max ( maxx , area ) ;
            }
            st.push(i) ;
        }

        while (!st.empty()) {
            int idx = st.top() ;
            st.pop() ;

            int h = a[idx] ;
            int w = st.empty() ? n : (n - st.top() - 1) ;
            
            int area = w * h ;
            maxx = max ( maxx , area ) ;
        }

        return maxx ;
    }
};