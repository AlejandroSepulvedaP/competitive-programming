//You are given a string s and an array of strings words. All the strings of words are of the same length.
//A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

class Solution {
    unordered_map<string, unsigned int> map;
public:
    vector<int> findSubstring(string s, vector<string>& words){
        vector<int> indexR;
        string subs;
        unsigned int length = words[0].size();
        map.clear();
        for(const string& word : words) map[word]++;
        for(unsigned int offset = 0; offset < length; offset++){
            unsigned int size = 0;
            unordered_map<string, unsigned int> seen;
            for(unsigned int i = offset; i + length <= s.size(); i += length){
                subs = s.substr(i, length);
                auto itr = map.find(subs);
                if(itr == map.end()){
                    size = 0;
                    seen.clear();
                    continue;
                }
                size++;
                seen[subs]++;
                while(seen[subs] > map[subs]){
                    string first = s.substr(i-(size-1)*length, length);
                    size--;
                    seen[first]--;
                }
                if(size == words.size()){
                    indexR.push_back(i-(size-1)*length);
                }
            }
        }
        return indexR;
    }
};
