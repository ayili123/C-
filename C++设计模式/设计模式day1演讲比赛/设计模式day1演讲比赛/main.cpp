/*
第一步  创建24个学生  因为每个学生都有参赛编号，参赛编号唯一，放到map容器中  key是编号 - value选手对象
vector<int> v1 第一轮参赛的（编号）列表 map[编号]  random_shuffle()
vector<int> v2 第一轮比赛的晋级名单
vector<int> v3 第二轮比赛的晋级名单
vector<int> v4 第三轮比赛的晋级名单
*/

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <deque>
#include <time.h>


using namespace std;

class Player {
public:
	string mName;
	int mScore[3];//保存三次比赛的成绩。编号保存在key中
};

struct myprint {
	void operator()(int a){
		cout << a << " ";
	}
};

//创建选手
void Creat_Player(map<int, Player>& mPlist, vector<int>& vInit) {
	string seedNAME = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24; i++) {
		Player P;
		P.mName = "选手";
		for (int j = 0; j < 3; j++) {
			P.mScore[j] = 0;
		}
		P.mName += seedNAME[i];
		int uID = 100 + i;
		mPlist.insert(make_pair(uID, P));//对组
		vInit.push_back(uID);//v1  参赛名单
	}
	
	for_each(vInit.begin(), vInit.end(), myprint());
	cout << endl;

}


void Set_Random(vector<int>& vRandom)//选手抽签
{
	random_shuffle(vRandom.begin(), vRandom.end());
	for_each(vRandom.begin(), vRandom.end(), myprint());
	cout << endl;

}

//给v1打分，存在map中，编号给v2,index第几轮
void Set_Score(int index,vector<int>&  vIn, map<int, Player>& mPlist, vector<int>& vOut)//打分  存在map中
{
	srand((unsigned int)time(NULL));//种子
	//技巧**************
	//分数和编号，分数就是key,会自动排序
	multimap<int,int,greater<int>> mGroup;//int int 分数 编号//默认从小到大排序
	int groupIndex = 0;
	for (vector<int>::iterator it = vIn.begin(); it != vIn.end(); it++) {
	 
		//打分
		deque<int> dScore;//deque可两头删除
		for (int i = 0; i < 10; i++) {
			int score = rand() % 40 + 60;
			
			dScore.push_back(score);
		}
        //排序
		sort(dScore.begin(), dScore.end());
		//去掉最高最低
		dScore.pop_front();
		dScore.pop_back();
		//求和
		int total_score = accumulate(dScore.begin(), dScore.end(),0);
		//平均分
		int avg_score = total_score /dScore.size();
		
		//根据key访问 
		mPlist[*it].mScore[index-1] = avg_score;
		//把当前选手编号放在mGroup中
		mGroup.insert(make_pair(avg_score,*it));//排序
		groupIndex++;
		if (groupIndex % 6 == 0) {
			int numIndex = 0;
			for (multimap<int, int>::iterator mIt = mGroup.begin(); mIt != mGroup.end(); mIt++) {
				if (numIndex >= 3) {
					break;
				}
				//取前三个
				vOut.push_back((*mIt).second);
				numIndex++;
			}
			mGroup.clear();//清空
		}
	}
	
}

//打印晋级名单
void Show_Good_Player(int index, map<int, Player>& mPlist, vector<int>& v)
{
	//v存储的和map里int一样
	cout << "__________________________" << endl;
	cout << "第" << index << "轮分数结果：" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "姓名：  " << mPlist[*it].mName << "," <<"分数：    "<< mPlist[*it].mScore[index-1] << endl;
	}
}

int main()
{
	//定义map容器  根据编号保存选手信息 编号存在key中
	map<int, Player> mPlist;

	//第一轮比赛的参赛列表
	vector<int> v1;//24人 晋级12人

	//第二轮比赛的参赛列表
	vector<int> v2;//12人 晋级6人

	//第三轮比赛的参赛列表
	vector<int> v3;//6人 晋级3人

	//最终前三名
	vector<int> v4;

	//创建选手
	Creat_Player(mPlist,v1);

	//第一轮比赛
	Set_Random(v1);//选手抽签
	Set_Score(1,v1,mPlist,v2);//打分  存在map中
	Show_Good_Player(1,mPlist,v2);//打印晋级选手

	//第二轮比赛
	Set_Random(v2);//选手抽签
	Set_Score(2, v2, mPlist, v3);//打分  存在map中
	Show_Good_Player(2, mPlist, v3);//打印晋级选手

	//第三轮比赛
	Set_Random(v3);//选手抽签
	Set_Score(3, v3, mPlist, v4);//打分  存在map中
	Show_Good_Player(3, mPlist, v4);//打印晋级选手
	
	
	return 0;
}