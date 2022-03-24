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
    
  res.substr(1);
    }
  return res;
}

void add_student_by_name(string name,vector<string> &names) {
  if (!count(names.begin(), names.end(), name)) {
    names.push_back(name);
  }
 }

bool check_appropriate(Student s,Group g) {
  vector<string> s_not_with = s.students_not_with;
  for (int i = 0; i < g.group_students.size(); i ++) {

    if (g.size == g.group_students.size()) {
      return false;
    }
    vector<string> g_not_with = g.group_students.at(i).students_not_with;
   if ((count(s_not_with.begin(),s_not_with.end(),g.group_students.at(i).name)) || (count (g_not_with.begin(),g_not_with.end(),s.name))) {
     return false;
   }
  }
  return true;
}

void move_into_group(Student s,Group *g) {
  cout << s.name << endl;
    g->group_students.push_back(s);
  
    g->accu_score = g->accu_score + s.cpp_experience * 5 + s.gdb_experience * 3 + s.proj_management * 4;
    g->accu_average_score = g->accu_score / g->group_students.size();
}
