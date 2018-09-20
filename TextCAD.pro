#-------------------------------------------------
#
# Project created by QtCreator 2013-02-14T14:18:55
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = TextCAD
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
	ui_TextCAD.h \
    glwidget.cpp \
    bubble.cpp \
    highlighter.cpp \
    model.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    bubble.h \
    highlighter.h \
    model.h

FORMS    += TextCAD.ui


#LIBS += -lopengl32 -lglu32
