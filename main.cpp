#include <iostream>
#include <fstream>
#include <string>
#include "Machine.h"
#include "functions.h"
using namespace std;


int main(int argc, char** argv){
	//read command line's parameters
  	bool steps=false;
  	bool state=false;
  	bool tape=false;
  	string word="";
  	string fileName="";
  	//we expect at least 2 parameters (name of the file and input value)
  	if(argc>2 && argc<7){
    	for (int i = 1; i < argc; ++i){
    		string temp=argv[i];
    		if(temp.compare("-steps")==0){
    			steps=true;
    		}
    		else if(temp.compare("-state")==0){
    			state=true;
    		}
    		else if(temp.compare("-tape")==0){
    			tape=true;
    		}
    		else{
    			//we check if the parameter is the name of the file
    			ifstream infile(temp);
    			if(infile.good()){
    				fileName=temp;
    				infile.close();
    			}
    			//if not, the parameter must be the input word
    			else{
    				word=temp;
    			}
    		}
    	}
	}
	else{
		cout<<"Error, wrong number of parameters\n";
		return 2;
	}
	//create object machine using the content of the file 
	Machine machine=readFile(fileName,steps,state,tape);
	interprete(machine,word);
}