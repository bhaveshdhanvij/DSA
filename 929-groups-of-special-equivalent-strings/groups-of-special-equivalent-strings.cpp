class Solution {
public:
    int numSpecialEquivGroups(vector<string>& a) {
        unordered_map<string,int> mp ;
        for ( string s : a ) {
            string t1 = "" , t2 = "" ;
            
            for ( int i = 0 ; i < s.size() ; i++ ) {
                if ( i % 2 == 0 ) t1 += s[i] ;
                else t2 += s[i] ;
            }

            sort ( t1.begin() , t1.end() ) ;
            sort ( t2.begin() , t2.end() ) ;

            mp[t1 + "|" + t2]++ ;
        }

        return (int)mp.size() ;
    }
};