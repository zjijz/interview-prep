#include <vector>
#include <iostream>
#include <algorithm>

using IntVec = std::vector<int>;

void printVector(IntVec& vec) {
  for (int i = 0; i < vec.size(); i++)
    std::cout << vec[i] << ", ";
  std::cout << std::endl;
}

int binarysearch_first(IntVec& list, int& find, const int& start,
                 const int& end) {
  const int mid = start + (end - start) / 2;
  int comp = list[mid] - find;
  if (comp == 0) {
    if ((end - start) < 1) {
      return mid;
    } else {
      int search = binarysearch_first(list, find, start, mid - 1);
      return (search == -1) ? mid : search;
    }
  } else {
    if ((end - start) < 1)
      return -1;
    else if (comp > 0)
      return binarysearch_first(list, find, start, mid - 1);
    else
      return binarysearch_first(list, find, mid + 1, end);
  }
}

int binarysearch_first(IntVec& list, int& find) {
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
