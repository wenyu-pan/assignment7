#ifndef group_h
#define group_h

#include <string>
#include <vector>
#include "student.hpp"
using namespace std;

struct Group {
    string name;
    int size;
    vector<Student> group_students;
    int accu_score;
    double accu_average_score;
};

vector<Group> initialize_group(int, int);

void print_groups(vector<Group>);

string print_names(Group);

void add_student_by_name(string ,vector<string> &names);


#endif 