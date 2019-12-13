#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//1297. ���Լ�С��Ԫ�ظ���
//�������뵽���Ǳ�����ⷽ��
//ʱ�临�Ӷ�ΪO(n^2)������ʱ�ᳬʱ
//ͨ��91%������
vector<int> countSmaller(vector<int> &nums) {
	// write your code here
	if (nums.empty()) {
		return nums;
	}
	int n = nums.size();
	vector<int> res(n, 0);
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = i + 1; j < n; j++) {
			if (nums[j] < nums[i]) {
				count++;
			}
		}
		res[i] = count;
	}
	return res;
}


//�ڶ��ַ���
//ʹ�ü��仯����ķ�ʽ����
//�����ύ����� 98.83% ���ύ!
const int MAXN = 100007;
int cnt[MAXN], n;

struct Node {
	int num;
	int index;
};

static bool Compare(Node &a, Node &b) {
	return a.num < b.num;
}

inline void add(int k){
	for (; k <= n; k += -k & k) cnt[k] += 1;
}

int sum(int k){
	int res = 0;
	for (; k; k -= -k & k) res += cnt[k];
	return res;
}

//���´����е�С����
//vector<int> countSmaller2(vector<int> &nums) {
//	 write your code here
//	if (nums.empty()) {
//		return nums;
//	}
//	int n = nums.size();
//	vector<int> res(n);
//	vector<Node> A(n);
//	/*����һ�����������ݵ�δ����ǰ������ӳ��A*/
//	for (int i = 0; i < n; i++) {
//		A[i].num = nums[i];
//		A[i].index = i + 1;
//	}
//	memset(cnt, 0, sizeof(cnt));
//	sort(A.begin(), A.end(), Compare);//ʹ�ÿ���˼��
//
//	for (int i = 0; i < n; i++) {
//		int idx = A[i].index;
//		int t = sum(n) - sum(idx);
//		res[idx - 1] = t;
//		add(idx);
//	}
//	return res;
//}

vector<int> countSmaller2(vector<int>& nums) {
	n = nums.size();
	vector<int> ans(n, 0);
	vector<pair<int, int>> A;
	/*����һ�����������ݵ�δ����ǰ������ӳ��A*/
	for (int i = 0; i < n; i++) {
		A.push_back({ nums[i], i + 1 });
	}
	memset(cnt, 0, sizeof(cnt));
	sort(A.begin(), A.end());
	/*��������*/
	for (int i = 0; i < n; i++) {
		int id = A[i].second;
		int t = sum(n) - sum(id);
		ans[id - 1] = t;
		add(id);
	}
	return ans;
}


//��3�ַ���
//ʹ�����ǿ���ÿ�����Ƕ�Ҫ��ĩβ������ͬ��Ԫ�أ�ʵ�������ǿ��Խ���һ���������������sorted_num��
//������������nums[i]֮�����е����������Ѿ��ź���
//ÿ����nums��������µ���Ҫ�жϵ�����Ҫ���뵽���sorted_num��
//Ȼ���������ͨ�����ֲ��ҵ��½�(������STL�Դ���lower_bound()) ��ȥsorted_num.begin()���Ǳ�nums[i]С��Ԫ�ظ����ˡ�
//�����ύ����� 42.80% ���ύ!
//vector<int> countSmaller3(vector<int>& nums) {
//	vector<int> sorted_num;
//	/*����һ���������������*/
//	vector<int> res;
//	/*���ڱ�����������*/
//	for (int i = nums.size() - 1; i >= 0; i--) {
//		auto iter = lower_bound(sorted_num.begin(), sorted_num.end(), nums[i]);
//		/*ͨ��lower_bound()����Ѱ���½磬����һ��������(Ҳ���������sorted_num��index)*/
//		int pos = iter - sorted_num.begin();
//		/*
//		ͨ����������Ķ��ֲ������ʣ����ǿ���֪��iter-sorted_num.begin()(��������sorted_num�������ʼλ��)����
//		��Ŀ��Ҫ�ı�nums[i]С�����ָ���
//		*/
//		sorted_num.insert(iter, nums[i]);
//		/*��ʱnums[i]�Ѿ�ʹ�����ˣ���Ҫ���Ժ�����������ж�
//		�����Ҫ����sorted_num��������nums[i]���뵽iterλ��*/
//		res.push_back(pos);
//	}
//	reverse(res.begin(), res.end());
//	/*һ·�϶��ǵ������ģ����������Ҫ��ת����*/
//	return res;
//}

vector<int> countSmaller3(vector<int>& nums) {
	vector<int>t, res(nums.size());
	/*��ʼ��t,res*/
	for (int i = nums.size() - 1; i >= 0; i--) {
		int left = 0, right = t.size();
		/*������һ����t��������ֲ��ҵĹ���*/
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (t[mid] >= nums[i]) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		res[i] = right;
		t.insert(t.begin() + right, nums[i]);
	}
	return res;
}


int main() {
	vector<int> nums = { 5,2,6,1 };
	vector<int> res = countSmaller2(nums);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}