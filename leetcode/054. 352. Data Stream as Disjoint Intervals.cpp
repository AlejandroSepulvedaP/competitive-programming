class SummaryRanges {
private:
    map<int, int> intervalMap; // Stores start/end markers for intervals
public:
    SummaryRanges() {
        // Constructor initializes an empty interval map
    }
    
    void addNum(int value) {
        // Increment start marker at 'value', decrement at 'value + 1'
        intervalMap[value]++;
        intervalMap[value + 1]--;
    }
    
    vector<vector<int>> getIntervals() {
        int count = 0;  // Tracks the active interval count
        int start = 0;   // Stores the start of the current interval
        vector<vector<int>> res;

        // Iterate through sorted keys in the map
        for (auto it = intervalMap.begin(); it != intervalMap.end(); it++) {
            if (count == 0) start = it->first; // Start a new interval
            count += it->second;
            if (count == 0) {
                res.push_back({start, prev(it)->first}); // Add completed interval
            }
        }
        return res;
    }
};

/**
 * Time Complexity:
 * - addNum(value): O(log N), due to insertion in std::map.
 * - getIntervals(): O(N), where N is the number of unique values added.
 *
 * Space Complexity: O(N), as we store at most 2N keys in the map.
 */
