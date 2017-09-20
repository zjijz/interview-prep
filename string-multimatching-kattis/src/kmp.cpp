#include <iostream>
#include <vector>

void calcFailure(const std::string& pattern, std::vector<int>& failure) {
  // Set constants
  failure[0] = -1;
  failure[1] = 0;
  int pnt = 2, next = 0;

  while (pnt < pattern.length()) {
    if (pattern[pnt - 1] == pattern[next]) // Substring continues
      failure[pnt++] = ++next; // This is so unreadable !!!
    else if (next > 0) // Substring breaks continuum
      next = failure[next];
    else
      failure[pnt++] = 0;
  }
}

void kmpSearch(const std::string& pattern, const std::string& string,
               const std::vector<int> failure) {
  int m = 0, i = 0;
}

int main() {
  std::string line;
  while (getline(std::cin, line)) {
    // Get number of keys
    int num = std::stoi(line);

    // Actually pull the strings
    std::vector<std::string> keys(num);
    for (int i = 0; i < num; i++)
      getline(std::cin, keys[i]);

    // Get the search string
    std::string search;
    getline(std::cin, search);

    // Calculate failure functions and run KMP
    // std::vector<std::vector<int>> failures(num);
    for (int i = 0; i < keys.size(); i++) {
      std::cout << keys[i] << std::endl;

      std::vector<int> failure(keys[i].length());
      calcFailure(keys[i], failure);
      // failures[i] = failure;

      // Testing
      for (int item : failures[i])
        std::cout << item << " ";
      std::cout << std::endl;

      // Run KMP
      kmpSearch(keys[i], search, failure);
    }
  }
}
