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
#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    cWidget = new QWidget( this );
    vLayout = new QVBoxLayout( cWidget );
    h1Layout = new QHBoxLayout();
    h2Layout = new QHBoxLayout();
    leFilePath = new QLineEdit( this );
    bSelectFile = new QPushButton( this );
    bStart = new QPushButton( this );
    slider = new QSlider(Qt::Horizontal, this);
    lSlider = new QLabel( this );
    progressBar = new QProgressBar( this );

    leFilePath->setReadOnly(true);
    leFilePath->setText("");

    bSelectFile->setText("&Select file");
    bStart->setText("St&art");
    bStart->setDisabled(true);
    slider->setMinimum( 0 );
    slider->setMaximum( 100 );
    slider->setValue( 50 ); setQuality( 50 );
    progressBar->setMinimum(0);
    progressBar->setMaximum(6);
    progressBar->setValue(0);

    connect( bSelectFile, SIGNAL( clicked() ), this, SLOT( selectFile() ) );
    connect( bStart, SIGNAL( clicked() ), this, SLOT( start() ) );
    connect( slider, SIGNAL( valueChanged( int ) ), this, SLOT( setQuality(int) ) );

    h1Layout->addWidget(leFilePath);
    h1Layout->addWidget(bSelectFile);
    h1Layout->addWidget(bStart);

    h2Layout->addWidget( lSlider );
    h2Layout->addWidget( slider );

    vLayout->addLayout(h1Layout);
    vLayout->addLayout( h2Layout );
    vLayout->addWidget(progressBar);

    cWidget->setLayout(vLayout);
    setCentralWidget(cWidget);
}


MainWindow::~MainWindow() {

}


void MainWindow::setQuality(int q) {
    quality = q;
    setLSliderQuality( q );
}


int MainWindow::getQuality() {
    return quality;
}


void MainWindow::setLSliderQuality(int q) {
    QString string("Quality: ");
    string.append("(");
    string.append( QString::number( q ) );
    string.append(") ");

    lSlider->setText( string );
}


void MainWindow::selectFile() {
    QString fp;
    fp = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Images (*.png *.jpg)"));

    if( !fp.isNull() ) {
        progressBar->setValue( 0 );
        leFilePath->setText( fp );
        bStart->setDisabled(false);
    }
    else {
        bStart->setDisabled(true);
    }
}


void MainWindow::start() {
    leFilePath->setDisabled( true );
    bSelectFile->setDisabled( true );
    bStart->setDisabled( true );
    slider->setDisabled( true );

    QString newFilePath;

    Resolutions * resolutions = new Resolutions();

    QList<Resolution *> * lRes = new QList<Resolution *>;
    *lRes << new Resolution( 2560, 1440 );
    *lRes << new Resolution( 1920, 1440 );
    *lRes << new Resolution( 1920, 1200 );
    *lRes << new Resolution( 1920, 1080 );
    *lRes << new Resolution( 1680, 1200 );
    *lRes << new Resolution( 1680, 1050 );
    *lRes << new Resolution( 1600, 1200 );
    *lRes << new Resolution( 1440, 900 );
    *lRes << new Resolution( 1440, 1050 );
    *lRes << new Resolution( 1280, 1024 );
    *lRes << new Resolution( 1280, 960 );
    *lRes << new Resolution( 1280, 800 );
    *lRes << new Resolution( 1280, 720 );
    *lRes << new Resolution( 1152, 864 );
    *lRes << new Resolution( 1024, 1024 );
    *lRes << new Resolution( 1024, 768 );
    *lRes << new Resolution( 800, 600 );
    *lRes << new Resolution( 800, 480 );
    *lRes << new Resolution( 640, 480 );
    *lRes << new Resolution( 320, 480 );

    progressBar->setMaximum( lRes->size() );
    progressBar->setValue( 0 );


    QImage qImg, qImg2;
    Geometry geometry;
    Geometry resGeometry;
    Geometry * cropGeometry = 0;

    try {
        //qDebug() << "img.read:" << leFilePath->text();
        qImg.load( leFilePath->text() );
    }
    catch( std::exception &error_ ) {
        //qDebug() << error_.what();
        return;
    }

    geometry.width( qImg.size().width() );
    geometry.height( qImg.size().height() );

    for(int i = 0; i < lRes->size(); i++) {
        qImg2 = qImg;
        newFilePath = leFilePath->text();
        newFilePath.insert( (newFilePath.size() - 4), '-' );
        newFilePath.insert( (newFilePath.size() - 4), QString::number( lRes->at(i)->getWidth() ) );
        newFilePath.insert( (newFilePath.size() - 4), 'x' );
        newFilePath.insert( (newFilePath.size() - 4), QString::number( lRes->at(i)->getHeight() ) );
        //qDebug() << "-----------------";
        //qDebug() << newFilePath;

        resGeometry.width( lRes->at(i)->getWidth() );
        resGeometry.height( lRes->at(i)->getHeight() );
        cropGeometry = resolutions->needCrop( geometry.width(), geometry.height(), resGeometry.width(), resGeometry.height() );

        if( cropGeometry ) {
            qImg2 = qImg.copy(cropGeometry->xOff(), cropGeometry->yOff(), cropGeometry->width(), cropGeometry->height());
            delete( cropGeometry );
        }

        qImg2 = qImg2.scaled( resGeometry.width(), resGeometry.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
        qImg2.save( newFilePath, 0, getQuality() );

        progressBar->setValue( progressBar->value() + 1 );
    }

    delete( resolutions );
    delete( lRes );

    leFilePath->setDisabled( false );
    bSelectFile->setDisabled( false );
    bStart->setDisabled( false );
    slider->setDisabled( false );
}
