#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
���󹤳�ֻ��Բ�Ʒ�壬�����ǲ�Ʒ�ṹ��
����Ĺ������ǳ��̣�ÿ�����̿�������ͬ�Ķ�����
�������Ӷ�����̣�������ҵ����������Ҫ�޸Ĵ���

*/
//�ȳ���ҵ���࣬��ͬ����ͬһҵ��,�����ƻ��
class AbstructApple {
public:
	virtual void showname() = 0;
};
//��ͬ������ͬҵ��̳�
//�й�
class ChinaApple : public AbstructApple {
public:
	virtual void showname() {
		cout<<"china apple...."<<endl;
	}
};
//����
class UsatApple : public AbstructApple {
public:
	virtual void showname() {
		cout << "USA apple...." << endl;
	}
};
//�ձ�
class JapanApple : public AbstructApple {
public:
	virtual void showname() {
		cout << "Japan apple...." << endl;
	}
};

//��������

class AbstructPear {
public:
	virtual void showname() = 0;
};
//��ͬ������ͬҵ��̳�
//�й�
class ChinaPear : public AbstructPear {
public:
	virtual void showname() {
		cout << "china pear...." << endl;
	}
};
//����
class UsatPear : public AbstructPear {
public:
	virtual void showname() {
		cout << "USA pear...." << endl;
	}
};
//�ձ�
class Japanpear : public AbstructPear {
public:
	virtual void showname() {
		cout << "Japan pear...." << endl;
	}
};

//���󹤳�
class AbstructFactory {
public:
	virtual AbstructApple* FruitCreatapple() = 0;
	virtual AbstructPear* FruitCreatpear() = 0;
};

//���幤�� china
class ChinaFactory : public AbstructFactory {
public:
	virtual AbstructApple* FruitCreatapple() {
		return new ChinaApple;
	}
	virtual AbstructPear* FruitCreatpear() {
		return new ChinaPear;
	}
};

//���幤�� USA
class USAFactory : public AbstructFactory {
public:
	virtual AbstructApple* FruitCreatapple() {
		return new UsatApple;
	}
	virtual AbstructPear* FruitCreatpear() {
		return new UsatPear;
	}
};
//���幤�� japan
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