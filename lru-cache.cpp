class LRUCache {
    int cap;
    int size;
    int lru;
    int mru;
    unordered_map<int,int> storage;
    unordered_map <int,pair<int,int>> cache;
    void keyIsLru(int key){
        int next= cache[lru].second;
                        cache[mru].second=key;
                        cache[key].first=mru;
cache[key].second=-1;
                        mru=key;
                        lru=next;
    }
    
    void keyNotLru(int key){
        int prev=cache[key].first;
                        int next=cache[key].second;
                        cache[prev].second=next;
                        cache[next].first=prev;
                        cache[key].second=-1;
cache[key].first=mru;
                        cache[mru].second=key;
                        mru=key;
                        
                        
                        
    }
    
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->size=0;
        this->lru=-1;
        this->mru=-1;
    }
    
    int get(int key) {
        //pending
        
        if(storage.find(key)==storage.end()){
        return -1;
     }else{
         //key exists
         if(key!=mru){
             if(key==lru){
                 keyIsLru(key);
             }else{
                 keyNotLru(key);
             }
         }
         return storage[key];
     }

    }
    
    void put(int key, int value) {
        
        if(storage.find(key)==storage.end()){
            //key not exist
            storage[key] =value;
            if(size<cap){
                if(size==0){
                    lru=key;
                    mru=key;
                    cache[key].first=-1;
                    cache[key].second=-1;
                    
                }else{
                    //size not zero
                    cache[mru].second=key;
                    cache[key].first=mru;
                    cache[key].second=-1;
                    mru=key;
                                 
                
                }
                size++;
            
            
            }else{
                //size ==cap
                
                   int next=cache[lru].second;
                    if(next==-1){
                        //delete lru
                        storage.erase(lru);
                        cache.erase(lru);
                        
                        lru = key;
                        mru=key;
                        cache[key].first=-1;
                        cache[key].second=-1;
                    }else{
                        // next !=-1
                        cache[next].first=-1;
                        //delete lru
                        storage.erase(lru);
                        cache.erase(lru);
                        cache[mru].second=key;
                        cache[key].first=mru;
                        cache[key].second=-1;
                        mru=key;
                        lru=next;
                        
                    }
                    
                    
                    
                }
            }else{
                //key exists
                storage[key]= value;
                if(key!=mru){
                
                    if(key==lru){
                        keyIsLru(key);
                    }else{
                        //key not lru;
                        keyNotLru(key);
                    }
                    
                }
                
            }
    }
    
    
    
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */