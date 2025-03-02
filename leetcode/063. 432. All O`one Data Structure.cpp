class AllOne {
public:
    struct block{
        int cnt;
        list<string> l2;
    };
    struct br{
        list<block>::iterator l1i;
        list<string>::iterator l2i;
    };
    list<block> l1;
    unordered_map<string, br> m1;

    AllOne() {
    }
    
    void inc(string key) {
        if(m1.contains(key)){
            br ref = m1[key];
            auto nexti = ref.l1i;
            nexti++;
            int cnt1 = ref.l1i->cnt;
            if(nexti == l1.end() || nexti->cnt > cnt1 + 1){
                nexti = l1.insert(nexti, {cnt1+1, {key}});
            } else{
                nexti->l2.push_front(key);
            }
            m1[key] = {nexti, nexti->l2.begin()};
            ref.l1i->l2.erase(ref.l2i);
            if(ref.l1i->l2.empty()){
                l1.erase(ref.l1i);
            }
        } else{
            if(l1.empty() || l1.front().cnt > 1){
                l1.push_front({1, {key}});
            } else{
                l1.front().l2.push_front(key);
            }
            m1[key] = {l1.begin(), l1.front().l2.begin()};
        }
    }
    
    void dec(string key){
        if(!m1.contains(key)) return;
        br ref = m1[key];
        int cnt1 = ref.l1i->cnt;
        if(ref.l1i == l1.begin()){
            if(ref.l1i->cnt == 1){
                m1.erase(key);
            } else{
                l1.push_front({cnt1-1, {key}});
                m1[key] = {l1.begin(), l1.front().l2.begin()};
            }
        } else{
            auto previ = ref.l1i;
            previ--;
            if(previ->cnt < cnt1-1){
                previ = l1.insert(ref.l1i, {cnt1-1, {key}});
            } else{
                previ->l2.push_front(key);
            }
            m1[key] = {previ, previ->l2.begin()};
        }
        ref.l1i->l2.erase(ref.l2i);
        if(ref.l1i->l2.empty()){
            l1.erase(ref.l1i);
        }
    }
    
    string getMaxKey() {
        if(l1.empty()) return "";
        else return l1.back().l2.front();
    }
    
    string getMinKey() {
        if(l1.empty()) return "";
        else return l1.front().l2.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
