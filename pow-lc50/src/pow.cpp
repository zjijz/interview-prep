/*
 * Ran in 0 or 3? ms
 * Beat 100% of submissions
 */

class Solution {
public:
  // Time: O(log(n))
  // (really it's linear in the number of bits, which is always 32 in this case,
  // but can someitmes be pre-emptively optimized by the solution below)
  // Space: O(1)
  double myPow(double x, int n) {
    if (n == 0 || x == 1) return 1;

    double ret = 1;
    bool neg = n < 0;
    long absN = (neg) ? -(long)n : n;
    while (absN > 0) {
      if ((absN & 1) == 1) ret *= x;
      absN >>= 1;
      x *= x;
    }

    return (neg) ? 1 / ret : ret;
  }

  // Time: O(log(n))
  // Space: O(n)
  /* double myPow(double x, int n) {
    if (n == 0) return 1;

    bool neg = n < 0;
    long absN = (neg) ? -n : n;

    std::vec<double> values(n + 1);
    values[0] = 1;
    values[1] = x;

    double calc = myPowDP(values, absN);
    return (neg) ? 1 / calc : calc;
  }

  double myPowDP(std::vec<double>& values, int n) {
    // If in table, use it
    if (values[n] != 0) return values[n];

    // If not, compute it
    int left = n / 2;
    int right = n - left;
    double calc = myPowDp(values, left) * myPow(values, right);
    values[n] = calc;
    return calc;
  } */

  /*
   * Naive
   * Time: O(n)
   * Space: O(1)
   */
  /* double myPow(double x, int n) {
    if (n == 0) return x;

    double ret = x;
    bool neg = n < 0;
    n = (neg) ? -n : n;
    while (n > 1) {
      ret *= x;
      n--;
    }
    return (neg) ? 1 / ret : ret;
  } */
}
