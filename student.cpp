#include <iostream>
#include <vector>
#include "student.hpp"

using namespace std;

Student search_by_name(vector<Student> &n,string s) {
  Student res;
  for (int i = 0; i < n.size();i ++) {
    if (n.at(i).name == s) {
      res = n.at(i);
    }
  }
  return res;
}



