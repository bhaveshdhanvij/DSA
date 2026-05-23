class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = k ;
        int i = num.size() - 1 ;
        while ( i >= 0 || carry > 0 ) {
            if ( i >= 0 ) {
                carry += num[i] ;
                num[i] = carry % 10 ;
                carry /= 10 ;
                i-- ;
            }else {
                num.insert(num.begin() , carry % 10) ;
                carry /= 10 ;
            }
        }
        return num ;
    }
};