#include <iostream>
#include <vector>

using namespace std;

class Solution {
	private:
		static constexpr int UNCOLORED = 0;
		static constexpr int RED = 1;
		static constexpr int GREEN = 2;
		vector<int> color;
		bool valid;
	public:
		void dfs(int node, int c, const vector<vector<int>>& grapth) {
			color[node] = c;
			int cNei = (c == RED? GREEN:RED);
			for(int neighbor:grapth[node]) {
				if(color[neighbor] == UNCOLORED) {
					dfs(neighbor, cNei, grapth);
					if(!valid) {
						return;
					}
				} else if(color[neighbor] != cNei) {
					valid = false;
					return;
				}
			}
		}
		bool isBipartite(vector<vector<int>>& graph) {
			int n = graph.size();
			valid = true;
			color.assign(n, UNCOLORED);
			for(int i = 0; i < n && valid; i ++) {
				if(color[i] == UNCOLORED) {
					dfs(i, RED, graph);
				}
			}
			return valid;
		}
};

int main(int argc, char *argv[])
{
	return 0;
}
