#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;


//54. 转换字符串到整数
//您的提交打败了 100.00% 的提交!
int atoi(string &str) {
	// write your code here
	if (str.size() <= 0){
		return 0;
	}
	//去掉空格
	//由于字符串中间有空格的是非法输入，所以空格只可能出现在字符串首部
    //遇到的空格都直接跳过
	int i = 0;
	while (str[i] == ' '){
		i++;  //去掉头部的空格
	}
	int sum = 0;
	int len = str.size();
	bool flag = true;
	if (i < len){
		if (str[i] == '-')
		{
			flag = false;  //处理负数
			i++;
		}
		else if (str[i] == '+')
		{
			i++;   //处理有+号的字符串
		}
	}
	while (i < len){
		if (str[i] < '0' || str[i] > '9')//一旦有非数字字符出现退出循环。
		{
			break;
		}
		//先判断不会溢出再来累加,两种溢出情况。
		//INT_MAX:214783647
		if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
		{
			return flag ? INT_MAX : INT_MIN;
		}
		sum = sum * 10 + (str[i] - '0');
		i++;
	}
	return flag ? sum : -sum;
}

int main({
	string str = "2147483648";
	int res = atoi(str);
	cout << res << endl;
	system("pause");
	return 1;
}