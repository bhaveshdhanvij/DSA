struct Transaction {
    string name ;
    int time ;
    int amount ;
    string city ;
    string original ;
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size() ;
        vector<string> ans ;
        vector<Transaction> t ;
        for ( const string &s : transactions ) {
            stringstream ss(s) ;
            string name , city , amountstr , timestr ;
            getline(ss , name , ',') ;
            getline(ss , timestr , ',') ;
            getline(ss , amountstr , ',') ;
            getline(ss , city , ',') ;

            t.push_back({name , stoi(timestr) , stoi(amountstr) , city , s}) ;
        }

        for ( int i = 0 ; i < n ; i++ ) {
            if ( t[i].amount > 1000 ) {
                ans.push_back(t[i].original) ;
                continue ;
            }

            bool flag = false ;
            for ( int j = 0 ; j < n ; j++ ) {
                if ( t[i].name == t[j].name && t[i].city != t[j].city && abs(t[i].time - t[j].time) <= 60 ) {
                    flag = true ;
                    break ;
                }
            }

            if ( flag ) ans.push_back(t[i].original) ;
        }

        return ans ;
    }
};