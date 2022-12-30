#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2,
                            vector<int> &nums3) {
    vector<int> res;
    unordered_set<int> s1, s2, s3;
    unordered_map<int, int> mp;
    for (auto i : nums1)
      s1.insert(i);
    for (auto i : nums2)
      s2.insert(i);
    for (auto i : nums3)
      s3.insert(i);
    for (int i : s1)
      mp[i]++;
    for (int i : s2)
      mp[i]++;
    for (int i : s3)
      mp[i]++;
    for (auto a : mp)
      if (a.second > 1)
        res.push_back(a.first);
    return res;
  }
};
