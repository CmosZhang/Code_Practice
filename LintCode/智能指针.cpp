#include <iostream>
#include <memory>

using namespace std;

//int main() 
//{
//	int a = 10;
//	shared_ptr<int> ptra = make_shared<int>(a);//���ü�����1 
//	shared_ptr<int> ptra2(ptra); //copy//���ü����ټ�1
//	cout << ptra.use_count() << endl;//���2
//
//	int b = 20;
//	int *pb = &a;
//	//std::shared_ptr<int> ptrb = pb;  //error
//	shared_ptr<int> ptrb = std::make_shared<int>(b);//ptrb�����ü�����1.
//	ptra2 = ptrb; //assign//ptrb�����ü�����1��ptra�����ü�����1
//	pb = ptrb.get(); //��ȡԭʼָ��
//
//	cout << ptra.use_count() << endl;//���1
//	cout << ptrb.use_count() << endl;//���2
//
//	system("pause");
//	return 0;
//}

//unique_ptrָ�������
//int main() {
//	{
//		unique_ptr<int> uptr(new int(10));  //�󶨶�̬����
//		//unique_ptr<int> uptr2 = uptr;  //�����xֵ
//		//unique_ptr<int> uptr2(uptr);  //���ܿ�ؐ
//		unique_ptr<int> uptr2 = move(uptr); //�D�Q���Й�
//		uptr2.release(); //�ͷ�����Ȩ
//	}
//	//���^uptr�������򣬃ȴ�ጷ�
//}


//weak_ptrָ�������
int main() {
	{
		shared_ptr<int> sh_ptr = std::make_shared<int>(10); //sh_ptr���ü�����1
		cout << sh_ptr.use_count() << endl;//���1

		weak_ptr<int> wp(sh_ptr);//weak_ptr��ȡ��sh_ptr��Դ������������������sh_ptr���ü���������
		cout << wp.use_count() << endl;//���1

		if (!wp.expired()) {//������ü�����Ϊ0
			shared_ptr<int> sh_ptr2 = wp.lock(); //get another shared_ptr
			*sh_ptr = 100;//����sh_ptr���ü�����1
			cout << wp.use_count() << endl;//���2
		}
	}
	//delete memory
	system("pause");
}