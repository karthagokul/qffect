#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <effectmanager.h>
#include <QCoreApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mEffectManager=new EffectManager(this);
    connect(ui->loadButton,SIGNAL(clicked(bool)),this,SLOT(onLoadButtonClickTemp()));
    connect(ui->sepiaButton,SIGNAL(clicked(bool)),this,SLOT(onSepiaTemp()));
    connect(mEffectManager,SIGNAL(ready(QImage)),this,SLOT(imageReady(QImage)));

}

void MainWindow::onLoadButtonClickTemp()
{
    QString tempFile(qApp->applicationDirPath()+"/test.jpg");
    ui->mEditor->loadPixmap(tempFile);
}

void MainWindow::onSepiaTemp()
{
   IEffect *aEffect=new SepiaEffect(ui->mEditor->getImage());
   EffectCommand *aCommand=new EffectCommand(aEffect,this);
   mEffectManager->apply(aCommand);
}

void MainWindow::imageReady(const QImage &aImage)
{
    qDebug()<<"Image Ready";
    ui->mEditor->setPixmap(QPixmap::fromImage(aImage));
}
MainWindow::~MainWindow()
{
    delete ui;
}
