TARGET = Trivia
TEMPLATE = app
QT += core gui widgets
CONFIG += c++11

INCLUDEPATH += source

HEADERS += source/MainWindow.h
HEADERS += source/NumericQuestion.h
HEADERS += source/Question.h
HEADERS += source/SingleChoiceQuestion.h
HEADERS += source/TextualQuestion.h
HEADERS += source/TriviaGame.h

SOURCES += source/main.cpp
SOURCES += source/MainWindow.cpp
SOURCES += source/NumericQuestion.cpp
SOURCES += source/Question.cpp
SOURCES += source/SingleChoiceQuestion.cpp
SOURCES += source/TextualQuestion.cpp
SOURCES += source/TriviaGame.cpp

FORMS += source/MainWindow.ui

RESOURCES += assets/assets.qrc
