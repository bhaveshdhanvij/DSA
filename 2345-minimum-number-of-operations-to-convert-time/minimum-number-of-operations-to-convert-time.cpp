class Solution {
public:
    int convertTime(string current, string correct) {
        
        int idx = current.find(':') ;
        int a = stoi(current.substr(0 , idx)) ;
        int b = stoi(current.substr(idx + 1)) ;

        idx = correct.find(':') ;
        int c = stoi(correct.substr(0 , idx)) ;
        int d = stoi(correct.substr(idx + 1)) ;

        int diff = (c * 60 + d) - (a * 60 + b) ;

        int temp[4] = { 1 , 5 , 15 , 60 } ;

        int ans = 0 ;

        for ( int i = 3 ; i >= 0 && diff > 0 ; i-- ) {
            int curr = diff / temp[i] ;

            ans += curr ;

            diff -= curr * temp[i] ;
        }

        return ans ;
    }
};