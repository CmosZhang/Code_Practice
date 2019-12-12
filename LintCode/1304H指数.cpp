#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

//1304. Hָ��
//�����ύ����� 71.65% ���ύ!
//���ַ�����������򵥵ķ���
int hIndex(vector<int> &citations) {
	// write your code here
	if (citations.empty()) {
		return 0;
	}
	int res = 0;
	int maxCit = citations[0];
	for (int i = 1; i < citations.size(); i++) {
		maxCit = max(citations[i], maxCit);
	}
	for (int i = maxCit; i >= 0; i--) {
		int count = 0;
		for (int j = 0; j < citations.size(); j++) {
			if (citations[j] >= i) {
				count++;
			}
		}
		if (count >= i) {
			res = max(i, res);//�ҵ����ľ��˳�
			break;
		}
	}
	return res;
}

//���ϵ������
//���ú�׺�͵���ʽ����
//��������±�i��Ӧ������ʾ���ڵ���i�����ֳ��ֵĴ���������������O(n)���
//Ȼ��Ӵ�Сö����Щ�����ҵ���������������������
//ʱ�临�Ӷ�ΪO(n)
int hIndex2(vector<int>& citations) {
	int n = citations.size();
	vector<int> num(n + 1, 0);//��һ��Сϸ�ڣ�ֻ��Nƪ���£�
	//*�����������ֵΪ6������Ϊ4,����ȥ����������6ƪ��������Ϊ6����Ϊ�������������

	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] >= n) {
			num[n] ++;//����Ƕ�*���Ĵ���չʾ
		}
		else {
			num[citations[i]] ++;
		}
	}
	int sum = 0;
	for (int i = n; i >= 0; i--) {
		sum += num[i];
		if (sum >= i)
			return i;
	}
	return 0;
}



int main() {
	vector<int> cit = { 3,0,6,1,5};
	cout << hIndex2(cit) << endl;
	system("pause");
	return 0;
}