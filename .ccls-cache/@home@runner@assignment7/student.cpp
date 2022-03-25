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

int score(Student s) {
  return s.cpp_experience * 5 + s.gdb_experience * 3 + s.proj_management * 4;
}



