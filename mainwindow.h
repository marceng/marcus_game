#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsItemAnimation>
#include <QLineEdit>
#include <QLabel>

#include <iostream>
#include <cstdlib>
#include <vector>
#include "mygraphicsscene.h"

#include "climber.h"
#include "gameobject.h"
#include "bird.h"
#include "goat.h"
#include "monkey.h"
#include "star.h"
#include "staticobject.h"

#define WINDOW_MAX_X 601
#define WINDOW_MAX_Y 601

using namespace std;

class MainWindow : public QWidget
	{
   Q_OBJECT
    
	public:
		/** constructor that sets of the MainWindow view*/
		explicit MainWindow();
		
		/** Destructor that deallocates memory*/
		~MainWindow();

		/** Function to handle pause game*/
		void pause();
		
		/** Function to handle the Key Press*/
		void spacePressed();
	
		/** Displays the window on the screen*/
		void show();

	private:
		//---Graphics Stuff---//
		QGraphicsScene *startScreen;
		MyGraphicsScene *gameScreen;
		QGraphicsView *view;

		//---Game Objects---//
		QGraphicsPixmapItem *background;
		QPixmap *wall;
		QPixmap *icicle;
		QPixmap *bird;
		QPixmap *goat;
		QPixmap *star;
		QPixmap *monkey;
		QPixmap *rope;
		QPixmap *playerA;
		QPixmap *playerB;
		
		Climber *player;
		vector<GameObject*> objects;
		
		int leftBound;
		int rightBound;
		
		//---Start Screen---//
		QLabel *title;
		QLabel *display;
		QLineEdit *nameInput;
		QPushButton *start;
		
		//---Game Screen---//
		QTimer *timer;
		QLabel *nameLabel;
		QLabel *label;
		QLabel *scoreLabel;
		QString userName;
		int score;
		bool movePlayer;
		
		StaticObject *leftWall1;
		StaticObject *leftWall2;
		StaticObject *rightWall1;
		StaticObject *rightWall2;
		
		void loadObjects();
		void loadOpening();
		void begin();
		void dismissOpening();
		void generateObjects();
		void handleOffscreen();

	public slots:
		/** Handles the animation once timer runs*/
		void animate();
		/** Loads game after opening screen*/
		void loadGame();
	};

#endif // MAINWINDOW_H
