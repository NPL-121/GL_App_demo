#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Start time
    this->start_time = QTime::currentTime();
    ui->label->setText(this->start_time.toString("hh:mm:ss"));
    // Timer
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
        timer->start(1); // И запустим таймер
    // Checkbox 'Animate' connect
    connect(ui->checkBox, SIGNAL(stateChanged(int)), this, SLOT(slotAnimate()));

    ui->openGLWidget->delta_time = 0.0;
    flag_animate = false;
    accel = 0.0; // ускорение вращения
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimerAlarm()
{
    /* Ежесекундно обновляем данные по текущему времени
     * Перезапускать таймер не требуется
     * */
    ui->label->setText("Local time: " + QTime::currentTime().toString("hh:mm:ss"));
    // time elapsed -> label_2
    QString Sdelta = QString::number(start_time.elapsed()/1000.0);
    ui->label_2->setText("Elapsed time: " + Sdelta);

    // Checkbox 'Animate'
    if (flag_animate == true)
    {
        accel = accel + 0.01;
        if (accel > 1.0) accel = 1.0;
        ui->openGLWidget->delta_time = ui->openGLWidget->delta_time + accel;
    }
    else
    {
        accel = accel - 0.01;
        if (accel < 0.0) accel = 0.0;
        ui->openGLWidget->delta_time = ui->openGLWidget->delta_time + accel;
    }

    // Radiobutton 'Primitives'
    if (ui->radioButton->isChecked() == true)
    {
        ui->openGLWidget->primitives_type = 1;
    }
    if (ui->radioButton_2->isChecked() == true)
    {
        ui->openGLWidget->primitives_type = 2;
    }
    if (ui->radioButton_3->isChecked() == true)
    {
        ui->openGLWidget->primitives_type = 3;
    }
    if (ui->radioButton_4->isChecked() == true)
    {
        ui->openGLWidget->primitives_type = 4;
    }
    if (ui->radioButton_5->isChecked() == true)
    {
        ui->openGLWidget->primitives_type = 5;
    }
    if (ui->radioButton_6->isChecked() == true)
    {
        ui->openGLWidget->primitives_type = 6;
    }
}

void MainWindow::slotAnimate()
{
    if (ui->checkBox->isChecked() == true)
    {
        flag_animate = true;
    }
    else
    {
        flag_animate = false;
    }
}
