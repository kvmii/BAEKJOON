#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
int result = 0;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());
	// ����

	for (int i = 0; i < vec.size(); i++) {
		int length = vec.size() - i;
		// ����
		result = max(result, length * vec[i]);
		// ���� * ���߿� ���� ū ��
	}

	cout << result << endl;
}