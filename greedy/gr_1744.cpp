#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> vec;
vector<int> vec2;
int n;
int result = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	// ū ������ ����

	for (int i = 0; i < vec.size(); i += 2) {
		if (i + 1 == vec.size()) {
			// ũ�Ⱑ Ȧ������ ������ ������ ��
			if (vec[i] > 0)
				// �����
				result += vec[i];
			else vec2.push_back(vec[i]);
			// ������
			break;
		}

		if (vec[i] > 0 && vec[i + 1] > 0) {
			result += max(vec[i] * vec[i + 1], vec[i] + vec[i + 1]);
			// �Ѵ� ����� �ΰ��� ��� ���ϱ�
		}

		if (vec[i + 1] <= 0) {
			// �� ��° ���� ������ ��
			if (vec[i] <= 0) {
				// �Ѵ� ������ vec2�� �ֱ�
				vec2.push_back(vec[i]);
				vec2.push_back(vec[i + 1]);
			}
			else {
				// ���, ������ ����� �����ְ� ������ vec2��
				result += vec[i];
				vec2.push_back(vec[i + 1]);
			}
		}

	}

	sort(vec2.begin(), vec2.end());

	for (int i = 0; i < vec2.size(); i += 2) {
		if (i + 1 == vec2.size()) {
			result += vec2[i];
			break;
		}

		result += max(vec2[i] * vec2[i + 1], vec2[i] + vec2[i + 1]);
		// �������� ���ϸ� ���
	}

	cout << result;
}