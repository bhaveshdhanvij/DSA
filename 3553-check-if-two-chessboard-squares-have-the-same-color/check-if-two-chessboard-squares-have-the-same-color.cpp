class Solution {
public:
    bool checkTwoChessboards(string x, string y) {
        int a = (x[0] - 'a' + 1) + (x[1] - '0') ;
        int b = (y[0] - 'a' + 1) + (y[1] - '0') ;

        return a % 2 == b % 2 ;
    }
};