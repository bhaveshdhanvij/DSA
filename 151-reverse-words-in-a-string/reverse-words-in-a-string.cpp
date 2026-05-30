class Solution {
public:
    // Nvidia
    // Google
    // Zoho
    // Amazon
    // Adobe
    // TCS
    // Infosys
    // Accenture
    string reverseWords(string s) {
        // Approach 1 : Reverse words using manual word extraction 
        // TC : O(N) , SC : O(N) 

        // vector<string> words ;
        // string word = "" ;
        // for ( char c : s ) {
        //     if ( c != ' ' ) word += c ;
        //     else if (!word.empty()) {
        //         words.push_back(word) ;
        //         word = "" ;
        //     }
        // } 
        // if ( !word.empty() ) words.push_back(word) ;
        // reverse(words.begin() , words.end()) ;
        // string ans = "" ;
        // for ( string t : words ) {
        //     if ( !ans.empty() ) ans += ' ' ;
        //     ans += t ;
        // }
        // return ans ;


        // Approach 2 : direct addition by greedy
        // TC : O(N) , SC : O(1) 
        
        string word = "" , ans = "" ;
        for ( int i = s.length() - 1 ; i >= 0 ; i-- ) {
            char c = s[i] ;
            if ( c != ' ' ) {
                word = c + word ;
            }else if ( !word.empty() ) {
                if (!ans.empty()) ans += ' ' ;
                ans += word ;
                word = "" ;
            }
        } 
        if ( !word.empty() ) {
            if ( !ans.empty() ) ans += ' ' ;
            ans += word ;
        }
        return ans ;
    }
};