#include<iostream>
#include<algorithm>

using namespace std;

//����Ǹ�λ�ֽڴ洢�ڵ͵�ַ��
//С���ǵ�λ�ֽڴ洢�ڵ͵�ַ
//�����ֽ��Ǵ�˵ģ�Ҳ���Ǹ�λ�ֽ��ȴ���

//��һ���жϷ�ʽ
int main()
{
	int a = 0x1234;
	char c = static_cast<char>(a);
	if (c == 0x12)
	{
		cout << "big endian" << endl;
	}
	else if (c == 0x34)
	{
		cout << "little endian" << endl;
	}
}

//�ڶ����жϷ�ʽ
//����union�ķ�ʽ�������ж�
union endian
{
	int a;
	char ch;
};

int main()
{
	endian value;
	value.a = 0x1234;
	if (value.ch == 0x12)
	{
		cout << "big endian" << endl;
	}
	else if (value.ch == 0x34)
	{
		cout << "little endian" << endl;
	}
}

//endian�е�ch��Ӧ����endian�ĵ͵�ַ�Σ�����һ�ε����ݵ���0x34��
//����������0x1234�еĵ�λ�ֽڣ�˵����λ�ֽ��ȴ洢��˵����С����
//��֮��ch=0x12˵����λ�ֽ��ȴ洢��˵���Ǵ����