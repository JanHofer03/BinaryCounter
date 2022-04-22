#ifndef COUNTERWIDGET_H
#define COUNTERWIDGET_H

#include <QLCDNumber>
#include <QLabel>
#include <QTimer>
#include "gpio.h"

class CounterWidget : public QWidget
{
    Q_OBJECT

public:
    CounterWidget(QWidget *parent = nullptr);
    ~CounterWidget();

public slots:
    void updateCounter();

private:
     int m_count;
     QTimer m_timer;
     Gpio m_gpio;
     QLCDNumber* lcdDisplay = nullptr;

};

#endif // COUNTERWIDGET_H
