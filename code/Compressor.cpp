#include <bits/stdc++.h>
#include "node.h"
using namespace std;

unordered_map<unsigned char, int> freqs;              //Map where byte frequencies are stored
unordered_map<unsigned char, string> huffCodes;       //Map, of byte -> binary compressed representation
priority_queue<node*, vector<node*>, greater<node*>> pq;
node * root = nullptr;

void makeCodes(node * rt, string route = ""){
    if(!rt) return;
    if(!rt->left && !rt->right) huffCodes[rt->c] = route;  //if rt is a leaf, then the route to it is its representation.
    makeCodes(rt->left, route + '0');
    makeCodes(rt->right, route + '1');
}

void makeTree(){
    while(pq.size() > 1){       //greedily make the tree, choosing the 2 node with less frequency
        node * n1 = pq.top(); pq.pop();
        node * n2 = pq.top(); pq.pop();
        pq.push(new node(n1, n2));
    }root = pq.top(); pq.pop();
}

string compress(const string &data){
    string c1 = "", c2 = "";
    for(unsigned char c: data) c1 += huffCodes.at(c); //for all bytes in data, transform, the byte to its compressed representation
    for(int i = 0; i<c1.size(); i+=8){
        bitset<8> byte(c1.substr(i, 8));
        c2 += static_cast<unsigned char>(byte.to_ulong());  //then transform the compressed representation, to char
    }return c2;

}

void makeTable(const string &name, const string &txt){
    for(auto c: txt) freqs[c]++;  //update frequencies
    for(auto p: freqs) pq.push(new node(p.second, p.first));  //push all the leaves of the tree
    makeTree();
    makeCodes(root);
    ofstream table(name.substr(0, name.find_last_of('.')) + ".table");
    for(const auto &p: huffCodes) table<<static_cast<int>(p.first)<<" "<<p.second<<'\n';
    table.close();
}

string readInput(const string& name){
    ifstream in(name, ios::binary);
    string data((istreambuf_iterator<char>(in)), (istreambuf_iterator<char>()));
    in.close();
    return data;
}

void writeInOut(const string &name, const string data){
    ofstream out(name.substr(0, name.find_last_of('.')) + ".huff", ios::binary);
    out.write(data.data(), data.size());
    out.close();
}

int main(){

    string name;
    cin>>name;
    string data = readInput(name);
    makeTable(name, data);
    writeInOut(name, compress(data));
    return 0;

}
