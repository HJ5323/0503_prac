//1. �ռ� ������� MyFunctions ��� ������ main �Լ��� �ִ� ���Ͽ��� �ҷ�����
//2. �ռ� ������� MyFunctions ��� ���Ͽ� �ִ� ������ ������ namespace �̸����� ���α�
//3. main �Լ��� �ִ� ���Ͽ��� MyFunctions�� �ִ� ������ namespace�� ���ļ� ����ϱ�

#include "MyFunctions.h"

int main() 
{
    // 3. MyFunctions namespace ���
    vector<MyFunctions::student_personal_info> students; 

    MyFunctions::InputStudentInfo(students);
    MyFunctions::PrintStudentInfo(students);
    MyFunctions::PrintAverAge(students);
    MyFunctions::PrintEarlyBirth(students);
    MyFunctions::EditStudentInfo(students);

    return 0;
}