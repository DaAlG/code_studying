#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100
#define DMAX 25
using namespace std;

int n;
int arr[MAX][MAX];
vector<pair<int, int>> matrix;
bool visited[MAX][MAX];
int dp[DMAX][DMAX];

pair<int, int> getMatrix(int x, int y)
{
	int r = x;
	int c = y;

	while (r < n && arr[r][y] != 0) r++;
	while (c < n && arr[x][c] != 0) c++;

	r = r - x;
	c = c - y;

	for (int i = x; i < x + r; i++) {
		for (int j = y; j < y + c; j++) {
			visited[i][j] = true;
		}
	}

	return make_pair(r, c);
}

vector<pair<int, int>> makeOrder()
{
	vector<pair<int, int>> nMatrix(matrix.size());
	
	for (int i = 0; i < matrix.size(); i++) {
		nMatrix[0].first = matrix[i].first;
		nMatrix[0].second = matrix[i].second;

		int idx = 1;
		int cur = nMatrix[0].second;

		for (int j = 0; j < matrix.size() - 1; j++) {
			bool flag = false;
			for (int k = 0; k < matrix.size(); k++) {
				if (matrix[k].first == cur) {
					flag = true;
					nMatrix[idx].first = matrix[k].first;
					nMatrix[idx].second = matrix[k].second;
					cur = nMatrix[idx].second;
					idx++;
				}
			}
			if (!flag) break;
		}
		if (idx == matrix.size()) break;
	}

	return nMatrix;
}


int getMin(int left, int right)
{
	if (left == right) return dp[left][right] = 0;
	if (dp[left][right] != -1) return dp[left][right];

	int minimum = INT_MAX;
	for (int i = left; i < right; i++) {
		int leftResult = getMin(left, i);
		int rightResult = getMin(i + 1, right);
		int d = matrix[left].first * matrix[i].second * matrix[right].second;
		minimum = min(minimum, leftResult + rightResult + d);
	}
	return dp[left][right] = minimum;
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n;
		memset(visited, false, sizeof(visited));
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] != 0 && !visited[i][j]) {
					matrix.push_back(getMatrix(i, j));
				}
			}
		}
		matrix = makeOrder();
		cout << "#" << test_case << " " << getMin(0, matrix.size() - 1) << "\n";
		matrix.clear();
	}
	return 0;
}