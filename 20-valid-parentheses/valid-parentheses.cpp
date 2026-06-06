class Solution {
public:
    // Amazon
    // JP morgan
    // Meta
    // Linkedin
    // Intuit
    // Google
    // Visa
    // TCS
    // IBM
    bool isValid(string s) {
        // Optimal Approach : Using stack : matching each closing brack with the opening and ensuring the non empty condition for equal no. of opening and closing brack 
        // TC : O(N) , SC : O(N) 
        
        stack<char> st ;
        for ( char c : s ) {
            if ( c == '(' || c == '{' || c == '[' ) st.push(c) ;
            else {
                if ( st.empty() ) return false ; // no opening brack for the closing one 

                char ch = st.top() ;
                st.pop() ;

                if ( (c == ')' && ch != '(') || (c == ']' && ch != '[') || (c == '}' && ch != '{') ) {
                    return false ; // matching condition check 
                }
            }
        }

        return st.empty() ; // ensuring every opening brack is matched 
    }
};