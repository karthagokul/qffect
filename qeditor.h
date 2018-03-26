#ifndef QEDITOR_H
#define QEDITOR_H

#include <QWidget>

class QEditor : public QWidget
{
    Q_OBJECT
public:
    explicit QEditor(QWidget *parent = 0);
    void loadPixmap(const QString &aFileName);
    void paintEvent(QPaintEvent *event);
    QImage getImage() const;
signals:

public slots:
    void setPixmap(const QPixmap &aPixmap);

private:
    QPixmap mPixmap;

};

#endif // QEDITOR_H
