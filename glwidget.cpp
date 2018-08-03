#include <QtGui>
#include <QtOpenGL>
#include <stdlib.h>

#include <math.h>

#include "bubble.h"
#include "model.h"
#include "glwidget.h"

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

//! [0]
GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    QTime midnight(0, 0, 0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    partmodel = 0;
    xRot = 0;
    yRot = 0;
    zRot = 0;

    //qtGreen = QColor::fromCmykF(1.00, 0.50, 0.30, 0.1);
    qtGreen = QColor::fromCmykF(0.50, 0.30, 0.10, 0.0);
    //qtPurple = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);
    qtRed = QColor::fromCmykF(0.50, 1.0, 1.0, 0.0);

    animationTimer.setSingleShot(false);
    connect(&animationTimer, SIGNAL(timeout()), this, SLOT(animate()));
    animationTimer.start(25);

    setAutoFillBackground(false);
    setMinimumSize(200, 200);
    setWindowTitle(tr("Overpainting a Scene"));
}
//! [0]

//! [1]
GLWidget::~GLWidget()
{
}
//! [1]

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 32;//16;
    while (angle > 360 *32)// 16)
        angle -= 360 * 32;//16;
}

static void qNormalizeZoom (int &zoom)
{
    while (zoom < 0)
        zoom += 1;
    while (zoom > 20)
        zoom-= 1;
}

void GLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot)
        xRot = angle;
}

void GLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot)
        yRot = angle;
}

void GLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot)
        zRot = angle;
}

void GLWidget::setZoom(int value)
{
    qNormalizeZoom(value);
    if (value != aZoom)
        aZoom = value;
}

//! [2]
void GLWidget::initializeGL()
{
    //here I inisicialize part and color of the part.
    glEnable(GL_MULTISAMPLE);

    partmodel = new QtModel(this);
    //logo->setColor(qtRed.light());

    //logo->setColor(qtGreen.dark());
}
//! [2]

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }
    lastPos = event->pos();


}

void GLWidget::wheelEvent(QWheelEvent *event)
{
    //mouse wheel rotation
    int delta = event->delta();
    if(delta!=0)
    {
        setZRotation(zRot + delta);
    }
    lastPos = event->pos();
}

void GLWidget::paintEvent(QPaintEvent *event)
{
    makeCurrent(); // Set the current DC for OpenGL ?
//! [4]
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
//! [4]

//! [6]
    qglClearColor(qtGreen.dark());
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_MULTISAMPLE);

    static GLfloat lightPosition[4] = { 4.5, 7.0, 3.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    setupViewport(width(), height());
//! [6]

//! [7]
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot / 32.0, 1.0, 0.0, 0.0); //16.0
    glRotatef(yRot / 32.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 32.0, 0.0, 0.0, 1.0);

    partmodel->draw();
//! [7]


//! [8]
    //glShadeModel(GL_FLAT);
    //glDisable(GL_CULL_FACE);
    //glDisable(GL_DEPTH_TEST);
    //glDisable(GL_LIGHTING);

    //glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
//! [8]

//! [10]

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    foreach (Bubble *bubble, bubbles) {
        if (bubble->rect().intersects(event->rect()))
            bubble->drawBubble(&painter);
    }
    drawInstructions(&painter);
    painter.end();

}
//! [10]

//! [11]
void GLWidget::resizeGL(int width, int height)
{
    setupViewport(width, height);
}
//! [11]

//! [12]
void GLWidget::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);


    //To DO Buubles here.
    //Timer dependent animation.
    //createBubbles(20 - bubbles.count());
}
//! [12]

QSize GLWidget::sizeHint() const
{
    return QSize(400, 400);
}

void GLWidget::createBubbles(int number)
{
    for (int i = 0; i < number; ++i) {
        QPointF position(width()*(0.1 + (0.8*qrand()/(RAND_MAX+1.0))),
                        height()*(0.1 + (0.8*qrand()/(RAND_MAX+1.0))));
        qreal radius = qMin(width(), height())*(0.0125 + 0.0875*qrand()/(RAND_MAX+1.0));
        QPointF velocity(width()*0.0125*(-0.5 + qrand()/(RAND_MAX+1.0)),
                        height()*0.0125*(-0.5 + qrand()/(RAND_MAX+1.0)));

        bubbles.append(new Bubble(position, radius, velocity));
    }
}

//! [13]
void GLWidget::animate()
{
    QMutableListIterator<Bubble*> iter(bubbles);

    while (iter.hasNext()) {
        Bubble *bubble = iter.next();
        bubble->move(rect());
    }
    update();
}
//! [13]

//! [14]
void GLWidget::setupViewport(int width, int height)
{
    //int side = qMin(width, height);
    int side = qMax(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);



    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES
    glOrthof(-0.5, +0.5, -0.5, 0.5, 4.0, 15.0);
#else
    glOrtho(-0.5, +0.5, -0.5, 0.5, 4.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}
//! [14]

//! [15]
void GLWidget::drawInstructions(QPainter *painter)
{
    QString text = tr("Click and drag with the left mouse button "
                      "to rotate the part.");
    QFontMetrics metrics = QFontMetrics(font());
    int border = qMax(4, metrics.leading());

    QRect rect = metrics.boundingRect(0, 0, width() - 2*border, int(height()*0.125),
                                      Qt::AlignCenter | Qt::TextWordWrap, text);
    painter->setRenderHint(QPainter::TextAntialiasing);
    painter->fillRect(QRect(0, 0, width(), rect.height() + 2*border),
                     QColor(0, 0, 0, 127));
    painter->setPen(Qt::white);
    painter->fillRect(QRect(0, 0, width(), rect.height() + 2*border),
                      QColor(0, 0, 0, 127));
    painter->drawText((width() - rect.width())/2, border,
                      rect.width(), rect.height(),
                      Qt::AlignCenter | Qt::TextWordWrap, text);
}
//! [15]


