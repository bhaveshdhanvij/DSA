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
    int find (int x) {
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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size() ;
        vector<pair<int,int>> a ;

        for ( int i = 0 ; i < n; i++ ) {
            a.push_back({nums[i] , i}) ;
        }

        DSU dsu(n) ;
        sort(a.begin() , a.end()) ;
        for ( int i = 1 ; i < n ; i++ ) {
            if ( a[i].first - a[i - 1].first <= limit ) {
                dsu.unite(a[i - 1].second, a[i].second) ;
            }
        }

        unordered_map<int,vector<int>> indices ;
        unordered_map<int,vector<int>> values ;
        
        for ( int i = 0 ; i < n ; i++ ) {
            int root = dsu.find(i) ;
            indices[root].push_back(i) ;
            values[root].push_back(nums[i]) ;
        }

        for ( auto& [root , idx] : indices ) {
            auto& b = values[root] ;
            
            sort(idx.begin() , idx.end()) ;
            sort(b.begin() , b.end()) ;

            for ( int i = 0 ; i < idx.size() ; i++ ) {
                nums[idx[i]] = b[i] ;
            }
        }

        return nums ;
    }
};