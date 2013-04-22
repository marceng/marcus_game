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
	
		/** Displays the window on the screen*/
		void show();
    
	private:
		//---Graphics Stuff---//
		QGraphicsScene *startScreen;
		QGraphicsScene *gameScreen;
		QGraphicsView *view;
		
		QTimer *timer;
		QString userName;
		
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
		vector<GameObject*> objects;
		
		//---Start Screen---//
		QLabel *title;
		QLabel *display;
		QLineEdit *nameInput;
		QPushButton *start;
		
		void loadObjects();
		void loadOpening();
		void begin();
		void dismissOpening();
		void handleOffscreen();

	public slots:
		/** Handles the timer to move tiles*/
		void animate();
		void loadGame();
	};

#endif // MAINWINDOW_H
