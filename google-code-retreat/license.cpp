/*
 * Dict has:
 * boolean isValidWord(std::string word)
 * std::vector<std::string> getAllWords()
 * std::unordered_map::iterator iterator()
 */

int getMinWord(std::string license, dictionary dict) {
  // Brute Force [> O(m) where m is size of dict]
  std::unorder_map letters;
  int count = 0;
  for (int i = 0; i < license.length(); i++) {
    char c = license[i].toUppercase();
    if ((license[i] >= 'A') && (license[i] <= 'Z')) { // is letter
      letters.set(i);
      count++;
    }
  }

  std::string minWord = "";
  std::string minWordLength = INTMAX;
  do {
    std::string str = iterator().next();
    int hasCount = 0;
    for (int i = 0; i < str.length(); i++) {
      // Need an array to keep track instead of a one-dimensional variable to store hasCount
      if (letters.get(str[i])) {
        hasCount++;
      }
    }
    if ((hasCount == count) && (str.length() < minWordLength)) {
      minWord = str;
      minWordLength = str.length();
    }
  } while (iterator.hasNext());

  /* * * * * * * * * * * * * * */
  // Get letters from plate
  int minSize = # min size of letters#

  // Partioning dict method (O(m) where m = |dict|)
  int maxLen = 0;
  // DOn't have to store 1
  std::unordered_map<int, std::vector<std::string>> dicts;
  while (dict.iterator().hasNext()) {
    std::string next = iterator.next();
    std::vector<std::string> hashed = dicts.get(next.length());
    if (hashed) {
      hashed.push_back(next); // keeps lexigraphical order
    } else {
      std::vector<std::string> newHash = { next };
      dicts.insert(next.length(), newHash);
    }

    if (maxLen < next.length()) maxLen = next.length();
  }

  // Iteratate over the minimum length list possible (i.e. if license has 4 letters, look at dicts.get(4))
  // O(o*n*c) where o = maxLen - minSize, n is size of each list, c is size of each string
  for (int i = minSize; i < maxLen; i++) {
    std::vector<std::string> hashed = dicts.get(i);
    if (hashed) {
      for (int j = 0; j < hashed.size(); j++) {
        // Do the method from before to check if string has all letters required
      }
    }
  }
}
