class Solution {
public:
    bool leap ( int n ) {
        return (n % 400 == 0) || (n % 4 == 0 && n % 100 != 0) ;
    }
    int day(string s) {
        int y = stoi(s.substr(0 , 4)) ;
        int m = stoi(s.substr(5 , 2)) ;
        int d = stoi(s.substr(8 , 2)) ;
        
        int a[13] = {0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 } ;
        int ans = 0 ;
        
        for (int year = 1971 ; year < y ; year++) {
            ans += leap(year) ? 366 : 365;
        }

        for ( int i = 1 ; i < m ; i++ ) {
            ans += a[i] ;
        }
        ans += d ;

        if ( leap(y) && m > 2 ) ans++ ;

        return ans ;
    }
    int daysBetweenDates(string date1, string date2) {
        int a = day(date1) ;
        int b = day(date2) ;
        return abs(a - b) ;
    }
};