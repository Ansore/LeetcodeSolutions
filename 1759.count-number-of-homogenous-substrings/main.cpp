#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int countHomogenous(string s) {
    if (s.length() == 0)
      return 0;
    long long count = 0;
    long long mod = 1e9 + 7;
    int temp = 0;
    char c = s[0];
    for (int i = 0; i < s.length();) {
      while (i < s.length() && c == s[i]) {
        temp++;
        i++;
      }
      count += (long long)(temp + 1) * temp / 2;
      temp = 0;
      c = s[i];
    }
    return (int)(count % mod);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.countHomogenous("abbcccaa") << endl;
  cout << s.countHomogenous("xy") << endl;
  cout << s.countHomogenous("zzzzz") << endl;
  return 0;
}
