#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotTimerAlarm();
    void slotAnimate();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTime start_time;
    bool flag_animate;
    double accel;
};

#endif // MAINWINDOW_H
