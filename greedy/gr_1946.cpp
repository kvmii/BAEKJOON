#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int T, n;
int result;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;

		vector<pair<int, int>> vec;

		for (int j = 0; j < n; j++) {
			int a, b;
			cin >> a >> b;
			vec.push_back(make_pair(a, b));
		}

		sort(vec.begin(), vec.end());
		result = 1;
		int ranking = vec[0].second;

		for (int k = 1; k < n; k++) {
			if (vec[k].second < ranking) {
				result++;
				ranking = vec[k].second;
			}
		}
		cout << result << endl;
	}

	return 0;
	// �ð��ʰ��� �߻��ߴ� ����
	// ó������ ������ �� �ϳ��� �� -> �ð��ʰ�
	// ���� ���� ����� ������ ���� �װź��ٸ� ������ �߰��ϴ� ������ ���� -> �ð��ʰ� �ذ�
}