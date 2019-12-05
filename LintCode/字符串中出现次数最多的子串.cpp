#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//使用后缀数组，后缀数组是一种数据结构，对于一个字符串生成相应的后缀数组后
//然后再排序，排完序后依次检测相邻的两个字符串的开头公共部分
//时间复杂度为O(N^2*logN).
pair<int, string> fun(string str) {
	int len = str.size();
	//构建后缀数组，每一行比上一行少一个
	vector<string> subs(len);
	for (int i = 0; i < len; i++) {
		subs[i] = str.substr(i, len - i);
		cout << subs[i] << endl;
	}

	int maxSub = 0;
	string res;
	//第一趟：第一行a与第二行第一个b比较是否相等，不等 
	//（若相等则继续在第二行后取长度为1的子串比较，碰到不等为止）则
	//（两个长度的子串）第一行ab与第三行首位两个ab比较，相等，
	//继续在第三行取长度为2的子串比较，碰到c不够终止。。
	//(三个长度的子串)以此类推
	//第二趟：从第二行的开始与第三行作比较
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
				//比较最大连续出现次数，并记录相应的子串
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