#include <iostream>
#include <queue>
#include <vector>

class Node {
    public:
    int data;
    int cost;
};

class comp {
    public:
    bool operator()(const Node & a, const Node & b) {
        return a.cost>b.cost;
    }
};

void spelloutq(std::priority_queue<int> pq);
// void printdapq(std::priority_queue<Node> pq);

int main () {

    std::priority_queue<int> pq;

    for(int n : {1, 2, 52, 32, 156, 3426, 4325, 342, 13, 172})
        pq.push(n);

    spelloutq(pq);

    Node n1;
    Node n2;
    Node n3;
    Node n4;
    Node n5;

    std::priority_queue<Node, std::vector<Node>, comp> dapq;

   

    n1.cost = 1104;
    n2.cost = 2843234;
    n3.cost = 3428;
    n4.cost = 38;
    n5.cost = 48283;


    // std::vector<Node> nodes = {};
    // nodes.push_back(n1);
    // nodes.push_back(n2);
    // nodes.push_back(n3);
    // nodes.push_back(n4);
    // nodes.push_back(n5);


    dapq.push(n1);
    dapq.push(n2);
    dapq.push(n3);
    dapq.push(n4);
    dapq.push(n5);

    while(!dapq.empty()) {
        std::cout << dapq.top().cost << std::endl;
        dapq.pop();
    }

    return 0;
}

void spelloutq(std::priority_queue<int> pq) {
    while(!pq.empty()) {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }
    std::cout << "\n";
}
