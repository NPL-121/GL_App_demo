#include "myglwidget.h"
#include <QSurfaceFormat>
#include <QtOpenGL/QtOpenGL>
//#include "geom_triangle.h"

MyGLWidget::MyGLWidget(QWidget* parent):
    QOpenGLWidget(parent)
{
    QSurfaceFormat format;

    format.setSamples(8); // не работает
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(3, 2);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);
}

void MyGLWidget::initializeGL()
{
    this->initializeOpenGLFunctions();
    this->scale_scene = 200.0;
    glEnable(GL_MULTISAMPLE); // не работает
}

void Draw_Quad(GLfloat scale)
{
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(-0.5f*scale, -0.5f*scale);
    glVertex2f(0.5f*scale, -0.5f*scale);
    glVertex2f(0.5f*scale, 0.5f*scale);
    glVertex2f(-0.5f*scale, 0.5f*scale);
}

void Draw_Triangle(GLfloat scale)
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.0f*scale, 0.5f*scale);
    glVertex2f(0.5f*scale, -0.5f*scale);
    glVertex2f(-0.5f*scale, -0.5f*scale);
}

void Draw_NGon(GLfloat scale, short int triangleAmount )
{
    GLfloat x, y, radius;
    short int i;
    GLfloat twicePi = 6.28318f;

    x =0.0f; y=0.0f; radius = 0.5f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (scale * radius * cos(i *  twicePi / triangleAmount)),
                    y + (scale * radius * sin(i * twicePi / triangleAmount)));
    }
}

void Draw_Star4(GLfloat scale)
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.0f*scale, 0.5f*scale);
    glVertex2f(0.1f*scale, 0.1f*scale);
    glVertex2f(0.0f*scale, 0.0f*scale);

    glVertex2f(0.0f*scale, 0.0f*scale);
    glVertex2f(0.1f*scale, 0.1f*scale);
    glVertex2f(0.5f*scale, 0.0f*scale);

    glVertex2f(0.5f*scale, 0.0f*scale);
    glVertex2f(0.1f*scale, -0.1f*scale);
    glVertex2f(0.0f*scale, 0.0f*scale);

    glVertex2f(0.0f*scale, 0.0f*scale);
    glVertex2f(0.1f*scale, -0.1f*scale);
    glVertex2f(0.0f*scale, -0.5f*scale);

    glVertex2f(0.0f*scale, -0.5f*scale);
    glVertex2f(-0.1f*scale, -0.1f*scale);
    glVertex2f(0.0f*scale, 0.0f*scale);

    glVertex2f(0.0f*scale, 0.0f*scale);
    glVertex2f(-0.1f*scale, -0.1f*scale);
    glVertex2f(-0.5f*scale, 0.0f*scale);

    glVertex2f(-0.5f*scale, 0.0f*scale);
    glVertex2f(-0.1f*scale, 0.1f*scale);
    glVertex2f(0.0f*scale, 0.0f*scale);

    glVertex2f(0.0f*scale, 0.0f*scale);
    glVertex2f(-0.1f*scale, 0.1f*scale);
    glVertex2f(0.0f*scale, 0.5f*scale);
}

void MyGLWidget::paintGL()
{  
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-this->geometry().size().width()/2, this->geometry().size().width()/2,
            -this->geometry().size().height()/2, this->geometry().size().height()/2, -200.0, 200.0);
    glMatrixMode(GL_MODELVIEW);


    glPushMatrix();
    glRotatef(this->delta_time*1.0f, 0.0, 0.0, 1.0);

    if (primitives_type == 1) // qaud
        Draw_Quad(this->scale_scene);

    if (primitives_type == 2) // triangle
        Draw_Triangle(this->scale_scene);

    if (primitives_type == 3) // circle filled
        Draw_NGon(this->scale_scene, 40);

    if (primitives_type == 4) // pentagon
        Draw_NGon(this->scale_scene, 5);

    if (primitives_type == 5) // hexagon
        Draw_NGon(this->scale_scene, 6);

    if (primitives_type == 6) // star 4
        Draw_Star4(this->scale_scene);


    glEnd();
    glPopMatrix();
    //glFlush();
    this->update();
}

/*void MyGLWidget::slotTimer()
{
    if (this->animate == true)
    {
        this->delta_time = ( mtime() - this->start_time) / 1000; // Счетчик времени, сек

    }
    else
    {
        this->delta_time_stop = (mtime() - this->stop_time);
    }
} */
