#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_checkBox_server_stateChanged(int checked);

private:
    Ui::MainWindow *ui;
    QTcpServer* serverSocket;
    QTcpSocket* clientSocket;
    QString logString;
    bool serverMode;
    bool connected;
    bool listening;
};

#endif // MAINWINDOW_H
