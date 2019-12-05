#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//����һ��������һЩ���ֵ����飬��һ��Ŀ��ֵ������������ȡ�������У�
//ʹ�����е����ֵĺ͵���target�����ж��������з����������������ظ�ȡ�����ġ�
//�����������[1, 2, 4]��targetֵ4����ô�ܵõ����µ���ϡ��ܹ���6�֣��򷵻�6.


int backPackVI(vector<int>&nums, int target) {
	vector<int> dp(target + 1);
	dp[0] = 1;
	for (int i = 1; i <= target; i++) {
		for (auto num : nums) {
			if (i >= num) {
				dp[i] += dp[i - num];
			}
		}
	}
	return dp[target];
}