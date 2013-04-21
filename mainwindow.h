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

#define WINDOW_MAX_X 601
#define WINDOW_MAX_Y 601

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
		
		//---Start Screen---//
		QLabel *title;
		QLabel *display;
		QLineEdit *nameInput;
		QPushButton *start;
		
		void loadObjects();
		void loadOpening();
		void begin();
		void dismissOpening();

	public slots:
		/** Handles the timer to move tiles*/
		void animate();
		void loadGame();
	};

#endif // MAINWINDOW_H
