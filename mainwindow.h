#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class EffectManager;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected slots:
    void onLoadButtonClickTemp();
    void onSepiaTemp();
    void imageReady(const QImage &aImage);

private:
    Ui::MainWindow *ui;
    EffectManager *mEffectManager;
};

#endif // MAINWINDOW_H
