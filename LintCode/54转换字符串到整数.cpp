#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;


//54. ת���ַ���������
//�����ύ����� 100.00% ���ύ!
int atoi(string &str) {
	// write your code here
	if (str.size() <= 0){
		return 0;
	}
	//ȥ���ո�
	//�����ַ����м��пո���ǷǷ����룬���Կո�ֻ���ܳ������ַ����ײ�
    //�����Ŀո�ֱ������
	int i = 0;
	while (str[i] == ' '){
		i++;  //ȥ��ͷ���Ŀո�
	}
	int sum = 0;
	int len = str.size();
	bool flag = true;
	if (i < len){
		if (str[i] == '-')
		{
			flag = false;  //������
			i++;
		}
		else if (str[i] == '+')
		{
			i++;   //������+�ŵ��ַ���
		}
	}
	while (i < len){
		if (str[i] < '0' || str[i] > '9')//һ���з������ַ������˳�ѭ����
		{
			break;
		}
		//���жϲ�����������ۼ�,������������
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