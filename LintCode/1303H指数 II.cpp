#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

//1303. Hָ�� II 
//�����Ŀ�У�citations���Ź����
//��򵥵ķ��������ú�׺�͵ķ�ʽ����ϸ��������1304 Hָ�������Ŀ���н��
int hIndex(vector<int> &citations) {
	// write your code here
	if (citations.empty()) {
		return 0;
	}
	int res = 0;
	int maxCit = citations[citations.size() - 1];
	for (int i = maxCit; i >= 0; i--) {
		int count = 0;
		for (int j = 0; j < citations.size(); j++) {
			if (citations[j] >= i) {
				count++;
			}
		}
		if (count >= i) {
			res = max(i, res);
			break;
		}
	}
	return res;
}

int main() {
	vector<int> cit = { 0,1,3,5,6 };
	cout << hIndex(cit) << endl;
	system("pause");
	return 0;
}