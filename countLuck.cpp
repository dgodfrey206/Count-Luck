#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <stack>
using namespace std;

// structure representing a node in the forest
struct node {
  // row and column positions
  int x, y;
  // the number of times Hermonie waves her wand while travelling
  int count;
  
  node() = default;
  node(int x, int y, int count = 0) : x(x), y(y), count(count)
  {}
};

// returns "Impressed" if k is the number of times Hermonie waves her wand, otherwise "Oops!"
// player is the starting position of Ron and Hermonie
// n and m are the dimensions of the forest
string makeGuess(vector<string> const& forest, int n, int m, node player, int k) {
  // keep track of nodes that have been visited
  vector<vector<bool>> visited(n, vector<bool>(m));

  // helper method for determining if v is a valid, unvisited node
  auto isUnvisitedNode = [&](node v)
  {return (0 <= v.x && v.x < n) && (0 <= v.y && v.y < m) && !visited[v.x][v.y];};

  // Use a depth first search inside of the forest to find the portkey
  std::stack<node> s;
  s.push(player);

  // last node will hold the answer in count
  node last;
  while (!s.empty()) {
    last = s.top();
    s.pop();
    int x = last.x, y = last.y;

    // if we have already visited or node is a tree
    if (!isUnvisitedNode(last) || forest[x][y] == 'X') continue;
    // mark node as visited
	visited[x][y] = true;

    // if we have found the answer then our search ends
	if (forest[x][y] == '*') break;

    // hold a sequence of adjacent nodes to determine if more than 1 is a valid path
	std::array<node, 4> arr = {{
	  node(x, y - 1, last.count),
	  node(x, y + 1, last.count),
	  node(x - 1, y, last.count),
	  node(x + 1, y, last.count)
    }};

    // count number of valid adjacent nodes
    int count = 0;
	for (auto const& v : arr) {
	  if (isUnvisitedNode(v)) {
	    // a '.' or '*' is a valid path
		if (forest[v.x][v.y] == '.' || forest[v.x][v.y] == '*') {
	      count++;
		}
		else {
		  // if this node is invalid set as visited
		  visited[v.x][v.y] = true;
		}
	  }
	}

	for (auto& v : arr) {
	  // if we counted more than 1 path then Hermonie waved her wand; increase count
	  if (count >= 2) v.count++;
	  // push onto the stack for the continuation of the search
	  if (isUnvisitedNode(v)) s.push(v);
	}
  }

  // last.count holds the answer
  if (k == last.count)
    return "Impressed";
  else
    return "Oops!";
}

int main() {
  int n, m, i, j, k, p, t;
  node player;

  cin >> t;
  for (p = 0; p < t; ++p) {
    cin >> n >> m;
    vector<string> forest(n);
    for (i = 0; i < n; ++i) {
      string str; cin >> str;
      if ((j = str.find('M')) != string::npos)
        player = node(i, j);
        forest[i] = move(str);
    }
    cin >> k;
    cout << makeGuess(forest, n, m, player, k) << '\n';
  }
}
