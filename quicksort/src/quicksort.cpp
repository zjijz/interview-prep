/*
Quicksort Pseudocode / Python

def quicksort(list, start, end):
  if list.size() <= 1:
    return;

  pivot = (end - start) / 2
  partition(list, pivot)
  quicksort(list, start, pivot)
  quicksort(list, pivot, end)

def partition(list, index):
  head = 0
  tail = list.size() - 1

  while head < index:
    while list[head] < list[pivot] and head < tail:
      head++

    while list[tail] > list[pivot] and tail >= 0:
      tail--

    swap(list, head, tail)

def swap(list, head, tail):
  list[head] = list[head] + list[tail]
  list[tail] = list[head] - list[tail]
  list[head] = list[head] - list[tail]
*/

#include <vector>
#include <iostream>

using IntVec = std::vector<int>;

void printVector(IntVec& vec) {
  for (int i = 0; i < vec.size(); i++)
    std::cout << vec[i] << ", ";
  std::cout << std::endl;
}

/*
 * Overflows if list[head] and list[tail] are too large
 */
void swap(IntVec& list, const int head, const int tail) {
  list[head] = list[head] + list[tail];
  list[tail] = list[head] - list[tail];
  list[head] = list[head] - list[tail];
}

/*
 * I couldn't get this to work without moving the pivot and then moving it back
 */
int partition(IntVec& list, int head, int tail) {
  int pivotInd = (head + tail) / 2;
  const int pivot = list[pivotInd];
  swap(list, head, pivotInd);
  pivotInd = head;
  while (true) {
    do {
      head++;
    } while (list[head] < pivot);

    do {
      tail--;
    } while (list[tail] > pivot);

    if (head >= tail)
      break;

    swap(list, head, tail);
  }
  swap(list, pivotInd, tail);
  return tail;
}

void quicksort(IntVec& list, const int start, const int end) {
  if ((end - start) <= 1) return;

  int pivot = partition(list, start, end);
  quicksort(list, start, pivot);
  quicksort(list, pivot + 1, end);
}

void quicksort(IntVec& list) {
  quicksort(list, 0, list.size());
}

int main(int argc, char* argv[]) {
  IntVec vec(10);

  for (int i = 0; i < vec.size(); i++)
    vec[i] = rand() % 10;

  printVector(vec);
  quicksort(vec);
  printVector(vec);
}
