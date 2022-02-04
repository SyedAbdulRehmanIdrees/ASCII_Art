#include <iostream>
#include <cmath>
using namespace std;

char leftUpperCorner = char(218); // ┌
char rightUpperCorner = char(191); // ┐
char leftBottomCorner = char(192); // └
char rightBottomCorner = char(217); // ┘
char upwardT = char(193); // ┴
char downwardT = char(194); // ┬
char rightwardT = char(195); // ├
char leftwardT = char(180); // ┤
char cross = char(197); // ┼
char nDash = char(196); // ─
char pipe = char(179); // │

void printInBox(string);
void printInGrid(string, int);

int main(){
    // printInBox(" Abdul Rehman ");
    printInGrid("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 6);
    // cout << leftUpperCorner << endl;
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

    cout << leftUpperCorner << nDash << nDash << nDash;
    for(int i = 0; i < gridSize - 1; i++){
        cout << downwardT << nDash << nDash << nDash;
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
        cout << rightwardT << nDash << nDash << nDash;
        for(int j = 0; j < gridSize - 1; j++){
            cout << cross << nDash << nDash << nDash;
        }
        cout << leftwardT << endl;

        cout << pipe;
        for(int i = 0; i < gridSize; i++){
            cout << " " << s[printedLines * gridSize + i] << " " << pipe;
        }
        cout << endl;
        printedLines++;
    }

    cout << leftBottomCorner << nDash << nDash << nDash;
    for(int i = 0; i < gridSize - 1; i++){
        cout << upwardT << nDash << nDash << nDash;
    }
    cout << rightBottomCorner << endl;
}
