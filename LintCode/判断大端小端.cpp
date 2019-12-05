#include<iostream>
#include<algorithm>

using namespace std;

//大端是高位字节存储在低地址，
//小端是低位字节存储在低地址
//网络字节是大端的，也就是高位字节先传输

//第一种判断方式
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

//第二种判断方式
//利用union的方式来进行判断
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

//endian中的ch对应整个endian的低地址段，若这一段的内容等于0x34，
//即等于整数0x1234中的低位字节，说明低位字节先存储，说明是小端序。
//反之若ch=0x12说明高位字节先存储，说明是大端序