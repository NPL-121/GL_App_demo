#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTimer>
#include <QTime>


class MyGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    MyGLWidget(QWidget* parent = nullptr);
    GLfloat delta_time;
    short int primitives_type;

private:
    float scale_scene;

private slots:
    //void slotTimer();

protected:
    void initializeGL() override;
    void paintGL() override;
    QTimer *timer;
};

#endif // MYGLWIDGET_H
