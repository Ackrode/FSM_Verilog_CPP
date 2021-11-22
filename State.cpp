#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <fstream>
#include <bitset>
#include <math.h>
using namespace std;

string toBinary(int n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}
float resultado;

void State(string FileName, array <map <string, array <int, 2>>, 2> Entity, array <map <string, vector <string>>, 2> States)
{
    vector <vector <string>> Inputs;
    for(auto it1 = Entity[0].begin(); it1 != Entity[0].end(); it1++)
    {
        vector <string> InputsColumns;
        InputsColumns.push_back(it1 -> first);          
            for (auto it2 = it1 -> second.begin(); it2 != it1 -> second.end(); ++it2)
            {
                InputsColumns.push_back(to_string(*it2));
            }
        Inputs.push_back(InputsColumns);
    }

    vector <vector <string>> Outputs;
    for(auto it1 = Entity[1].begin(); it1 != Entity[1].end(); it1++)
    {
        vector <string> OutputsColumns;
        OutputsColumns.push_back(it1 -> first);          
            for (auto it2 = it1 -> second.begin(); it2 != it1 -> second.end(); ++it2)
            {
                OutputsColumns.push_back(to_string(*it2));
            }
        Outputs.push_back(OutputsColumns);
    }

    vector <vector <string>> FutureStates;
    for(auto it1 = States[0].begin(); it1 != States[0].end(); it1++)
    {
        vector <string> FutureStatesColumns;
        FutureStatesColumns.push_back(it1 -> first);          
            for (auto it2 = it1 -> second.begin(); it2 != it1 -> second.end(); ++it2)
            {
                FutureStatesColumns.push_back(*it2);
            }
        FutureStates.push_back(FutureStatesColumns);
    }    

    fstream OL;
    /* define the module*/
    OL.open(FileName, ios::out);
    OL << "module "<< Inputs[0][0] << "(" + Inputs[1][0] + ", " + Inputs[2][0] + ", " + Inputs[3][0] + ", " + Outputs[0][0] + ");" << endl;
    OL << "\tinput [" + Inputs[1][1] + ":" + Inputs[1][2] + "] " + Inputs[1][0] + ";" << endl;
    OL << "\tinput [" + Inputs[2][1] + ":" + Inputs[2][2] + "] " + Inputs[2][0] + ";" << endl;
    OL << "\tinput [" + Inputs[3][1] + ":" + Inputs[3][2] + "] " + Inputs[3][0] + ";" << endl;
    OL << "\toutput reg [" + Outputs[0][1] + ":" + Outputs[0][2] + "] " + Outputs[0][0] + ";" << endl;

    /* State and next state*/
    float y; int reg1, x, resultado;
    y = 0.0; x = 0; reg1 = 0; resultado = 0;   
    x = FutureStates.size() ; 
    y = log(x)/log(2);
    reg1 = ceil(y);
    resultado = reg1 - 1;
    OL << endl << "\treg [" << resultado << ":0] state;" << endl;
    OL << "\treg [" << resultado << ":0] next_state;" << endl;

    /*State codification*/
    OL << endl;
    for (int i = 0; i < x; i++)
    {    
        OL << "\tparameter " + FutureStates[i][0] + " = " << i << ";" << endl;
    }

    /* intial begin*/
    bitset<3> bs2(toBinary(0)); 
    OL << endl << "\tinitial begin" << endl;
    OL << "\t\tstate = " + FutureStates[0][0] + ";" << endl;
    OL << "\tend" << endl;

    /*State register*/
    OL << endl << "\talways @(posedge " + Inputs[1][0] + ", posedge " + Inputs[2][0] + ")" <<endl;
    OL << "\t\tbegin" << endl;
    OL << "\t\t\tif(" + Inputs[2][0] +")" << endl;
    OL << "\t\t\t\tstate <= " + FutureStates[0][0] + ";" << endl;
    OL << "\t\t\telse" << endl;
    OL << "\t\t\t\tstate <= next_state;" << endl;
    OL << "\t\tend\n" << endl;
    OL.close();
}