class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size() ;
        stack<int> st ; // store indices 
        
        st.push(0) ;
        vector<int> ans(n) ;
        for ( int i = 1 ; i < n ; i++ ) {
            while ( !st.empty() && a[i] > a[st.top()] ) {
                ans[st.top()] = i - st.top() ;
                st.pop() ;
            }
            st.push(i) ;
        }

        while (!st.empty()) {
            ans[st.top()] = 0 ;
            st.pop() ;
        }

        return ans ;
    }
};