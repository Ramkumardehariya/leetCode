class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> temp;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        temp.push_back(val);
        if(mp.find(val) == mp.end()){
            mp[val]++;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {

        if(temp.size() > 0){
            int index = -1;
            for(int i = 0; i<temp.size(); i++){
                if(temp[i] == val){
                    index = i;
                    break;
                }
            }
            if(index != -1){
                temp.erase(temp.begin()+index);
            }
        }
        
        if(mp.find(val) == mp.end()){
            return false;
        }
        else{
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int size = temp.size();
        int ran = rand()%size;
        return temp[ran];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */