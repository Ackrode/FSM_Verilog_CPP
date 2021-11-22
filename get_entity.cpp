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

/////////////////////
auto split(const std::string& str, const std::string& delim)
{
	std::vector<std::string> vs;
	size_t pos {};
    for (size_t fd = 0; (fd = str.find(delim, pos)) != std::string::npos; pos = fd + delim.size())
		vs.emplace_back(str.data() + pos, str.data() + fd);

	vs.emplace_back(str.data() + pos, str.data() + str.size());
	return vs;
}
////////////////////////////

array<map<string,array<int,2>>,2> get_entity(string Path)
{ ////////////vectors and variables
vector<string> matches;
std::vector<string> test,test1,containerall,cont_bus,cont_size;
std::vector<string> input_bus,input_bus_s,output_bus,output_bus_s,inputs,outputs,inputsize,outputsize;
vector<string> type_name={"module","input","output","fatal error inputs/outputs in state table"};
int modein;
vector<string> cont{},cont_s{};
array<int,2 > n;
///////////////containers////////////////////
map<string,array<int,2>> input,output;

////////////////regular expression////////////////////
 regex re1("(module|input|output)[\\s]+([^;)]+)*"); 
 regex re2("[^\\,\\:]");
 regex re3("([a-zA-Z_a-zA-Z])([^,\\s])*");
 regex re4("(reg|wire)");
 regex re5("([^:\\s\\[\\]\\n])\\b");
 regex re6("([\\[\\]*])");
////////////////////////////


ifstream f;
f.open(Path, ios::in);
stringstream text;
text << f.rdbuf();
f.close();
string des= text.str();

//get module name
//cout<<des;
  
sregex_iterator rit ( des.begin(), des.end(), re1 );
sregex_iterator rend;
while (rit!=rend) {
 matches.push_back(rit->str());
           ++rit;  }   
//////split matches
for(int t=0; t<matches.size(); t++){  //for all matches
 std::string e,e1;
test.clear();
test1.clear();
containerall.clear();
cont.clear();
cont_bus.clear();
cont_size.clear();
cont_s.clear();
const auto vs {split(matches[t], ",")};  ///function split, separate words when find a ","
	for (const auto& e : vs){
  	test.push_back(e);}

 const auto vs1 {split(test[0], " ")};  ///function split, separate words when find a " "
     	for (const auto& e1 : vs1){
 		 test1.push_back(e1);}

 containerall.insert(containerall.end(), test1.begin(), test1.end());
 containerall.insert(containerall.end(), test.begin()+1, test.end()); 


////////////////decide if is a input or output
if(containerall[0]==type_name[0]){ modein=1;
	//input.insert(pair<string,array<int,2>>(containerall[1],{0,0}));
 }
else if (containerall[0]==type_name[1] ){ modein=1; }
else if (containerall[0]==type_name[2]){  modein=2; }
else{ std::cout<<type_name[3]; } 


if(std::regex_search(containerall[1], re6) ){
    for(int l=2; l<containerall.size(); l++) {
	cont_bus.push_back(containerall[l]);
	sregex_iterator rit2( containerall[1].begin(), containerall[1].end(), re5 );
    sregex_iterator rend2;
	  while (rit2!=rend2){
        cont_size.push_back(rit2->str());
            ++rit2;  } 
   		      } 				 ///input with bus              	
	}
	else{
	//cout<<" ";			///module input without bus
	for(int l=1; l<containerall.size(); l++){ 
      cont.push_back(containerall[l]);
	  cont_s.push_back("0");
	  	  }
		
}
////aasign another vector is there is a bus
if(std::regex_search(containerall[1], re6) ){
if(modein==1){ //for inputs
for(int n=0; n<cont_bus.size();n++){
		input_bus.push_back(cont_bus[n]); 
	}
for(int n=0; n<cont_size.size();n++){
		input_bus_s.push_back(cont_size[n]); 	}

 }
else if (modein==2)  ///for outputs
{
	for(int n=0; n<cont_bus.size();n++){
		output_bus.push_back(cont_bus[n]); 	} 
    for(int n=0; n<cont_size.size();n++){
		output_bus_s.push_back(cont_size[n]);  }  

}
else{
	cout<<"fail"<<endl;
}
}
/////////////////if there isn't a bus//////
if(modein==1){ //for inputs
for(int n=0; n<cont.size();n++){
		inputs.push_back(cont[n]); 
	}
for(int n=0; n<cont_s.size();n++){
		inputsize.push_back(cont_s[n]); 	}

 }
else if (modein==2)  ///for outputs
{
	for(int n=0; n<cont.size();n++){
		outputs.push_back(cont[n]);	
		} 
    for(int n=0; n<cont_s.size();n++){
		outputsize.push_back(cont_s[n]);  }  
       
		
}
else{
	cout<<"fail"<<endl;
}


}///

 ////fill maps

 for(int i=0; i<inputs.size(); i++){
    n[0]=atoi(inputsize[i].c_str());
    input.insert(pair<string,array<int,2>>(inputs[i],{0,n[0]}));
 } 
for(int i=0; i<outputs.size(); i++){
     n[0]=atoi(outputsize[i].c_str());
     output.insert(pair<string,array<int,2>>(outputs[i],{0,n[0]}));
  } 

////for buses

for(int i=0; i<input_bus.size(); i++){
    n[1]=atoi(input_bus_s[2*i].c_str());
    n[0]=atoi(input_bus_s[(2*i)+1].c_str());
    input.insert(pair<string,array<int,2>>(input_bus[i],{n[1],n[0]}));
 } 
 for(int i=0; i<output_bus.size(); i++){
    n[1]=atoi(output_bus_s[2*i].c_str());
    n[0]=atoi(output_bus_s[(2*i)+1].c_str());
    output.insert(pair<string,array<int,2>>(output_bus[i],{n[1],n[0]}));
 } 




    return {input,output};
    }