#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      string str = s + s;
      return str.find(s, 1) != s.size();
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  cout << s.repeatedSubstringPattern("abcabcabcabc") << endl;
  return 0;
}
