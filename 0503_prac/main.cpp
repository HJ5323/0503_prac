//1. MyFunctions ��� ���� ���� �� ���սǽ��� ���� ������� �Լ����� �����(������Ÿ��)�� �ۼ�
//2. MyFunctions CPP ���� ���� �� ��� ���Ͽ��� ������ �Լ��� ���� ����
//3. main �Լ��� �ִ� CPP ���Ͽ��� MyFunctions ��������� �������� �� �Լ��� ����Ͽ� ����� ���

#include "MyFunctions.h"

int main()
{
    vector<student_personal_info> students;

    InputStudentInfo(students);
    PrintStudentInfo(students);
    PrintAverAge(students);
    PrintEarlyBirth(students);
    EditStudentInfo(students);
    PrintStudentInfo(students);

    return 0;
}