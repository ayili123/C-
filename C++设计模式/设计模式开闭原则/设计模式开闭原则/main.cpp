#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*
开闭原则案例：对扩展开放，对修改关闭。
增加功能是通过增加代码实现不是通过修改源代码
计算器案例
*/
//抽象计算器
class AbstractCaculate {
public:
	virtual int getValue() = 0;
};

//加法
class PlusCaculate : public AbstractCaculate
{
public:
	PlusCaculate(int a,int b) {
		this->mA = a;
		this->mB = b;
	}
	virtual int getValue() {
		return mA + mB;
	}
public:
	int mA;
	int mB;
};

//减法
class MinuteCaculate : public AbstractCaculate
{
public:
	MinuteCaculate(int a, int b){
		this->mA = a;
		this->mB = b;
	}
	virtual int getValue() {
		return mA - mB;
	}
public:
	int mA;
	int mB;
};

//乘法
class MuliplyCaculate : public AbstractCaculate
{
public:
	MuliplyCaculate(int a, int b) {
		this->mA = a;
		this->mB = b;
	}
	virtual int getValue() {
		return mA * mB;
	}
public:
	int mA;
	int mB;
};
//还可以将初始化提出去，init给父类
void test() {
	//父类指针指向子类对象
	AbstractCaculate* c = new PlusCaculate(10,20);//还可以将初始化提出去，init给父类  这样只调用父类指针
	cout << c->getValue() << endl;
	AbstractCaculate* d = new MuliplyCaculate(10, 20);
	cout << d->getValue() << endl;
	delete c;
	delete d; 
}


int main() {

	test();
	return 0;
}