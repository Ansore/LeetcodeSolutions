#include <iostream>
#include <string>

using namespace std;

class Solution {
  private:
    int num = 0;
  public:
    int countSubstrings(string s) {
      for(int i = 0; i < s.length(); i ++) {
        count(s, i, i);
        count(s, i, i+1);
      }
      return num;
    }

    void count(string s, int start, int end) {
      while(start >= 0 && end < s.length() && s[start] == s[end]) {
        num ++;
        start --;
        end ++;
      }
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  cout << s.countSubstrings("aaa") << endl;
  return 0;
}
