class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n = a.size() ;
        priority_queue<int> pq ;

        for ( int x : a ) pq.push(x) ;

        for ( int i = 1 ; i < n ; i += 2 ) {
            a[i] = pq.top() ;
            pq.pop() ;
        }

        for ( int i = 0 ; i < n ; i += 2 ) {
            a[i] = pq.top() ;
            pq.pop() ;
        }

        return a ;
    }
};