class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& a, vector<int>& f) {
        unordered_map<int,long long> mp ;
        multiset<long long> s ;
        vector<long long> ans ;

        for ( int i = 0 ; i < a.size() ; i++ ) {
            int id = a[i] ;
            long long c = f[i] ;

            if ( mp.count(id) ) {
                s.erase(s.find(mp[id])) ;
            }

            mp[id] += c ;
            s.insert(mp[id]) ;

            ans.push_back(*s.rbegin()) ;
        }

        return ans ;
    }
};