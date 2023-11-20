#include "window.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QFile>
#include <QTextStream>

Window::Window(QWidget *parent) : QMainWindow(parent)
{
  setWindowTitle("Hello World");
  QVBoxLayout* vLayout = new QVBoxLayout();
  QHBoxLayout* hLayout = new QHBoxLayout();
  QLabel* label = new QLabel("Hello World");
  lineEdit = new QLineEdit();
  QPushButton* button = new QPushButton("Find");
  hLayout->addWidget(label);
  hLayout->addWidget(lineEdit);
  hLayout->addWidget(button);

  vLayout->addLayout(hLayout);
  textEdit = new QTextEdit();
  vLayout->addWidget(textEdit);

  QWidget* centralWidget = new QWidget(this);
  centralWidget->setLayout(vLayout);
  setCentralWidget(centralWidget);

  connect(button, SIGNAL(released()), this, SLOT(onButtonReleased()));

  QFile file("../CMakeLists.txt");
  file.open(QIODevice::ReadOnly);
  QTextStream stream(&file);

  textEdit->setText(stream.readAll());
}

Window::~Window()
{
}

void Window::onButtonReleased()
{
  QString searchString = lineEdit->text();
  QTextDocument *document =  textEdit->document();

    bool found = false;

    // undo previous change (if any)
    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);
            }
        }

        cursor.endEditBlock();
                if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }
}