#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamelogic.h"
#include "player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, GameLogic *gameLogicPtr);
    ~MainWindow();

private slots:
    void on_northButton_clicked(); // MOVE NSEW, just calls gamelogic get location to
    void on_westButton_clicked();
    void on_eastButton_clicked();
    void on_southButton_clicked();

    void on_takeButton_clicked();

    void on_eatButton_clicked();

    void on_useButton_clicked();

private:
    Ui::MainWindow *ui;
    GameLogic *gl;

    void updateLocationLabel(); // Update location name text
    void updateDescriptionLabel(); // update desc text
    void updateImageLabel();  //update game screen main image
    void setMapLabel(); // just runs once on initialisation of mainwindow
    void updateItemLabel(); // update items available in room
    void updateInventoryLabel(); // update items in inventory
    void updateEdInventoryLabel();
    void updateEdItemLabel();
    void updateCalories();
};

#endif // MAINWINDOW_H
