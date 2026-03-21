class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size() ;
        unordered_map<char,int> mp ;
        priority_queue<pair<int,char>> pq ;

        for ( char c : s ) mp[c]++ ;
        for ( auto p : mp ) {
            if ( p.second > (n + 1) / 2 ) return "" ;
            pq.push({p.second , p.first}) ;
        }

        string ans = "" ;
        auto prev = pq.top() ;
        pq.pop() ;
        ans += prev.second ;
        prev.first-- ;

        while (!pq.empty()) {
            auto curr = pq.top() ;
            pq.pop() ;

            ans += curr.second ;
            curr.first-- ;

            if ( prev.first > 0 ) pq.push(prev) ;
            prev = curr ;
        }

        return ans ;
    }
};