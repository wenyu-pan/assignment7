#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "helpers.hpp"
using namespace std;
vector<string> readIntoVector(string s1,string space_delimiter) {

    vector<string> result;
  
     size_t pos = 0;
     vector<string> words{};
  
     while ((pos = s1.find(space_delimiter)) != string::npos) {
        words.push_back(s1.substr(0, pos));
        s1.erase(0, pos + space_delimiter.length());
    }
  words.push_back(s1.substr(pos + 1));
  return words;
  }

int checkLevel(string line) {
   if (line == "Advanced") {
        return 3;
      }

      else if (line == "Intermediate") {
        return 2;
      }

      else if (line == "Novice") {
        return 1;
      }
  return 0;
}

bool checkManagement(string line) {
    if (line == "Yes") {
        return true;
      }

      else {
        return false;
      }

}