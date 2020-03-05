#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
抽象工厂只针对产品族，而不是产品结构，
抽象的工厂类是厂商，每个厂商可以有相同的东西，
可以增加多个厂商，而增加业务类型则需要修改代码

*/
//先抽象业务类，不同厂商同一业务,如抽象苹果
class AbstructApple {
public:
	virtual void showname() = 0;
};
//不同厂商相同业务继承
//中国
class ChinaApple : public AbstructApple {
public:
	virtual void showname() {
		cout<<"china apple...."<<endl;
	}
};
//美国
class UsatApple : public AbstructApple {
public:
	virtual void showname() {
		cout << "USA apple...." << endl;
	}
};
//日本
class JapanApple : public AbstructApple {
public:
	virtual void showname() {
		cout << "Japan apple...." << endl;
	}
};

//抽象梨子

class AbstructPear {
public:
	virtual void showname() = 0;
};
//不同厂商相同业务继承
//中国
class ChinaPear : public AbstructPear {
public:
	virtual void showname() {
		cout << "china pear...." << endl;
	}
};
//美国
class UsatPear : public AbstructPear {
public:
	virtual void showname() {
		cout << "USA pear...." << endl;
	}
};
//日本
class Japanpear : public AbstructPear {
public:
	virtual void showname() {
		cout << "Japan pear...." << endl;
	}
};

//抽象工厂
class AbstructFactory {
public:
	virtual AbstructApple* FruitCreatapple() = 0;
	virtual AbstructPear* FruitCreatpear() = 0;
};

//具体工厂 china
class ChinaFactory : public AbstructFactory {
public:
	virtual AbstructApple* FruitCreatapple() {
		return new ChinaApple;
	}
	virtual AbstructPear* FruitCreatpear() {
		return new ChinaPear;
	}
};

//具体工厂 USA
class USAFactory : public AbstructFactory {
public:
	virtual AbstructApple* FruitCreatapple() {
		return new UsatApple;
	}
	virtual AbstructPear* FruitCreatpear() {
		return new UsatPear;
	}
};
//具体工厂 japan
class JapanFactory : public AbstructFactory {
public:
	virtual AbstructApple* FruitCreatapple() {
		return new JapanApple;
	}
	virtual AbstructPear* FruitCreatpear() {
		return new Japanpear;
	}
};


void test() {
	AbstructFactory* factory = new ChinaFactory;
	AbstructApple* apple = factory->FruitCreatapple();
	AbstructPear* pear = factory->FruitCreatpear();
	apple->showname();
	pear->showname();
	delete pear;
	delete apple;
	delete factory;


}



int main() {

	test();
	system("pause");
	return 0;
}