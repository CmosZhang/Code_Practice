#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


//1373. �ɻ��Ͽ���Ӱ
//����֮�͵ı���
//������Ȼ��������ָ��
//�����ύ����� 96.88% ���ύ! �����Ŀ�Ĳ��԰�����Ҳ�����������Ĳ��԰����ж����
//����Ϊ12,27����ϵ�Ӱ��ʱ��Ϊ426������Ϊ0,32����ϵ�Ӱ��ʱ��ҲΪ426��
struct Node {
	int time;
	int index;
};

static bool NodeCompare(Node &a, Node &b) {
	return a.time < b.time;
}


vector<int> FlightDetails(vector<int> &arr, int k) {
	// write your code here
	if (arr.empty()) {
		return arr;
	}
	vector<int> res;
	int len = arr.size();
	vector<Node> movie(len);
	for (int i = 0; i < len; i++) {
		movie[i].time = arr[i];
		movie[i].index = i;
	}
	sort(movie.begin(), movie.end(), NodeCompare);
	int start = 0;
	int end = len - 1;
	int sum = k - 30;
	int first = 0;
	int second = 0;
	int maxMovie = 0;
	while (start < end) {
		int temp = movie[start].time + movie[end].time;
		if (temp > sum) {
			end--;
		}
		else {
			if (maxMovie < temp) {//û�еȺţ����Ϊ12,27���еȺŽ��Ϊ0,32
				maxMovie = temp;
				first = movie[start].index;
				second = movie[end].index;
			}
			start++;
		}
	}
	res.push_back(min(first, second));
	res.push_back(max(first, second));
	return res;
}

int main() {
	vector<int> arr = { 183, 117, 452, 296, 229, 21, 331, 498, 481, 429, 387, 155, 359, 370, 209, 245, 106, 164, 312, 325, 444, 81, 31, 151, 411, 107, 192, 67, 341, 139, 372, 483, 243, 468 };
	int k = 457;
	vector<int> res = FlightDetails(arr, k);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 1;
}