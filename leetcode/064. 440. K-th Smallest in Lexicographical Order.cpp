class Solution {
public:
    long dis(int n, long curr){
        long n2 = curr+1;
        long cnt = 0;
        while(curr <= n){
            cnt += min((long)(n+1), (long) n2) - curr;
            curr *= 10;
            n2 *= 10;
        }
        return cnt;
    }

    int findKthNumber(int n, int k) {
        long curr = 1;
        k--;
        while(k > 0){
            int cnt = dis(n, curr);
            if(cnt <= k){
                curr++;
                k -= cnt;
            } else{
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};

/*
imagine k as the total neccesary steps until the number we are looking for, that's why we start with k-- (1 is already a step)
imagine a trie where:
root = 0
leaf: 1,2,3,4,5,6,7,8,9
from there, each leaf will have 10 nodes
1 has 10, 11, 12.. 19
10 has 100, 101, 102... 109

now, imaagine n = 11 and k = 4, so 
1,10,11,2

in fuction dis, we will have 
cnt += 2-1
cnt += 12-10
3, which is the distance between 1,10,11,2

n2 is curr+1 in order to "jump", for example
if curr = 1, then n2 = 2, which allow us "jump":
2-1 = 1
20-10 = 10
200 - 100 = 100
remember that each leaf has 10 leaf 

the general idea is that from curr, we count how many nodes they are:
  if they are not enough: then curr++ and k -= cnt
  if they are: then curr *= 10 and k--
*/
