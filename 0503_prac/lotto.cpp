//�ζ� ��ȣ ��õ ���α׷� �����
//1. 1~45 ������ �� �߿��� 
//2. �������� 6���� ��ȣ�� �����ϴ� ���α׷�
//3. �ߺ� �Ұ���
//4. ������ �Ϸ�Ǹ� 6���� ��÷��ȣ ���

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// �ζ� ��ȣ ��÷ �Լ�
vector<int> LottoNumbers() 
{
    vector<int> lottoNumbers;

    srand(time(NULL));

    // 1���� 45������ ���ڸ� ���Ϳ� ����
    for (int i = 1; i <= 45; i++) 
    {
        lottoNumbers.push_back(i);
    }

    // ���� ����
    random_shuffle(lottoNumbers.begin(), lottoNumbers.end());

    // result ���Ϳ� 6���� �ζ� ��ȣ ����
    vector<int> result(lottoNumbers.begin(), lottoNumbers.begin() + 6);

    return result;
}

int main() 
{
    // 6���� �ζ� ��ȣ ����
    vector<int> lottoResult = LottoNumbers();

    // ����� ��ȣ ����
    sort(lottoResult.begin(), lottoResult.end());

    // ��÷ ��ȣ ���
    cout << "�ζ� ��÷ ��ȣ: ";
    for (int i = 0; i < 6; i++) 
    {
        cout << lottoResult[i] << " ";
    }
    cout << endl;

    return 0;
}