#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Question {//存储题目信息用
public:
	int id;//编号
	int rank;//分值
	int num;//选项个数
	int correct;//正确选项个数
	char good[5];//正确的选项分别是那些
	int wrong;//这道题有几人错了
};

bool cmp(Question a, Question b) {
	if (a.wrong == b.wrong)
		return a.id < b.id;
	return a.wrong > b.wrong;
}

int main() {
	int N, M;
	vector<Question> ques;//记录题目信息
	Question que;
	int level = 0;//计算学生成绩用
	string answer;//读取学生作答用

	cin >> N >> M;

	int i, j, k, t, s;
	for (i = 0, que.wrong = 0; i < M; i++) {//读取题目信息
		que.id = i + 1;
		cin >> que.rank >> que.num >> que.correct;
		for (j = 0; j < que.correct; j++)
			cin >> que.good[j];
		ques.push_back(que);
	}

	getchar();//消去之前使用cin>>未读取的结尾\n,使getline()正常运作
	for (i = 0; i < N; i++) {//读取学生作答情况，并给出学生得分
		getline(cin, answer);
		for (j = 0, s = 0; j < M; j++, s++) {
			while (answer[s] != '(')//找'('
				s++;
			t = answer[s + 1] - '0';//得到学生该题作了几个选项，记为t
			if (t == ques[j].correct) {//判断该题的正误,首先判断学生选项数对不对
				for (k = 0; k < t; k++) {
					if (ques[j].good[k] != answer[s + 3 + 2 * k]) {//此处默认学生的选项也是顺序的
						ques[j].wrong++;
						break;
					}
				}
				if (k == t)
					level += ques[j].rank;
			}
			else
				ques[j].wrong++;
		}
		cout << level << endl;
		level = 0;
	}

	sort(ques.begin(), ques.end(), cmp);//排序，按题目错误的数量排序
	if (ques[0].wrong == 0)
		cout << "Too simple\n";
	else {
		t = ques[0].wrong;
		i = 0;
		cout << t;
		while (ques[i].wrong == t)
			cout << ' ' << ques[i++].id;
		cout << endl;
	}
	return 0;
}