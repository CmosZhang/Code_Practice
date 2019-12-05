#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


//685. 数据流中第一个唯一的数
//您的提交打败了 1.60% 的提交!
//设计一个链表以此来统计在终止数字之前，每个数字出现的次数
class listnode {
public:
	int val;
	int count;
	listnode *next;
	listnode(int val, int count) {
		this->val = val;
		this->count = count;
		this->next = NULL;
	}
};

int firstUniqueNumber(vector<int> &nums, int number) {
	// Write your code here
	if (nums.empty()) {
		return -1;
	}
	listnode *head = new listnode(-1, 1);
	bool Number_ex = false;
	int index = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == number) {
			index = i;
			Number_ex = true;
			break;
		}
	}
	if (Number_ex) {
		for (int i = 0; i <= index; i++) {
		bool no_flag = true;
		listnode *p = head;
		listnode *q = head->next;
			while (p != NULL && q != NULL) {
				if (q->val == nums[i]) {
					q->count++;
					no_flag = false;
					break;
				}
				p = q;
				q = q->next;
			}
			if (no_flag) {
				q = new listnode(nums[i], 1);
				p->next = q;
			}
		}
		while (head->next != NULL) {
			if (head->next->count == 1) {
				return head->next->val;
			}
			head = head->next;
		}
	}
	return -1;
}


int main() {
	vector<int> nums = { 1,2,2,1,2,4,4,5,6,5,7,6,8 };
	int number = 8;
	cout << firstUniqueNumber(nums, number) << endl;
	system("pause");
	return 1;
}