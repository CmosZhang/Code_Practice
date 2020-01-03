#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//1040. ���ֿ����� II
//���ϵ����㷽��
//�����ύ����� 77.66% ���ύ!
int maxChunksToSorted(vector<int> &arr) {
	// write your code here
	if (arr.empty()) {
		return -1;
	}
	int len = arr.size();
	vector<int> maxOfLeft(len);
	vector<int> minOfRight(len);

	maxOfLeft[0] = arr[0];
	for (int i = 1; i < len; i++) {
		maxOfLeft[i] = max(maxOfLeft[i - 1], arr[i]);
	}

	minOfRight[len - 1] = arr[len - 1];
	for (int i = len - 2; i >= 0; i--) {
		minOfRight[i] = min(minOfRight[i + 1], arr[i]);
	}

	int res = 0;
	for (int i = 0; i < len - 1; i++) {
		if (maxOfLeft[i] <= minOfRight[i + 1])
			res++;
	}
	return res + 1;
}

//����ʹ�õ���ջ����������������ģ��������� arr={1,3,2,5,4,4,7,6,6,8}

//��������
//˼·������ջ������������ջ�����Ǳ��浱ǰ���������������������һ����ջ��С��Ԫ�أ����¼ջ��Ԫ�أ�
//��ջ��С�ڸ�Ԫ�ص�ֵȫ����������ζ����ЩֵӦ�÷ֵ�һ��������ȥ��
//��󽫼�¼��ջ��ֵ����ѹ��ջ�У�����ǰ���е����ֵ
//�����ύ����� 77.66% ���ύ!
//����������Ⱑ
//int maxChunksToSorted2(vector<int> &arr) {
//	if (arr.empty()) {
//		return -1;
//	}
//	int len = arr.size();
//	stack<int> stk;
//	stk.push(arr[0]);
//	for (int i = 1; i < len; i++) {
//		if (arr[i] >= stk.top()) {
//			stk.push(arr[i]);
//		}
//		else {
//			int temp = stk.top();
//			stk.pop();
//			while (!stk.empty() && stk.top() < temp) {
//				stk.pop();
//			}
//			stk.push(temp);
//		}
//	}
//	return stk.size();
//}

////ͨ��40%������
//int maxChunksToSorted3(vector<int> &arr) {
//	// write your code here
//	if (arr.empty()) {
//		return -1;
//	}
//	int len = arr.size();
//	stack<int> stk;
//	stack<int> help;
//	stk.push(arr[0]);
//	for (int i = 1; i < len; i++) {
//		if (arr[i] > stk.top()) {
//			stk.push(arr[i]);
//		}
//		else {
//			int temp = stk.top();
//			stk.pop();
//			while (!stk.empty()) {
//				help.push(stk.top());
//				stk.pop();
//			}
//			while (!help.empty()) {
//				if (help.top() >= temp) {
//					stk.push(help.top());
//				}
//				help.pop();
//			}
//			stk.push(temp);
//		}
//	}
//	return stk.size();
//}



int main() {
	vector<int> num;
	while (1) {
		int temp;
		cin >> temp;
		num.push_back(temp);
		char c;
		c = getchar();
		if (c == '\n') {
			break;
		}
	}
	cout << maxChunksToSorted(num) << endl;
	system("pause");
	return 0;
}