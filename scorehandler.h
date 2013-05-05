#ifndef SCORE_HANDLER_H
#define SCORE_HANDLER_H

#include <map>
#include <string>

using namespace std;

class ScoreHandler
	{
 	public:
 		void read();
 		void insertScore(string name, int score);
		void write();
		map<int, string>& getScores();
		
	private:
		map<int, string> highscores;
	};


#endif
