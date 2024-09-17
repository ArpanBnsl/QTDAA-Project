#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QDebug>
#include <bits/stdc++.h>
using namespace std;
TrieNode* root = new TrieNode();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    generateTrie();
    connect(ui->input,&QTextEdit::textChanged, this,&MainWindow::display);
}

MainWindow::~MainWindow()
{
    delete root;
    delete ui;
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
    QStringList words = text.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    QString lastWord;
    if(!text.isEmpty() && text.at(text.length()-1)<'a' && text.at(text.length()-1)>'z' || text.at(text.length()-1)<'A' && text.at(text.length()-1)>'Z'){
        qDebug() << "6";
        ui->s1->clear();
    }
    else if (!words.isEmpty()) {
        lastWord = words.last();
        //ui->s1->setText(lastWord);
        qDebug() << "Last word: " << lastWord;
    }
    else{
        ui->s1->clear();
    }

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
                ui->s1->clear();
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
    }
}
