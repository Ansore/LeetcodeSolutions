#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
  bool reorderedPowerOf2(int n) {
    string s = to_string(n);
    long long target = 1;
    char cnts[10] = {0};
    char cntt[10] = {0};
    for (auto c : s) {
      cnts[c - '0']++;
    }
    for (int i = 1; i < 32; i++) {
      string t = to_string(target);
      if (t.size() < s.size()) {
        target *= 2;
        continue;
      }
      if (t.size() > s.size())
        break;
      memset(cntt, 0, sizeof(cntt));
      for (auto c : t) {
        cntt[c - '0']++;
      }
      bool flag = true;
      for (int i = 0; i < 10; i++) {
        if (cntt[i] != cnts[i])
          flag = false;
      }
      if (flag)
        return true;
      target *= 2;
    }
    return false;
  }
};

int main(int argc, char *argv[]) { return 0; }
