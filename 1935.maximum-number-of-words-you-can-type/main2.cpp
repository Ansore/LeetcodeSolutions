#include <string>

using namespace std;

class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    int sum = 0;
    int b_sum = 0;
    bool flag = true;
    unsigned char table[26] = {0};
    for (char b : brokenLetters) {
      table[b - 'a'] = 1;
    }

    for (char t : text) {
      if (t == ' ') {
        sum++;
        flag = true;
        continue;
      }
      if (flag && table[t - 'a'] == 1) {
        b_sum++;
        flag = false;
      }
    }
    sum++;
    return sum - b_sum;
  }
};
