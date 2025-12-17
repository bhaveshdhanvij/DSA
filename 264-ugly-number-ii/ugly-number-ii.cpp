class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long , vector<long long> , greater<long long>> pq ;
        set<long long> s ;
        int count = 0 ;
        pq.push(1) ;
        long long temp ;
        while ( count < n ) {
            temp = pq.top() ;
            pq.pop() ;
            if (!s.count(2 * temp)) {
                pq.push(2 * temp) ;
                s.insert(2 * temp) ;
            }
            if (!s.count(3 * temp)) {
                pq.push(3 * temp) ;
                s.insert(3 * temp) ;
            }
            if (!s.count(5 * temp)) {
                pq.push(5 * temp) ;
                s.insert(5 * temp) ;
            }
            count++ ;
        }
        return temp ;
    }
};