#include <cctype>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <utility>

#include <bits/stdc++.h>

// https://www.geeksforgeeks.org/sorting-a-map-by-value-in-c-stl/
bool cmp(std::pair<char, uint32_t> &a, std::pair<char, uint32_t> &b) {
  return a.second > b.second;
}
// https://www.geeksforgeeks.org/sorting-a-map-by-value-in-c-stl/
void sortMapAndOutput(std::map<char, uint32_t> &M) {
  std::vector<std::pair<char, uint32_t>> A;
  for (auto &it : M) {
    A.push_back(it);
  }
  sort(A.begin(), A.end(), cmp);
  int i = 1;
  for (auto &it : A) {
    printf("%i: %c has %u occurances\n", i, it.first, it.second);
    i++;
  }
}

int main() {
  std::map<char, uint32_t> data{};
  for (int i = 0; i < 26; i++) {
    data[i + 97] = 0;
  }
  std::ifstream wordFile;
  wordFile.open("words_alpha.txt");
  if (!wordFile.is_open()) {
    throw std::runtime_error("Failed to open file");
  }
  while (!wordFile.eof()) {
    char curChar = tolower(wordFile.get());
    if (curChar >= 97 && curChar < 123) {
      data[curChar] += 1;
    }
  }
  sortMapAndOutput(data);
}