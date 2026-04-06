class Solution {
public:
    string mostCommonWord(string s, vector<string>& banned) {
        unordered_set<string> uset ;
        for ( string &t : banned ) {
            string temp = "" ;
            for ( char c : t ) {
                c = tolower(c) ;
                temp += c ;
            }
            uset.insert(temp) ;
        }
        for ( char &c : s ) {
            if ( isalpha(c) ) {
                c = tolower(c) ;
            }else {
                c = ' ' ;
            }
        }
        unordered_map<string,int> mp ;
        int maxx = 0 ;
        string ans ;

        stringstream ss(s) ;
        string word ;
        while ( ss >> word ) {
            if ( !uset.count(word) ) {
                ++mp[word] ;
                int temp = mp[word] ;

                if ( temp > maxx ) {
                    maxx = temp ;
                    ans = word ;
                } 
            }
        }

        return ans ;
    }
};