#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void OutputLogic(string FileName, array <map <string, array <int, 2>>, 2> Entity, array <map <string, vector <string>>, 2> States)
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

    vector <vector <string>> OutputValues;
    for(auto it1 = States[1].begin(); it1 != States[1].end(); it1++)
    {
        vector <string> OutputValuesColumns;
        OutputValuesColumns.push_back(it1 -> first);          
            for (auto it2 = it1 -> second.begin(); it2 != it1 -> second.end(); ++it2)
            {
                OutputValuesColumns.push_back(*it2);
            }
        OutputValues.push_back(OutputValuesColumns);
    }
    
    fstream OL;
    OL.open(FileName, ios::app);
    OL << "\n\talways @(state, " + Inputs[3][0] + ")" << endl;
    OL << "\t\tbegin" << endl << "\t\t\tcase (state)" << endl;
    for (int i = 0; i < FutureStates.size(); i++)
    {
        OL << "\t\t\t\t" + FutureStates[i][0] + ": if(" + Inputs[3][0] + ")" << endl;
        for (int j = OutputValues[i].size(); j > 0 ; j--)
        {
            switch (j)
            {
                case 2:
                    OL << "\t\t\t\t\t" + Outputs[0][0] + " = 1\'b" + OutputValues[i][j] + ";" << endl;
                    OL << "\t\t\t\telse" << endl; break;
                case 1:
                    OL << "\t\t\t\t\t" + Outputs[0][0] + " = 1\'b" + OutputValues[i][j] + ";" << endl; break;
                default: break;
            }
        }
    }
    OL << "\t\t\t\tdefault: " + Outputs[0][0] + " = 1\'b0;" << endl;
    OL << "\t\t\tendcase" << endl << "\t\tend" << endl << "endmodule";
    OL.close();
}