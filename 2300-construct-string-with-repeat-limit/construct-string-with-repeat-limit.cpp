class Solution {
public:
    string repeatLimitedString(string s, int maxx) {
        unordered_map<char,int> mp ;
        for ( char c : s ) mp[c]++ ;

        priority_queue<pair<char,int>> pq ;
        for ( auto p : mp ) {
            pq.push({p.first , p.second}) ;
        }

        string ans = "" ;
        while (!pq.empty()) {
            auto [ch , count] = pq.top() ;
            pq.pop() ;

            int take = min ( maxx , count ) ;
            count -= take ;

            ans.append(take , ch) ;

            if ( count > 0 ) {
                if ( pq.empty() ) break ;
                
                auto [ch2 , count2] = pq.top() ;
                pq.pop() ;

                ans += ch2 ;
                --count2 ;
                
                if ( count2 > 0 ) pq.push({ch2 , count2}) ;
                pq.push({ch , count}) ;
            }
        }

        return ans ;
    }
};