#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, k;
vector<pair<int, int>> vec;
vector<int> bag;
long long result = 0;
priority_queue<int> pq;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}

	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		bag.push_back(a);
	}

	sort(vec.begin(), vec.end());
	sort(bag.begin(), bag.end());

	int cnt = 0;
	for (int i = 0; i < k; i++) {
		while (cnt < n && vec[cnt].first <= bag[i]) {
			// ������ ���Ұ� ���濡 �� �� ������
			pq.push(vec[cnt].second);
			// pq�� �� �� �ִ� ������ ���� ���� ������ ���ĵǱ� ������ ���� ������ k���� ���� �ȴ�
			cnt++;
		}

		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}
	// greedy�� �켱���� ť
	cout << result;
}