#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> vec;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a, b });
	}

	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	// ���� �Ⱓ�� ū ������ ����

	int score = 0;
	int index = 0;

	priority_queue<int> q;
	for (int i = n; i > 0; i--) {
		for (int j = index; j < n; j++) {
			if (vec[j].first != i) {
				index = j;
				break;
			}
			q.push(vec[j].second);
		}
		if (!q.empty()) {
			score += q.top();
			q.pop();
		}
	}

	cout << score;
}