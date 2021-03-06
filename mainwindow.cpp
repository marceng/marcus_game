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

#include "mainwindow.h"

/** Constructor that sets up the view to play the game
 	* @param nothing
 	* @return nothing
 	*/
MainWindow::MainWindow()
	{
   startScreen = new QGraphicsScene();
   startScreen->setSceneRect(1, 1, WINDOW_MAX_X-2, WINDOW_MAX_Y-2);
   view = new QGraphicsView( startScreen );
  
   view->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );
   view->setWindowTitle("Mountain Climber");

	loadObjects();
	loadOpening();
	gameScreen = NULL;
	
	//---Creating Timer---///
   timer = new QTimer(this);
   timer->setInterval(20);
   connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
	}

/** Destructor that deallocates memory
 	* @param nothing
 	* @return nothing
 	*/
MainWindow::~MainWindow()
	{
   timer->stop();
   delete timer;
   delete start;

	for(std::vector<GameObject*>::iterator it = objects.begin(); it != objects.end(); ++it)
		{
		delete *it;
		}

   delete background;
	delete wall;
	delete icicle;
	delete bird;
	delete goat;
	delete star;
	delete monkey;
	delete rope;
	delete playerA;
	delete playerB;

   if(gameScreen != NULL)
   	{
	  	if(!isAlive)
			{
			scoreHandler.insertScore(userName.toStdString(), score);
			scoreHandler.write();
			delete endLabel;
			}
  
     	delete nameLabel;
		delete label;
		delete scoreLabel;
  		
   	delete player;
   	delete leftWall1;
		delete leftWall2;
		delete rightWall1;
		delete rightWall2;
		
   	delete returnButton;
 		delete quitButton;
   	delete gameScreen;
		}

   delete startScreen;
   delete view;
	}

/** When called, freezes the timer and displays a menu of buttons
 	* @param nothing
 	* @return nothing
 	*/

void MainWindow::pause()
	{
	if(isAlive)
		{
		if(timer->isActive())
			{
			timer->stop();
			returnButton->show();
			quitButton->show();
			}
		else
			{
			timer->start();
			returnButton->hide();
			quitButton->hide();
			}
		}
	}

