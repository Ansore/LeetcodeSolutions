#include <string>
#include <vector>

using namespace std;

class Spreadsheet {
public:
  Spreadsheet(int rows) { sheet = vector(26, vector(rows, 0)); }

  void setCell(string cell, int value) {
    if (cell.size() < 2) {
      return;
    }
    sheet[cell[0] - 'A'][str2num(cell.substr(1))] = value;
  }

  int str2num(string s) {
    int t = 0;
    for (char c : s) {
      t = t * 10 + (c - '0');
    }
    return t;
  }

  void resetCell(string cell) {
    if (cell.size() < 2) {
      return;
    }
    sheet[cell[0] - 'A'][str2num(cell.substr(1))] = 0;
  }

  int getPostValue(string s) {
    if ((s[0] >= 'A') && (s[0] <= 'Z')) {
      return sheet[s[0] - 'A'][str2num(s.substr(1))];
    } else {
      return str2num(s);
    }
  }

  int getValue(string formula) {
    for (int i = 1; i < formula.size(); i++) {
      switch (formula[i]) {
      case '+':
        return getPostValue(formula.substr(1, i - 1)) +
               getPostValue(formula.substr(i + 1));
      case '-':
        return getPostValue(formula.substr(1, i - 1)) -
               getPostValue(formula.substr(i + 1));
      case '*':
        return getPostValue(formula.substr(1, i - 1)) *
               getPostValue(formula.substr(i + 1));
      case '/':
        return getPostValue(formula.substr(1, i - 1)) /
               getPostValue(formula.substr(i + 1));
      }
    }
    return 0;
  }

private:
  vector<vector<int>> sheet;
};
