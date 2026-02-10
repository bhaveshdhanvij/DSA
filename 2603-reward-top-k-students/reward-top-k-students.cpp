class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string,int> x , y ;
        
        for ( string &s : positive_feedback ) x[s]++ ;
        for ( string &s : negative_feedback ) y[s]++ ;

        vector<pair<int,int>> a ;
        
        for ( int i = 0 ; i < report.size() ; i++ ) {
            int curr = 0 ;
            string s = report[i] ;
            string word ;

            stringstream ss(s) ;
            while ( ss >> word ) {
                if ( x.count(word) ) curr += 3 ;
                else if ( y.count(word) ) curr-- ;
            }

            a.push_back({curr , student_id[i]}) ;
        }

        sort ( a.begin() , a.end() , [&]( const pair<int,int>& a , const pair<int,int>& b ) {
            if ( a.first == b.first ) return a.second < b.second ;
            return a.first > b.first ;
        });

        vector<int> ans ;
        for ( int i = 0 ; i < a.size() && i < k ; i++ ) {
            ans.push_back(a[i].second) ;
        }

        return ans ;
        
    }
};