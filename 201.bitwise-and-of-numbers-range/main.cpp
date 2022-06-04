#include <iostream>

using namespace std;

class Solution {
  public:
    int rangeBitwiseAnd(int m, int n) {
      int offset = 0;
      for(;m != n; offset ++) {
        n >>= 1;
        m >>= 1;
      }
      return n << offset;
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  cout << s.rangeBitwiseAnd(5, 7) << endl;
  return 0;
}
