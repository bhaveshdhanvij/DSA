class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a1 , a2 , a ;
        for ( int num : nums ) {
            if ( a1.empty() ) a1.push_back(num) ;
            else if ( a2.empty() ) a2.push_back(num) ;
            else if ( a1.back() > a2.back() ) {
                a1.push_back(num) ;
            }else {
                a2.push_back(num) ;
            }
        }
        for ( int num : a1 ) a.push_back(num) ;
        for ( int num : a2 ) a.push_back(num) ;
        return a ;
    }
};