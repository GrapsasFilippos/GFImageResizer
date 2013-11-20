#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    cWidget = new QWidget;
    vLayout = new QVBoxLayout();
    hLayout = new QHBoxLayout();
    leFilePath = new QLineEdit();
    bSelectFile = new QPushButton();
    bStart = new QPushButton();
    progressBar = new QProgressBar();

    connect( bSelectFile, SIGNAL( clicked() ), this, SLOT( selectFile() ) );
    connect( bStart, SIGNAL( clicked() ), this, SLOT( start() ) );

    leFilePath->setReadOnly(true);
    leFilePath->setText("");

    bSelectFile->setText("&Select file");
    bStart->setText("St&art");
    bStart->setDisabled(true);
    progressBar->setMinimum(0);
    progressBar->setMaximum(6);
    progressBar->setValue(0);

    hLayout->addWidget(leFilePath);
    hLayout->addWidget(bSelectFile);
    hLayout->addWidget(bStart);

    vLayout->addLayout(hLayout);
    vLayout->addWidget(progressBar);

    cWidget->setLayout(vLayout);
    setCentralWidget(cWidget);
}


MainWindow::~MainWindow() {

}


void MainWindow::selectFile() {
    QString fp;
    fp = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Images (*.png *.jpg)"));

    if( !fp.isNull() ) {
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
        qDebug() << "img.read:" << leFilePath->text();
        qImg.load( leFilePath->text() );
    }
    catch( std::exception &error_ ) {
        qDebug() << error_.what();
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
        qDebug() << "-----------------";
        qDebug() << newFilePath;

        resGeometry.width( lRes->at(i)->getWidth() );
        resGeometry.height( lRes->at(i)->getHeight() );
        cropGeometry = resolutions->needCrop( geometry.width(), geometry.height(), resGeometry.width(), resGeometry.height() );

        if( cropGeometry ) {
            qImg2 = qImg.copy(cropGeometry->xOff(), cropGeometry->yOff(), cropGeometry->width(), cropGeometry->height());
            delete( cropGeometry );
        }

        qImg2 = qImg2.scaled( resGeometry.width(), resGeometry.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
        qImg2.save( newFilePath );

        progressBar->setValue( progressBar->value() + 1 );
    }

    delete( resolutions );
    delete( lRes );

    leFilePath->setDisabled( false );
    bSelectFile->setDisabled( false );
    bStart->setDisabled( false );
}
