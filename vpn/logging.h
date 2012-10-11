#ifndef LOGGING_H
#define LOGGING_H

#include <QObject>

// Facade Class that handles all writing to Qt text window.
// The output target is connected via signals and slots from mainwindow.h

namespace Ui {
class Logging;
}

class Logging : public QObject
{
    Q_OBJECT
public:
    explicit Logging(QObject *parent = 0);
    
    void write(QString str);

signals:
    void valueChanged(QString str);
    
};

#endif // LOGGING_H
