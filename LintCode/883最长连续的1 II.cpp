#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


//883. �������1 II
//�����ύ����� 100.00% ���ύ!
//���ⲻ����򵥵ķ���
//ʱ�临�Ӷ�ΪO(n^2)
int findMaxConsecutiveOnes(vector<int> &nums) {
	// write your code here
	if (nums.empty()) {
		return 0;
	}
	int res = 0;
	int count = 0;//ͳ��0֮ǰ����1�ĸ���
	int temp = 0;//ͳ��0֮�����1�ĸ���
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 1) {
			count++;
		}
		else {
			temp = 0;
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[j] == 0) {
					break;
				}
				else {
					temp++;
				}
			}
			res = max(count + temp + 1, res);
			count = 0;
		}
		if (i == nums.size() - 1) {
			res = max(res, count);
		}
	}
	return res;
}

//���ϵ������
//ʹ�ö�̬�滮��˼������
int findMaxConsecutiveOnes2(vector<int> &nums) {
	// write your code here
	if (nums.empty()) {
		return 0;
	}
	int res = 0;
	int countZero = 0;//������ת0����1�ĳ���
	int countNotZero = 0;//��������ת0����1�ĳ���
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 1) {
			countNotZero++;
			countZero++;
		}
		else {
			countZero = countNotZero + 1;
			countNotZero = 0;
		}
		res = max(res, max(countNotZero, countZero));
	}
	return res;
}


int main() {
	vector<int> nums;
	char c;
	int temp;
	while (1) {
		cin >> temp;
		nums.push_back(temp);
		c = getchar();
		if (c == '\n') {
			break;
		}
	}
	cout << findMaxConsecutiveOnes2(nums) << endl;
	system("pause");
	return 0;
}