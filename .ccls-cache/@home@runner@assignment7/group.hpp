#ifndef group_h
#define group_h

#include <string>
#include <vector>
#include "student.hpp"
using namespace std;

struct Group {
    string name;
    vector<Student> group_students;
    int accu_score;
    double average_cpp_score;
    double average_gdb_score;
    double average_management_score;
};

vector<Group> initialize_group(int, int);

void print_groups(vector<Group>);

string print_names(Group);

#endif 