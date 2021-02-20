#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 100 + 1;

int n, m;

string dp[MAX][MAX];

string sum(string num1, string num2){

    long long sum = 0;
    string result;
    //1�� �ڸ����� ���ϱ�

    while (!num1.empty() || !num2.empty() || sum)
    {
        if (!num1.empty())
        {
            sum += num1.back() - '0';
            num1.pop_back();
        }

        if (!num2.empty()){
            sum += num2.back() - '0';
            num2.pop_back();
        }

        result.push_back((sum % 10) + '0');
        // 10�� ������� �������� �����
        sum /= 10;
        // 10�� ������� �ڸ� �ø�
    }

    reverse(result.begin(), result.end());
    // �Ųٷ� ���ֱ�
    return result;
}

//nCr = n-1Cr + n-1Cr-1

string comb(int n, int r){
    if (n == r || r == 0)
        return "1";
    
    string& result = dp[n][r];
    if (result != "")
        return result;
    result = sum(comb(n - 1, r - 1), comb(n - 1, r));

    return result;
}

int main(){
    cin >> n >> m;

    cout << comb(n, m) << endl;

    return 0;
    // long long���ε� �Ѱ谡 �־ string���� ��ȯ
    // ��������� �˾Ҵµ� ��û �����ɷȴ�
}
