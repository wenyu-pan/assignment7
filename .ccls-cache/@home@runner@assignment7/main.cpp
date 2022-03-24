#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "student.hpp"
#include "helpers.hpp"
using namespace std;

int main() {
  ifstream infile;
  infile.open("input.csv");
  string line_2;
  getline(infile,line_2);


  vector<Student> students;

    

  while (infile.good()) {
    string line;
    getline(infile,line);
  
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
  
  int number_of_groups = split_group_n(students.size(),number_each_group);
  cout << "Number of n-people groups: " << number_of_groups << endl;
  int number_of_n_minus_one_gourps = split_group_n_1(students.size(),number_each_group);
  cout << "Number of (n-1)-people groups: " << number_of_n_minus_one_gourps << endl;
    }








    
    

  

  
}

