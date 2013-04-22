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
	
	//---Creating Timer---///
   timer = new QTimer(this);
   timer->setInterval(5);
   connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
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
	//QPixmap *playerA;
	//QPixmap *playerB;
	}

void MainWindow::loadOpening()
	{
	startScreen->addItem(background);
	
	//---Creating Title---//
	title = new QLabel("Mountain Climber");	
	QFont font( "Quicksand", 46);
  	title->setFont(font);
	title->setGeometry(0, 40, WINDOW_MAX_X, 120);
	title->setAlignment(Qt::AlignCenter);
	title->setStyleSheet("background-color: rgba(255, 255, 255, 0); color : yellow;");
	startScreen->addWidget(title);
	
	//---Creating Name Input---//
	display = new QLabel("Enter your name:");
	QFont font2( "Quicksand");
  	display->setFont(font2);
	display->setGeometry(WINDOW_MAX_X/2-90, WINDOW_MAX_Y/2+30, 180, 30);
	display->setAlignment(Qt::AlignCenter);
	display->setStyleSheet("background-color: rgba(255, 255, 255, 0); color : white;");
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
	gameScreen = new QGraphicsScene();
   gameScreen->setSceneRect(1, 1, WINDOW_MAX_X-2, WINDOW_MAX_Y-2);
   view->setScene( gameScreen );
   gameScreen->setFocus();
   gameScreen->addItem(background);
   
   StaticObject *right = new StaticObject(wall, 'w', 0, 0, WINDOW_MAX_X, false);
   gameScreen->addItem(right);
   objects.push_back(right);	
   
   StaticObject *left = new StaticObject(wall, 'w', 0, 0, WINDOW_MAX_X, true);
   gameScreen->addItem(left);
   objects.push_back(left);
   
   leftBound = left->getWidth();
   rightBound = WINDOW_MAX_X - right->getWidth();

   timer->start();
	}

void MainWindow::dismissOpening()
	{
	title->hide();
	delete title;
	display->hide();
	delete display;
	nameInput->hide();
	delete nameInput;
	
	start->hide();
	}

void MainWindow::generateObjects()
	{/*
	Star *myStar = new Star(star, 80, 200, leftBound, rightBound, false);
   gameScreen->addItem(myStar);
   objects.push_back(myStar);
   
   Goat *myGoat = new Goat(goat, 140, 40, leftBound, rightBound, true);
   gameScreen->addItem(myGoat);
   objects.push_back(myGoat);
   
   StaticObject *myRope = new StaticObject(rope, 'r', 40+goat->height(), leftBound, rightBound, true);
   gameScreen->addItem(myRope);
   objects.push_back(myRope);
  
   Bird *myBird = new Bird(bird, WINDOW_MAX_X+bird->width(), 300, true);
   //Bird *myBird = new Bird(bird, -bird->width(), 300, false);
   gameScreen->addItem(myBird);
   objects.push_back(myBird);
   
   Monkey *myMonkey = new Monkey(monkey, 150, leftBound, rightBound, true);
   gameScreen->addItem(myMonkey);
   objects.push_back(myMonkey);

   StaticObject *ice = new StaticObject(icicle, 'i', 90, leftBound, rightBound, true);
   gameScreen->addItem(ice);
   objects.push_back(ice);
  	*/
	}

void MainWindow::handleOffscreen()
	{
	bool needWall = false;
	for(std::vector<GameObject*>::iterator it = objects.begin(); it != objects.end(); ++it)
		{
		if((*it)->getObject() == 'w' && ((*it)->getY() + (*it)->getHeight()) == WINDOW_MAX_Y)
			{
			needWall = true;
			}

		if((*it)->getX() + (*it)->getWidth()*2 < 0 ||
			(*it)->getX() - (*it)->getWidth() > WINDOW_MAX_X || (*it)->getY() > WINDOW_MAX_Y)
			{
			cout << "Deleting: " << (*it)->getObject() << endl;
			(*it)->hide();
			delete (*it);
			objects.erase(it);
			--it;
			}
		}
	
	//---Generating New Walls---//
	if(needWall)
		{
		StaticObject *right = new StaticObject(wall, 'w', -wall->height()+1, 0, WINDOW_MAX_X, false);
		gameScreen->addItem(right);
		objects.push_back(right);	
		
		StaticObject *left = new StaticObject(wall, 'w', -wall->height()+1, 0, WINDOW_MAX_X, true);
		gameScreen->addItem(left);
		objects.push_back(left);
		
		needWall = false;
		}
	}

//---Slots---//
/** When timer is activated, begins the game
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::animate()
	{		
	for(int i = 0; i < (int) objects.size(); ++i)
		{
		objects[i]->move();
		}
	
	generateObjects();
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

/** Destructor that deallocates memory */
MainWindow::~MainWindow()
	{
   timer->stop();
   delete timer;
   
   delete background;
   
   delete start;
   delete startScreen;
   delete gameScreen;
   delete view;
	}

