#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
适配模式：
  将写好的接口改写成自己使用的接口
*/

//比如这里是打印两个的函数，而for_each只有一个打印参数
struct Print {

	void operator()(int i,int j) {
		cout << i+j << endl;
	}
};

//处理方法：适配器
class MyPrint {
public:

	virtual void operator()(int i) = 0;  //   1.首先将本来对的写成虚函数
};

class shipeiqi : public MyPrint {
public:
	shipeiqi(int i) {
		this->mNUM = i;
	}
	virtual void operator()(int i) {
		mPrint(i, mNUM);
	}
public:
	Print mPrint;//实体                         2.再把我们目标的实体写进来
	int mNUM;
};
//

//下面改写可变适配上面这些是增加的
/*
shipeiqi(int i) {
		this->mNUM = i;
	}
	int mNUM;
*/
shipeiqi test2(int i) {
	return shipeiqi(i);
}

void test() {
	vector<int> a;
	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}
	for_each(a.begin(), a.end(), test2(10));

}

int main() {

	test();
	system("pause");
	return 0;
}