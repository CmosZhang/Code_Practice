#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//1312. ����1�ĸ���
//�����ύ����� 46.27% ���ύ!
int countDigitOne(int n) {
	// write your code here
	if (n <= 0) {
		return 0;
	}

	int res = 0;
	int factor = 1;
	int lower = 0;
	int cur = 0;
	int higher = 0;

	while ((n / factor )!= 0) {
		lower = n - (n / factor)*factor;
		cur = (n / factor) % 10;
		higher = n / (factor * 10);

		switch (cur) {
		case 0:
			res += higher * factor;
			break;
		case 1:
			res += higher * factor + lower + 1;
			break;
		default:
			res += (higher + 1)*factor;
			break;
		}
		factor *= 10;
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	cout << countDigitOne(n) << endl;
	system("pause");
	return 0;
}