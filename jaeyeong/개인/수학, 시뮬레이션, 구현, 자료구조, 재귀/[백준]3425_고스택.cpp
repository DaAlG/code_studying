using namespace std;
#include <iostream>
#include <string>
#include <vector>
#define MAX 1000000000

vector<string> order;

string solve(int start) {
	vector<int> st;
	int size = order.size();
	st.push_back(start);
	for (int i = 0; i < size; i++) {
		if (order[i].size() > 3) {//NUM
			int k = stoi(order[i].substr(4));
			st.push_back(k);
			continue;
		}
		if (order[i] == "POP") {
			if (st.empty()) return "ERROR";
			st.pop_back();
		}
		else if (order[i] == "INV") {
			if (st.empty()) return "ERROR";
			st[st.size() - 1] *= -1;
		}
		else if (order[i] == "DUP") {
			if (st.empty()) return "ERROR";
			st.push_back(st.back());
		}
		else if (order[i] == "SWP") {
			if (st.size() < 2) return "ERROR";
			auto temp = st[st.size() - 2];
			st[st.size() - 2] = st.back();
			st[st.size() - 1] = temp;
		}
		else if (order[i] == "ADD") {
			if (st.size() < 2) return "ERROR";
			auto a = st.back();
			st.pop_back();
			auto b = st.back();
			st.pop_back();
			if (abs(a + b) > MAX) return "ERROR";
			st.push_back(a + b);
		}
		else if (order[i] == "SUB") {
			if (st.size() < 2) return "ERROR";
			auto a = st.back();
			st.pop_back();
			auto b = st.back();
			st.pop_back();
			if (abs(b - a) > MAX) return "ERROR";
			st.push_back(b - a);
		}
		else if (order[i] == "MUL") {
			if (st.size() < 2) return "ERROR";
			long long a = st.back();
			st.pop_back();
			long long b = st.back();
			st.pop_back();
			if (abs(a * b) > MAX) return "ERROR";
			st.push_back(a * b);
		}
		else if (order[i] == "DIV") {
			if (st.size() < 2) return "ERROR";
			int sign = 1;
			long long a = st.back();
			if (a < 0) sign *= -1;
			st.pop_back();
			long long b = st.back();
			if (b < 0) sign *= -1;
			st.pop_back();

			if (a == 0) return "ERROR";
			st.push_back((abs(b) / abs(a)) * sign);
		}
		else if (order[i] == "MOD") {
			if (st.size() < 2) return "ERROR";
			long long a = st.back();
			st.pop_back();
			long long b = st.back();
			st.pop_back();

			if (a == 0) return "ERROR";
			st.push_back(b % a);
		}
	}
	if (st.size() != 1) return "ERROR";
	else return to_string(st.back());
}
int main() {
	//입력을 처리하는 부분
		//명령어 문자로 들어오니까 명령어에 따라서 분기
		//NUM 같은 경우는 뒤에 숫자가 들어옴
		//JAVA 한 줄씩 읽으면 되는데 cpp같은 경우는 문자열로 읽게되면 숫자도 더 읽어야 한다
		//분기를 해서 적절한 명령어를 수행해야 함
	//스택의 구현
		//직접 해도 되고
		//JAVA stack(), list, cpp vector, array, python vector, array
	//명령어를 구현하는 부분 총 10개정도
		//가장 중요. 왜냐면
		//예외처리
			//뭔가 값을 pop해야하는데 없거나
			//divide해야 하는데 0이거나
			//값을 연산했는데 너무 크거나 .. 10^9. long을 써야 함.
		//더 예외들이 있음
	//초기화 + 각각의 연산을 수행하는 로직

	//주의할 점
		//1.예외처리
		//2. 초기화 안되는 것
		//3. 디버깅 (빡셈)
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input;
	cin >> input;
	while (input != "QUIT") {
		if (input == "END") {
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				long long k;
				cin >> k;
				cout << solve(k) << '\n';
			}
			cout << "\n";
			order.clear();
		}
		else {
			if (input == "NUM") {
				int t;
				cin >> t;
				input = input + " " + to_string(t);
			}
			order.push_back(input);
		}
		cin >> input;
		cin.ignore();
	}
	return 0;
}