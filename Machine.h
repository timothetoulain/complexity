#ifndef MACHINE_H_
#define MACHINE_H_
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* The Machine class stores all the information necessary to interpret a given word
* and display the result according to the user choice
*/
class Machine{
	private:
		string m_initial;
		string m_finalTape;
		string m_blank;
		string m_currentState;
		/*m_states[x][0] contains the name of the state and m_states[x][1] contains T or F*/
		vector<vector<string>> m_states; 

		/*m_symbols[x][0] contains the symbol and m_symbols[x][1] contains T or F*/
		vector<vector<string>> m_symbols;

		/*m_transitionsStates[x][0] contains the initial state and m_transitionsStates[x][1] contains the future state*/
		vector<vector<string>> m_transitionsStates;

		/*m_transitionsSymbols[x][0] contains the input symbol and m_transitionsSymbols[x][1] contains the output symbol*/
		vector<vector<string>> m_transitionsSymbols;
 		
 		/*indicates if we read left or right*/
		vector<string> m_direction;

		bool m_displaySteps=false;
		bool m_displayState=false;
		bool m_displayTape=false;
		int m_count;

	public:
		Machine();

		string getInitial();
		string getCurrentState();
		string getFinalTape();
		string getDirection(int i);
		string getBlank();

		vector<vector<string>> getStates();
		vector<vector<string>> getSymbols();
		vector<vector<string>> getTransitionsStates();
		vector<vector<string>> getTransitionsSymbols();
		
		bool getDisplaySteps();
		bool getDisplayState();
		bool getDisplayTape();


		void setInitial(string initial);
		void setBlank(string blank);
		void setStates(string state, string term);
		void setSymbols(string symb, string term);
		void setCurrentState(string state);
		void setFinalTape(string currentSymbol);
		void setDirection(string direction);
		void setDisplaySteps(bool x);
		void setDisplayState(bool x);
		void setDisplayTape(bool x);
		void setTransitionsStates(string present, string future);
		void setTransitionsSymbols(string present, string future);
};
#endif
