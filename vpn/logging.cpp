#include "logging.h"

Logging::Logging(QObject *parent) :
    QObject(parent)
{
}

void Logging::write(QString str) {
    emit valueChanged(str);
}
