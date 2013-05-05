#include "scorehandler.h"
#include <iostream>
#include <fstream>

using namespace std;

void ScoreHandler::read()
	{
	ifstream myfile("Score.txt");
   
   if(myfile.fail())
   	{
		return;
   	}

	int counter = 0;//Used to keep only the top 10 scores

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

void ScoreHandler::insertScore(string name, int score)
	{
	highscores.insert(pair<int,string>(score, name));
	}

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

map<int, string>& ScoreHandler::getScores()
	{
	return highscores;
	}
	

