#include <bits/stdc++.h>
using namespace std;

unordered_map<string, unsigned char> huffCodes;

string decompress(string zip){
    string rslt = "", curr = "";
    for(unsigned char byte: zip)
        for(int i = 7; i>=0; i--){                        //read each bit, of the string zip
            curr += (byte & (1<<i))? '1': '0';
            if(huffCodes.find(curr) != huffCodes.end()){  //of curr is in the table
                rslt += huffCodes[curr];
                curr = "";
            }
        }
    return rslt;
}

void readTable(string &name){
    ifstream table(name);
    int ch; string route;
    while(table >> ch >> route) huffCodes[route] = ch;
    table.close();
}

string readInput(string &name){

    ifstream in(name, ios::binary);
    string data((istreambuf_iterator<char>(in)), (istreambuf_iterator<char>()));
    in.close();
    return data;
}

void writeInOut(string &name, string data){
    ofstream out(name, ios::binary);
    out.write(data.data(), data.size());
    cout<<"Successful decompression on: "<<name<<'\n'; 
    out.close();
}

int main(){

    string zip, codes, outName;
    cin>>zip>>codes>>outName;
    readTable(codes);
    writeInOut(outName, decompress(readInput(zip)));
    return 0;

}
