#include <iostream>
#include <queue>

using namespace std;
int n, m;
long long int result = 0;

int main() {
	priority_queue<long long int, vector<long long int>, greater<long long int>> q;
	// �켱���� ť(���� ���� ���)
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push(a);
	}

	for (int i = 0; i < m; i++) {
		long long int x = q.top();
		q.pop();
		long long int y = q.top();
		q.pop();
		// ���� �� �ΰ� ���ϰ� �ΰ� �־��ֱ�
		q.push(x + y);
		q.push(x + y);
	}

	while (!q.empty()) {
		long long int num = q.top();
		result += num;
		q.pop();
	}

	cout << result;
}