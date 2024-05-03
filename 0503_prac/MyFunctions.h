#pragma once

#ifndef _MYFUNCTIONS_
#define _MYFUNCTIONS_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//2. namespace 이름으로 감싸기
namespace MyFunctions
{
    struct student_personal_info
    {
        string name;
        float age;
        string birthday;
    };

    void InputStudentInfo(vector<student_personal_info>& students);
    void PrintStudentInfo(const vector<student_personal_info>& students);
    void PrintAverAge(const vector<student_personal_info>& students);
    void PrintEarlyBirth(const vector<student_personal_info>& students);
    void EditStudentInfo(vector<student_personal_info>& students);
}


#endif
