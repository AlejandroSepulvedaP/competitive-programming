class RandomizedCollection {

    unordered_map<int, priority_queue<int>> map;
    vector<int> arr;
    bool search(int val){
        return (map.find(val) != map.end() && !map[val].empty());
    }

public:
    RandomizedCollection() {
        map.clear();
        arr.clear();
    }
    
    bool insert(int val) {
        map[val].push(arr.size());
        arr.push_back(val);
        return !search(val);
    }
    bool remove(int val) {
        bool ret = false;
        if(search(val)){
            int idx = map[val].top();
            swap(arr[idx], arr[arr.size()-1]);
            map[arr[idx]].pop();
            map[arr[idx]].push(idx);
            map[val].pop();
            arr.pop_back();
            ret=true;
        }
        return ret;
    }
    int getRandom() {
        int r = rand()%arr.size();
        return arr[r];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
