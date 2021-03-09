#include <iostream>
#include <vector>

using namespace std;
vector<int> arr;

void print(int x, int y) {
	if (x > y) return; 

	int root = arr[x];
	int cnt = y;
	while (arr[cnt] > root) cnt--;
	// ������ �ڽ� ã��

	print(x + 1, cnt);
	// ���ʿ��� �ٽ�
	print(cnt + 1, y);
	// �����ʿ��� �ٽ�

	cout << root << endl;
}

int main() {
	int a;
	while (cin >> a) {
		arr.push_back(a);
		// �Է� �ޱ�
	}

	print(0, arr.size() - 1);
	return 0;
}