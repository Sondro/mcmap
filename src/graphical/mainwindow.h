#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void reset_selection();

  void on_renderButton_clicked();

  void on_saveSelectButton_clicked();
  void on_outputSelectButton_clicked();
  void on_colorSelectButton_clicked();

  void on_dimensionSelectDropDown_currentIndexChanged(int index);

  void on_minX_textEdited(const QString &arg1);
  void on_maxX_textEdited(const QString &arg1);

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
