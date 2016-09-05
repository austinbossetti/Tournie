#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <QMessageBox>
#include <fstream>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::on_skinSliderOne_sliderMoved(0);
    MainWindow::on_skinSliderTwo_sliderMoved(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_updateButton_clicked()
{
    //title box//
        QString title = getTitle();
        QFile file("textstream/title.txt");
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream outt(&file);
        outt << title;

    //p1Box//
        QString p1text = getP1Box();
        QFile filep1("textstream/player1.txt");
        if(!filep1.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream outp1(&filep1);
        outp1 << p1text;

    //p2Box//
        QString p2text = getP2Box();
        QFile filep2("textstream/player2.txt");
        if(!filep2.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream outp2(&filep2);
        outp2 << p2text;

    //p1Char//
        QString p1textc = getP1Char();
        QFile filep1c("textstream/player1char.txt");
        if(!filep1c.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream outp1c(&filep1c);
        outp1c << p1textc;

    //p2Char//
        QString p2textc = getP2Char();
        QFile filep2c("textstream/player2char.txt");
        if(!filep2c.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream outp2c(&filep2c);
        outp2c << p2textc;

        unsigned int count1 = 0;
        for(unsigned int i = 0; i < 26; i++){
            if(getP1Char() == chars[i]){
                break;
            }else{
                count1++;
            }
        }
        QString qs1 = charsFolders[count1];
        std::string ss1 = qs1.toUtf8().constData();
        std::string newSkin1 = "images/characters/" + ss1 + "/" + ss1 + std::to_string(ui->skinSliderOne->value()) + ".png";

    //out1//
        std::ifstream in1(newSkin1, std::ios::binary);
        std::ofstream out1("images/output/out1.png", std::ios::binary);
        out1 << in1.rdbuf();

        unsigned int count2 = 0;
        for(unsigned int i = 0; i < 26; i++){
            if(getP2Char() == chars[i]){
                break;
            }else{
                count2++;
            }
        }
        QString qs2 = charsFolders[count2];
        std::string ss2 = qs2.toUtf8().constData();
        std::string newSkin2 = "images/characters/" + ss2 + "/" + ss2 + std::to_string(ui->skinSliderTwo->value()) + ".png";

    //out2//
        std::ifstream in2(newSkin2, std::ios::binary);
        std::ofstream out2("images/output/out2.png", std::ios::binary);
        out2 << in2.rdbuf();

    //p1score
        QString p1score_s = getP1Score();
        QFile filep1s("textstream/player1score.txt");
        if(!filep1s.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream outp1s(&filep1s);
        outp1s << p1score_s;

    //p2score
        QString p2score_s = getP2Score();
        QFile filep2s("textstream/player2score.txt");
        if(!filep2s.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream outp2s(&filep2s);
        outp2s << p2score_s;

    //setType
        QString setType_s;
        if(ui->setTypeCheckBox->isChecked()){
            setType_s = QString(ui->setTypeSDBox->currentText() + " " + ui->setTypeWLBox->currentText());
        }else{
            setType_s = QString(ui->setTypeWLBox->currentText());
        }
        QFile filest("textstream/settype.txt");
        if(!filest.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream outst(&filest);
        outst << setType_s;
}

void MainWindow::on_titleBox_textChanged(const QString &arg1)
{
    setTitle(arg1);
}

void MainWindow::on_nameOneBox_textChanged(const QString &arg1)
{
    setP1Box(arg1);
}

void MainWindow::on_nameTwoBox_textChanged(const QString &arg1)
{
    setP2Box(arg1);
}

void MainWindow::on_charOneBox_currentIndexChanged(const QString &arg1)
{
    setP1Char(arg1);
    unsigned int count = 0;
    for(unsigned int i = 0; i < 26; i++){
        if(arg1 == chars[i]){
            break;
        }else{
            count++;
        }
    }
    ui->skinSliderOne->setValue(0);
    ui->skinSliderOne->setMaximum(skins[count]-1);
    QString qs = charsFolders[count];
    std::string ss = qs.toUtf8().constData();
    std::string newSkin = "images/characters/" + ss + "/" + ss + std::to_string(ui->skinSliderOne->value()) + ".png";
    QString newSkinQS = QString::fromStdString(newSkin);
    QPixmap pixmap(newSkinQS);
    ui->sliderImageOne->setPixmap(pixmap);
}

void MainWindow::on_charTwoBox_currentIndexChanged(const QString &arg1)
{
    setP2Char(arg1);
    unsigned int count = 0;
    for(unsigned int i = 0; i < 26; i++){
        if(arg1 == chars[i]){
            break;
        }else{
            count++;
        }
    }
    ui->skinSliderTwo->setValue(0);
    ui->skinSliderTwo->setMaximum(skins[count]-1);
    QString qs = charsFolders[count];
    std::string ss = qs.toUtf8().constData();
    std::string newSkin = "images/characters/" + ss + "/" + ss + std::to_string(ui->skinSliderTwo->value()) + ".png";
    QString newSkinQS = QString::fromStdString(newSkin);
    QPixmap pixmap(newSkinQS);
    ui->sliderImageTwo->setPixmap(pixmap);
}

void MainWindow::on_swapButton_clicked()
{
//p1text to p2text,p1char to p2char,update textboxes to new text,update comboboxes to new options
    QString buf1pc = getP1Char();
    QString buf2pc = getP2Char();
    setP1Char(buf2pc);
    setP2Char(buf1pc);

    QString buf1 = ui->nameOneBox->text();
    QString buf2 = ui->nameTwoBox->text();
    ui->nameOneBox->setText(buf2);
    ui->nameTwoBox->setText(buf1);
    setP1Box(buf2);
    setP2Box(buf1);

    QString buf1c = ui->charOneBox->currentText();
    QString buf2c = ui->charTwoBox->currentText();
    ui->charOneBox->setCurrentText(buf2c);
    ui->charTwoBox->setCurrentText(buf1c);

    unsigned int buf1s = ui->skinSliderOne->sliderPosition();
    unsigned int buf2s = ui->skinSliderTwo->sliderPosition();
    MainWindow::on_skinSliderOne_sliderMoved(buf2s);
    ui->skinSliderOne->setValue(buf2s);
    MainWindow::on_skinSliderTwo_sliderMoved(buf1s);
    ui->skinSliderTwo->setValue(buf1s);

    QString buf1sc = ui->scoreOneBox->text();
    QString buf2sc = ui->scoreTwoBox->text();
    ui->scoreOneBox->setText(buf2sc);
    ui->scoreTwoBox->setText(buf1sc);
}

void MainWindow::on_skinSliderOne_sliderMoved(int position)
{
    unsigned int count = 0;
    for(unsigned int i = 0; i < 26; i++){
        if(getP1Char() == chars[i]){
            break;
        }else{
            count++;
        }
    }
    QString qs = charsFolders[count];
    std::string ss = qs.toUtf8().constData();
    std::string newSkin = "images/characters/" + ss + "/" + ss + std::to_string(position) + ".png";
    QString newSkinQS = QString::fromStdString(newSkin);
    QPixmap pixmap(newSkinQS);
    ui->sliderImageOne->setPixmap(pixmap);
}

void MainWindow::on_skinSliderTwo_sliderMoved(int position)
{
    unsigned int count = 0;
    for(unsigned int i = 0; i < 26; i++){
        if(getP2Char() == chars[i]){
            break;
        }else{
            count++;
        }
    }
    QString qs = charsFolders[count];
    std::string ss = qs.toUtf8().constData();
    std::string newSkin = "images/characters/" + ss + "/" + ss + std::to_string(position) + ".png";
    QString newSkinQS = QString::fromStdString(newSkin);
    QPixmap pixmap(newSkinQS);
    ui->sliderImageTwo->setPixmap(pixmap);
}

void MainWindow::on_scoreOneBox_textChanged(const QString &arg1)
{
    setP1Score(arg1);
}

void MainWindow::on_scoreTwoBox_textChanged(const QString &arg1)
{
    setP2Score(arg1);
}

void MainWindow::on_actionReset_triggered()
{
    //title, set type, player{ names, scores, characters, sliders, images }
    ui->charOneBox->setCurrentIndex(0);
    ui->charTwoBox->setCurrentIndex(0);
    ui->titleBox->setText(QString("Title"));
    ui->nameOneBox->setText(QString("Player 1"));
    ui->nameTwoBox->setText(QString("Player 2"));
    ui->scoreOneBox->setText(QString("0"));
    ui->scoreTwoBox->setText(QString("0"));
    ui->setTypeSDBox->setCurrentIndex(0);
    ui->setTypeWLBox->setCurrentIndex(0);
    ui->skinSliderOne->setValue(0);
    MainWindow::on_skinSliderOne_sliderMoved(0);
    ui->skinSliderTwo->setValue(0);
    MainWindow::on_skinSliderTwo_sliderMoved(0);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionDocumentation_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Documentation");
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setText("Instructions:");
    msgBox.setInformativeText("1. All text files are located in the folder \"textstream\".\n"
                              "2. All character images are located in the folder \"images\\output\".\n"
                              "For use with OBS or XSplit use text from local file to display the text files.\n"
                              "For images:\n\tOBS: Use the \"Image\" option for each image.\n"
                              "\tXSplit: Use the \"Image Slideshow\" option for each image.\n"
                              "\nSee readme for license information.");
    msgBox.exec();
}
