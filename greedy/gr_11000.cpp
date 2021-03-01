#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int visited[200001];
int result = 0;
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<int>> pq;



int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}

	sort(vec.begin(), vec.end());
	// ���۽ð� ������ ����
	pq.push(vec[0].second);

	for (int i = 1; i < n; i++) {
		if (pq.top() <= vec[i].first) pq.pop();
		// ���� ���� ������ �ͺ��� �ڿ� �����ϸ�
		// ���� ���� ������ �� pop
		pq.push(vec[i].second);
		// ������ �ð� push
	}
	
	cout << pq.size();
}