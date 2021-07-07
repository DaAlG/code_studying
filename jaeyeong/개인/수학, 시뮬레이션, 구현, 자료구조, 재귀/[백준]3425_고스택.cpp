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
	//�Է��� ó���ϴ� �κ�
		//��ɾ� ���ڷ� �����ϱ� ��ɾ ���� �б�
		//NUM ���� ���� �ڿ� ���ڰ� ����
		//JAVA �� �پ� ������ �Ǵµ� cpp���� ���� ���ڿ��� �аԵǸ� ���ڵ� �� �о�� �Ѵ�
		//�б⸦ �ؼ� ������ ��ɾ �����ؾ� ��
	//������ ����
		//���� �ص� �ǰ�
		//JAVA stack(), list, cpp vector, array, python vector, array
	//��ɾ �����ϴ� �κ� �� 10������
		//���� �߿�. �ֳĸ�
		//����ó��
			//���� ���� pop�ؾ��ϴµ� ���ų�
			//divide�ؾ� �ϴµ� 0�̰ų�
			//���� �����ߴµ� �ʹ� ũ�ų� .. 10^9. long�� ��� ��.
		//�� ���ܵ��� ����
	//�ʱ�ȭ + ������ ������ �����ϴ� ����

	//������ ��
		//1.����ó��
		//2. �ʱ�ȭ �ȵǴ� ��
		//3. ����� (����)
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