#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP


#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QProgressBar>
#include <QFileDialog>
#include <QImage>

#include "resolutions.hpp"
#include "resolution.hpp"


class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    public slots:
        void selectFile();
        void start();

    private:
        QWidget * cWidget;
        QVBoxLayout * vLayout;
        QHBoxLayout * hLayout;
        QLineEdit * leFilePath;
        QPushButton * bSelectFile;
        QPushButton * bStart;
        QProgressBar * progressBar;
        //QString * filePath;
};


#endif // MAINWINDOW_HPP
