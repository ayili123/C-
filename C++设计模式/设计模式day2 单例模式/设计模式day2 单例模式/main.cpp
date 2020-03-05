#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*
单例：只能创建一个这样的类有----懒汉式(先判断在创建)---饿汉式(先于main函数创建)
遇到多线程时用饿汉式，懒汉式不安全，懒汉式就不是真的单例了
步骤：
1.将构造函数私有化
2.增加静态私有的当前类的指针变量
3.增加静态对外接口，可以让用户获得单例对象  static      可以这样::
*/

class A {
private:
	A() {
		pA = new A;
	}
public://返回单例
	static A* getA() {//这里返回A*   *************  static:私有构造这样可以::外部函数调用调用
		return pA;            //静态成员函数可以通过类名调用

	}
private:
	static A* pA;
};
A* A::pA = NULL;

//懒汉式

class Singleton_lazy {
private:
	Singleton_lazy() {
	}
public:
	static Singleton_lazy* getInstance() {
		if (pSingleton_lazy == NULL)
		{
			pSingleton_lazy = new  Singleton_lazy;//***********不是return
		}
		return NULL;
	}
private:
	static Singleton_lazy* pSingleton_lazy;
};

Singleton_lazy* Singleton_lazy::pSingleton_lazy = NULL;

//饿汉式
class Singleton_hangry {
private:
	Singleton_hangry() {
	}
public:
	static Singleton_hangry* getInstance() {
	
			return pSingleton_hangry;
	
	}
private:
	static Singleton_hangry* pSingleton_hangry;
};

Singleton_hangry* Singleton_hangry::pSingleton_hangry = new Singleton_hangry;

void test() {
	Singleton_lazy* p1 = Singleton_lazy::getInstance();
	Singleton_lazy* p2 = Singleton_lazy::getInstance();
	if (p1 == p2) {
		cout << "是单例" << endl;
	}
	else
		cout << "不是单例" << endl;
	cout << "_______________"<<endl;
	Singleton_hangry* p3 = Singleton_hangry::getInstance();
	Singleton_hangry* p4 = Singleton_hangry::getInstance();
	if (p3 == p4) {
		cout << "是单例" << endl;
	}
	else
		cout << "不是单例" << endl;


}

int main() {

	test();
	system("pause");
	return 0;
}