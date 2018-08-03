#include "mainwindow.h"
#include "ui_TextCAD.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    editline = 1;
    highlighter = new Highlighter(ui->textEdit->document());

    QFile file("editbuffer.txt");
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        ui->textEdit->setPlainText(file.readAll());

        file.close();
    }
    pcursor = 0; //start parse from begginig

    typePatterns << "dot" << "soc" << "vector"
                 << "line" << "segment" << "arc"
                 << "body" << "ellipse" << "circle"
                 << "contour" << "angle" << "surface"
                 << "sector"  << "point"
                 << "integer" << "real" << "rectangle"
                 << "plane" << "triangle";



}

MainWindow::~MainWindow()
{
    delete highlighter;
    delete ui;

}

int MainWindow::GetIndex (const QTextCursor &crQTextCursor ){
    QTextBlock           b;
    int                  column = 1;
    b = crQTextCursor.block();
    column = crQTextCursor.position() - b.position();
    return column;
}

int MainWindow::GetLine (const QTextCursor &crQTextCursor ){
  QTextBlock              b,cb;
  int                     line = 1;
  cb = crQTextCursor.block();
  for(b = ui->textEdit->document()->begin();b!=ui->textEdit->document()->end();b = b.next()){
    if(b==cb)
        return line;
    line++;
  }
  return(line);
}

void MainWindow::on_textEdit_textChanged()
{
    // if the text in editor is changed Main Window should
    // 0) Get text

    //QApplication::setOverrideCursor(Qt::WaitCursor);
    allcontent = ui->textEdit->toPlainText();
    int size = allcontent.length();

    UpdateCursor();

    if (editline != line)
    {

        QFile file("editbuffer.txt");


        file.open(QFile::WriteOnly | QFile::Text);

        QTextStream out(&file);

        out << allcontent;

        file.close();
        editline = line;
    }

    //QApplication::restoreOverrideCursor();

    //setCurrentFile(fileName);
    //statusBar()->showMessage(tr("File saved"), 2000);

    // 1) Save raw input to the backup file
    // 2) Parse file and if there is any errors

    ParseAll();

    //  Put message to console output.
    // 3) If there is no error compile data for OpenGLView
    // 4) Send data to GLView.




    //ui->textBrowser->setHtml("<html><body>Hello pepole</body></html>");
    UpdateStatus();
}

void MainWindow::UpdateCursor()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    line = GetLine(cursor);
    col = GetIndex(cursor);
}

void MainWindow::UpdateStatus()
{
    //ui->textBrowser->setHtml("<html><body>Hello pepole</body></html>");
    QString debug_output = "";
    debug_output.sprintf("L:%d|C:%d\n", line, col);

    /*
    ui->plainTextEdit->setPlainText(debug_output);
    */
    //Changing status bar.
    ui->statusbar->showMessage(debug_output);

}

void MainWindow::on_textEdit_cursorPositionChanged()
{
    // this happends when user clicks on a different location of file or type something.
    // Context help should be displayed in the HINT Box.



    ui->lineEdit->setText("<html><body>POsitioon Cahged</body></html>");
    UpdateCursor();
    UpdateStatus();
}

void MainWindow::on_textEdit_selectionChanged()
{
    //ui->textBrowser->setHtml("<html><body>selection changed<br>----</body></html>");
    //ui->plainTextEdit->setPlainText("Debug information");

    //put here right hints

    UpdateCursor();
    UpdateStatus();
}

int MainWindow::ParseAll()
{
    // parsing input data. Returns an error code.

    //1) Create a Name Table of symbols
    QList<int> sOffset; // index of all expression begins in allcontent.
    QList<QString> sName;

    //Reset all values. After I have to optimize parsing process by skipping untouched lines.
    sOffset.clear();
    sName.clear();

    QString debugText= "";


    debugText = findNextPhrase();
    ui->plainTextEdit->setPlainText(debugText);
    ui->textBrowser->setPlainText(debugText);

    return 0;
}

