#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, int>> arr;


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		// a ���۽ð� b ����ð�
		cin >> a >> b;
		arr.push_back(make_pair(b, a));
	}

	sort(arr.begin(), arr.end());
	// ���� �ð� �������� �����ϱ�

	int result = 0;
	int end = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].second >= end) {
			// ���۽ð��� ����ð� ���ĸ�
			end = arr[i].first;
			result++;
		}
	}

	cout << result << endl;
}