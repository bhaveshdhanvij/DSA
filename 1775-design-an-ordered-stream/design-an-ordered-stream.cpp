class OrderedStream {
public:
    int ptr ;
    map<int,string> mp ;
    OrderedStream(int n) {
        ptr = 1 ;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> ans ;
        mp[idKey] = value ;

        while ( mp.count(ptr) ) {
            ans.push_back(mp[ptr]) ;
            ptr++ ;
        }

        return ans ;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */