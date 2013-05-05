#include "scorehandler.h"
#include <iostream>
#include <fstream>

using namespace std;

/** A function to handle reading the high score file before gameplay begins
 	* @param nothing
 	* @return nothing
 	*/
void ScoreHandler::read()
	{
	ifstream myfile("Score.txt");
   
   if(myfile.fail())
   	{
		return;
   	}

	int counter = 0; //Used to keep only the top 10 scores

   while(myfile.good() && counter < 10)
		{
		int score;
		string name;
		
		myfile >> score;
		//myfile >> name;
		getline(myfile, name);
		getline(myfile, name);
		
		highscores.insert(pair<int,string>(score, name));
		++counter;
    	}
	}

/** A function that inserts a user's score into the high score table
 	* @param string the name of the player
 	* @param int the score of the player from that game
 	* @return nothing
 	*/
void ScoreHandler::insertScore(string name, int score)
	{
	highscores.insert(pair<int,string>(score, name));
	}

/** A function to write out the current high score table to a text file
 	* @param nothing
 	* @return nothing
 	*/
void ScoreHandler::write()
  	{
  	ofstream ofile; // Initializes ofstream object to work with
  	ofile.open("Score.txt", ios::out);

  	if(ofile.fail())
   	{
     	cerr << "Could not write file: " << "Score.txt" << endl;
     	return;
   	}

	for(map<int, string>::reverse_iterator it = highscores.rbegin(); it != highscores.rend(); ++it)
		{
		ofile << it->first << endl;
		ofile << it->second << endl;
		}

	ofile.close();
	}

/** A function that returns the current score table
 	* @param nothing
 	* @return map<int, string> containing the information of high scores
 	*/
map<int, string>& ScoreHandler::getScores()
	{
	return highscores;
	}
	

