#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//ʹ�ú�׺���飬��׺������һ�����ݽṹ������һ���ַ���������Ӧ�ĺ�׺�����
//Ȼ������������������μ�����ڵ������ַ����Ŀ�ͷ��������
//ʱ�临�Ӷ�ΪO(N^2*logN).
pair<int, string> fun(string str) {
	int len = str.size();
	//������׺���飬ÿһ�б���һ����һ��
	vector<string> subs(len);
	for (int i = 0; i < len; i++) {
		subs[i] = str.substr(i, len - i);
		cout << subs[i] << endl;
	}

	int maxSub = 0;
	string res;
	//��һ�ˣ���һ��a��ڶ��е�һ��b�Ƚ��Ƿ���ȣ����� 
	//�������������ڵڶ��к�ȡ����Ϊ1���Ӵ��Ƚϣ���������Ϊֹ����
	//���������ȵ��Ӵ�����һ��ab���������λ����ab�Ƚϣ���ȣ�
	//�����ڵ�����ȡ����Ϊ2���Ӵ��Ƚϣ�����c������ֹ����
	//(�������ȵ��Ӵ�)�Դ�����
	//�ڶ��ˣ��ӵڶ��еĿ�ʼ����������Ƚ�
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			int cnt = 1;
			if (subs[i].substr(0, j - i) == subs[j].substr(0, j - i)) {
				cnt++;
				for (int k = j + (j - i); k < len; k += j - i) {
					if (subs[i].substr(0, j - i) == subs[k].substr(0, j - i)){
						cnt++;
					}
					else {
						break;
					}
				}
				//�Ƚ�����������ִ���������¼��Ӧ���Ӵ�
				if (cnt > maxSub) {
					maxSub = cnt;
					res = subs[i].substr(0, j - i);
				}
			}
		}
	}
	return make_pair(maxSub, res);
}


int main() {
	string str;
	cin >> str;
	pair<int, string> res = fun(str);
	cout << res.first << endl;
	cout << res.second << endl;
	system("pause");
	return 0;
}