class Solution {
public:
    vector<int> scoreValidator(vector<string>& e) {
        int score = 0 , c = 0 ;
        
        for ( string s : e ) {
            if ( s == "W" ) c++ ;
            else if ( s == "WD" || s == "NB" ) score++ ;
            else {
                score += stoi(s) ;
            }

            if ( c == 10 ) break ;
        }
        return {score , c} ;
    }
};