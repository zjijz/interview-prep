/*
Mergsort Pseudocode / Python

def mergesort(l):
  if len(l) <= 1:
    return l

  int mid = len(l) / 2
  left = l[:mid]
  right = l[mid:]
  left = mergesort(left)
  right = mergesort(right)
  return merge(left, right)

def merge(l, r):
  merged = new list of size len(l) + len(r)
  int l_point = 0
  int r_point = 0

  # This needs bounds checking
  for (i in range(0, len(l) + len(r))):
    if l[l_point] < r[r_point]:
      merged[i] = l[l_point]
    else:
      merged[i] = r[r_point]
*/

#include <vector>
#include <iostream>
#include <algorithm>

using IntVec = std::vector<int>;

void printVector(IntVec& vec) {
  for (int i = 0; i < vec.size(); i++)
    std::cout << vec[i] << ", ";
  std::cout << std::endl;
}

void merge(IntVec& vec, IntVec& left, IntVec& right) {
  int c = 0, l = 0, r = 0;

  while (true) {
    if (left[l] <= right[r]) {
      vec[c] = left[l];
      l++;
      c++;
      if (l >= left.size()) {
        break;
      }
    } else {
      vec[c] = right[r];
      r++;
      c++;
      if (r >= right.size()) {
        break;
      }
    }
  }

  while (l < left.size()) {
    vec[c] = left[l];
    l++;
    c++;
  }

  while (r < right.size()) {
    vec[c] = right[r];
    r++;
    c++;
  }
}

void mergesort(IntVec& l) {
  if (l.size() <= 1) return;

  int mid = l.size() / 2;
  std::vector<int> left(l.begin(), l.begin() + mid);
  std::vector<int> right(l.begin() + mid, l.end());

  mergesort(left);
  mergesort(right);

  merge(l, left, right);
}

int main(int argc, char* argv[]) {
  IntVec vec(1000);

  for (int i = 0; i < vec.size(); i++)
    vec[i] = rand() % 1000;

  printVector(vec);
  mergesort(vec);
  printVector(vec);
}
