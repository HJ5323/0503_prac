#include "MyFunctions.h"


void InputStudentInfo(vector<student_personal_info>& students)
{
    // 1. 사용자에게 학생 수 입력 받기
    int student_num;
    cout << "학생 수를 입력하세요: ";
    cin >> student_num;
    cin.ignore(); // 버퍼 비우기

    // 2. 학생 수 만큼 정보 입력 받기
    for (int i = 0; i < student_num; i++)
    {
        cout << "학생 " << i + 1 << " 정보 입력 (이름,나이,생일(0000.00.00)): ";
        string name, birthday;
        float age;

        // 쉼표(,)를 기준으로 문자열을 나누고 각 정보를 저장
        getline(cin, name, ','); // 쉼표가 나올때까지 읽고 name으로 저장, 쉼표 버림
        cin >> age; // 그 다음 age로 저장
        cin.ignore();
        getline(cin, birthday); // 나머지 birthday 저장

        students.push_back({ name, age, birthday }); // students 벡터에 저장
    }
}

// 학생 정보 출력
void PrintStudentInfo(const vector<student_personal_info>& students)
{
    cout << "\n<학생 정보>" << endl;
    for (int i = 0; i < students.size(); i++)
    {
        cout << "학생 " << i + 1 << endl;
        cout << "이름: " << students[i].name << endl;
        cout << "나이: " << students[i].age << endl;
        cout << "생일: " << students[i].birthday << "\n" << endl;
    }
}

// 평균 나이 출력
void PrintAverAge(const vector<student_personal_info>& students)
{
    float sum_age = 0;

    for (size_t i = 0; i < students.size(); i++)
    {
        sum_age += students[i].age;
    }

    cout << "\n평균나이 : " << sum_age / students.size() << endl;
}

// 가장 빠른 생일 출력
void PrintEarlyBirth(const vector<student_personal_info>& students)
{
    string EarlyBirth = students[0].birthday; // 초기화
    int EarlyBirthIndex = 0;

    for (int i = 1; i < students.size(); i++)
    {
        if (students[i].birthday < EarlyBirth) // 현재 생일이 더 빠른 경우 업데이트
        {
            EarlyBirth = students[i].birthday;
            EarlyBirthIndex = i;
        }

    }

    cout << "\n가장 빠른 생일 : " << EarlyBirth << endl;
    cout << "이름 : " << students[EarlyBirthIndex].name << endl;
    cout << "나이 : " << students[EarlyBirthIndex].age << "\n" << endl;

}

// 학생 정보 편집 (이름으로 검색하여 나이 또는 생일 변경)
void EditStudentInfo(vector<student_personal_info>& students)
{
    string SearchName;
    bool ExitRequest = false;
    while (!ExitRequest)
    {
        cout << "편집할 학생의 이름을 입력하세요. (편집 종료 : exit 입력): ";
        getline(cin, SearchName);

        if (SearchName == "exit")
        {
            cout << "편집을 종료합니다." << endl;
            ExitRequest = false;
            return;
        }

        bool found = false;
        for (size_t i = 0; i < students.size(); i++)
        {
            if (students[i].name == SearchName)
            {
                found = true;

                while (!ExitRequest)
                {
                    int EditNum;
                    cout << "편집할 항목을 선택해 주세요. (1: 나이, 2: 생일, 3: 해당 편집 종료) : ";
                    cin >> EditNum;

                    if (EditNum == 1) // 나이 편집
                    {
                        float NewAge;
                        cout << "새로운 나이를 입력하세요: ";
                        cin >> NewAge;
                        students[i].age = NewAge;
                        cout << "나이가 변경되었습니다.\n" << endl;
                    }

                    else if (EditNum == 2) // 생일 편집
                    {
                        string NewBirthday;
                        cout << "새로운 생일을 입력하세요 (0000.00.00): ";
                        cin.ignore();
                        getline(cin, NewBirthday);
                        students[i].birthday = NewBirthday;
                        cout << "생일이 변경되었습니다.\n" << endl;
                    }

                    else if (EditNum == 3) // 종료
                    {
                        cout << students[i].name << "의 편집을 종료합니다.\n" << endl;
                        cin.ignore();
                        break;
                    }

                    else
                    {
                        cout << "잘못된 입력입니다.\n" << endl;
                    }
                }
            }
        }

        if (!found && !ExitRequest && SearchName != "exit")
        {
            cout << "해당하는 이름의 학생이 없습니다.\n" << endl;
        }

    }
}