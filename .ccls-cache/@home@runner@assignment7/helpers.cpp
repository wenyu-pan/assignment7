#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdio.h>     
#include <math.h>
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


int split_group_n(int total_number, int number) {
  int max_groups = total_number / number + 1;
  
  
  int number_of_n_minus_one_gourps = max_groups * number - total_number;

  
  int number_of_n_groups = (total_number - number_of_n_minus_one_gourps * (number - 1)) / number;
  return number_of_n_groups;
}

int split_group_n_1(int total_number, int number) {
  int max_groups = total_number / number + 1;
  
  
  int number_of_n_minus_one_gourps = max_groups * number - total_number;

  
  int number_of_n_groups = (total_number - number_of_n_minus_one_gourps * (number - 1)) / number;

  
  return number_of_n_minus_one_gourps;
  
}