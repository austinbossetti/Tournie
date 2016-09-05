#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString getTitle()const {return title;}
    QString getP1Box()const {return p1Box;}
    QString getP2Box()const {return p2Box;}
    QString getP1Char()const {return p1Char;}
    QString getP2Char()const {return p2Char;}
    QString getP1Score() const {return p1Score;}
    QString getP2Score() const {return p2Score;}
    QString getChars(unsigned int index)const{
        if(index <= 0){return "";}
        if(index > 25){return "";}
        return chars[index];
    }
    QString getCharsFolder(unsigned int index)const{
        if(index <= 0){return "";}
        if(index > 25){return "";}
        return charsFolders[index];
    }
    unsigned int getSkins(unsigned int index)const{
        if(index <= 0){return 0;}
        if(index > 25){return 0;}
        return skins[index];
    }

    void setTitle(QString s){title = s;}
    void setP1Box(QString s){p1Box = s;}
    void setP2Box(QString s){p2Box = s;}
    void setP1Char(QString s){p1Char = s;}
    void setP2Char(QString s){p2Char = s;}
    void setP1Score(QString s){p1Score = s;}
    void setP2Score(QString s){p2Score = s;}
private slots:
    void on_updateButton_clicked();

    void on_titleBox_textChanged(const QString &arg1);

    void on_nameOneBox_textChanged(const QString &arg1);

    void on_nameTwoBox_textChanged(const QString &arg1);

    void on_charOneBox_currentIndexChanged(const QString &arg1);

    void on_charTwoBox_currentIndexChanged(const QString &arg1);

    void on_swapButton_clicked();

    void on_skinSliderOne_sliderMoved(int position);

    void on_skinSliderTwo_sliderMoved(int position);

    void on_scoreOneBox_textChanged(const QString &arg1);

    void on_scoreTwoBox_textChanged(const QString &arg1);

    void on_actionReset_triggered();

    void on_actionExit_triggered();

    void on_actionDocumentation_triggered();

private:
    Ui::MainWindow *ui;

    QString title = "Title";
    QString p1Box = "Player 1";
    QString p2Box = "Player 2";
    QString p1Char = "Fox";
    QString p2Char = "Fox";
    QString p1Score = "0";
    QString p2Score = "0";

    const QString chars[26] = {
        "Fox",
        "Sheik",
        "Falco",
        "Marth",
        "Jigglypuff",
        "Peach",
        "Captain Falcon",
        "Ice Climbers",
        "Samus",
        "Pikachu",
        "Dr. Mario",
        "Ganondorf",
        "Luigi",
        "Mario",
        "Young Link",
        "Yoshi",
        "Link",
        "Donkey Kong",
        "Roy",
        "Mr. Game and Watch",
        "Mewtwo",
        "Ness",
        "Zelda",
        "Pichu",
        "Bowser",
        "Kirby"
    };
    const QString charsFolders[26] = {
        "fox",
        "sheik",
        "falco",
        "marth",
        "jigglypuff",
        "peach",
        "captainfalcon",
        "iceclimbers",
        "samus",
        "pikachu",
        "drmario",
        "ganondorf",
        "luigi",
        "mario",
        "younglink",
        "yoshi",
        "link",
        "donkeykong",
        "roy",
        "mrgameandwatch",
        "mewtwo",
        "ness",
        "zelda",
        "pichu",
        "bowser",
        "kirby"
    };
    const unsigned int skins[26] = {
        4,
        5,
        4,
        5,
        5,
        5,
        6,
        4,
        5,
        4,
        5,
        5,
        4,
        5,
        5,
        6,
        5,
        5,
        5,
        4,
        4,
        4,
        5,
        4,
        4,
        6
    };
};

#endif // MAINWINDOW_H
