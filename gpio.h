#ifndef GPIO_H
#define GPIO_H

#include <QObject>

class Gpio : public QObject
{
    Q_OBJECT
public:
    explicit Gpio(QObject *parent = nullptr); // constructor
    ~Gpio(); // destructor for clean-up
    void set(int pin, bool value);
    void setPattern(int pattern);
    bool get(int pin);
    bool isActivated(int pin);

signals:

public slots:

private:
    int m_handle;
    QList<bool> m_oldstates;

};

#endif // GPIO_H
