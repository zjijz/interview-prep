#include <vector>
#include <iostream>
#include <algorithm>

using IntVec = std::vector<int>;
using IntVecIter = IntVec::const_iterator;

void printVector(IntVec& vec) {
  for (int i = 0; i < vec.size(); i++)
    std::cout << vec[i] << ", ";
  std::cout << std::endl;
}

/*
 * One-pass to update min and max.
 * Updates parameters directly.
 */
void getRange(IntVec& list, int& min, int& max) {
  for (IntVecIter iter = list.begin(); iter != list.end(); iter++) {
    if (*iter < min) min = *iter;
    if (*iter > max) max = *iter;
  }
}

/*
 * Scans the list and finds the minimum and maximum elements.
 * As long as the range is less than the size of the list,
 * this is effective. Also, if there a few gaps in the range of numbers.
 *
 * O(n) space
 * O(n) time
 * Three-pass (One-pass gets range)
 */
void countingsort(IntVec& list) {
  int min = INT_MAX, max = INT_MIN;
  getRange(list, min, max);
  IntVec counts(max - min + 1, 0); // O(n)

  for (IntVecIter iter = list.begin(); iter != list.end(); iter++) // O(n)
    counts[*iter]++;

  int ind = 0;
  for (int i = 0; i < counts.size(); i++) // O(n) total
    for (int j = 0; j < counts[i]; j++)
      list[ind++] = i;
}

int main(int argc, char* argv[]) {
  IntVec vec(10);

  for (int i = 0; i < vec.size(); i++)
    vec[i] = rand() % 10;

  printVector(vec);
  countingsort(vec);
  printVector(vec);
}
