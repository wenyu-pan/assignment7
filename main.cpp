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








    
    cout << s.name << endl;
    cout << s.email << endl;
    cout << s.cpp_experience << endl;
    cout << s.gdb_experience << endl;
    cout << s.proj_management << endl;
    for (int i = 0; i < s.students_not_with.size(); i ++) {
      cout << "Student not with: " << s.students_not_with.at(i) << endl;;
      }
    cout << endl;

    for (int i = 0; i < s.students_with.size(); i ++) {
      cout << "Student with: " << s.students_with.at(i) << endl;
      }
    cout << endl;
    

  }
  

  

  
}

