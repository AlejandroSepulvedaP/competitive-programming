class Solution {
public:
int countPartitions(vector<int>& nums, int maxsum) {
    int partitions = 1;
    long long currentSum = 0;
    for (int num : nums) {
        if (currentSum + num <= maxsum) {
            currentSum += num;
        } else {
            partitions++;
            currentSum = num;
        }
    }
    return partitions;
}

int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    
    while (low != high) {
        int mid = low + (high - low) / 2;
        int partitions = countPartitions(nums, mid);
        cout << low << ", " << high << ", " << mid << ", " << partitions << endl;
        if (partitions > k) {
            low = mid + 1;  
        } else {
            high = mid;  
        }
    }
    return high;
}
};

/*
We have an array [a1,a2,a3...an].

We know the result lays between the largest number from the array (low), and the sum of all the numbers (high).

Now, take the middle between low and high and see if it serves as a possible answer. If it does (1), that means the answer lays between [low, mid], otherwise (2) lays between [mid+1, high]. 

If n = partitions, We know (1) when you can split the array with maxSum = mid, in n  <= k. We know (2) when you can split the array with maxSum = mid, in n > k. 

[7,2,5,10,8] k = 2
low, high, mid, partitions
10, 32, 21, 2
10, 21, 15, 3
16, 21, 18, 2
16, 18, 17, 3

[7,2,5,10,8] k = 3
low, high, mid, partitions
10, 32, 21, 2
10, 21, 15, 3
10, 15, 12, 4
13, 15, 14, 3
13, 14, 13, 4
*/
