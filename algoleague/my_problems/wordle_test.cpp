#include <bits/stdc++.h>
using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

void generateTestCase(ofstream& out) {
    // Constants
    const int MAX_N = 1e5;  // Maximum number of nodes
    const int MAX_M = 2e5;  // Maximum number of edges
    const int MAX_K = 1e9; // MAximum cost of each attempt
    const int MAX_WEIGHT = 1e9;  // Maximum weight of an edge

    // Random values for N and M
    int N = randInt(6, MAX_N);  // At least 6 nodes
    int M = randInt(N - 1, min(MAX_M, N * (N - 1) / 2));  // At least N-1 edges for connected graph
    int K = randInt(1, MAX_K);

    // int N = 7, M = 11, K = 3;
    out << N << " " << M << " " << K << '\n';

    // Generate M unique edges (u, v, w)
    set<pair<int, int>> edges;
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        do {
            u = randInt(1, N);
            v = randInt(1, N);
        } while (u == v || edges.count({min(u, v), max(u, v)}));
        edges.insert({min(u, v), max(u, v)});
        w = randInt(1, MAX_WEIGHT);
        out << u << " " << v << " " << w << endl;
    }

    // src[5] is always 1, so generate 5 other unique nodes for src[0] to src[4]
    set<int> specialNodes;
    specialNodes.insert(1);  // src[5] is node 1
    while (specialNodes.size() < 6) {
        specialNodes.insert(randInt(2, N));  // Avoid node 1 for the other src elements
    }
    
    // Remove src[5] (which is 1) from the set and write the rest (src[0] to src[4])
    specialNodes.erase(1);
    for (int x : specialNodes) {
        out << x << " ";
    }
    out << endl;
}

signed main() {
    // Open file to write the test case
    string s = "input";
    string x = ".txt";
    for (int i = 0; i < 23; ++i) {
        string a = to_string(i);
        string y = s + a + x;
        ofstream outFile(y);
        generateTestCase(outFile);
        outFile.close();
    }
    
    // Generate the test case
    
    // Close the file
    
    return 0;
}
