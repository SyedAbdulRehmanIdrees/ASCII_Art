#include <iostream>
#include <cmath>
using namespace std;

string leftUpperCorner = "┌"; // ┌
string rightUpperCorner = "┐"; // ┐
string leftBottomCorner = "└"; // └
string rightBottomCorner = "┘"; // ┘
string upwardT = "┴"; // ┴
string downwardT = "┬"; // ┬
string rightwardT = "├"; // ├
string leftwardT = "┤"; // ┤
string cross = "┼"; // ┼
string nDash = "─"; // ─
string nDash3 = "───"; // ─
string pipe = "│"; // │

void printInBox(string);
void printInGrid(string, int);

int main(){
    printInBox(" Abdul Rehman ");
    // printInGrid("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 6);
}

void printInBox(string s){
    int l = s.length();

    cout << leftUpperCorner;
    for(int i = 0; i < l; i++){
        cout << nDash;
    }
    cout << rightUpperCorner << endl << pipe;

    for(int i = 0; i < l; i++){
        cout << s[i];
    }
    cout << pipe << endl << leftBottomCorner;

    for(int i = 0; i < l; i++){
        cout << nDash;
    }
    cout << rightBottomCorner << endl;
}

void printInGrid(string s, int gridSize){
    int l = s.length();
    int lines = ceil((float)l / gridSize);
    int printedLines = 0;
    int currentLine = 0;

    for(int i = 0; i < (lines * gridSize - l); i++){
        s += ' ';
    }

    cout << leftUpperCorner << nDash3;
    for(int i = 0; i < gridSize - 1; i++){
        cout << downwardT << nDash3;
    }
    cout << rightUpperCorner << endl;
    currentLine++;

    cout << pipe;
    for(int i = 0; i < gridSize; i++){
        cout << " " << s[printedLines * gridSize + i] << " " << pipe;
    }
    cout << endl;
    printedLines++;


    for(; currentLine < lines; currentLine++){
        cout << rightwardT << nDash3;
        for(int j = 0; j < gridSize - 1; j++){
            cout << cross << nDash3;
        }
        cout << leftwardT << endl;

        cout << pipe;
        for(int i = 0; i < gridSize; i++){
            cout << " " << s[printedLines * gridSize + i] << " " << pipe;
        }
        cout << endl;
        printedLines++;
    }

    cout << leftBottomCorner << nDash3;
    for(int i = 0; i < gridSize - 1; i++){
        cout << upwardT << nDash3;
    }
    cout << rightBottomCorner << endl;
}
