class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
    sort(e.begin(), e.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        vector<int> nums(e.size());
        for (int i = 0; i < e.size(); i++)
            nums[i] = e[i][1];
        vector<int>lis;
        for(int num:nums){
            auto it=lower_bound(lis.begin(),lis.end(),num);
            if(it==lis.end()) lis.push_back(num);
            else *it=num;
        }
        return lis.size();
    }
};
