#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>

class Window : public QMainWindow
{
  Q_OBJECT
public:
  Window(QWidget *parent = 0);
  ~Window();

private slots:
  void onButtonReleased();

private:
  QLineEdit* lineEdit;
  QTextEdit* textEdit;
};


#endif