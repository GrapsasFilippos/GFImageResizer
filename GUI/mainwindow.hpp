#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP


#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QProgressBar>
#include <QFileDialog>
#include <QImage>
#include <QSlider>
#include <QLabel>

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
        void setQuality( int q );

    private:
        int getQuality();
        void setLSliderQuality( int q );

        int quality;

        QWidget * cWidget;
        QVBoxLayout * vLayout;
        QHBoxLayout * h1Layout;
        QHBoxLayout * h2Layout;
        QLineEdit * leFilePath;
        QPushButton * bSelectFile;
        QPushButton * bStart;
        QProgressBar * progressBar;
        QSlider * slider;
        QLabel * lSlider;
};


#endif // MAINWINDOW_HPP
