#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*
1.�����Ͽ���ԭ��
2.ˮ����������ˮ�����������Ȼ��ÿ��ˮ���̳г��� ����󹤳����ô���ˮ��
  �����ͻ��Ͳ����Լ�����new
*/
//����ˮ��
class AbstructFruit{
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

class Factory {
public:
	Factory(string name) {
		this->Pname = name;
	}
	Factory() {};
	 AbstructFruit* FruitCreat(){   //����ָ�룬���Բ�����������
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
	Factory* f = new Factory("apple");//����ƻ������
	AbstructFruit* apple = f->FruitCreat();//����ƻ��  �������ָ��͹�����һ����
	apple->FruitShowname();
	delete apple;
	delete f;

}

int main() {


	test();
	system("pause");
	return 0;

}