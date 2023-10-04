class MyHashMap {
public:
    vector<int> keyStore;
    vector<int> valueStore;

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        bool flag = false;
        int index;
        for(int i = 0; i<keyStore.size(); i++){
            if(key == keyStore[i]){
                flag = true;
                index = i;
                break;
            }
        }
        if(flag == true){
            valueStore[index] = value;
        }
        else{
            keyStore.push_back(key);
            valueStore.push_back(value);
        }
    }
    
    int get(int key) {
        int ans = -1;

        for(int i = 0; i<keyStore.size(); i++){
            if(key == keyStore[i]){
                ans = valueStore[i];
                break;
            }
        }

        return ans;

    }
    
    void remove(int key) {
        for(int i = 0; i<keyStore.size(); i++){
            if(key == keyStore[i]){
                keyStore.erase(keyStore.begin()+i);
                valueStore.erase(valueStore.begin()+i);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */