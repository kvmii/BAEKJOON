#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> vec;
int arr[1001];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ b, a });
	}

	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	// ������ ���� ������ ����

	for (int i = 0; i < vec.size(); i++) {
		int score = vec[i].first;
		int day = vec[i].second;

		if (arr[day] == 0) {
			// day���� �ƹ��͵� ���ϸ�
			// ������¥�� ���缭 ����
			arr[day] = score;
		}

		else {
			// �׳� �ٸ� ������ �ִٸ�
			while (day >= 1) {
				if (arr[day] == 0) {
					arr[day] = score;
					break;
					// �Ϸ羿 �ٿ����鼭 ����
				}
				day--;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 1001; i++) {
		result += arr[i];
	}

	cout << result;
}