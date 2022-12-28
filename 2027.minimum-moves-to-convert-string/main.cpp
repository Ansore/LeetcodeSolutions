#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int minimumMoves(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'X') {
        count++;
        i += 2;
      }
    }
    return count;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.minimumMoves("XXOX") << endl;
  cout << s.minimumMoves("XXX") << endl;
  cout << s.minimumMoves("OOOO") << endl;
  return 0;
}
