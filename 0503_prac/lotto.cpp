//로또 번호 추천 프로그램 만들기
//1. 1~45 사이의 수 중에서 
//2. 랜덤으로 6개의 번호를 추출하는 프로그램
//3. 중복 불가능
//4. 추출이 완료되면 6개의 당첨번호 출력

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// 로또 번호 추첨 함수
vector<int> LottoNumbers() 
{
    vector<int> lottoNumbers;

    srand(time(NULL));

    // 1부터 45까지의 숫자를 벡터에 저장
    for (int i = 1; i <= 45; i++) 
    {
        lottoNumbers.push_back(i);
    }

    // 숫자 섞기
    random_shuffle(lottoNumbers.begin(), lottoNumbers.end());

    // result 벡터에 6개의 로또 번호 추출
    vector<int> result(lottoNumbers.begin(), lottoNumbers.begin() + 6);

    return result;
}

int main() 
{
    // 6개의 로또 번호 추출
    vector<int> lottoResult = LottoNumbers();

    // 추출된 번호 정렬
    sort(lottoResult.begin(), lottoResult.end());

    // 당첨 번호 출력
    cout << "로또 당첨 번호: ";
    for (int i = 0; i < 6; i++) 
    {
        cout << lottoResult[i] << " ";
    }
    cout << endl;

    return 0;
}