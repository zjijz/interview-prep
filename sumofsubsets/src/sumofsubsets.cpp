#include <vector>
#include <iostream>
#include <algorithm>

using IntVec = std::vector<int>;
using IntVecIter = IntVec::const_iterator;

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

int normalizeIndex(int currSum, int minSum, int rowSize, int offset) {
  return rowSize - offset + currSum - minSum;
}

void printSumArray(bool *S, int rowSize) {
  for (int i = 0; i < 2; i++) {
    std::cout << "Row " << i + 1 << ": ";
    for (int j = 0; j < rowSize; j++) {
      std::cout << S[i * rowSize + j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

/*
 * Essentially, the problem can be reduced to looking at the finite range of
 * minimum possible sum to desired sum. (Found in O(n) time)
 *
 * Next, let function S(i, s) be the truth value of a sum s existing
 * in list[:i] (inclusive).
 *
 * S(i, s) = S(i - 1, s) || list[i] == s || S(i - 1, s - list[i])
 * (The first is if the elmeent at index i can be ignored,
 *  the second is if the element itself is equal to the element,
 *  the last is if the elment is included and the remaining part is
 *  able to be made with the other elents)
 * (Takes O(kn) time to make where k = |minimum possible sum - sum|)
 * (This is not really linear since k does not depend directly on
 *  the input size)
 *
 * Look at S(len(list), sum) for answer
 *
 * Only the ith and (i-1)th values of S need to be kept at any time, so we can
 * store it in O(2n) space.
 *
 * This seems to be related to the integer partition function:
 * p(n, k) = p(n - 1, k - 1) + p (n - k, k - 1)
 */
bool subsetSum(IntVec& list, int sum) {
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

  // Check sum bounds
  if ((sum > maxSum) || (sum < minSum)) return false;

  // Table building
  int m = sum - minSum + 1;
  bool S[m * 2];

  for (int s = minSum; s <= sum; s++) // O(m)
    S[s - minSum] = (list[0] == s);

  int offset = 0;
  for (int i = 1; i < list.size(); i++) { // O(mn)
    // Alternates rows to store values
    offset = (i % 2 == 1) ? m : 0;

    for (int s = minSum; s <= sum; s++) {
      int normInd = normalizeIndex(s, minSum, m, offset);

      // Bounds checks (normally handled by recursion)
      bool ifNotTake = ((normInd >= 0) && (normInd < (m * 2)))
                        ? S[normInd] : false;
      bool ifTake = ((normInd - list[i] >= 0) && (normInd - list[i] < (m * 2)))
                      ? S[normInd - list[i]] : false;

      S[offset + s - minSum] = ifNotTake || (list[i] == s) || ifTake;
    }

    printSumArray(S, m);
  }

  return S[m + offset - 1];
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
