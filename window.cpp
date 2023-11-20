#include "window.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

Window::Window(QWidget *parent) : QMainWindow(parent)
{
  setWindowTitle("Hello World");
  QVBoxLayout* vLayout = new QVBoxLayout();
  QHBoxLayout* hLayout = new QHBoxLayout();
  QLabel* label = new QLabel("Hello World");
  QLineEdit* lineEdit = new QLineEdit();
  QPushButton* button = new QPushButton("Quit");
  hLayout->addWidget(label);
  hLayout->addWidget(lineEdit);
  hLayout->addWidget(button);

  vLayout->addLayout(hLayout);
  QTextEdit* textEdit = new QTextEdit();
  vLayout->addWidget(textEdit);

  QWidget* centralWidget = new QWidget(this);
  centralWidget->setLayout(vLayout);
  setCentralWidget(centralWidget);
}

Window::~Window()
{
}