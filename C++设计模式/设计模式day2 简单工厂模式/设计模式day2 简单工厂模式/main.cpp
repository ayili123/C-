#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*
1.不符合开闭原则
2.水果工厂：将水果抽象出来，然后每个水果继承抽象 ，最后工厂调用创建水果
  这样客户就不用自己创建new
*/
//抽象水果
class AbstructFruit{
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

class Factory {
public:
	Factory(string name) {
		this->Pname = name;
	}
	Factory() {};
	 AbstructFruit* FruitCreat(){   //传出指针，所以不用析构函数
		if (Pname == "apple") {
			return new AppleFruit;
		}
		if (Pname == "banana") {
			return new BananaFruit;
		}
		if (Pname == "pear") {
			return new PearFruit;
		}
		else
			return NULL;
	}

public:
	
	string Pname;
};

void test() {
	Factory* f = new Factory("apple");//创建苹果工厂
	AbstructFruit* apple = f->FruitCreat();//生产苹果  这个传出指针和工厂里一样的
	apple->FruitShowname();
	delete apple;
	delete f;

}

int main() {


	test();
	system("pause");
	return 0;

}