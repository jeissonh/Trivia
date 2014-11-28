#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(actionNewTriggered()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

#include <QDebug>

void MainWindow::actionNewTriggered()
{
	qDebug() << "action new was triggered!";
}
