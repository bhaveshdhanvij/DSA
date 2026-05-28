class Solution {
public:
    string categorizeBox(int l, int w, int h, int mass) {
        long long vol = 1LL * l * w * h ;
        bool bulky = false ;
        if ( l >= 10000 || w >= 10000 || h >= 10000 || vol >= 1000000000 ) bulky = true ;
        bool heavy = false ;
        if ( mass >= 100 ) heavy = true ;
        if ( bulky && heavy ) return "Both" ;
        if ( !bulky && !heavy ) return "Neither" ;
        if ( bulky ) return "Bulky" ;
        return "Heavy" ; 
    }
};