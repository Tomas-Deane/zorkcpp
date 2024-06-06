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
    std::string text = gl->getCurrentLocation()->getInventory().getStringInvList();
    if (text.length() > 1) {
        ui->itemLabel->setText(QString::fromStdString(text));
    } else {
        ui->itemLabel->setText(QString::fromStdString("This location has no items"));
    }
    qDebug() << "itemLabel updated to: " << QString::fromStdString(text);
}


void MainWindow::updateInventoryLabel()
{
    std::string text = gl->getInventory().getStringInvList();
    if (text.length() > 1) {
    ui->inventoryLabel->setText(QString::fromStdString(text));
    } else {
        ui->inventoryLabel->setText(QString::fromStdString("Your Inventory is Empty"));
    }
    qDebug() << "InventoryLabel updated to: " << QString::fromStdString(text);
}



void MainWindow::updateCalories() {
    std::string calorieString = std::to_string(TOTAL_CALORIES);
    calorieString = "Calories: " + calorieString;
    ui->calories->setText(QString::fromStdString(calorieString));
}

void MainWindow::on_takeButton_clicked()
{
    QString itemName = ui->takeItemName->text();
    if (gl->takeItemFromLocation(itemName.toStdString())) {
        updateItemLabel();
        updateInventoryLabel();
        qDebug() << "Item taken: " << itemName;
    } else {
        qDebug() << "Item not found: " << itemName;
    }
}


void MainWindow::on_eatButton_clicked()
{
    QString itemName = ui->takeItemName->text();
    std::string itemNameS = itemName.toStdString();
    auto item = gl->getInventory().findItem(itemNameS);
    if (item && item->getName() == itemNameS) {
        // Check if the item is edible
        std::shared_ptr<EdibleItem> edibleItem = std::dynamic_pointer_cast<EdibleItem>(item);
        if (edibleItem) {
            // Create a new inventory excluding the item
            Inventory newInv(itemNameS, gl->getInventory()); // Create a new Inventory object on the stack
            gl->getInventory() = newInv; // Assign the new object by copy
            // Player eats the item
            gl->getPlayer().eatItem(edibleItem);

            // Updates
            ui->takeItemName->clear();
            updateCalories();
            updateInventoryLabel();
        } else {
            qDebug() << "Item not edible: " << itemName;
        }
    } else {
        qDebug() << "Item not found: " << itemName;
    }
}

void MainWindow::on_useButton_clicked() {
    QString itemName = ui->takeItemName->text();
    std::string itemNameS = itemName.toStdString();
    auto item = gl->getInventory().findItem(itemNameS);
    if (item && item->getName() == itemNameS) {
        // Check if the item is usable
        std::shared_ptr<UsableItem> usableItem = std::dynamic_pointer_cast<UsableItem>(item);
        if (usableItem) {

            // Updates
            ui->takeItemName->clear();
            updateInventoryLabel();
            ui->recentItemUse->setText(QString::fromStdString(usableItem->getUseDescription()));

        } else {
            qDebug() << "Item not usable: " << itemName;
        }
    } else {
        qDebug() << "Item not found: " << itemName;
    }
}

