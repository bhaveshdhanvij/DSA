class Solution {
public:
    int maxProduct(vector<int>& a) {
        priority_queue<int> pq ;
        for ( int x : a ) pq.push(x) ;

        int x = pq.top() ; pq.pop() ;
        int y = pq.top() ; pq.pop() ;

        return (x - 1 ) * (y - 1) ;
    }
};