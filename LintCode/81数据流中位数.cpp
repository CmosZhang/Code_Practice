#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;

//81. ��������λ��
//�����ύ����� 44.40% ���ύ!
//ʹ�����ȼ�����������һ������һ����С��
priority_queue<int, vector<int>, greater<int>> minheap;
priority_queue<int, vector<int>, less<int>> maxheap;
vector<int> ans;

vector<int> medianII(vector<int> &nums) {
	// write your code here
	if (nums.size() == 0)
		return ans;
	for (int num : nums) {
		maxheap.push(num);
		minheap.push(maxheap.top());
		maxheap.pop();
		if (minheap.size() > maxheap.size()) {
			maxheap.push(minheap.top());
			minheap.pop();
		}
		ans.push_back(maxheap.top());
	}
	return ans;
}