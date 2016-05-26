#include <vector>
#include <iostream>
#include <algorithm>

using IntVec = std::vector<int>;
using IntVecIter = std::vector<int>::const_iterator;

void getMinMaxElements(IntVec& list, int& min, int& max) {
  for (IntVecIter iter = list.begin(); iter != list.end(); iter++) {
    if (*iter < min)
      min = *iter;
    if (*iter > max)
      max = *iter;
  }
}

void getSums(IntVec& list, int& minSum, int& maxSum) {
  for (IntVecIter iter = list.begin(); iter != list.end(); iter++)
    if (*iter < 0)
      minSum += *iter;
    else
      maxSum += *iter;
}

bool subsetSum(IntVec& list, const int sum, const int minSum,
               const int maxSum, int i) {
  if ((sum > maxSum) || (sum < minSum) || (i < 0)) return false;
  if (list[i] == sum) return true;

  // First recursive call is if this elmeent isn't taken, second is if it is
  return subsetSum(list, sum, minSum, maxSum, i - 1)
          || subsetSum(list, sum - list[i], minSum, maxSum, i - 1);
}

bool subsetSum(IntVec& list, const int sum) {
  // Find min / max possible sums
  int min = INT_MAX, max = INT_MIN, minSum = 0, maxSum = 0;
  getMinMaxElements(list, min, max); // O(n)
  getSums(list, minSum, maxSum); // O(n)

  if ((minSum < min) && (min > 0))
    minSum = min;

  if ((maxSum > max) && (max < 0))
    maxSum = max;

  std::cout << "Min Element: " << min << ", Max Element: " << max << std::endl;
  std::cout << "Min sum: " << minSum << ", Max sum: " << maxSum << std::endl;

  return subsetSum(list, sum, minSum, maxSum, list.size() - 1);
}

int main(int argc, char* argv[]) {
  int size, sum;

  std::cout << "Enter your multiset size: ";
  std::cin >> size;

  if (size < 1) return 0;

  IntVec vec(size);
  for (int i = 0; i < size; i++)
    std::cin >> vec[i];

  std::cout << "Enter your sum: ";
  std::cin >> sum;

  std::string ans = (subsetSum(vec, sum)) ? "True" : "False" ;
  std::cout << "Answer: " << ans << std::endl;
}
