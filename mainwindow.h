#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QTextBlock>
#include "highlighter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int GetIndex (const QTextCursor &crQTextCursor );
    int GetLine (const QTextCursor &crQTextCursor );
    void UpdateStatus();
    void UpdateCursor();
    
private slots:
    void on_textEdit_textChanged();

    void on_textEdit_cursorPositionChanged();

    void on_textEdit_selectionChanged();

private:
    Ui::MainWindow *ui;
    int editline;
    Highlighter *highlighter;
    int line;
    int col;
    QString allcontent; // Current document

    int ParseAll(); // parsing input data. Returns an error code.
    int pcursor; // parse counsor.
    int findNextSymbol();
    QString parseError;
    int symbolbegin; // begin index of symbol
    int symbolend; //end index of symbol

    bool isType(QString lexem);
    QString findNextPhrase();

    QStringList typePatterns;


};

#endif // MAINWINDOW_H
