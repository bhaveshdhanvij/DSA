class FrequencyTracker {
public:
    unordered_map<int,int> mp ;
    multiset<int> m ;
    FrequencyTracker() {
        
    }
    
    void add(int n) {
        int prev = mp.count(n) ? mp[n] : 0 ;
        if ( prev != 0 ) {
            m.erase(m.find(prev)) ;
        } 
        ++mp[n] ;
        m.insert(mp[n]) ;
    }
    
    void deleteOne(int n) {
        if ( !mp.count(n) ) return ;
        int prev = mp[n] ;
        --mp[n] ;
        m.erase(m.find(prev)) ;
        if ( mp[n] == 0 ) mp.erase(n) ;
        else {
            m.insert(mp[n]) ;
        }
    }
    
    bool hasFrequency(int f) {
        return m.count(f) ;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */