#include "mainwindow.h"

using namespace std;

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

/** Displays the board onto the computer screen
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::show()
	{
  	timer->start();
   view->show();
	}

void MainWindow::loadObjects()
	{
	background = new QGraphicsPixmapItem(QPixmap("Images/Background.png"));

	}

void MainWindow::loadOpening()
	{
	startScreen->addItem(background);
	
	//---Creating Name Input---//
	display = new QLabel("Enter your name:");
	display->setGeometry(WINDOW_MAX_X/2-90, WINDOW_MAX_Y/2-60, 180, 30);
	display->setAlignment(Qt::AlignCenter);
	display->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
	startScreen->addWidget(display);
	
	nameInput = new QLineEdit();
	nameInput->setGeometry(WINDOW_MAX_X/2-90, WINDOW_MAX_Y/2-30, 180, 30);
	nameInput->setAlignment(Qt::AlignCenter);
	startScreen->addWidget(nameInput);

	//---Creating Start Button---//
	start = new QPushButton("Begin!"); 
	connect(start, SIGNAL(clicked()), this, SLOT(loadGame()));
	start->setGeometry(WINDOW_MAX_X/2-30, WINDOW_MAX_Y/2+60, 60, 60);
	startScreen->addWidget(start);
	}

//---Slots---//

/** When timer is activated, calls this function to animate tile movement
 	* @param nothing
 	* @return nothing
 	*/
void MainWindow::animate() //figure out way to disable movement while in animation.
	{		

	}

void MainWindow::loadGame()
	{
	userName = nameInput->text();
	if(userName == "")
		{
		display->setText("Error! Enter your name!");
		return;
		}

	cout << "Loading Game..." << endl;
	}

/** Destructor that deallocates memory */
MainWindow::~MainWindow()
	{
   timer->stop();
   delete timer;
   delete startScreen;
   delete view;
	}

