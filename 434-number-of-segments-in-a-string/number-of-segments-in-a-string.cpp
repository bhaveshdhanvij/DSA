class Solution {
public:
    int countSegments(string s) {
        int ans = 0 ;
        stringstream ss(s) ;
        string word ;
        while ( ss >> word ) {
            ans++ ;
        }
        return ans ;
    }
};