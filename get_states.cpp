
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <vector>
#include <array>
#include <algorithm>
#include <map>
#include <cstdlib>
using namespace std;

array<map <string, vector<string> >,2> get_states(string Path) {
vector<string> reg,m_edo,m_edof,m_out,m_edop,m_edofp,m_outp; //matches
vector<string> test; 
ifstream f;
vector<pair<regex, string>> re;
vector<string> data_table={"present_state","future_state","outputs"};

f.open(Path, ios::in);
stringstream text;
text << f.rdbuf();
f.close();
string des= text.str();

re.push_back(make_pair(regex("(\\b[A-Z])([\\,])"), "present_state"));
re.push_back(make_pair(regex("(\\b[A-Z])([\\-])"), "future_state"));
re.push_back(make_pair(regex("\\-([0-1]*)"), "outputs"));

for(auto it=re.begin(); it!=re.end(); ++it){
 sregex_iterator rit1 ( des.begin(), des.end(), it->first);
 sregex_iterator rend1;
 while (rit1!=rend1) {
  reg.push_back(rit1->str());
            ++rit1;  } 
if(std::regex_search(des,it->first)){
  if(it->second==data_table[0])
    for(int i=0; i<reg.size();i++){
      m_edop.push_back(reg[i]);
      m_edo.push_back(m_edop[i].substr (0,m_edop[i].length()-1));
    }
  else if(it->second==data_table[1])
    for(int i=0; i<reg.size();i++){
      m_edofp.push_back(reg[i]);
       m_edof.push_back(m_edofp[i].substr (0,m_edofp[i].length()-1));
  }
  else {
        for(int i=0; i<reg.size();i++){
          m_outp.push_back(reg[i]);
          m_out.push_back(m_outp[i].substr (1,m_outp[i].length()-1));
  }}}
reg.clear();
}

///creation of maps.
map <string, vector<string> > states,output; 
vector<string> reg1,reg2;
int Ncomb=2,posi=0;
for(int j=0; j<m_edo.size(); j++){
vector<string> reg1{};
  for(int i=0; i<Ncomb; i++){
    reg1.push_back(m_edof[posi+i]);   
    reg2.push_back(m_out[posi+i]);    
}
    if(Ncomb==2){
      posi=posi+2;
}
states.insert({m_edo[j], reg1});  /////assign values to maps
output.insert({m_edo[j], reg2});  /////assign values to maps
reg1.clear();
reg2.clear();
}

    return {states,output};
}