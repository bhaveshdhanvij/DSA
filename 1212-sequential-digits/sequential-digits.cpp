class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789" ;
        vector<int> ans ;
        int maxx = to_string(high).size() ;
        int minn = to_string(low).size() ;
        for ( int l = minn ; l <= maxx ; l++ ) {
            for ( int i = 0 ; i + l <= 9 ; i++ ) {
                int num = stoi(s.substr(i , l)) ;
                if ( num >= low && num <= high ) ans.push_back(num) ;
            }
        }
        return ans ;
    }
};