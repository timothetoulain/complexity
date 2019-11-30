#include "Machine.h"
#include<iostream>
#include<cstring>
using namespace std;

Machine::Machine(){m_count=0;}

string Machine::getInitial(){
	return m_initial;
}
vector<vector<string>> Machine::getStates(){
	return m_states;
}
string Machine::getBlank(){
	return m_blank;
}
vector<vector<string>> Machine::getSymbols(){
	return m_symbols;
}
string Machine::getCurrentState(){
	return m_currentState;
}
string Machine::getFinalTape(){
	//we delete the blank character from the final tape
	string b=m_blank; 
    char blank_array[1];  
    strcpy(blank_array, b.c_str()); 
  
	for(int i=0;i<m_finalTape.length();i++){
		if(m_finalTape.at(i)==blank_array[0]){
  			m_finalTape.erase (m_finalTape.begin()+i);
		}
	}
	return m_finalTape;
}
string Machine::getDirection(int i){
	return m_direction[i];
}
bool Machine::getDisplaySteps(){
	return m_displaySteps;
}
bool Machine::getDisplayState(){
	return m_displayState;
}
bool Machine::getDisplayTape(){
	return m_displayTape;
}
vector<vector<string>> Machine::getTransitionsStates(){
	return m_transitionsStates;
}
vector<vector<string>> Machine::getTransitionsSymbols(){
	return m_transitionsSymbols;
}



void Machine::setDirection(string direction){
	m_direction.push_back(direction);
}
void Machine::setInitial(string initial){
	m_initial=initial;
}
void Machine::setBlank(string blank){
	m_blank=blank;
}
void Machine::setStates(string state, string term){
	vector<string>vect;
	vect.push_back(state);
	int size=m_count;
	m_states.push_back(vect);
	m_states[size].push_back(term);
	m_count++;
}
void Machine::setSymbols(string symb,string term){
	vector<string>vect;
	vect.push_back(symb);
	int size=m_symbols.size();
	m_symbols.push_back(vect);
	m_symbols[size].push_back(term);	
}
void Machine::setCurrentState(string state){
	m_currentState=state;
}
//concatenate symbol to m_finalTape
void Machine::setFinalTape(string currentSymbol){
	m_finalTape+=currentSymbol;
}
void Machine::setDisplaySteps(bool x){
	m_displaySteps=x;
}
void Machine::setDisplayState(bool x){
	m_displayState=x;
}
void Machine::setDisplayTape(bool x){
	m_displayTape=x;
}
void Machine::setTransitionsStates(string present, string future){
	vector<string>pres;
	pres.push_back(present);
	int size=m_transitionsStates.size();
	m_transitionsStates.push_back(pres);
	m_transitionsStates[size].push_back(future);
}
void Machine::setTransitionsSymbols(string present, string future){
	vector<string>pres;
	pres.push_back(present);
	int size=m_transitionsSymbols.size();
	m_transitionsSymbols.push_back(pres);
	m_transitionsSymbols[size].push_back(future);
}
