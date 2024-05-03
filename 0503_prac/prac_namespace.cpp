//1. 앞서 만들었던 MyFunctions 헤더 파일을 main 함수가 있는 파일에서 불러오기
//2. 앞서 만들었던 MyFunctions 헤더 파일에 있는 내용을 적절한 namespace 이름으로 감싸기
//3. main 함수가 있는 파일에서 MyFunctions에 있는 내용을 namespace를 거쳐서 사용하기

#include "MyFunctions.h"

int main() 
{
    // 3. MyFunctions namespace 사용
    vector<MyFunctions::student_personal_info> students; 

    MyFunctions::InputStudentInfo(students);
    MyFunctions::PrintStudentInfo(students);
    MyFunctions::PrintAverAge(students);
    MyFunctions::PrintEarlyBirth(students);
    MyFunctions::EditStudentInfo(students);

    return 0;
}