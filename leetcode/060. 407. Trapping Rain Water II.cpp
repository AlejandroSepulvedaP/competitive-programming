#include <ranges>
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
    int m = ssize(heightMap);
    int n = ssize(heightMap[0]);
    if (m < 3 || n < 3) return 0;

    vector<tuple<int, int, int>> q_data = {};
    vector<bitset<200>> discovered (m);
    for (auto i : views::iota(0, m)) {
      if (i == 0 || i == m - 1) {
        for (auto j : views::iota(0, n)) {
          q_data.emplace_back(heightMap[i][j], i, j);
          discovered[i].set(j);
        }
      } else {
        q_data.emplace_back(heightMap[i][0], i, 0);
        q_data.emplace_back(heightMap[i][n - 1], i, n - 1);
        discovered[i].set(0);
        discovered[i].set(n - 1);
      }
    }
    int num_cells = m * n;
    int num_discovered = size(q_data);
    auto q = priority_queue(greater{}, q_data);
    vector<pair<int, int>> fill_coords = {};
    int water_volume = 0;
    auto process_neighbor = 
      [&heightMap, &q, &fill_coords, &discovered, &water_volume,
       &num_discovered](int i, int j, int height) {
        discovered[i].set(j);
        ++num_discovered;
        if (heightMap[i][j] <= height) {
            water_volume += height - heightMap[i][j];
            fill_coords.emplace_back(i, j);
        } else {
            q.emplace(heightMap[i][j], i, j);
        } 
    };
    while (num_discovered != num_cells) {
        auto [height, i, j] = q.top();
        q.pop();
        fill_coords.emplace_back(i, j);
        while (num_discovered != num_cells && !empty(fill_coords)) {
            auto [i, j] = fill_coords.back();
            fill_coords.pop_back();
            if (i > 0 && !discovered[i - 1][j])
            process_neighbor(i - 1, j, height);
            if (j > 0 && !discovered[i][j - 1])
            process_neighbor(i, j - 1, height);
            if (j < n - 1 && !discovered[i][j + 1])
            process_neighbor(i, j + 1, height);
            if (i < m - 1 && !discovered[i + 1][j])
            process_neighbor(i + 1, j, height);
        }
    }
    return water_volume;
  }
};
