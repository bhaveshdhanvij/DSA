class Solution {
public:
    int calculate(string ss) {
        long long ans = 0 ;
        long long s = 1 ;
        long long num = 0 ;
        stack<long long> st ;

        for ( char c : ss ) {
            if ( isdigit(c) ) {
                num = num * 10 + (c - '0') ;
            }else if ( c == '+' ) {
                ans += num * s ;
                num = 0 ;
                s = 1 ;
            }else if ( c == '-' ) {
                ans += num * s ;
                num = 0 ;
                s = -1 ;
            }else if ( c == '(' ) {
                st.push(ans) ;
                st.push(s) ;

                ans = 0 ;
                s = 1 ;
            }else if ( c == ')' ) {
                ans += num * s ;
                num = 0 ;

                int prevsign = st.top() ;
                st.pop() ;

                int prevans = st.top() ;
                st.pop() ;

                ans = prevans + prevsign * ans ;
            }
        }

        return ans + s * num ;
    }
};