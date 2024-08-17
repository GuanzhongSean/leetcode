#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int duplicateNumbersXOR(vector<int> &nums) {
    unordered_map<int, int> count;
    for (int num : nums) count[num]++;
    int result = 0;
    for (auto &pair : count) {
      if (pair.second == 2) {
        result ^= pair.first;
      }
    }
    return result;
  }
  vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries,
                                   int x) {
    vector<int> occurrences;
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == x) occurrences.push_back(i);

    vector<int> answer;
    for (int query : queries)
      if (query <= occurrences.size())
        answer.push_back(occurrences[query - 1]);
      else
        answer.push_back(-1);

    return answer;
  }
  vector<int> queryResults(int limit, vector<vector<int>> &queries) {
    unordered_map<int, int> ballColors;
    unordered_set<int> distinctColors;
    vector<int> result;

    for (const auto &query : queries) {
      int ball = query[0];
      int color = query[1];

      // Check if the ball already has a color
      if (ballColors.find(ball) != ballColors.end()) {
        int oldColor = ballColors[ball];
        ballColors[ball] = color;

        // If the old color is no longer present in the map, remove it from the
        // set
        if (find_if(ballColors.begin(), ballColors.end(),
                    [oldColor](const auto &pair) {
                      return pair.second == oldColor;
                    }) == ballColors.end()) {
          distinctColors.erase(oldColor);
        }
      } else {
        ballColors[ball] = color;
      }

      distinctColors.insert(color);
      result.push_back(distinctColors.size());
    }

    return result;
  }
  vector<bool> getResults(vector<vector<int>> &queries) {
    vector<int> obstacles;
    vector<bool> results;
    for (const auto &query : queries) {
      if (query[0] == 1) {
        auto position =
            std::lower_bound(obstacles.begin(), obstacles.end(), query[1]);
        obstacles.insert(position, query[1]);
      } else if (query[0] == 2) {
        int x = query[1];
        int sz = query[2];
        if (x < sz) {
          results.push_back(false);
          continue;
        }
        bool canPlace = false;
        int prev = 0;

        for (int current : obstacles) {
          if (current - prev >= sz) {
            canPlace = true;
            break;
          }
          prev = current;
          if (current > x - sz) break;
        }

        if (!canPlace && x - prev >= sz) canPlace = true;

        results.push_back(canPlace);
      }
    }

    return results;
  }
};
