#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
/*
代理案例：
1.已经写好的接口或者系统
2.将上面的接口或者系统要用的方法提取出来，写一个抽象类，让上面的接口继承这个类
3.写一个代理函数，同样继承上述抽象的类，里面包含同样的方法
4.将1封装在代理函数里
*/

//我需要用MySystem的run()函数，所以抽象出来,所以MySystem面要继承我
class AbstractMySystem {
public:
	virtual void run() = 0;

};
//已经写好的
class MySystem : public AbstractMySystem {
public:
	virtual void run() {
		cout << "系统正在运行" << endl;
	}
};


//代理类，同样要继承我，然后把1封装在我的成员里
//这里代理的原因我是要输入密码账号才能登入
//同样有共同的virtual函数
class daili : public AbstractMySystem {
public:
	daili(string name, string passward) {
		this->mName = name;
		this->mPassward = passward;
		pmysystem = new MySystem;
	};
	daili() {};
	//判断是否正确
	bool panduan() {
		if (this->mName == "liyi" && this->mPassward == "123") {
			cout << "验证通过！" << endl;
			return true;

		}
		return false;
		
	}
	virtual void run() {
		if (panduan()) {
		
			pmysystem->run();
		}
		else
			cout << "用户名或者密码错误！" << endl;
	
	}
	~daili() {        //有new,且不是返回的
		if (pmysystem != NULL)
			delete pmysystem;
	}

public:
	MySystem* pmysystem;
	string mName;
	string mPassward;
};


void test() {
	//daili* d = new daili;
	daili* d = new daili("liyi","123");
	d->run();
	delete d;

}

int main() {

	test();
	system("pause");
	return 0;
}