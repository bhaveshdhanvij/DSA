class Solution {
public:
    vector<int> maxSubsequence(vector<int>& a, int k) {
        int n = a.size() ;
        priority_queue<pair<int,int>> pq ;

        for ( int i = 0 ; i < n ; i++ ) {
            pq.push({a[i] , i}) ;
        }

        vector<pair<int,int>> t ;
        
        while (!pq.empty() && k > 0) {
            auto b = pq.top() ;
            pq.pop() ;

            t.push_back({b.second , b.first}) ;
            k-- ;
        } 

        sort ( t.begin() , t.end() ) ;

        vector<int> ans ;
        for ( auto p : t ) {
            ans.push_back(p.second) ; 
        }

        return ans ;
    }
};