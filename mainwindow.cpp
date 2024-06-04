#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamelogic.h"
#include <QDebug>
#include <QPixmap>
#include <sstream>

MainWindow::MainWindow(QWidget *parent, GameLogic *gameLogicPtr)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gl(gameLogicPtr)
{
    ui->setupUi(this);
    updateLocationLabel(); // init game screen withfirst location information: name, description, image
    updateDescriptionLabel();
    updateImageLabel();
    setMapLabel();
    updateItemLabel(); // display items at starting location
    updateInventoryLabel(); // init inventory to empty
    updateEdInventoryLabel();
    updateEdItemLabel();
    updateCalories();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateImageLabel()
{
    QString imagePath = QString::fromStdString(gl->getCurrentLocation()->getImagePath());
    QPixmap image(imagePath);
    if (!image.isNull()) {
        ui->imageLabel->setPixmap(image);
        ui->imageLabel->setScaledContents(true);
    } else {
        qDebug() << "Failed to load image: " << imagePath;
    }
}

void MainWindow::setMapLabel() {
    QString imagePath = QString::fromStdString(":/images/map.png");
    QPixmap image(imagePath);
    if (!image.isNull()) {
        ui->mapLabel->setPixmap(image);
        ui->mapLabel->setScaledContents(true);
    } else {
        qDebug() << "Failed to load map image: " << imagePath;
    }
}

void MainWindow::on_northButton_clicked()
{
    qDebug() << "North button clicked";
    if (gl->moveLocGL(0)) {
        updateLocationLabel();
        updateDescriptionLabel();
        updateImageLabel();
        updateItemLabel();
        updateEdInventoryLabel();
        updateEdItemLabel();
    } else {
        qDebug() << "Cannot move North!";
    }
}

void MainWindow::on_westButton_clicked()
{
    qDebug() << "West button clicked";
    if (gl->moveLocGL(3)) {
        updateLocationLabel();
        updateDescriptionLabel();
        updateImageLabel();
        updateItemLabel();
        updateEdInventoryLabel();
        updateEdItemLabel();
    } else {
        qDebug() << "Cannot move West!";
    }
}

void MainWindow::on_eastButton_clicked()
{
    qDebug() << "East button clicked";
    if (gl->moveLocGL(2)) {
        updateLocationLabel();
        updateDescriptionLabel();
        updateImageLabel();
        updateItemLabel();
        updateEdInventoryLabel();
        updateEdItemLabel();
    } else {
        qDebug() << "Cannot move East!";
    }
}

void MainWindow::on_southButton_clicked()
{
    qDebug() << "South button clicked";
    if (gl->moveLocGL(1)) {
        updateLocationLabel();
        updateDescriptionLabel();
        updateImageLabel();
        updateItemLabel();
        updateEdInventoryLabel();
        updateEdItemLabel();
    } else {
        qDebug() << "Cannot move South!";
    }
}

void MainWindow::updateLocationLabel()
{
    ui->locationLabel->setText(QString::fromStdString(gl->getCurrentLocation()->getName()));
    qDebug() << "Location updated to: " << QString::fromStdString(gl->getCurrentLocation()->getName());
}

void MainWindow::updateDescriptionLabel()
{
    ui->descriptionLabel->setText(QString::fromStdString(gl->getCurrentLocation()->getDescription()));
    qDebug() << "Description updated to: " << QString::fromStdString(gl->getCurrentLocation()->getDescription());
}

void MainWindow::updateItemLabel()
{
    ui->itemLabel->setText(QString::fromStdString(gl->getCurrentLocation()->getInventory().getStringInvList()));
    qDebug() << "ItemLabel updated to: " << QString::fromStdString(gl->getCurrentLocation()->getInventory().getStringInvList());
}

void MainWindow::updateEdItemLabel()
{
    ui->edItemLabel->setText(QString::fromStdString(gl->getCurrentLocation()->getEdInventory().getStringInvList()));
    qDebug() << "ItemLabel updated to: " << QString::fromStdString(gl->getCurrentLocation()->getEdInventory().getStringInvList());
}



void MainWindow::updateInventoryLabel()
{

    ui->inventoryLabel->setText(QString::fromStdString(gl->getInventory().getStringInvList()));
    qDebug() << "ItemLabel updated to: " << QString::fromStdString(gl->getInventory().getStringInvList());
}


void MainWindow::updateEdInventoryLabel()
{

    ui->edInventoryLabel->setText(QString::fromStdString(gl->getEdInventory().getStringInvList()));
    qDebug() << "ItemLabel updated to: " << QString::fromStdString(gl->getEdInventory().getStringInvList());
}

void MainWindow::updateCalories() {
    std::string calorieString = std::to_string(TOTAL_CALORIES);
    ui->calories->setText(QString::fromStdString(calorieString));
}

void MainWindow::on_takeButton_clicked()
{
    QString itemName = ui->takeItemName->text();
    if (gl->takeItemFromLocation(itemName.toStdString())) {
        updateItemLabel();
        updateInventoryLabel();
        ui->takeItemName->clear();
        qDebug() << "Item taken: " << itemName;
    } else {
        qDebug() << "Item not found: " << itemName;
    }
}


void MainWindow::on_eatButton_clicked()
{
    QString itemName = ui->takeItemName->text();
    std::string itemNameS = itemName.toStdString();
    EdibleItem* item = gl->getCurrentLocation()->getEdInventory().findItem(itemName.toStdString());
    if (item->getName() == itemName.toStdString()) {
        EdibleInventory newInv(itemName.toStdString(), gl->getEdInventory()); // Create a new Inventory object on the stack
        gl->getCurrentLocation()->getEdInventory() = newInv; // Assign the new object by copy
    gl->getPlayer().eatItem(*(gl->getCurrentLocation()->getEdInventory().findItem(itemName.toStdString())));
    updateEdInventoryLabel();
    updateCalories();
}

}
