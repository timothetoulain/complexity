#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Machine.h"
using namespace std;

//read the content of the file and create a machine according to the content of this file
//return the newly created machine, or exit
Machine readFile(string fileName,bool steps,bool state,bool tape);

/*find the nth occurence of a caracter in a string
* param: str=inital string
* findMe=caracter/substring to find
* nth= the occurence of findMe we want to find in str
* return: position of the nth occurence of findMe in str
* source: https://stackoverflow.com/questions/18972258/index-of-nth-occurrence-of-the-string
*/
int nthOccurrence(const string& str, const string& findMe, int nth);

// display the different steps during the execution of the machine
//these functions are called only if the user specified the parameter "-steps"
void displaySteps1(Machine machine,vector<vector<string>>transiSymbols,int i);
void displaySteps2(Machine machine,vector<vector<string>>transiSymbols,int i);
void displaySteps3(Machine machine,int i);

//main function, interpretes the word using the machine described in the file
void interprete(Machine machine, string word);
