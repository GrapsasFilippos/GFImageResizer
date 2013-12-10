/*
 * GFImageResizer
 * Copyright (C) 2013  Grapsas A. Filippos
 *
 * GFImageResizer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
