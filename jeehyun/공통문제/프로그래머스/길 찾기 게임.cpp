#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Node {
public:
    int x, y, n, left, right;
    Node(int x, int y, int n) : x(x), y(y), n(n) { }
    void setChild(int left, int right) {
        this->left = left;
        this->right = right;
    }
    bool operator<(Node& p) {
        if (this->y == p.y)
            return this->x < p.x;
        return this->y > p.y;
    }
};

bool visited[10000];

void makeTree(vector<Node>& tree, int now, int lmin, int rmax) {
    if (now >= tree.size()) return;

    visited[now] = true;

    int left = -1;
    int right = -1;
    for (int i = now + 1; i < tree.size(); i++) {
        if (tree[i].y < tree[now].y) {
            if (left == -1 && !visited[i] && tree[i].x < tree[now].x && tree[i].x > lmin) {
                left = i;
            }
            else if (right == -1 && !visited[i] && tree[i].x > tree[now].x && tree[i].x < rmax) {
                right = i;
            }
        }

        if (left != -1 && right != -1) break;
    }

    tree[now].setChild(left, right);
    if (left != -1) makeTree(tree, left, lmin, tree[now].x);
    if (right != -1) makeTree(tree, right, tree[now].x, rmax);
}

void preorder(const vector<Node>& tree, vector<int>& answer, int now) {
    if (now == -1) return;
    answer.push_back(tree[now].n);
    preorder(tree, answer, tree[now].left);
    preorder(tree, answer, tree[now].right);
}

void postorder(const vector<Node>& tree, vector<int>& answer, int now) {
    if (now == -1) return;
    postorder(tree, answer, tree[now].left);
    postorder(tree, answer, tree[now].right);
    answer.push_back(tree[now].n);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2, vector<int>());

    vector<Node> tree;
    for (int i = 0; i < nodeinfo.size(); i++) {
        tree.push_back(Node(nodeinfo[i][0], nodeinfo[i][1], i + 1));
    }
    sort(tree.begin(), tree.end());

    makeTree(tree, 0, -1, 100001);

    preorder(tree, answer[0], 0);
    postorder(tree, answer[1], 0);

    return answer;
}