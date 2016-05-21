#include <vector>
#include <iostream>
#include <algorithm>

using IntVec = std::vector<int>;

void printVector(IntVec& vec) {
  for (int i = 0; i < vec.size(); i++)
    std::cout << vec[i] << ", ";
  std::cout << std::endl;
}

int binarysearch(IntVec& list, int& find, const int& start,
                 const int& end) {
  const int mid = start + (end - start) / 2;
  int comp = list[mid] - find;
  if (comp == 0) {
    return mid;
  } else {
    if ((end - start) < 1)
      return -1;
    else if (comp > 0)
      return binarysearch(list, find, start, mid - 1);
    else
      return binarysearch(list, find, mid + 1, end);
  }
}

int binarysearch(IntVec& list, int& find) {
  return binarysearch(list, find, 0, list.size() - 1);
}

int main(int argc, char* argv[]) {
  IntVec vec(20);

  for (int i = 0; i < vec.size(); i++)
    vec[i] = rand() % 100;
  std::sort(vec.begin(), vec.end());

  int find;
  std::cout << "What number would you like to find?: ";
  std::cin >> find;

  printVector(vec);
  std::cout << binarysearch(vec, find) << std::endl;
}
