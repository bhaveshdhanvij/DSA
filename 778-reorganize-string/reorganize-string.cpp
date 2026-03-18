class Solution {
public:
    string reorganizeString(string s) {
        int c[26] = {0} ;
        for ( char ch : s ) c[ch - 'a']++ ;

        priority_queue<pair<int,char>> pq ;
        for ( int i = 0 ; i < 26 ; i++ ) {
            if ( c[i] != 0 ) pq.push({c[i] , i + 'a'}) ;
        }

        string ans = "" ;
        pair<int,char> prev = pq.top() ;
        pq.pop() ;

        ans += prev.second ;
        prev.first-- ;

        while ( !pq.empty() ) {
            pair<int,char> next = pq.top() ;
            pq.pop() ;

            ans += next.second ;
            next.first-- ;

            if ( prev.first > 0 ) {
                pq.push(prev) ;
            }

            prev = next ;
        }

        if ( prev.first > 0 ) return "" ;
        return ans ;
    }
};