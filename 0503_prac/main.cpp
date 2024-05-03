//1. MyFunctions 헤더 파일 생성 후 종합실습을 통해 만들었던 함수들의 선언부(프로토타입)만 작성
//2. MyFunctions CPP 파일 생성 후 헤더 파일에서 선언한 함수의 내용 구현
//3. main 함수가 있는 CPP 파일에서 MyFunctions 헤더파일을 가져오고 각 함수를 사용하여 결과값 출력

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