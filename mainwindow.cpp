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
   timer->setInterval(5);
   connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
	}

/** Destructor that deallocates memory */
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
   	//delete returnButton;
 		//delete quitButton;
   	//delete gameScreen;
		}

   delete startScreen;
   delete view;
	}

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

void MainWindow::loadOpening()
	{
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

	//---Creating Start Button---//
	start = new QPushButton("Begin!"); 
	connect(start, SIGNAL(clicked()), this, SLOT(loadGame()));
	start->setGeometry(WINDOW_MAX_X/2-30, WINDOW_MAX_Y/2+180, 60, 60);
	startScreen->addWidget(start);
	}

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

void MainWindow::dismissOpening()
	{
	title->hide();
	delete title;
	display->hide();
	delete display;

	userName = nameInput->text();
	nameInput->hide();
	delete nameInput;
	
	start->hide();
	}

void MainWindow::generateObjects()
	{
	int generator = rand() % 15000;
	int randomX = 50 + rand() % 380;
	bool temp = false;

	if(generator % 2 == 0)
		{
		temp = true;
		}

	if(0 <= generator && generator < 20 && icicleCounter > 100) // Icicle
		{
	   StaticObject *ice = new StaticObject(icicle, 'i', -icicle->height(), leftBound, rightBound, temp, speed);
   	gameScreen->addItem(ice);
   	objects.push_back(ice);

   	icicleCounter = 0;
		}
	
	else if(30 <= generator && generator < 33)//Star
		{
		Star *myStar = new Star(star, randomX, -star->height(), leftBound, rightBound, temp, speed);
   	gameScreen->addItem(myStar);
   	objects.push_back(myStar);
		}
	
	else if(100 <= generator && generator < 103)//Bird
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

	else if(800 <= generator && generator < 810)//Monkey
		{
		Monkey *myMonkey = new Monkey(monkey, -monkey->height(), leftBound, rightBound, temp, speed);
		gameScreen->addItem(myMonkey);
		objects.push_back(myMonkey);
		}
	
	++icicleCounter;
	}
	
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
				invCounter = 2000;
				
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
			}
			
		else if(invCounter <= 0 && player->isInvincible())
			{
			player->setInvincible(false);
			label->setStyleSheet("background-color: rgba(255, 255, 255, 0);color:yellow;");
			scoreLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);color:yellow;");
			}
		
		if(score % 2000 == 0) // For every 2000 your score goes up, the timer speeds up
			{
			for(std::vector<GameObject*>::iterator it = objects.begin(); it != objects.end(); ++it)
				{
				(*it)->speedUp();
				}
			
			leftWall1->speedUp();
			rightWall1->speedUp();
			leftWall2->speedUp();
			rightWall2->speedUp();

			speed += .25;
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
			player->setY(player->getY()+1);
			}
		}
	
	handleOffscreen();
	}

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

void MainWindow::returnGame()
	{
	pause();
	}
