#ifndef SCORE_HANDLER_H
#define SCORE_HANDLER_H

#include <map>
#include <string>

using namespace std;

class ScoreHandler
	{
 	public:
 		/** The function to read the current file of high scores*/
 		void read();
 		/** The function to insert a new user's high score*/
 		void insertScore(string name, int score);
 		/** The function to save the current high scores*/
		void write();
		/** Function to return the map of high scores*/
		map<int, string>& getScores();
		
	private:
		map<int, string> highscores;
	};


#endif
