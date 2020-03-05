#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*   *****************工厂方法模式（简单工厂模式加上开闭原则）
1.符合开闭原则
2.将工厂也抽象出来
  
  缺点：增加一个类就得增加一个工厂类 。
*/
//抽象水果
class AbstructFruit {
public:
	virtual void FruitShowname() = 0;
};

//苹果
class AppleFruit : public AbstructFruit {
public:
	virtual void FruitShowname() {
		cout << "我是苹果..." << endl;
	}
};
//香蕉
class BananaFruit : public AbstructFruit {
public:
	virtual void FruitShowname() {
		cout << "我是香蕉..." << endl;
	}
};
//梨子
class PearFruit : public AbstructFruit {
public:
	virtual void FruitShowname() {
		cout << "我是梨子..." << endl;
	}
};


//抽象工厂   返回的是抽象水果
class AbstructFactory {
public:
	virtual AbstructFruit* FruitCreat() = 0;
};
//具体工厂 apple
class AppleFactory : public AbstructFactory {
public:
	virtual AbstructFruit* FruitCreat() {
		return new AppleFruit;
	}
};
//具体工厂 pear
class PearFactory : public AbstructFactory {
public:
	virtual AbstructFruit* FruitCreat() {
		return new PearFruit;
	}
};
//具体工厂 banana
class BnanaFactory : public AbstructFactory {
public:
	virtual AbstructFruit* FruitCreat() {
		return new BananaFruit;
	}
};

void test() {
	/*AbstructFactory* Factory = new AppleFactory;
	AbstructFruit* fruit = Factory->FruitCreat();*/

	AbstructFactory* Factory = NULL;
	AbstructFruit* fruit = NULL;
	Factory = new AppleFactory;
	fruit = Factory->FruitCreat();
	fruit->FruitShowname();
	delete fruit;
	delete Factory;

}


int main() {

	test();
	system("pause");
	return 0;
}