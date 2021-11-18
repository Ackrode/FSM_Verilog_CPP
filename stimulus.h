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

void stimulus(array<map<string, array<int,2>>,2> inf_entity,array<map <string, vector<string> >,2> states,string module){  
vector<string> edop;
array<vector<string>,2> estados;
array<vector<int>,2> estadosnum;
//////////////////////////////////////////////////////////////////////////////////////
for(auto it=states[0].begin(); it!=states[0].end();it++){
     edop.push_back(it->first);
     estados[0].push_back(it->second[0]);
     estados[1].push_back(it->second[1]);
     }
//////////////////////////////////////////////////////////////////////////////////////////7
int valor=0,valor1=0;
for(int i=0; i<edop.size(); i++ ){
// cout<<edop[i]<<","<<estados[0][i]<<","<<estados[1][i]<<endl;
if(estados[0][i]=="A"){
    valor=0;
}
else if (estados[0][i]=="B")
{
    valor=1;
}
else if (estados[0][i]=="C")
{
    valor=2;
}
else if (estados[0][i]=="D")
{
    valor=3;
}
else if (estados[0][i]=="E")
{
    valor=4;
}
else if (estados[0][i]=="F")
{
    valor=5;
}
else if (estados[0][i]=="G")
{
    valor1=6;
}
else if (estados[0][i]=="H")
{
    valor1=7;
}
else{
    valor<<0;
}
if(estados[1][i]=="A"){
    valor1=0;
}
else if (estados[1][i]=="B")
{
    valor1=1;
}
else if (estados[1][i]=="C")
{
    valor1=2;
}
else if (estados[1][i]=="D")
{
    valor1=3;
}
else if (estados[1][i]=="E")
{
    valor1=4;
}
else if (estados[1][i]=="F")
{
    valor1=5;
}
else if (estados[1][i]=="G")
{
    valor1=6;
}
else if (estados[1][i]=="H")
{
    valor1=7;
}
else{
    valor1<<0;
}
 estadosnum[0].push_back(valor);
 estadosnum[1].push_back(valor1);
}
////////////////////////////////////////////////////////////////////7
int p,p1,i,j;
int v,m,a,f,count;
// int val1;
vector<int> x,val,val1;
// p=estadosnum[0][0];
// p1=estadosnum[0][p];
i=0;
j=1; //cambiar a 0 si es una maquina mealy

/////////////////////////////////////////////////////////////////////
count=0;
 /////////cambiar de posicion en la matriz
 for(int t=0; t<9; t++){
 val.push_back(estadosnum[i][j]);
 v=(val.size())-1;
 val1.push_back(val[v]);

//buscar un valor repetido
if((val.size()-1)>0){
  for(int n=0; n<val.size(); n++){
    if(val[n]==val[v]){   
     
  count++;
    
}}}
  x.push_back(i);
  
 if(count>1){
     val.pop_back();
     val1.pop_back();
     x.pop_back();
     if(i==0){i=1;}
    else{i=0;}   
     v=(val.size())-1;
    j=val[v]; 
 } 
 else{
j=val[v];////cambio la posicion de la matriz
 }
count=0;  
 }
/////////////////////////////////////////////////////////
fstream OL;
/* define the module*/
OL.open( module + "_TB.sv", ios::app);

OL << "$display("<<"\"*********************************************\")"<<";"<<endl;
OL << "clk = 1'b0; reset = 1'b1; x = 1'b0; #2"<<endl;
OL << "$display(\"clk = %b, reset = %b, x = %b, outp = %b\", clk, reset, x, outp);"<<endl;
OL << "reset = 1'b0;"<<endl;
  for (int i = 0; i <x.size(); i++)
 {
   OL <<"x = 1'b"<<x[i]<<";"<<" #2"<<endl;
   OL << "$display(\"clk = %b, reset = %b, x = %b, outp = %b\", clk, reset, x, outp);"<<endl;
    
 }

OL << "$finish;"<<endl;
OL << " end"<<endl;
OL << " always #1 clk = ~clk;"<<endl;
OL << "endmodule"<<endl;

    for (int i = 0; i <x.size(); i++)
 {
   cout<<x[i];
    
 }
}