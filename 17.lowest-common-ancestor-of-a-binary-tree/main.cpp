#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  private:
    vector<string> res;
  public:
    string getMappingString(char c) {
      switch(c) {
        case '1':
          return "";
        case '2':
          return "abc";
        case '3':
          return "def";
        case '4':
          return "ghi";
        case '5':
          return "jkl";
        case '6':
          return "mno";
        case '7':
          return "pqrs";
        case '8':
          return "tuv";
        case '9':
          return "wxyz";
      }
      return "";
    }
    void backTrace(string& digits, string temp, int start) {
      if(temp.size() == digits.size()) {
        res.push_back(temp);
        return;
      }
      for(auto& c : getMappingString(digits[start])) {
        temp.push_back(c);
        backTrace(digits, temp, start+1);
        temp.pop_back();
      }
    }
    vector<string> letterCombinations(string digits) {
      if(digits=="") return res;
      string temp = "";
      backTrace(digits, temp, 0);
      return res;
    }
};

int main(int argc, char *argv[])
{
  return 0;
}
