class Solution {
public:
    vector<string> getFolderNames(vector<string>& a) {
        unordered_map<string,int> mp ;
        vector<string> ans ;

        for ( int i = 0 ; i < a.size() ; i++ ) {
            string curr = a[i] ;
            if ( !mp.count(curr) ) {
                ans.push_back(curr) ;
                mp[curr] = 1 ;
            }else {
                int count = mp[curr] ;
                string temp ;

                while ( true ) {
                    temp = curr + "(" + to_string(count) + ")" ;
                    if ( !mp.count(temp) ) break ;
                    count++ ;
                }

                ans.push_back(temp) ;
                mp[curr] = count + 1 ;
                mp[temp] = 1 ;
            }
        }

        return ans ;
    }
};