QString MainWindow::findNextPhrase()
{
    QString debugText;
    do{
        pcursor = findNextSymbol(); // is looking for the next symbol

        if (pcursor > 0)
        {
            QString symbol = allcontent.mid(symbolbegin, symbolend - symbolbegin);

            debugText.append(symbol + " ");

            if (symbol[0] == ';') {
                pcursor = 0; //must be removed after

                debugText.append("\r");
                break;
            }
        } else
        {
            debugText.append(parseError);
        }

    }while(pcursor>0);

    return debugText;
}

int MainWindow::findNextSymbol()
{
    //looks for symbol in all content and stops at next symbol or return 0 if there is no symbols left.
    int startPos = pcursor;
    int endPos = allcontent.length() - 1;
    symbolbegin = startPos; // begin index of symbol
    symbolend = startPos; //end index of symbol

    while (startPos <= endPos)
    {
        //1) Looking for non space character.
        QChar tmp = allcontent[startPos];
        while( tmp.isSpace())
        {
            tmp = allcontent[++startPos];
        }


        // Skipping endlines comments
        QChar tmp0 = allcontent[startPos];
        if (tmp0 == QChar('#'))
        {
            while (tmp0 != 0x0A)
            {
                tmp0 = allcontent[startPos++];
            }
            continue; // after skipping comment go to new line
        }

        tmp0 = allcontent[startPos];


        symbolbegin = startPos;
        symbolend = startPos+1;
        int i = startPos;
        if (allcontent[i] == QChar('{')){
            return symbolend;
        }
        if (allcontent[i] == QChar('}')){
            return symbolend;
        }
        if (allcontent[i] == QChar(':')){
            return symbolend;
        }
        if (allcontent[i] == QChar(';')){
            return symbolend;
        }
        if (allcontent[i] == QChar(',')){
            return symbolend;
        }
        if (allcontent[i] == QChar('(')){
            return symbolend;
        }
        if (allcontent[i] == QChar(')')){
            return symbolend;
        }


        if (!tmp0.isSpace())
        {
            //3) have something and it's not a comment
            //looking for end of the symbol.
            symbolbegin = startPos;
            symbolend = startPos+1;

            for (int i = startPos+1; i<=endPos; i++)
            {
                symbolend = i;
                //looking for end of symbol
                if (allcontent[i] == QChar(' ')){
                    // end of symbol is found
                    break;
                }
                if (allcontent[i] == QChar('{')){
                    // end of symbol is found
                    break;
                }
                if (allcontent[i] == QChar('}')){
                    // end of symbol is found
                    break;
                }
                if (allcontent[i] == QChar(':')){
                    // end of symbol is found
                    break;
                }
                if (allcontent[i] == QChar(';')){
                    // end of symbol is found
                    break;
                }
                if (allcontent[i] == QChar(',')){
                    // end of symbol is found
                    break;
                }
                if (allcontent[i] == QChar('(')){
                    // end of symbol is found
                    break;
                }
                if (allcontent[i] == QChar(')')){
                    // end of symbol is found
                    break;
                }
                if (allcontent[i] == 0x0A){
                    // end of symbol is found
                    break;
                }

            }//for

            return symbolend;

            /*
            if (symbolend > startPos)
            {
                //found some symbol
                symbolbegin = startPos;
                return symbolend;
            }else{
                // no ending of symbol till the end of file.
                parseError.sprintf("No symbols found at offset %d.\n", startPos);
                return 0; //-1;
            }*/
        }

    }//while;
    //just rewind to begin
    pcursor = 0;
    return pcursor;
}

bool MainWindow::isType(QString lexem)
{
    QString debugText;

    for(int i=0; i<typePatterns.count(); i++) {
        if ( lexem == typePatterns[i] )
        {
            debugText  = "<html><body>" + lexem + "</body></html>";
            ui->textBrowser->setHtml(debugText);
            return true;
        }
        debugText = "<html><body> " + lexem + "</body></html>";
        ui->textBrowser->setHtml(debugText);
    }

    return false;
}
