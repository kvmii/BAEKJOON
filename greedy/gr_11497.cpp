#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, n;

// ���Ժ��� ó�� ����� ���� �ٽ�
int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		vector<int> vec;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			vec.push_back(a);
		}

		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		// ū ������ ����

		vector<int> a;
		vector<int> b;
		
		a.push_back(vec[0]);
		b.push_back(vec[0]);
		// ���� ū ���� �Ѵ� push

		for (int i = 1; i < vec.size(); i += 2) {
			a.push_back(vec[i]);
			// �ϳ��� a �ϳ��� b�� push
			if (i == vec.size() - 1) break;
			b.push_back(vec[i + 1]);
		}

		int result = 0;

		for (int i = 0; i < a.size() - 1; i++) {
			if (a[i] - a[i + 1] > result) {
				result = a[i] - a[i + 1];
				// a���� ���� ���� ū�� ������
			}
		}

		for (int i = 0; i < b.size() - 1; i++) {
			if (b[i] - b[i + 1] > result) {
				result = b[i] - b[i + 1];
				// b�� a�� ����������
			}
		}

		cout << result << endl;
	}
}