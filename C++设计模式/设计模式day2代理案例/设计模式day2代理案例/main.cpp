#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
/*
��������
1.�Ѿ�д�õĽӿڻ���ϵͳ
2.������Ľӿڻ���ϵͳҪ�õķ�����ȡ������дһ�������࣬������Ľӿڼ̳������
3.дһ����������ͬ���̳�����������࣬�������ͬ���ķ���
4.��1��װ�ڴ�������
*/

//����Ҫ��MySystem��run()���������Գ������,����MySystem��Ҫ�̳���
class AbstractMySystem {
public:
	virtual void run() = 0;

};
//�Ѿ�д�õ�
class MySystem : public AbstractMySystem {
public:
	virtual void run() {
		cout << "ϵͳ��������" << endl;
	}
};


//�����࣬ͬ��Ҫ�̳��ң�Ȼ���1��װ���ҵĳ�Ա��
//��������ԭ������Ҫ���������˺Ų��ܵ���
//ͬ���й�ͬ��virtual����
class daili : public AbstractMySystem {
public:
	daili(string name, string passward) {
		this->mName = name;
		this->mPassward = passward;
		pmysystem = new MySystem;
	};
	daili() {};
	//�ж��Ƿ���ȷ
	bool panduan() {
		if (this->mName == "liyi" && this->mPassward == "123") {
			cout << "��֤ͨ����" << endl;
			return true;

		}
		return false;
		
	}
	virtual void run() {
		if (panduan()) {
		
			pmysystem->run();
		}
		else
			cout << "�û��������������" << endl;
	
	}
	~daili() {        //��new,�Ҳ��Ƿ��ص�
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