#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
ģ�巽��ģʽ���ݲ衢�ݿ��� ������ˮ�����ݡ�����
�������й�ͬ�����ĺ������Խ����ǹ�ͬ�ķ��������д���麯����Ȼ�󼯳�һ����ͬ�����Ľӿ�
����ϸ�ڷ��ڸ���������
*/

class Make {
public:
	//���������ͬ����
	//��ˮ
	virtual void BotWarter() = 0;
	//����
	virtual void Makefood() = 0;
	//����
	virtual void PutSomething() = 0;
	//��װ������ͬ��һ������
	void make() {
		this->BotWarter();
		this->Makefood();
		this->PutSomething();
	}
};
//����ϸ��Tea
class Tea :public Make {
	//��ˮ
	virtual void BotWarter() {
		cout << "Tea������ˮ..." << endl;
	}
	//����
	virtual void Makefood() {
		cout << "Tea����Ҷ��..." << endl;
	}
	//����
	virtual void PutSomething() {
		cout << "Tea��ţ��..." << endl;
	}
};
//����ϸ��Coffee
class Coffee :public Make {
	//��ˮ
	virtual void BotWarter() {
		cout << "Coffee�ô���ˮ..." << endl;
	}
	//����
	virtual void Makefood() {
		cout << "Coffee������..." << endl;
	}
	//����
	virtual void PutSomething() {
		cout << "Coffee����..." << endl;
	}
};

void test() {
	//����ָ��ָ��������� ����ָ��Ҳ����ָ���������  ��̬
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