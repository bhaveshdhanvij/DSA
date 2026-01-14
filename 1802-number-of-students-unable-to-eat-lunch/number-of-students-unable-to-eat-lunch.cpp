class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> s ;

        for ( int i = sandwiches.size() - 1 ; i >= 0 ; i-- ) {
            s.push(sandwiches[i]) ;
        }

        queue<int> q ;
        for ( int x : students ) q.push(x) ;

        int r = 0 ;
        
        while (!q.empty() && r < q.size() ) {
            if ( q.front() == s.top()) {
                q.pop();
                s.pop() ;
                r = 0 ;
            }else {
                q.push(q.front()) ;
                q.pop() ;
                r++ ;
            }
        }
        
        return q.size() ;
    }
};