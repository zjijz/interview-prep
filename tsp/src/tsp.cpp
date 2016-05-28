#include <vector>
#include <bitset>
#include <iostream>

using IntVec = std::vector<int>;
using IntVecVec = std::vector<IntVec>;
using BoolVec = std::vector<bool>;

void printEdges(IntVecVec& edges) {
  for (int i = 0; i < edges.size(); i++) {
    for (int j = 0; j < edges[i].size(); j++)
      std::cout << edges[i][j] << " ";

    std::cout << std::endl;
  }
}

bool allVisited(BoolVec& visited) {
  u_char ret = 1;
  for (bool b : visited)
    ret &= b;
  return ret;
}

/*
 * We keep track of the visited nodes with a boolean vector
 * (bitset needed size known at compile time).
 *
 * We then conduct an exhaustive search of the tree, breaking only when L
 * becomes 0 or negative. If L is zero, we check if the current node (i) is
 * the start node and that all nodes have been visited. If so, we return true.
 * If L is negative, we return false since this path didn't yield a satisfatory
 * result.
 *
 * If L is still positive, we'll see if we can go to any of the neighboring
 * nodes by doing a recursive call on L - (the cost to get to the neighbor)
 *
 * I believe this creates a tree of roughly depth n, with each node having (n-1)
 * children. I think this corresponds to a O((n-1)^n) runtime, but this
 * varies based on the state of edges.
 */
bool tsp(IntVecVec& edges, const int L, const int start, BoolVec& visited, int i) {
  std::cout << "Current: " << i << ", Length: " << L << std::endl;

  if (L < 0) return false;
  if (L == 0) return (i == start) && allVisited(visited);

  // Branches n-1 times (sometimes less based on conditions)
  for (int j = 0; j < edges[i].size(); j++) {
    visited[i] = true;
    if ((i != j)
        && (edges[i][j] != 99999)
        && tsp(edges, L - edges[i][j], start, visited, j))
      return true;
  }

  return false;
}

bool tsp(IntVecVec& edges, const int L, const int start) {
  BoolVec boolVec = BoolVec(edges.size());
  return tsp(edges, L, start, boolVec, start);
}

int main(int argc, char* argv[]) {
  IntVecVec edges = IntVecVec(3, IntVec(3));
  for (int i = 0; i < edges.size(); i++)
    for (int j = 0; j < edges[i].size(); j++)
      edges[i][j] = rand() % 10 + 1;

  int L;
  std::cout << "Specify path length: ";
  std::cin >> L;

  printEdges(edges);
  std::cout << std::endl;
  std::cout << tsp(edges, L, 0) << std::endl;
}
