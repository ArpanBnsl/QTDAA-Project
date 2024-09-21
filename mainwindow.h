#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class TrieNode;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void display();
    void generateTrie();
    void insertWord(TrieNode* root,std::string s);
    void onPressingButton();

private:
    Ui::MainWindow *ui;
};

class TrieNode {
public:
    TrieNode* child[26];
    bool wordEnd;

    TrieNode(){
        wordEnd=false;
        for(int i=0 ; i<26 ; ++i)
            child[i]=nullptr;
    }

    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            delete child[i];
        }
    }
};

#endif // MAINWINDOW_H
