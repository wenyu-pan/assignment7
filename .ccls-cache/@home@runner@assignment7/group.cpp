#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <iomanip>
#include "group.hpp"
#include "student.hpp"

using namespace std;

void print_groups(vector<Group> groups) {
  ofstream outfile("out.csv");
  if(!outfile){ cout<<"can't open file"<<endl; return 
    EXIT_FAILURE;}

  for (int i = 0; i < groups.size(); i ++) {
    outfile << groups.at(i).name << ",";
    outfile << print_names(groups.at(i)) << ",";
    outfile << to_string(groups.at(i).accu_score) << endl;
  }
  outfile.close();
}

string print_names(Group p) {
  vector<Student> students = p.group_students;
  string res;
  if (students.size() > 0) {
 
  for (int i = 0; i < students.size(); i ++) {
    res = res + " " + students.at(i).name;
     }
    }

  else {
    
  }
  res.substr(1);
}