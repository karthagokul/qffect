#include "qeditor.h"
#include <QPainter>
#include <QDebug>

QEditor::QEditor(QWidget *parent) : QWidget(parent)
{

}

void QEditor::setPixmap(const QPixmap &aPixmap)
{
    mPixmap=aPixmap.copy(aPixmap.rect());
    update();
}

void QEditor::loadPixmap(const QString &aFileName)
{
    if(!mPixmap.load(aFileName))
    {
        qDebug()<<"loading failed";
    }
    update();
}

void QEditor::paintEvent(QPaintEvent *event)
{
   // if(mPixmap.isNull()) return;
    QPainter p(this);
    p.drawPixmap(rect(),mPixmap);
}

QImage QEditor::getImage() const
{
    return mPixmap.toImage();
}
