#ifndef ROULETTE_H
#define ROULETTE_H

#include "stdc++.h"
#include "ListPlayer.h"
#include "Player.h"
#include "include.h"
#include "Square.h"
#include "TimePLay.h"

class Player;
class ListPlayer;
class Register;
class TimePlay;
class Roulette{
    private:
        int N, nums;
        ListPlayer *list;

        std::string username, password;

        int incorrect = 5;
        int correct = 0;
        int pointerX = 0;
        int pointerY = 0;

        int level = 1;
        TimePlay *timePlay;

        Square **grid;
        Square **normalgrid;
        Square **highLights;

    public:
        Roulette();
        Roulette(int N);
        ~Roulette();

        void Display();

        void Menu();
        void gotoMenu(char choice);
        void exitMenu();
        void Rules(string located);

        void RegisterMenu();
        void regis_log(char auth);
        void registation();
        void login();
        void forgot();

        void saveInformation();
        void printInformation(string name, bool saved);

        void rouletteTable(int num, bool isResult);
        void creatTable();
        void fillDiagonal();
        void fillTable(int row, int col);

        void Play();
        char table();
        void mainGame(int value);

            // Keyboard
        void upKey();
        void downKey();
        void leftKey();
        void rightKey();
        void enterKey();
        void escKey();
        void pauseKey();
        void backSpaceKey();
};

#endif