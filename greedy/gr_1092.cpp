#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
int n, m;
vector<int> arr;
vector<int> crain;
int visited[10001];
int check[21];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end(), greater<int>());
	// �������� ����

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		crain.push_back(a);
	}

	sort(crain.begin(), crain.end(), greater<int>());
	// �������� ����

	if (arr[0] < crain[0]) {
		// ���� ���ſ�� ũ���� ���� ũ��
		cout << -1;
		return 0;
	}

	int score = 0;

	while (!crain.empty()) {
		// ���ſ� �� ���� ���ʴ�� ũ���ο� ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < crain.size(); j++) {
				if (arr[i] >= crain[j]) {
					crain.erase(crain.begin() + j);
					break;
				}
			}
		}
		// ũ���� 3���� �� ����ϸ� score++;
		score++;
	}

	cout << score;
}