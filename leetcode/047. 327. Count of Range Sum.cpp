#define ll long long
class FenwickTree {
public:

    int N;
	vector<ll>bit;

	FenwickTree(int sz): N(sz + 1) {
		bit.resize(N, 0);
	}
	void add(int ind, ll x)
	{
		for (; ind < N; ind += (ind & (-ind))) {
			bit[ind] += x;
		}
	}
	ll sum(int l) {
		ll res = 0;
		for (; l > 0; l -= (l & (-l))) {
			res += bit[l];
		}
		return res;
	}
	ll sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        long long ans=0;
        int n=nums.size();
        long long sum=0;
        vector<long long>pref(n+1);
        pref[0]=0;
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        
        FenwickTree BITS(n + 2);
        sort(pref.begin(),pref.end());

        int ind=lower_bound(pref.begin(),pref.end(),0)-pref.begin()+1;
        BITS.add(ind,1);

        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ind=lower_bound(pref.begin(),pref.end(),sum)-pref.begin()+1;
            // We have two cases, were x is the largest pref that satisfies the property pref[i-1] <= pref[j]-lowe
            // x  = pref[j]-lower, then we have to add + 1 because Fenwick tree, but upper_bound already does this
            // x  < pref[j]-lower, upper_bound automatically directs us to the nearest greater of x, whose place is actually of x in the fenwick tree 
            int r=upper_bound(pref.begin(),pref.end(),sum-lower)-pref.begin();
            // Here we only need the first x that satisfies the property pref[j]-upper <= pref[i-1], and add + 1 in order to access to its place
            int l=lower_bound(pref.begin(),pref.end(),sum-upper)-pref.begin()+1;
            ans+= BITS.sum(l,r);
            BITS.add(ind,1);
        }
        return ans;
    }
};

/* 
APPROACH:
For all j consider i , such that 
lower <= sum(i,j) <= upper
Now sum(i,j) = pref[j]-pref[i-1]
lower <= pref[j]-pref[i-1] <= upper
lower-pref[j] <= -pref[i-1] <= upper-pref[j]
pref[j]-lower >= pref[i-1] >= pref[j]-upper 
pref[j]-upper <= pref[i-1] <= pref[j]-lower

EXAMPLE 1: (here we don't show the actually fenwick tree, but it is array normal presentation)
-2,2
nums [-2,5,-1]
pre 0,-2,3,2
sort -2,0,2,3

1) -2, 1, 2, 1
0,1,2,3,4,5,6
0,0,1,0,0,0,0
1

2) 3, 4, 4, 3
0,1,2,3,4,5,6
0,1,1,0,0,0,0
0

3) 2, 3, 4, 2
0,1,2,3,4,5,6
0,1,1,0,1,0,0
3

EXAMPLE 2
-2,2
nums -2,5,-1,20,-30,10,
pre 0,-2,3,2,22,-8,2,
sort -8,-2,0,2,2,3,22,

1) -2, 2, 3, 2
0,1,2,3,4,5,6,
0,0,0,1,0,0,0,0,
1

2) 3, 6, 6, 4
0,1,2,3,4,5,6,
0,0,1,1,0,0,0,0,
1

3) 2, 4, 6, 3
0,1,2,3,4,5,6,
0,0,1,1,0,0,1,0,
3

4) 22, 7, 7, 7
0,1,2,3,4,5,6,
0,0,1,1,1,0,1,0,
3

5) -8, 1, 1, 1
0,1,2,3,4,5,6,
0,0,1,1,1,0,1,1,
3

6) 2, 4, 6, 3
0,1,2,3,4,5,6,
0,1,1,1,1,0,1,1,
6

*/
