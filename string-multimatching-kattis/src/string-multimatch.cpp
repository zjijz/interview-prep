#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
  int counter = 0;
  std::string line;
  while (counter < 10 && getline(std::cin, line)) {
    // Get number of keys
    int num = std::stoi(line);

    // Actually pull the strings
    std::vector<std::string> keys(num);
    for (int i = 0; i < num; i++)
      getline(std::cin, keys[i]);

    // Get the search string
    std::string search;
    getline(std::cin, search);

    // Turn keys into numbers for faster search
    std::vector<int> keyNums(num);
    for (int i = 0; i < num; i++) {
      int keyNum = 0;
      for (char& c : keys[i])
        keyNum += c;
      keyNums[i] = keyNum;
    }

    /*std::cout << std::endl << "Search: " << search << std::endl;
    for (int i = 0; i < num; i++) {
      std::cout << "Key: " << keys[i] << ", Code: " << keyNums[i] << std::endl;
    }
    std::cout << std::endl;*/

    // Do the searching
    for (int keyInd = 0; keyInd < num; keyInd++) {
      // Add first |key| characters together as a key
      int curr = 0;
      for (int i = 0; i < keys[keyInd].size(); i++)
        curr += search[i];

      // Do searching
      int searchInd = 0;
      while ((searchInd + keys[keyInd].size()) <= search.size()) {
        if ((curr == keyNums[keyInd])
            && (search.compare(searchInd, keys[keyInd].size(), keys[keyInd]) == 0))
          std::cout << searchInd << " ";

        curr -= search[searchInd];
        curr += search[searchInd + keys[keyInd].size()];
        searchInd++;
      }

      std::cout << std::endl;
    }
    counter++;
  }
}
