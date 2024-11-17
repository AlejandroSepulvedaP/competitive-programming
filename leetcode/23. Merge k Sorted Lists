// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.
// --

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* listR = nullptr, *aux;
        int minorInt, index;
        while(lists.size() != 0){
            minorInt = std::numeric_limits<int>::max();
            index = -1;
            for(int i = 0; i < lists.size(); i++){
                if(lists[i] && lists[i]->val <= minorInt){
                    minorInt = lists[i]->val; 
                    index = i;
                }
            }
            if(index == -1) break;
            if(listR){
                aux->next = lists[index];
                aux = aux->next;
            }
            else{
                listR = lists[index]; 
                aux = lists[index];
            }
            lists[index] = lists[index]->next;
            if(!lists[index]) lists.erase(lists.begin() + index);
        }
        aux->next = nullptr;
        return listR;
    }
};
