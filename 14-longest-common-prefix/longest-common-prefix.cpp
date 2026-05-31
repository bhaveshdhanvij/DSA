// class Node {
// public:
//     Node* child[26] ;
//     int c ;
//     Node() {
//         for ( int i = 0 ; i < 26 ; i++ ) {
//             child[i] = nullptr ;
//         }
//         c = 0 ;
//     }
// };
class Solution {
public:
    // void insert(Node* root , string& s ) {
    //     Node* node = root ;
        
    //     for ( int i = 0 ; i < s.size() ; i++ ) {
    //         int idx = s[i] - 'a' ;
    //         if ( node->child[idx] == nullptr ) {
    //             node->child[idx] = new Node() ;
    //         }
    //         node = node->child[idx] ;
    //         node->c++ ;
    //     }
    // }
    // string search(Node* root , int n) {
    //     Node* node = root ;
    //     string ans = "" ;

    //     while ( true ) {
    //         int cnt = 0 ;
    //         int idx = -1 ;

    //         for ( int i = 0 ; i < 26 ; i++ ) {
    //             if ( node->child[i] != nullptr && node->child[i]->c == n ) {
    //                 cnt++ ; 
    //                 idx = i ;
    //             }
    //         }

    //         if ( cnt != 1 ) break ;
    //         ans.push_back(char(idx + 'a')) ;
    //         node = node->child[idx] ;
    //     }
    //     return ans ;
    // }
    string longestCommonPrefix(vector<string>& a) {
        // int n = strs.size() ;
        // if ( n == 0 ) return "" ;

        // Node* root = new Node() ;
        
        // for ( string s : strs ) {
        //     insert(root , s) ;
        // }
        
        // return search(root , n) ;


        // Approach 1 : Horizontal Scalling 
        // TC : O(N * M) , SC : O(1) 

        // if (a.empty()) return "" ;
        // string p = a[0] ;
        
        // for ( int i = 1 ; i < a.size() ; i++ ) {
        //     while ( a[i].find(p) != 0 ) {
        //         p.pop_back() ;
        //         if ( p.empty() ) {
        //             return "" ;
        //         }
        //     }
        // }
        // return p ;

        // Approach 2 : Vertical Scanning 
        // TC : O(N * M) , SC : O(1) 

        // if (a.empty()) return "" ;
        // for ( int i = 0 ; i < a[0].size() ; i++ ) {
        //     char ch = a[0][i] ;
        //     for ( int j = 1 ; j < a.size() ; j++ ) {
        //         if ( i >= a[j].size() || a[j][i] != ch ) {
        //             return a[0].substr(0 , i) ;
        //         }
        //     }
        // }
        // return a[0] ;


        // Optimal Approach : Sorting + Greedy 
        // TC : O(Nlog(N)) , SC : O(1) 

        sort ( a.begin() , a.end() ) ;
        string x = a.front() ;
        string y = a.back() ;
        
        int i = 0 ;
        while ( i < x.size() && i < y.size() && x[i] == y[i] ) {
            i++ ;
        }
        return x.substr(0 , i) ;
    }
};