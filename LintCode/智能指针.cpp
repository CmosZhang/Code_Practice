#include <iostream>
#include <memory>

using namespace std;

//int main() 
//{
//	int a = 10;
//	shared_ptr<int> ptra = make_shared<int>(a);//引用计数加1 
//	shared_ptr<int> ptra2(ptra); //copy//引用计数再加1
//	cout << ptra.use_count() << endl;//输出2
//
//	int b = 20;
//	int *pb = &a;
//	//std::shared_ptr<int> ptrb = pb;  //error
//	shared_ptr<int> ptrb = std::make_shared<int>(b);//ptrb的引用计数加1.
//	ptra2 = ptrb; //assign//ptrb的引用计数加1，ptra的引用计数减1
//	pb = ptrb.get(); //获取原始指针
//
//	cout << ptra.use_count() << endl;//输出1
//	cout << ptrb.use_count() << endl;//输出2
//
//	system("pause");
//	return 0;
//}

//unique_ptr指针的例子
//int main() {
//	{
//		unique_ptr<int> uptr(new int(10));  //绑定动态对象
//		//unique_ptr<int> uptr2 = uptr;  //不能賦值
//		//unique_ptr<int> uptr2(uptr);  //不能拷貝
//		unique_ptr<int> uptr2 = move(uptr); //轉換所有權
//		uptr2.release(); //释放所有权
//	}
//	//超過uptr的作用域，內存釋放
//}


//weak_ptr指针的例子
int main() {
	{
		shared_ptr<int> sh_ptr = std::make_shared<int>(10); //sh_ptr引用计数加1
		cout << sh_ptr.use_count() << endl;//输出1

		weak_ptr<int> wp(sh_ptr);//weak_ptr获取了sh_ptr资源，监视他，不会引起sh_ptr引用计数的增加
		cout << wp.use_count() << endl;//输出1

		if (!wp.expired()) {//如果引用计数不为0
			shared_ptr<int> sh_ptr2 = wp.lock(); //get another shared_ptr
			*sh_ptr = 100;//导致sh_ptr引用计数加1
			cout << wp.use_count() << endl;//输出2
		}
	}
	//delete memory
	system("pause");
}