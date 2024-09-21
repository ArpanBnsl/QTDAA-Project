#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QDebug>
#include <bits/stdc++.h>
using namespace std;

// global objects
TrieNode* root = new TrieNode();
QString lastWord;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    generateTrie();

    connect(ui->input,&QTextEdit::textChanged, this,&MainWindow::display);

    QList<QPushButton*> buttons = {ui->s1 , ui->s2 , ui->s3, ui->s4 ,ui->s4, ui->s5, ui->s6};
    for(auto x:buttons)
        connect(x,&QPushButton::clicked, this , &MainWindow::onPressingButton);
}

MainWindow::~MainWindow()
{
    delete root;
    delete ui;
}
void MainWindow::onPressingButton(){
    qDebug() <<1 ;
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());

    if(clickedButton){
        qDebug() << 2;
        QString inputText = ui->input->toPlainText();
        int i = inputText.lastIndexOf(' ');
        qDebug() << inputText  << i ;

        if(!inputText.isEmpty() && !lastWord.isEmpty()){
            QString before = inputText.left(i);
            QString updated = before + " " + clickedButton->text() + " ";

            ui->input->setPlainText(updated);

            QTextCursor cursor = ui->input->textCursor();
            cursor.movePosition(QTextCursor::End);
            ui->input->setTextCursor(cursor);
            ui->input->setFocus();
            return;
        }
    }
}
void MainWindow::insertWord(TrieNode* root, string key){
    TrieNode* curr = root;
    for (char c : key) {
        c=tolower(c);
        if (curr->child[c - 'a'] == nullptr) {
            TrieNode* newNode = new TrieNode();
            curr->child[c - 'a'] = newNode;
        }
        curr = curr->child[c - 'a'];
    }
    curr->wordEnd = true;
    return;
}

void MainWindow::generateTrie(){
    qDebug() << "gen" ;
    vector<string> arr ;
    ifstream file("C:\\Users\\LENOVO\\Desktop\\arpan btech\\sem 3\\QT Projects\\2\\build\\Desktop_Qt_6_7_2_MinGW_64_bit-Debug\\debug\\general.txt");
    string s;
    while(file>>s){
        //qDebug() << "s : " << s;
        arr.push_back(s);
    }
    file.close();
    int i=0;
    for (const string& s : arr){
        //qDebug() << "i : " << i;
        //qDebug() << "s[0] : " << s[0];
        //++i;
        insertWord(root, s);
    }
    //qDebug() << "gen1" ;
}

void MainWindow::display()
{
    QString text = ui->input->toPlainText();
    qDebug() << "Input text: " << text;

    //qDebug() << 1 ;

    QStringList words = text.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

    qDebug() <<2 ;

    if(!text.isEmpty()){
        qDebug() << 3;
        QChar lastChar = text.at(text.length()-1);
        qDebug() << lastChar;
        if(!((lastChar >= 'a' && lastChar <= 'z') || (lastChar >= 'A' && lastChar <= 'Z'))){
            qDebug() << "6";
            ui->s1->setText("");
            return;
        }
        else{
            qDebug() << 'a';
            lastWord = words.last();
            //ui->s1->setText(lastWord);
            //qDebug() << "Last word: " << lastWord;
        }
    }
    else{
        qDebug() << 3 ;
        ui->s1->setText("");
        return;
    }
    //qDebug() << 4;
    //qDebug() << lastWord;
    if(!lastWord.isEmpty()){
        QString sug = lastWord;
        TrieNode* curr = root;

        for(int i=0 ; i<lastWord.length();++i){
            if(lastWord[i]<'a' && lastWord[i]>'z' || lastWord[i]<'A' && lastWord[i]>'Z'){
                lastWord.remove(i,1);
                --i;
                continue;
            }
            QChar c=lastWord[i];
            c=c.toLower();
            qDebug() << "c :" << c ;
            int index = c.toLatin1()-'a';
            qDebug() << "ind :" << index ;
            if(curr->child[index]==nullptr){
                qDebug() << "ind :" << index ;
                ui->s1->setText("");
                return;
            }
            curr=curr->child[index];
        }
        while(curr->wordEnd!=true){
            bool found=false;
            for(int i=0 ; i<26 ; ++i){
                if(curr->child[i]!=nullptr){
                    sug.push_back(QChar(i+'a'));
                    curr=curr->child[i];
                    found=true;
                    break;
                }
            }
            if(!found)
                break;
            qDebug() << "sug :" << sug ;
        }
        qDebug() << "Suggested word: " << sug;
        ui->s1->setText(sug);
        return;
    }
    else{
        ui->s1->setText("");
        return;
    }
}
