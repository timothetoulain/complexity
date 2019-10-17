#include"functions.h"

int nthOccurrence(const string& str, const string& findMe, int nth){
    size_t  pos = 0;
    int     cnt = 0;
    while(cnt != nth){
        pos+=1;
        pos = str.find(findMe, pos);
        if ( pos == std::string::npos )
            return -1;
        cnt++;
    }
    return pos;
}


Machine readFile(string fileName,bool steps,bool state,bool tape){
	ifstream machineFile(fileName);
	if(machineFile){
		string line;
		size_t start,end,sep;
		string tuple;
		Machine machine;

		//we read each line 
		while(getline(machineFile, line)){
			//we create two substrings(tuple and line) considering the pattern of the current line
 			start=line.find("(");
 			//tuple contains what's before the first parenthesis on the current line
			tuple=line.substr(0,start);
			end = line.find(")"); 
			//line contains what's between the parenthesis on the current line
			line = line.substr(start+1, end-start-1);

			if(tuple.compare("initial")==0){
				machine.setInitial(line);
			}
			else if(tuple.compare("state")==0){
				sep = line.find(",");
				machine.setStates(line.substr(0,sep),line.substr(sep+1,line.size()-sep));
			}
			else if(tuple.compare("blank")==0){
				machine.setBlank(line);
			}
			else if(tuple.compare("symbol")==0){
				sep = line.find(",");
				machine.setSymbols(line.substr(0,sep),line.substr(sep+1,line.size()-sep));
			}
			//for transition, we need to parse the line in order to store the present and future state,
			//along with the input symbol and the output symbol
			else if(tuple.compare("transition")==0){
				size_t virg1=line.find(",");
				string present=line.substr(0,virg1); 

				//parse the file to retrieve the substring between the second and third ","
				size_t virg2= nthOccurrence(line, ",", 2);
				size_t virg3= nthOccurrence(line, ",", 3);
				string future=line.substr(virg2+1,virg3-virg2-1);		
				machine.setTransitionsStates(present,future);
		
				//parse the file to retrieve the substring between the third and fourth ","
				size_t virg4= nthOccurrence(line, ",", 4);
				present=line.substr(virg1+1,virg2-virg1-1);
				future=line.substr(virg3+1,virg4-virg3-1);
				
				machine.setTransitionsSymbols(present,future);
				//the direction is either "R" or "L"
				machine.setDirection(line.substr(virg4+1,1));
			}
			
			else{
				cout<<"Unknown line encountered, please reformate your file \n";
				machineFile.close();
				exit(2);
			}	
		}
		machine.setDisplaySteps(steps);
		machine.setDisplayState(state);
		machine.setDisplayTape(tape);
		machine.setCurrentState(machine.getInitial());
		machineFile.close();
		return machine;
	}
	else{
		cout<<"Error, can't open file\n";
		exit(1);
	}
}

void interprete(Machine machine, string word){
	int sizeWord=word.size();
	bool foundSymb=false;
	int caracterCount=0;
	string currentSymbol;
	vector<vector<string>> vect=machine.getSymbols();
	bool final=false;
	//while we haven't read each character and we are not in a final state
	while(caracterCount<sizeWord && final==false){
		currentSymbol=word.at(caracterCount);

		//we look for a match between the current symbol and a symbol that the machine can read
		for(int i=0; i<vect.size(); i++){
			if(vect[i][0]==currentSymbol){
				foundSymb=true;
				break;
			}
			else if(currentSymbol==machine.getBlank()){
				foundSymb=true;
				break;
			}
		}

		//if the current symbol from the word is interpretable
		if(foundSymb){
			vector<vector<string>>transiStates=machine.getTransitionsStates();
			vector<vector<string>>transiSymbols=machine.getTransitionsSymbols();
			//we look at what transition we can do and what the outpout symbol would be
			for(int i=0; i<transiSymbols.size(); i++){
				if(transiStates[i][0]==machine.getCurrentState()){
					if(transiSymbols[i][0]==currentSymbol){
						displaySteps1(machine,transiSymbols,i);
						//we concatenate the output symbol to finalTape
						machine.setFinalTape(transiSymbols[i][1]);
						//we update the state
						machine.setCurrentState(transiStates[i][1]);
						displaySteps2(machine,transiSymbols,i);

						//we check if the current state is final or not
						vector<vector<string>> states=machine.getStates();
						for(int j=0;j<states.size();j++){
							if(states[j][0]==machine.getCurrentState()){
								if(states[j][1]=="T"){
									final=true;
									break;
								}
							}
						}
						displaySteps3(machine,i);
						//read left or right
						if(machine.getDirection(i)=="R")
							caracterCount++;
						else
							if(caracterCount!=0)
								caracterCount--;
						foundSymb=false;
						break;
					}
				}
			}
		}
		else{
			cout<<"Error, unknown symbol: "<<currentSymbol<<"\n";
			exit(3);
		}
	}



	//if we are not in a final state, we read blank
	if(final==false){
		currentSymbol=machine.getBlank();
		for(int i=0; i<vect.size(); i++){
			if(vect[i][0]==currentSymbol){
				foundSymb=true;
				break;
			}
			else if(currentSymbol==machine.getBlank()){
				foundSymb=true;
				break;
			}
		}

		//if the current symbol from the word is interpretable
		if(foundSymb){
			vector<vector<string>>transiStates=machine.getTransitionsStates();
			vector<vector<string>>transiSymbols=machine.getTransitionsSymbols();
			//we look at what transition we can do and what the outpout symbol would be
			for(int i=0; i<transiSymbols.size(); i++){
				if(transiStates[i][0]==machine.getCurrentState()){
					if(transiSymbols[i][0]==currentSymbol){
						displaySteps1(machine,transiSymbols,i);
						//we concatenate the output symbol to finalTape
						machine.setFinalTape(transiSymbols[i][1]);
						//we update the state
						machine.setCurrentState(transiStates[i][1]);
						displaySteps2(machine,transiSymbols,i);

						//we check if the current state is final or not
						vector<vector<string>> states=machine.getStates();
						for(int j=0;j<states.size();j++){
							if(states[j][0]==machine.getCurrentState()){
								if(states[j][1]=="T"){
									final=true;
									break;
								}
							}
						}
						displaySteps3(machine,i);
						//read left or right
						if(machine.getDirection(i)=="R")
							caracterCount++;
						else
							if(caracterCount!=0)
								caracterCount--;
						foundSymb=false;
						break;
					}
				}
			}
		}
		else{
			cout<<"Error, unknown symbol: "<<currentSymbol<<"\n";
			exit(3);
		}
	}

	//display depending on the user choice
	if(machine.getDisplayState())
		cout<<"Final State: "<<machine.getCurrentState()<<endl;
	if(machine.getDisplayTape())
		cout<<"Final Tape: "<<machine.getFinalTape()<<endl;
}


void displaySteps1(Machine machine,vector<vector<string>>transiSymbols,int i){
	if(machine.getDisplaySteps())
		cout<<"("<<machine.getCurrentState()<<", "<<transiSymbols[i][0]<<") -> ";
}
void displaySteps2(Machine machine,vector<vector<string>>transiSymbols,int i){
	if(machine.getDisplaySteps())
		cout<<"("<<machine.getCurrentState()<<", "<<transiSymbols[i][1];
}
void displaySteps3(Machine machine,int i){
	if(machine.getDisplaySteps()){
		string direction;
		if(machine.getDirection(i)=="R")
			direction="RIGHT";
		else
			direction="LEFT";
		cout<<", "<<direction<<")"<<endl;
	}
}
