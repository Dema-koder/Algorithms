#include <iostream>
//#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;

struct node 
{
	int key;
	int height;
	node* left;
	node* right;
	node(int k) { key = k; left = right = 0; height = 1; }
};

unsigned char height(node* p)
{
	return p ? p->height : 0;
}

int bfactor(node* p)
{
	return height(p->right) - height(p->left);
}

void fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

node* rotateright(node* p)
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q) 
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p) 
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; 
}

node* exist(node* p, int k) {
	if (p == NULL)
		return NULL;
	if (p->key == k) {
		return p;
	}
	if (p->key > k)
		return exist(p->left, k);
	else
		return exist(p->right, k);
}

node* insert(node* p, int k) 
{
	if (exist(p, k) != NULL) {
		return balance(p);
	}
	if (!p) return new node(k);
	if (k < p->key)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}

node* findmin(node* p) 
{
	return p->left ? findmin(p->left) : p;
}

node* removemin(node* p)
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

node* next_min(node* p, int k) {
	if (p == NULL)
		return NULL;
	if (p->key == k) {
		p = p->right;
		if (p != NULL)
			while (true) {
				if (p->left == NULL)
					break;
				else
					p = p->left;
			}
		return p;
	}
	if (p->key > k)
		if (p->left == NULL) {
			return p;
		}
		else {
			return (next_min(p->left, k) == NULL ? p : next_min(p->left, k));
		}
	else
		if (p->right == NULL) {
			return NULL;
		}
		else {
			return next_min(p->right, k);
		}
}

node* prev_max(node* p, int k) {
	if (p == NULL) {
		return NULL;
	}
	if (p->key == k) {
		p = p->left;
		if (p != NULL) 
			while (true) {
				if (p->right == NULL)
					break;
				else
					p = p->right;
			}
		return p;
	}
	if (p->key > k) {
		if (p->left == NULL) {
			return NULL;
		}
		else
			return prev_max(p->left, k);
	}
	else {
		if (p->right == NULL) {
			return p;
		}
		else
			return (prev_max(p->right, k) == NULL ? p : prev_max(p->right, k));
	}
}

node* remove(node* p, int k) 
{
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else 
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if (!r) return q;
		node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

int main() {
	string oper;
	int value; 
	node* root = NULL;
	while (cin >> oper >> value) {
		if (oper == "insert")
			root = insert(root, value);
		if (oper == "exists") {
			cout << (exist(root, value) != NULL ? "true\n" : "false\n");
		}
		if (oper == "delete") {
			root = remove(root, value);
		}
		if (oper == "next") {
			node* cur = next_min(root, value);
			if (cur == NULL)
				cout << "none\n";
			else
				cout << cur->key << endl;
		}
		if (oper == "prev") {
			node* cur = prev_max(root, value);
			if (cur == NULL)
				cout << "none\n";
			else
				cout << cur->key << endl;
		}
	}
}
