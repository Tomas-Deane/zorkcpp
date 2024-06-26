QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    edibleitem.cpp \
    gamelogic.cpp \
    inventory.cpp \
    item.cpp \
    location.cpp \
    main.cpp \
    mainwindow.cpp \
    negativecalorieexception.cpp \
    player.cpp \
    print_namespace.cpp \
    seed.cpp \
    useableitem.cpp

HEADERS += \
    edibleitem.h \
    gamelogic.h \
    inventory.h \
    item.h \
    location.h \
    mainwindow.h \
    negativecalorieexception.h \
    player.h \
    print_namespace.h \
    seed.h \
    useableitem.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qtResourceFile.qrc

DISTFILES += \
    ../../../../../Pictures/Screenshots/Screenshot 2023-11-17 125326.png
