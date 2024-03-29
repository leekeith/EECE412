#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QKeyEvent>
#include "connectionmanager.h"
#include "encryptionhelper.h"
#include "logging.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onConnected();
private slots:
    void on_checkBox_server_stateChanged(int checked);

    void on_pushButton_connect_clicked();



    void on_pushButton_listen_clicked();

    void on_pushButton_send_clicked();

    void on_pushButton_step_clicked();

protected:
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::MainWindow *ui;

    Logging* log;
    ConnectionManager* connectionManager;
    EncryptionHelper* encryptionHelper;
    bool serverMode;
};

#endif // MAINWINDOW_H
