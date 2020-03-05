#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
模板方法模式：泡茶、泡咖啡 都是煮水、冲泡、加料
即就是有共同方法的函数可以将他们共同的方法抽出来写成虚函数，然后集成一个共同方法的接口
具体细节放在各个子类里
*/

class Make {
public:
	//抽象出来共同方法
	//煮水
	virtual void BotWarter() = 0;
	//冲泡
	virtual void Makefood() = 0;
	//加料
	virtual void PutSomething() = 0;
	//封装步骤相同的一个函数
	void make() {
		this->BotWarter();
		this->Makefood();
		this->PutSomething();
	}
};
//具体细节Tea
class Tea :public Make {
	//煮水
	virtual void BotWarter() {
		cout << "Tea用自来水..." << endl;
	}
	//冲泡
	virtual void Makefood() {
		cout << "Tea用竹叶青..." << endl;
	}
	//加料
	virtual void PutSomething() {
		cout << "Tea加牛奶..." << endl;
	}
};
//具体细节Coffee
class Coffee :public Make {
	//煮水
	virtual void BotWarter() {
		cout << "Coffee用纯净水..." << endl;
	}
	//冲泡
	virtual void Makefood() {
		cout << "Coffee用拿铁..." << endl;
	}
	//加料
	virtual void PutSomething() {
		cout << "Coffee加糖..." << endl;
	}
};

void test() {
	//父类指针指向子类对象 子类指针也可以指向子类对象  多态
	Make* tea = new Tea;
	Coffee* coffee = new Coffee;
	tea->make();
	coffee->make();
	delete coffee;
	delete tea;

}

int main() {

	test();
	system("pause");
	return 0;
}