/** Called when user presses the spacebar, triggers action that makes user move
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::spacePressed()
	{
	movePlayer = true;
	}

/** Displays the game onto the computer screen
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::show()
	{
   view->show();
	}

/** Called when program begins, loads images into program from files
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::loadObjects()
	{
	background = new QGraphicsPixmapItem(QPixmap("Images/Background.png"));
	wall = new QPixmap("Images/Wall.png");
	icicle = new QPixmap("Images/Icicle.png");
	bird = new QPixmap("Images/Bird.png");
	goat = new QPixmap("Images/Goat.png");
	star = new QPixmap("Images/Star.png");
	monkey = new QPixmap("Images/Monkey.png");
	rope = new QPixmap("Images/Rope.png");
	playerA = new QPixmap("Images/ClimberA.png");
	playerB = new QPixmap("Images/ClimberB.png");
	}

/** Loads the opening screen of the game
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::loadOpening()
	{
	scoreHandler.read();
	startScreen->addItem(background);
	
	//---Creating Title---//
	title = new QLabel("Mountain Climber");	
	QFont font("Quicksand", 46);
  	title->setFont(font);
	title->setGeometry(0, 40, WINDOW_MAX_X, 120);
	title->setAlignment(Qt::AlignCenter);
	title->setStyleSheet("background-color: rgba(255, 255, 255, 0);color:yellow;");
	startScreen->addWidget(title);
	
	//---Creating Name Input---//
	display = new QLabel("Enter your name:");
	QFont font2("Quicksand");
  	display->setFont(font2);
	display->setGeometry(WINDOW_MAX_X/2-90, WINDOW_MAX_Y/2+30, 180, 30);
	display->setAlignment(Qt::AlignCenter);
	display->setStyleSheet("background-color: rgba(255, 255, 255, 0);color:white;");
	startScreen->addWidget(display);
	
	nameInput = new QLineEdit();
	nameInput->setGeometry(WINDOW_MAX_X/2-90, WINDOW_MAX_Y/2+60, 180, 30);
	nameInput->setAlignment(Qt::AlignCenter);
	startScreen->addWidget(nameInput);

	//---Creating Instruction Label---//
	instructionLabel= new QLabel("INSTRUCTIONS:\n\n"
									"-Jump from side to side using space\n"
									"-Avoid icicles, monkeys, and birds\n"
									"-Capture goats and stars for bonuses\n"
									"-Press 'P' to pause the game");
	QFont font3("Quicksand", 8);
  	instructionLabel->setFont(font3);	
	instructionLabel->setGeometry(WINDOW_MAX_X/2-100, WINDOW_MAX_Y/2+95, 215, 80);
	instructionLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);color:white;");
	startScreen->addWidget(instructionLabel);

	//---Creating High Score List---//
	map<int, string> tempScores = scoreHandler.getScores();	
	string scoreString = "HIGH SCORES\nName\t\tScore\n\n";
	
	int counter = 0;
	for(map<int, string>::reverse_iterator it = tempScores.rbegin(); it != tempScores.rend(); ++it)
		{
		stringstream ss;
		ss << it->first;
		string temp = ss.str();

		scoreString += it->second;
		
		if(it->second.length() > 7)
			{
			scoreString += "\t";
			}
		else
			{
			scoreString += "\t\t";
			}
		
		scoreString += temp;
		
		++counter;
		
		if(counter < (int) tempScores.size())
			{
			scoreString += "\n";
			}
		}

	scoreList = new QLabel(QString::fromStdString(scoreString));
	QFont font4("Quicksand", 9);
  	scoreList->setFont(font4);
  	scoreList->setAlignment(Qt::AlignVCenter);
   scoreList->setGeometry(WINDOW_MAX_X/2-74, 120, 148, 214);
   scoreList->setStyleSheet("background-color: rgba(255, 255, 255, 0);color:red;");
   startScreen->addWidget(scoreList);

	if(tempScores.size() == 0)
		{
		scoreList->hide();
		}

	//---Creating Start Button---//
	start = new QPushButton("Begin!"); 
	connect(start, SIGNAL(clicked()), this, SLOT(loadGame()));
	start->setGeometry(WINDOW_MAX_X/2-45, WINDOW_MAX_Y/2+180, 90, 30);
	startScreen->addWidget(start);
	}

/** Called after the opening screen is dismissed, initializes and begins the game
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::begin()
	{
	score = 0;
	icicleCounter = 0;
	invCounter = 0;
	speed = 1.0;
	movePlayer = false;
	isAlive = true;

	//---Creating Game Window---//
	gameScreen = new MyGraphicsScene(this);
   gameScreen->setSceneRect(1, 1, WINDOW_MAX_X-2, WINDOW_MAX_Y-2);
   view->setScene( gameScreen );
   gameScreen->addItem(background);
	gameScreen->setFocus();

	//---Creating Menu Buttons---//
	returnButton = new QPushButton("Return");
	connect(returnButton, SIGNAL(clicked()), this, SLOT(returnGame()));
	returnButton->setGeometry(WINDOW_MAX_X/2-60, WINDOW_MAX_Y/2-60, 120, 60);
	gameScreen->addWidget(returnButton);
  	returnButton->hide();
  	
  	quitButton = new QPushButton("Quit");
   connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	quitButton->setGeometry(WINDOW_MAX_X/2-60, WINDOW_MAX_Y/2, 120, 60);
	gameScreen->addWidget(quitButton);
	quitButton->hide();
	
	//---Creating Game Labels---//
	nameLabel = new QLabel(userName);
	QFont font("Quicksand");
	font.setPointSize(14);
  	nameLabel->setFont(font);
	nameLabel->setGeometry(55, WINDOW_MAX_Y-70, 180, 40);
	nameLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);color:yellow;");
	gameScreen->addWidget(nameLabel);

	label = new QLabel("Score: ");
  	label->setFont(font);
	label->setGeometry(55, WINDOW_MAX_Y-40, 60, 40);
	label->setStyleSheet("background-color: rgba(255, 255, 255, 0);color:yellow;");
	gameScreen->addWidget(label);

	scoreLabel = new QLabel(QString::number(score));
  	scoreLabel->setFont(font);
	scoreLabel->setGeometry(115, WINDOW_MAX_Y-40, 60, 40);
	scoreLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);color:yellow;");
	gameScreen->addWidget(scoreLabel);

   //---Creating Walls---//   
   leftWall1 = new StaticObject(wall, 'w', 0, 0, WINDOW_MAX_X, true, speed);
	rightWall1 = new StaticObject(wall, 'w', 0, 0, WINDOW_MAX_X, false, speed);
	leftWall2 = new StaticObject(wall, 'w', -wall->height()+1, 0, WINDOW_MAX_X, true, speed);
	rightWall2 = new StaticObject(wall, 'w', -wall->height()+1, 0, WINDOW_MAX_X, false, speed);
   
   gameScreen->addItem(leftWall1);
   gameScreen->addItem(rightWall1);
   gameScreen->addItem(leftWall2);
   gameScreen->addItem(rightWall2);
   
   //---Setting Bounds---//
   leftBound = leftWall1->getWidth();
   rightBound = WINDOW_MAX_X - rightWall1->getWidth();

   //---Creating Player---//
	player = new Climber(playerA, playerB, leftBound, rightBound, speed);
   gameScreen->addItem(player);
   
   timer->start();
	}

/** Dismisses the opening screen
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::dismissOpening()
	{
	title->hide();
	delete title;
	display->hide();
	delete display;
	instructionLabel->hide();
	delete instructionLabel;

	userName = nameInput->text();
	nameInput->hide();
	delete nameInput;
	
	start->hide();
	}

/** Called every iteration of the timer, generates objects randomly
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::generateObjects()
	{
	int generator = rand() % 7000 - (score/10); //As time progresses, things show up more frequently
	int randomX = 50 + rand() % 380;
	bool temp = false;

	if(generator % 2 == 0)
		{
		temp = true;
		}

	if(0 <= generator && generator < 25 && icicleCounter > 70) // Icicle
		{
	   StaticObject *ice = new StaticObject(icicle, 'i', -icicle->height(), leftBound, rightBound, temp, speed);
   	gameScreen->addItem(ice);
   	objects.push_back(ice);

   	icicleCounter = 0;
		}
	
	else if(30 <= generator && generator < 32)//Star
		{
		Star *myStar = new Star(star, randomX, -star->height(), leftBound, rightBound, temp, speed);
   	gameScreen->addItem(myStar);
   	objects.push_back(myStar);
		}
	
	else if(100 <= generator && generator < 102)//Bird
		{
		int side = -bird->width();
		
		if(temp)
			{
			side = WINDOW_MAX_X+bird->width();
			}

	   Bird *myBird = new Bird(bird, side, 300, temp, speed);
   	gameScreen->addItem(myBird);
   	objects.push_back(myBird);
		}
	
	else if(500 <= generator && generator < 509)//Goat
		{		
	  	Goat *myGoat = new Goat(goat, randomX, -goat->height()-1, leftBound, rightBound, temp, speed);
		gameScreen->addItem(myGoat);
		objects.push_back(myGoat);
		
		StaticObject *myRope = new StaticObject(rope, 'r', -1, leftBound, rightBound, true, speed);
		gameScreen->addItem(myRope);
		objects.push_back(myRope);
		}

	else if(800 <= generator && generator < 806)//Monkey
		{
		Monkey *myMonkey = new Monkey(monkey, -monkey->height(), leftBound, rightBound, temp, speed);
		gameScreen->addItem(myMonkey);
		objects.push_back(myMonkey);
		}
	
	++icicleCounter;
	}

/** Called in every iteration of the timer, handles collision between player and objects
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::handleCollisions()
	{
	for(std::vector<GameObject*>::iterator it = objects.begin(); it != objects.end(); ++it)
		{
		if(player->collidesWithItem((*it)))
			{
			if(!player->isInvincible() && ((*it)->getObject() == 'i' || //Collides with Icicle
				(*it)->getObject() == 'b' || (*it)->getObject() == 'm')) //Collides with Bird or Monkey
				{
				isAlive = false;
				break;
				}
			
			else if((*it)->getObject() == 's') //Collides with Star
				{
				(*it)->hide();
				delete (*it);
				objects.erase(it);
				--it;
				
				player->setInvincible(true);
				label->setStyleSheet("background-color:rgba(255, 255, 255, 0); color:green;");
				scoreLabel->setStyleSheet("background-color:rgba(255, 255, 255, 0); color:green;");
				invCounter = 1200;
				
				break;
				}
			
			else if((*it)->getObject() == 'g') //Collides with Goat
				{
				(*it)->hide();
				delete (*it);
				objects.erase(it);
				--it;

				score += 500;
				break;
				}
			}
		}
	}

/** Called every iteration of the timer, deletes objects off the screen
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::handleOffscreen()
	{
	//---Handling of the Walls---//
	if(leftWall1->getY() >= WINDOW_MAX_Y)
		{
		leftWall1->setY(-wall->height() + 2 + (leftWall1->getY() - WINDOW_MAX_Y));
		rightWall1->setY(-wall->height() + 2 + (rightWall1->getY() - WINDOW_MAX_Y));
		}
	
	else if(leftWall2->getY() >= WINDOW_MAX_Y)
		{
		leftWall2->setY(-wall->height() + 2 + (leftWall2->getY() - WINDOW_MAX_Y));
		rightWall2->setY(-wall->height() + 2 + (rightWall2->getY() - WINDOW_MAX_Y));
		}

	//---Handling of the Other Objects---//
	if(icicleCounter % 10 == 0)
		{//Removes offscreen objects every ~10 intervals to increse performance
		for(std::vector<GameObject*>::iterator it = objects.begin(); it != objects.end(); ++it)
			{
			if((*it)->getX() + (*it)->getWidth()*2 < 0 ||
				(*it)->getX() - (*it)->getWidth() > WINDOW_MAX_X || (*it)->getY() > WINDOW_MAX_Y)
				{
				(*it)->hide();
				delete (*it);
				objects.erase(it);
				--it;
				}
			}
		}
	}

/** When the game ends, displays game over and provides a quit button
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::callEnd()
	{
	endLabel = new QLabel("Game Over!");
	QFont font("Quicksand", 36);
  	endLabel->setFont(font);
  	endLabel->setAlignment(Qt::AlignCenter);
	endLabel->setGeometry(0, 40, WINDOW_MAX_X, 80);
	endLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);color:red;");
	gameScreen->addWidget(endLabel);

	quitButton->show();
	}

//---Slots---//
/** When timer is activated, begins the game
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::animate()
	{
	if(isAlive)
		{
		//---Movement of Player---//
		if(movePlayer)
			{
			player->move();
		
			if(player->getX() <= leftBound || (player->getX() + player->getWidth()) >= rightBound)
				{
				movePlayer = false;
				}
			}
		else
			{
			player->update();
			}
	
		//---Movement of Game Things---//
		for(int i = 0; i < (int) objects.size(); ++i)
			{
			objects[i]->move();
			}

		//---Movement of Walls---//
		leftWall1->move();
		rightWall1->move();
		leftWall2->move();
		rightWall2->move();


		//---Handling of Object Generation and Score---//
		generateObjects();
		++score;
		scoreLabel->setText(QString::number(score));
		
		//---Handling of Invincibility---//
		if(invCounter > 0)
			{
			--invCounter;
			
			if(invCounter < 200)
				{
				if(invCounter % 10 == 0)
					{
					label->setStyleSheet("background-color:rgba(255, 255, 255, 0); color:yellow;");
					scoreLabel->setStyleSheet("background-color:rgba(255, 255, 255, 0); color:yellow;");
					}
				else if(invCounter % 10 == 5)
					{
					label->setStyleSheet("background-color:rgba(255, 255, 255, 0); color:green;");
					scoreLabel->setStyleSheet("background-color:rgba(255, 255, 255, 0); color:green;");
					}
				}
			}
			
		else if(invCounter <= 0 && player->isInvincible())
			{
			player->setInvincible(false);
			label->setStyleSheet("background-color: rgba(255, 255, 255, 0);color:yellow;");
			scoreLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);color:yellow;");
			}
		
		if(score % 1500 == 0) // For every 1500 your score goes up, the timer speeds up
			{
			for(std::vector<GameObject*>::iterator it = objects.begin(); it != objects.end(); ++it)
				{
				(*it)->speedUp();
				}
			
			leftWall1->speedUp();
			rightWall1->speedUp();
			leftWall2->speedUp();
			rightWall2->speedUp();

			speed += .5;
			}
		
		handleCollisions();
		}
	
	else
		{
		if(player->getY() >= WINDOW_MAX_Y)
			{
			callEnd();
			timer->stop();
			}
		else
			{
			player->setY(player->getY()+4);
			}
		}
	
	handleOffscreen();
	}

/** Function to begin the game after user inputs a name
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::loadGame()
	{
	userName = nameInput->text();

	if(userName == "")
		{
		display->setText("Error! Enter your name");
		return;
		}

	dismissOpening();
	begin();
	}

/** Function to unpause the game
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::returnGame()
	{
	pause();
	}
