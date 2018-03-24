#ifndef EFFECTMANAGER_H
#define EFFECTMANAGER_H

#include <QObject>
#include <QStack>
#include <QImage>
#include <QThread>

class IEffect:public QObject
{
public:
    IEffect(QImage aImage);
protected:
    //need to see the result image
    QImage mSourceImage;
public:
    virtual QImage process()=0;
    QImage revert();
};

class SepiaEffect:public IEffect
{
public:
    SepiaEffect(QImage aImage);
    QImage process();
};

class EffectCommand:public QThread
{
    Q_OBJECT
public:
    EffectCommand(IEffect *aEffect,QObject *aParent);
    ~EffectCommand();
protected:
    void run();
signals:
    void ready(const QImage &aImage);
private:
    IEffect *mEffect;
};

class EffectManager : public QObject
{
    Q_OBJECT
public:
    EffectManager(QObject *aParent);
    void apply(EffectCommand *aCommand);
signals:
    void ready(const QImage &aImage);
private:
    QStack<EffectCommand *> mCommands;
};

#endif // EFFECTMANAGER_H
