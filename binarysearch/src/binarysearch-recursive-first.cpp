#include <vector>
#include <iostream>
#include <algorithm>

using IntVec = std::vector<int>;

void printVector(IntVec& vec) {
  for (int i = 0; i < vec.size(); i++)
    std::cout << vec[i] << ", ";
  std::cout << std::endl;
}

int binarysearch_first(IntVec& list, int find, const int start,
                 const int end) {
  if (start >= end) return -1;

  const int mid = start + (end - start) / 2;
  if (list[mid] == find) {
    const int search = binarysearch_first(list, find, start, mid);
    return (search == -1) ? mid : search;
  }
  return (list[mid] > find) ? binarysearch_first(list, find, start, mid)
                            : binarysearch_first(list, find, mid + 1, end);
}

int binarysearch_first(IntVec& list, int find) {
  return binarysearch_first(list, find, 0, list.size() - 1);
}

int main(int argc, char* argv[]) {
  IntVec vec(25);

  for (int i = 0; i < vec.size(); i++)
    vec[i] = rand() % 10;
  std::sort(vec.begin(), vec.end());

  int find;
  std::cout << "What number would you like to find?: ";
  std::cin >> find;

  printVector(vec);
  std::cout << binarysearch_first(vec, find) << std::endl;
}
