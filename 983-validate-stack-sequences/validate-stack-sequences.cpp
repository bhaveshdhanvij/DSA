class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // TC : O(N) , SC : O(N) 
        stack<int> st ;
        int j = 0 ;

        for ( int x : pushed ) {
            st.push(x) ;
            while (!st.empty() && st.top() == popped[j] ) {
                st.pop() ;
                j++ ;
            }
        }

        return st.empty() && j == popped.size() ;
    }
};