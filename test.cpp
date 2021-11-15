#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <fstream>
using namespace std;
int main(){
    map <string, vector<string> > States2;
    vector <string> FSO2 = {"E", "0", "D", "1"};
    States2.insert({"A", FSO2});
    FSO2 = {"F", "0", "D", "0"};
    States2.insert({"B", FSO2});
    FSO2 = {"E", "0", "B", "1"};
    States2.insert({"C", FSO2});
    FSO2 = {"F", "0", "B", "0"};
    States2.insert({"D", FSO2});
    FSO2 = {"C", "0", "F", "1"};
    States2.insert({"E", FSO2});
    FSO2 = {"B", "0", "C", "0"};
    States2.insert({"F", FSO2});
    for (auto it = States2.begin(); it != States2.end(); ++it){
        cout << it->first << ": ";
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            cout << *it2 << " ";
        }
    }
    vector <string> Inputs = {"clk", "reset", "x"};
}