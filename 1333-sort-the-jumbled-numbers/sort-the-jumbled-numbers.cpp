class Solution {
public:
    vector<int> sortJumbled(vector<int>& m, vector<int>& nums) {
        unordered_map<char,char> mp ;

        for ( int i = 0 ; i < m.size() ; i++ ) {
            mp[i + '0'] = m[i] + '0' ;
        }

        vector<pair<int,int>> temp ;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            string s = to_string(nums[i]) ;
            string t = "" ;

            for ( char c : s ) {
                t += mp[c] ;
            }

            int no = stoi(t) ;
            temp.push_back({no , i}) ;
        }

        sort ( temp.begin() , temp.end() , [&](const pair<int,int> x , const pair<int,int> y){
            if ( x.first == y.first ) return x.second < y.second ;
            return x.first < y.first ;
        });

        vector<int> ans ;
        for ( auto x : temp ) {
            int idx = x.second ;
            ans.push_back(nums[idx]) ;
        }

        return ans ;
    }
};