#include <bits/stdc++.h>
using namespace std;

#define int int64_t

// template<typename T>
struct Node {
	Node() {}
	Node(int value_arg): value{value_arg} {}
	int value{};
	array<Node *, 2> child{};
	Node* parent{};
	Node* path_parent{};
	bool side() const {
		/*! Returns true if child is on the right, and false otherwise*/
		return parent->child[1] == this;
	}
	void rotate() {
		/*! Rotate node x around its parent */
		const auto p = parent;
		const bool i = side();

		if (p->parent) {
			p->parent->attach(p->side(), this);
		} else {
			parent = nullptr;
		}
		p->attach(i, child[!i]);
		attach(!i, p);
		this->path_parent = p->path_parent; // Added for link-cut tree
	}
	void splay() {
		/*! Splay node x. x will become the root of the tree*/
		for(;parent ;rotate()) {
			if (parent->parent) {
			  (side() == parent->side() ? parent : this)->rotate();
			}
		}
	}
	array<Node *, 2> split() {
		splay();
		// TODO use detach function
		const auto right = child[1];
		if (right) {
			right->parent = nullptr;
		}
		this->child[1] = nullptr;
		return {this, right};
	}
	void attach(bool side, Node *const new_) {
		if (new_) {
			new_->parent = this;
		}
		child[side] = new_;
	}
};

Node* make_tree() {
	/*! Make a new tree */
	return new Node{};
}

void detach_child(Node* node){
	/*! Converts node's preferred child edge to a path parent edge*/
	if(node->child[1]){
		node->child[1]->path_parent = node;
		node->child[1]->parent = nullptr;
	}
}
Node *access(Node *node) {
	/*! Moves node to the root of the auxillary tree containing the root node of the tree. Returns last path-parent of node as it moves up the tree*/
	node->splay();
	detach_child(node);
	node->child[1] = nullptr;
	Node *par = node;
	while (node->path_parent) {
		par = node->path_parent;
		par->splay();
		detach_child(par);
		par->attach(1, node);
		node->path_parent = nullptr;
		node->splay();
	}
	return par;
}

Node *find_root(Node *node) {
	/** Finds the root of the tree containing node*/
	access(node);
	for (; node->child[0]; node = node->child[0]);
	access(node);
	return node;
}

void cut(Node *node) {
	/*! Detaches the subtree of node from the tree of node's parent*/
	access(node);
  if (node->child[0]) {
    node->child[0]->parent = nullptr;
  }
	node->child[0] = nullptr;
}

void link(Node *par, Node *child) {
	/*! Makes child the child of par*/
	access(child);
	access(par);
	child->attach(0, par);
}

Node *lca(Node *u, Node *v) {
	/*! Returns lowest common ancestor of nodes u and v or nullptr if u and v are in different trees*/
	if (find_root(u) != find_root(v)) {
		return nullptr;
	}
	access(u);
	return access(v);
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<Node*> nodes(n + 1);  // 1-based indexing
  for (int i = 1; i <= n; ++i) {
    nodes[i] = new Node(i);
  }
  for (int i = 1; i <= n; ++i) {
    int p;
    cin >> p;
    if (p && p != i) { 
      link(nodes[p], nodes[i]);
    }
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      cut(nodes[x]);
      if (y) {
        link(nodes[y], nodes[x]);
      }
    } else if (type == 2) {
      int x;
      cin >> x;
      cout << find_root(nodes[x])->value << '\n';
    }
  }
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}