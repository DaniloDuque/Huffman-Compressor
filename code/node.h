#include <iostream>
#include <vector>
using namespace std;

class node{

    public:
        int frq;
        unsigned char c;
        node *left, *right;
        node(int x, unsigned char y): frq(x), c(y) ,left(nullptr), right(nullptr){}
        node(node *l, node *r) : c('\0'), left(l), right(r), frq(l->frq + r->frq){}
        
};
