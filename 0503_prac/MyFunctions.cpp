#include "MyFunctions.h"


void InputStudentInfo(vector<student_personal_info>& students)
{
    // 1. ����ڿ��� �л� �� �Է� �ޱ�
    int student_num;
    cout << "�л� ���� �Է��ϼ���: ";
    cin >> student_num;
    cin.ignore(); // ���� ����

    // 2. �л� �� ��ŭ ���� �Է� �ޱ�
    for (int i = 0; i < student_num; i++)
    {
        cout << "�л� " << i + 1 << " ���� �Է� (�̸�,����,����(0000.00.00)): ";
        string name, birthday;
        float age;

        // ��ǥ(,)�� �������� ���ڿ��� ������ �� ������ ����
        getline(cin, name, ','); // ��ǥ�� ���ö����� �а� name���� ����, ��ǥ ����
        cin >> age; // �� ���� age�� ����
        cin.ignore();
        getline(cin, birthday); // ������ birthday ����

        students.push_back({ name, age, birthday }); // students ���Ϳ� ����
    }
}

// �л� ���� ���
void PrintStudentInfo(const vector<student_personal_info>& students)
{
    cout << "\n<�л� ����>" << endl;
    for (int i = 0; i < students.size(); i++)
    {
        cout << "�л� " << i + 1 << endl;
        cout << "�̸�: " << students[i].name << endl;
        cout << "����: " << students[i].age << endl;
        cout << "����: " << students[i].birthday << "\n" << endl;
    }
}

// ��� ���� ���
void PrintAverAge(const vector<student_personal_info>& students)
{
    float sum_age = 0;

    for (size_t i = 0; i < students.size(); i++)
    {
        sum_age += students[i].age;
    }

    cout << "\n��ճ��� : " << sum_age / students.size() << endl;
}

// ���� ���� ���� ���
void PrintEarlyBirth(const vector<student_personal_info>& students)
{
    string EarlyBirth = students[0].birthday; // �ʱ�ȭ
    int EarlyBirthIndex = 0;

    for (int i = 1; i < students.size(); i++)
    {
        if (students[i].birthday < EarlyBirth) // ���� ������ �� ���� ��� ������Ʈ
        {
            EarlyBirth = students[i].birthday;
            EarlyBirthIndex = i;
        }

    }

    cout << "\n���� ���� ���� : " << EarlyBirth << endl;
    cout << "�̸� : " << students[EarlyBirthIndex].name << endl;
    cout << "���� : " << students[EarlyBirthIndex].age << "\n" << endl;

}

// �л� ���� ���� (�̸����� �˻��Ͽ� ���� �Ǵ� ���� ����)
void EditStudentInfo(vector<student_personal_info>& students)
{
    while (true)
    {
        string SearchName;
        cout << "������ �л��� �̸��� �Է��ϼ���. (���� ���� : exit �Է�): ";
        getline(cin, SearchName);
        cin.ignore();

        if (SearchName == "exit")
        {
            cout << "������ �����մϴ�." << endl;
            return;
        }

        bool found = false;
        for (size_t i = 0; i < students.size(); i++)
        {
            if (students[i].name == SearchName)
            {
                found = true;

                while (true)
                {
                    int EditNum;
                    cout << "������ �׸��� ������ �ּ���. (1: ����, 2: ����, 3: �ش� ���� ����) : ";
                    cin >> EditNum;

                    if (EditNum == 1) // ���� ����
                    {
                        float NewAge;
                        cout << "���ο� ���̸� �Է��ϼ���: ";
                        cin >> NewAge;
                        students[i].age = NewAge;
                        cout << "���̰� ����Ǿ����ϴ�.\n" << endl;
                    }

                    else if (EditNum == 2) // ���� ����
                    {
                        string NewBirthday;
                        cout << "���ο� ������ �Է��ϼ��� (0000.00.00): ";
                        cin.ignore();
                        getline(cin, NewBirthday);
                        students[i].birthday = NewBirthday;
                        cout << "������ ����Ǿ����ϴ�.\n" << endl;
                    }

                    else if (EditNum == 3) // ����
                    {
                        cout << students[i].name << "�� ������ �����մϴ�." << endl;
                        break;
                    }

                    else
                    {
                        cout << "�߸��� �Է��Դϴ�." << endl;
                    }

                }

            }
        }

        if (!found)
        {
            cout << "�ش��ϴ� �̸��� �л��� �����ϴ�." << endl;
        }

    }
}