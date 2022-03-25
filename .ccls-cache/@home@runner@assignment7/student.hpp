#ifndef student_h
#define student_h

#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    string email;
    int cpp_experience;
    int gdb_experience;
    bool proj_management;
    vector<string> students_not_with;
    vector<string> students_with;
};


Student search_by_name(vector<Student> &n,string s);

int score(Student);

#endif /* student_h */
