#ifndef GLWIDGET_H

#define GLWIDGET_H

#include <QBrush>
#include <QFont>
#include <QImage>
#include <QPen>
#include <QGLWidget>
#include <QTimer>

class Bubble;
class QtModel;
QT_BEGIN_NAMESPACE
class QPaintEvent;
class QWidget;
QT_END_NAMESPACE

//! [0]
class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();
//! [0]

    QSize sizeHint() const;
    int xRotation() const { return xRot; }
    int yRotation() const { return yRot; }
    int zRotation() const { return zRot; }

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setZoom(int value);

//! [1]
protected:
    void initializeGL();
    void paintEvent(QPaintEvent *event);
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void showEvent(QShowEvent *event);

private slots:
    void animate();

private:
    void createBubbles(int number);
    void drawInstructions(QPainter *painter);
//! [1]
    void setupViewport(int width, int height);

    QColor qtGreen;
    QColor qtRed;
    QColor qtPurple;

    GLuint object;
    int xRot;
    int yRot;
    int zRot;
    int aZoom;
    QPoint lastPos;
//! [4]
    QtModel *partmodel;
    QList<Bubble*> bubbles;
    QTimer animationTimer;
//! [4]
};


#endif // GLWIDGET_H
