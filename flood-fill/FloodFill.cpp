#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      if(image.size() <= 0 || image[0].size() <= 0) return image;
      int color = image[sr][sc];
      if(color == newColor) return image;
      fill(image, color, newColor, sr, sc);
      return image;
    }

    void fill(vector<vector<int>> &image, int color, int newColor, int sr, int sc) {
      if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != color || image[sr][sc] == newColor) return;
      image[sr][sc] = newColor;
      fill(image, color, newColor, sr-1, sc);
      fill(image, color, newColor, sr+1, sc);
      fill(image, color, newColor, sr, sc+1);
      fill(image, color, newColor, sr, sc-1);
    }
};

int main(int argc, char *argv[])
{
  vector<vector<int>> image = {{0,0,0},{0,1,1}};
  Solution s;
  cout << s.floodFill(image, 1, 1, 1).size() << endl;
  return 0;
}
