#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<vector<string>> answer(2, vector<string>());

void recursive(int k)
{
	string s;
	s.append(4 * k, '_');
	
	if (k == n) {
		for (int i = 0; i < answer[1].size(); i++)
			cout << s + answer[1][i];
		return;
	}

	for (int i = 0; i < answer[0].size() - 1; i++)
		cout << s + answer[0][i];

	recursive(k + 1);

	cout << s + answer[0].back();
}


int main()
{
	cin >> n;

	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	answer[0].push_back("\"재귀함수가 뭔가요?\"\n");
	answer[0].push_back("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
	answer[0].push_back("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
	answer[0].push_back("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
	answer[0].push_back("라고 답변하였지.\n");
	
	answer[1].push_back("\"재귀함수가 뭔가요?\"\n");
	answer[1].push_back("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
	answer[1].push_back("라고 답변하였지.\n");

	recursive(0);

	return 0;
}