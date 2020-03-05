#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*   *****************��������ģʽ���򵥹���ģʽ���Ͽ���ԭ��
1.���Ͽ���ԭ��
2.������Ҳ�������
  
  ȱ�㣺����һ����͵�����һ�������� ��
*/
//����ˮ��
class AbstructFruit {
public:
	virtual void FruitShowname() = 0;
};

//ƻ��
class AppleFruit : public AbstructFruit {
public:
	virtual void FruitShowname() {
		cout << "����ƻ��..." << endl;
	}
};
//�㽶
class BananaFruit : public AbstructFruit {
public:
	virtual void FruitShowname() {
		cout << "�����㽶..." << endl;
	}
};
//����
class PearFruit : public AbstructFruit {
public:
	virtual void FruitShowname() {
		cout << "��������..." << endl;
	}
};


//���󹤳�   ���ص��ǳ���ˮ��
class AbstructFactory {
public:
	virtual AbstructFruit* FruitCreat() = 0;
};
//���幤�� apple
class AppleFactory : public AbstructFactory {
public:
	virtual AbstructFruit* FruitCreat() {
		return new AppleFruit;
	}
};
//���幤�� pear
class PearFactory : public AbstructFactory {
public:
	virtual AbstructFruit* FruitCreat() {
		return new PearFruit;
	}
};
//���幤�� banana
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