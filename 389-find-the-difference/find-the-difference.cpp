class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> count1(26 , 0) , count2(26, 0) ;
        for ( char c : s ) count1[c - 'a']++ ;
        for ( char c : t ) count2[c - 'a']++ ;
        for ( int i = 0 ; i < 26 ; i++ ) {
            if ( count2[i] - count1[i] == 1 ) return 'a' + i ;
        }
        return 'a' ;
    }
};