class Solution {
public:
    // Google
    // salesforce
    // Nvidia
    // Meta
    // Amazon
    // Oracle
    // Adobe
    // PayPal
    // TCS
    string helper(string &s) {
        string hash = "" ;
        vector<int> f(26 , 0) ;
        for ( char c : s ) {
            f[c - 'a'] += 1 ;
        }
        for ( int i = 0 ; i < 26 ; i++ ) {
            hash.append(to_string(f[i])) ;
            hash.append("$") ;
        }
        return hash ;
    }
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        // Approach 1 : Using Hashing with sorted strings as keys 
        // TC : O(Nklog(k)) , SC : O(N * K) 

        // vector<vector<string>> ans ;
        // int n = a.size() ;
        // unordered_map<string,vector<string>> mp ;
        
        // for ( int i = 0 ; i < n ; i++ ) {
        //     string s = a[i] ;
        //     string t = s ;
        //     sort ( t.begin() , t.end() ) ;
        //     mp[t].push_back(s) ;
        // }

        // for ( auto p : mp ) {
        //     ans.push_back(p.second) ;
        // }
        // return ans ;


        // Optimal Approach : Signature hashing approach 
        // TC : O(N * K) , SC : O(N * k) 

        vector<vector<string>> ans ;
        unordered_map<string,vector<string>> mp ;

        for ( int i = 0 ; i < a.size() ; i++ ) {
            string k = helper(a[i]) ;
            mp[k].push_back(a[i]) ;
        }

        for ( auto p : mp ) {
            ans.push_back(p.second) ;
        }

        return ans ;
    }
};