#include <QHBoxLayout>
#include "counterwidget.h"
#include "config.h"
#include "gpio.h"

CounterWidget::CounterWidget(QWidget *parent)
    : QWidget(parent), m_count(0), m_timer(this), m_gpio(this)
{
    setWindowTitle("BinaryCounter");
    resize(300, 200);
    QHBoxLayout* layout = new QHBoxLayout(this);
    setLayout(layout);


    // QLCDNumber zur Anzeige des Zaehlerstandes dezimal:

    lcdDisplay = new QLCDNumber(2);
    layout->addWidget(lcdDisplay);

    connect(&m_timer, &QTimer::timeout, this, &CounterWidget::updateCounter);
    m_timer.start(T_UPDATE);
    m_count = 0;
}

CounterWidget::~CounterWidget()
{

}

// Zaehlerstand im Widget und dual ueber LEDs anzeigen:
void CounterWidget::updateCounter()
{
    if(m_gpio.isActivated(BUTTONS[0]) == true)
    {
        m_count--;
    }
    else if (m_gpio.isActivated(BUTTONS[1]) == true)
    {
        m_count = 0;
    }
    else if (m_gpio.isActivated(BUTTONS[2]) == true)
    {
        m_count++;
    }
    if(m_count < 0){
        m_count = 15;
    }

    if(m_count > 15) {
        m_count = 0;

    }

    m_gpio.setPattern(m_count);
    lcdDisplay->display(QString::number(m_count));
}
