#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str;
int x;
int result = 0;

int main() {
	cin >> str;

	string num = "";
	int sum = 0;
	bool minus = false;

	// - �� ���� ���ķ� �� ���ֱ�
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (minus) {
				sum -= stoi(num);
			}
			else {
				sum += stoi(num);
				// ���������� ��� +
			}
			if (str[i] == '-') {
				// -�� ó�� �����ߴٸ�
				minus = true;
			}

			num = "";
		}
		else
			num += str[i];
		// ��ȣ�� �ȳ����� string���� �����ֱ�
	}

	cout << sum;
	
}