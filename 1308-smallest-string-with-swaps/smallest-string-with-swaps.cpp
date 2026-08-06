class DSU {
public:
    vector<int> parent , size ;
    DSU(int n) {
        parent.resize(n) ;
        size.resize(n , 1) ;
        for ( int i = 0 ; i < n ; i++ ) {
            parent[i] = i ;
        }
    }

    int find(int x) {
        if ( parent[x] == x ) return x ;
        return parent[x] = find(parent[x]) ;
    }

    void unite(int a , int b) {
        a = find(a) ;
        b = find(b) ;
        if ( a == b ) return ;
        if ( size[a] < size[b] ) swap(a , b) ;
        parent[b] = a ;
        size[a] += size[b] ;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size() ;
        DSU dsu(n) ;
        for ( auto p : pairs ) {
            dsu.unite(p[0] , p[1]) ;
        }

        unordered_map<int,vector<int>> mp ;
        for ( int i = 0 ; i < n ; i++ ) {
            mp[dsu.find(i)].push_back(i) ; // parent => idx 
        }
        
        string ans = s ;
        for ( auto p : mp ) {
            vector<int> a = p.second ;
            
            string t = "" ;
            for ( int idx : a ) {
                t += s[idx] ;
            }

            sort(t.begin() , t.end()) ;
            sort(a.begin() , a.end()) ;
            
            for ( int i = 0 ; i < a.size() ; i++ ) {
                ans[a[i]] = t[i] ;
            }
        }

        return ans ;
    }
};