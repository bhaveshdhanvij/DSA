class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size() ;
        double total = 0 ;
        for ( int x : nums ) total += x ;
        priority_queue<double> pq ;
        for (int x : nums) {
            pq.push(x) ;
        }
        double sum = 0 ;
        int ans = 0 ;
        while ( sum < total / 2 ) {
            ans++ ;
            double x = pq.top() ;
            pq.pop() ;
            sum += x / 2 ;
            pq.push(x / 2) ;
        }
        return ans ;
    }
};