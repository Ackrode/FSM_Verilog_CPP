#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <fstream>
using namespace std;

void NextState(string FileName, array <map <string, array <int, 2>>, 2> inouts, array <map <string, vector <string>>, 2> states)
{
    map <string, array<int, 2>> inputs;
    map<string,array<int,2>> outputs;
    map <string, vector<string>> next_states;
    map <string, vector<string>> next_outputs;
    string design,ins;
    next_states=states[0];
    next_outputs=states[1];
    inputs=inouts[0];
    outputs=inouts[1];
    //delete first element on inputs
    inputs.erase(inputs.begin());
    inputs.erase(inputs.begin());
    inputs.erase(inputs.begin());
    design.append("always @(state, ");
    for (auto it = inputs.begin(); it != inputs.end(); ++it)
    {
        design.append(it->first);
        ins.append(it->first);
        design.append(",");
    }
    //delete last comma
    design.erase(design.end()-1);
    design.append(")\n");
    design.append("\tbegin\n");
    design.append("\t\tcase (state)\n");
    for (auto it = next_states.begin(); it != next_states.end(); ++it)
    {
        design.append("\t\t\t");
        design.append(it->first);
        design.append(":\n");
        int j=0;
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
        {
            if(it2+1==it->second.end()){
                design.append("\t\t\t\t\telse\n");
                design.append("\t\t\t\t\t\tnext_state="+*it2+";\n");
                j++;
            }
            else{
                design.append("\t\t\t\t\tif("+ins+"=="+to_string(j)+")\n");
                design.append("\t\t\t\t\t\tnext_state="+*it2+";\n");
                j++;
            }
        }

    }
    design.append("\t\tendcase\n");
    design.append("\tend");
    fstream OL;
    OL.open(FileName, ios::app);
    OL << design << endl;
    OL.close();
}