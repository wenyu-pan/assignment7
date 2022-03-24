#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "student.hpp"
#include "helpers.hpp"
#include "group.hpp"
using namespace std;

int main() {
  ifstream infile;
  infile.open("input.csv");
  string line_2;
  getline(infile,line_2);

  int number_of_groups;
  int number_of_n_minus_one_gourps;


  vector<Student> students;

    

 
  string line;
  while (getline(infile,line)) {
  
    vector<string> temp;
    vector<string> temp_1;
    vector<string> temp_2;
    vector<string> temp_3;
    vector<string> temp_4;
    
    temp = readIntoVector(line,",");

    Student s;
    s.name = temp.at(0);
    s.email = temp.at(1);
    s.cpp_experience = checkLevel(temp.at(2));
    s.gdb_experience = checkLevel(temp.at(3));
    s.proj_management = checkManagement(temp.at(4));


    if (temp.at(5) != "N/A" || temp.at(5) != "None") {
      
    
    temp_1 = readIntoVector(temp.at(5)," ");
    
    for (int i = 0 ; i < temp_1.size() / 2; i ++) {
      string student_name;
      student_name = student_name + temp_1.at(2 * i);
      student_name = student_name + " " + temp_1.at(2 * i + 1);
      temp_2.push_back(student_name);
    }
    s.students_not_with = temp_2;
      }


    if (temp.at(6) != "N/A" || temp.at(6) != "None") {
    temp_3 = readIntoVector(temp.at(6)," ");
    for (int i = 0 ; i < temp_3.size() / 2; i ++) {
      string student_name;
      student_name = student_name + temp_3.at(2 * i);
      student_name = student_name + " " + temp_3.at(2 * i + 1);
      temp_4.push_back(student_name);
    }
    s.students_with = temp_4;
      }

    students.push_back(s);
    }

    cout << "Total number of students: " << students.size() << endl;
    cout << "Please enter the number of students you want to have in each group: (A ideal group should have a size between 2 and 5)" << endl;
    string s1;
    cin >> s1;
    int number_each_group = stoi(s1);

  if (number_each_group > 5 || number_each_group < 2) {
    cout << "The number you entered is invalid" << endl;
  }

  else {
  
   number_of_groups = split_group_n(students.size(),number_each_group);
  cout << "Number of n-people groups: " << number_of_groups << endl;
  number_of_n_minus_one_gourps = split_group_n_1(students.size(),number_each_group);
  cout << "Number of (n-1)-people groups: " << number_of_n_minus_one_gourps << endl;
    }

  vector<Group> groups (number_of_groups + number_of_n_minus_one_gourps); 

  for (int i = 0; i < groups.size(); i ++) {
    groups.at(i).name = "Group " + to_string(i + 1);
  }

  for (int i = 0; i < number_of_groups; i ++) {
    groups.at(i).size = number_each_group;
  }

  for (int j = number_of_groups; j < groups.size(); j ++) {
    groups.at(j).size = number_each_group - 1;
  }

  for (int i = 0; i < groups.size(); i ++) {
    cout << groups.at(i).name << ": " <<groups.at(i).size << endl;
  }

  vector<Student> priority_student;

  vector<string> priority_student_names;


  for (int i = 0; i < students.size();i ++) {
   if (students.at(i).students_not_with.size() != 0) {
     for (int j = 0; j < students.at(i).students_not_with.size(); j ++) {
       add_student_by_name(students.at(i).students_not_with.at(j),priority_student_names);
     }
     add_student_by_name(students.at(i).name,priority_student_names);
   }
 }

  

  for (int i = 0; i < students.size(); i ++) {
    if (count(priority_student_names.begin(),priority_student_names.end(),students.at(i).name )) {
      priority_student.push_back(students.at(i));
    }
  }

  for (int i = 0; i <priority_student.size();i ++) {
    cout << priority_student.at(i).name << endl;
  }

  for (int i = 0; i < priority_student.size();i ++) {
    for (int j = 0; j < groups.size(); j ++) {
      
    if (check_appropriate(priority_student.at(i),groups.at(j))) {
    move_into_group(priority_student.at(i),&groups.at(j));
     break;
    }
  }
}

  print_groups(groups);

  for (int i = 0; i < groups.size(); i ++) {
    cout <<groups.at(i).group_students.size() << endl;
  }

  vector<Student> other_students;
  for (int i = 0; i < students.size(); i ++) {
    if (!count(priority_student_names.begin(),priority_student_names.end(),students.at(i).name)) {
      other_students.push_back(students.at(i));
    }
  }
  
  
  }