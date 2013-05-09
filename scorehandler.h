/*
Copyright (C) 2013  MARCUS ENG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

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
