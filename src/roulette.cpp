#include"roulette.h"
#include<iostream>
#include<stdc++.h>

/*void Roulette::Display(){
    std::cout<<"\n=======================================================================================================================================================================";
    std::cout<<"\n=======================================================================================================================================================================";
    std::cout<<"\n";
    std::cout<<"\n      RRRRRRRRRRRR           RRRRRRRR      UUU          UUU   LLLL            EEEEEEEEEEEEE   TTTTTTTTTTTTTTTTTTTTT   TTTTTTTTTTTTTTTTTTTTTT   EEEEEEEEEEEEE";
    std::cout<<"\n      RRR         RRR      RRR      RRR    UUU          UUU   LLLL            EEEEEEEEEEEEE   TTTTTTTTTTTTTTTTTTTTT   TTTTTTTTTTTTTTTTTTTTTT   EEEEEEEEEEEEE";
    std::cout<<"\n      RRR          RRR    RRR        RRR   UUU          UUU   LLLL            EEE                     TTTT                     TTTT            EEE";
    std::cout<<"\n      RRR          RRR    RRR        RRR   UUU          UUU   LLLL            EEE                     TTTT                     TTTT            EEE";
    std::cout<<"\n      RRR         RRR     RRR        RRR   UUU          UUU   LLLL            EEE                     TTTT                     TTTT            EEE";
    std::cout<<"\n      RRR         RRR     RRR        RRR   UUU          UUU   LLLL            EEEEEEEEEEEE            TTTT                     TTTT            EEEEEEEEEEEE";
    std::cout<<"\n      RRRRRRRRRRRR        RRR        RRR   UUU          UUU   LLLL            EEEEEEEEEEEE            TTTT                     TTTT            EEEEEEEEEEEE";
    std::cout<<"\n      RRR         RR      RRR        RRR   UUU          UUU   LLLL            EEE                     TTTT                     TTTT            EEE";
    std::cout<<"\n      RRR          RRR    RRR        RRR   UUU          UUU   LLLL            EEE                     TTTT                     TTTT            EEE";
    std::cout<<"\n      RRR          RRR    RRR        RRR   UUUU        UUUU   LLLL            EEE                     TTTT                     TTTT            EEE";
    std::cout<<"\n      RRR          RRR     RRR      RRR     UUUUUUUUUUUUUU    LLLLLLLLLLLLLL  EEEEEEEEEEEEE           TTTT                     TTTT            EEEEEEEEEEEEE";
    std::cout<<"\n      RRR          RRR       RRRRRRRR        UUUUUUUUUUUU     LLLLLLLLLLLLLL  EEEEEEEEEEEEE           TTTT                     TTTT            EEEEEEEEEEEEE";
    std::cout<<"\n";
    std::cout<<"\n=======================================================================================================================================================================";
    std::cout<<"\n=======================================================================================================================================================================";
}*/
Roulette::Roulette(int N){
    this->N = N;
    Menu();
}
Roulette::~Roulette(){
    for(int i = 0; i < N; i++){
        delete grid[i];
        delete normalgrid[i];
        delete highLights[i];
    }
    delete[] grid;
    delete[] normalgrid;
    delete[] highLights;
}


void Roulette::RegisterMenu(){
    int auth;
    while(true){
        clearSystem();
        std::cout << "\t\t\t_________________________________________\n\n\n";
        std::cout << "\t\t\t          welcome to the login page      \n\n\n";
        std::cout << "\t\t\t_________        MENU        ____________\n\n\n";
        std::cout << "                                                 \n\n\n";
        std::cout << "\t|  Press 1 to LOGIN                     |" << std::endl;
        std::cout << "\t|  Press 2 to REGISTER                  |" << std::endl;
        std::cout << "\t|  Press 3 if you forgot your PASSWORD  |" << std::endl;
        std::cout << "\t|  Press 4 to go back to Menu  |" << std::endl;
        std::cout << std::endl;
        char select = getch();
        if (!(select < '1' || select > '4'))
        {
            auth = select;
            break;
        }
    }
    regis_log(auth);
}
void Roulette::regis_log(char auth){
    switch(auth){
        case '1':
            login();
            break;
        case '2':
            registation();
            break;
        case '3':
            forgot();
            break;
        case '4':
            Menu();
            break;
    }
}

void Roulette::login(){
    int count;
    string userId, password, id, pass;
    system("cls");
    std::cout << "\t\t\t Please enter the username and password : " << std::endl;
    std::cout << "\t\t\t USERNAME ";
    std::cin >> userId;
    std::cout << "\t\t\t PASSWORD ";
    std::cin >> password;

    ifstream input("data.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        std::cout << userId << "\n Your LOGIN is successfull /n Thanks for logging in ! \n";
        Menu();
    }
    else
    {
        std::cout << "\n LOGIN ERROR \n Please check your username and password\n";
        login();
    }
}
void Roulette::registation(){
    std::string ruserId, rpassword, rid, rpass;
    system("cls");
    std::cout << "\t\t\t Enter the username : ";
    std::cin >> ruserId;
    std::cout << "\t\t\t Enter the password : ";
    std::cin >> rpassword;

    ofstream f1("data.txt", ios::app);
    f1 << ruserId << " " << rpassword << std::endl;
    system("cls");
    std::cout << "\n\t\t\t Registrationis succesfull! \n";
    Menu();
}
void Roulette::forgot(){
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password? No Worries \n";
    cout << "Press 1 to search your id by username " << endl;
    cout << "press 2 to go to the main menu " << endl;
    cout << "\t\t\t Enter your choice :";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        std::string suserId, sId, spass;
        std::cout << "\n\t\t\t Enter the username which you remembered :";
        std::cin >> suserId;

        ifstream f2("data.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            std::cout << "\n\n Your account is found \n";
            std::cout << "\n\n Your password is :" << spass;
        }
        else
        {
            std::cout << "\n\t Sorry! your account is not found! \n";
        }

        break;
    }
    case 2:
    {
        RegisterMenu();
    }
    default:
        std::cout << "\t\t\t Wrong choice ! Please try again " << std::endl;
        forgot();
    }
}


void Roulette::Menu(){
    ListPlayer *listPlayer = new ListPlayer();
    this->list = listPlayer;
    int size;
    list->getLength() < 10 ? size = listPlayer->getLength() : size = 9;

    level = 1;

    int choice;
    while (true)
    {
        clearSystem();
        std::cout << printColor("=========================================", 37) << endl;
        std::cout << setw(35) << right << printColor("ROULETTE", 36) << endl;
        std::cout << printColor("=========================================", 37) << endl;
        std::cout << endl;
        std::cout << printColor("[1] REGISTER / LOGIN", 32) << endl;
        std::cout << printColor("[2] PLAY", 36) << endl;
        std::cout << printColor("[3] INSTRUCTIONS", 33) << endl;
        std::cout << printColor("[4] EXIT", 31) << endl;
        std::cout << endl;
        char select = getch();
        if (!(select < '1' || select > '4'))
        {
            choice = select;
            break;
        }
    }
    gotoMenu(choice);
}
void Roulette::gotoMenu(char choice){
    switch(choice){
        case '1': 
            RegisterMenu();
            break;
        case '2':
            Play();
            break;
        case '3':
            Rules("main");
            break;
        case '4':
            exitMenu();
            break;
    }
}
void Roulette::exitMenu(){
    clearSystem();
    std::cout << printColor("=========================================", 37) << endl;
    std::cout << setw(10) << right << "" << printColor("DO YOU WANT TO EXIT?", 31) << endl;
    std::cout << printColor("[1] YES", 32) << endl;
    std::cout << printColor("[2] NO", 33) << endl;
    std::cout << printColor("=========================================", 37) << endl;

    while (true)
    {
        char select = getch();
        if ((select == '1' || select == '2' || (int)select == 27))
        {
            std::cout << endl;
            if (select == '1')
            {
                exit(0);
            }
            else
            {
                Menu();
            }
        }
    }
}


void Roulette::Rules(string located){
    std::cout<<"\nThe roulette spin have 2 part : the ball and the wheel";
    std::cout<<"\nThe wheels have high value spot and normal value spot . The high value spot is RED and normal value is BLACK";
    std::cout<<"\nIf you win the high value spot , you earn double money . But if you lose , it will cost you double";
    std::cout<<"\nFor the normal spot , everything will be normal";
    std::cout<<"\nEach round , choose the spot with the number you want and the roulette will start";
    std::cout<<"\nAfter the roulette finish spin , if your spot have the same number with the spot where the ball stop on roulette spin , you win the bet";
    std::cout<<"\nThe minimum for the bet is 100$ , and the maximum is 10000000$";
    std::cout<<"\n";
    std::cout<<"\nGood luck !";

    getch();
    // GO TO MAIN MENU
    if (located == "main")
    {
        Menu();
    }
}


void Roulette::saveInformation(){
    std::string name;
    double money;
    bool saved = false;

    printInformation(name, saved);

    while (true)
    {
        // ESC
        char key = getch();

        if (!saved)
        {
            if ((int)key == 27)
            {
                mainGame(0);
            }
            // Enter
            if ((int)key == 13)
            {
                if (name == "")
                {
                    name = "Robot";
                }

                Player player(name, money);

                list->AddPlayer(player);

                // IsSaved non call again
                saved = true;
                printInformation(name, saved);
            }
            // Input name
            if (((int)key == 8 || (int)key == 83) && name.size() > 0)
            {
                name.pop_back();
                printInformation(name, saved);
            }
            else
            {
                if (key >= 'a' && key <= 'z' || key >= 'A' && key <= 'Z')
                {
                    if (name.size() <= 10)
                    {
                        name.push_back(key);
                    }
                    printInformation(name, saved);
                }
            }
        }
        else
        {
            printInformation(name, saved);
            if (key == 27)
                break;
            }
        }
    }

void Roulette::printInformation(string name, bool saved){
    double money;
    clearSystem();
    std::cout << printColor("=========================================", 37) << std::endl;
    std::cout << setw(12) << "" << printColor("SAVE INFORMATION", 36) << std::endl;
    std::cout << printColor("=========================================", 37) << std::endl;
    std::cout << std::endl;
    std::cout << setw(2) << ""
         << "Enter your name: " << name << "_";
    std::cout << std::endl;
    std::cout << setw(2) << ""
         << "Your Money: " << money;

    std::cout << std::endl;
    std::cout << std::endl;
    if (!saved)
    {
        std::cout << setw(2) << "" << printColor("Press [ENTER] to save", 36) << std::endl;
        std::cout << setw(2) << "" << printColor("Press [ESC] to back the game", 33) << std::endl;
    }
    else
    {
        std::cout << setw(2) << "" << printColor("SAVED", 32) << std::endl;
        std::cout << setw(2) << "" << printColor("Press [ESC] go to menu", 32) << std::endl;
    }
}


void Roulette::rouletteTable(int num, bool isResult){
    int colorBorder = 35;
    int colorValueDefault = 37;
    int colorFalse = 31;
    int colorTrue = 32;
    int colorFocus = 34;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << printColor("=========================================", colorBorder) << std::endl;

    for (int i = 0; i < N; i++)
    {
        int h = i + 1;
        for (int j = 0; j < N; j++)
        {
            int k = j + 1;

            string value = to_string(grid[i][j].getValue());

            if (grid[i][j] == 0)
            {
                value = " ";
                if (pointerX == i && pointerY == j && grid[pointerX][pointerY] == 0)
                {
                    value = "x";
                    highLights[i][j] = colorFocus;
                }

                if (num != 0 && pointerX == i && pointerY == j)
                {
                    value = to_string(num);
                    isResult ? highLights[i][j] = colorTrue : highLights[i][j] = colorFalse;
                }
            }
            else
            {
                if (pointerX == i && pointerY == j && grid[pointerX][pointerY] != 0)
                {
                    value = to_string(grid[pointerX][pointerY].getValue());
                    if (highLights[i][j] != 32 && highLights[i][j] != 31)
                    {
                        highLights[i][j] = colorFocus;
                    }
                }
                else if (highLights[i][j] != 32 && highLights[i][j] != 31)
                {
                    highLights[i][j] = colorValueDefault;
                }
            }

            if (j == 0)
            {

                std::cout << printColor("|| ", colorBorder) << printColor(value, highLights[i][j].getValue()) << printColor(" |", colorBorder);
                continue;
            }
            else if (j == 8)
            {
                std::cout
                    << " " << printColor(value, highLights[i][j].getValue()) << printColor(" ||", colorBorder);
            }
            else if (j == 2 || j == 5)
            {
                std::cout << " " << printColor(value, highLights[i][j].getValue()) << printColor(" ||", colorBorder);
            }
            else
            {
                std::cout << " " << printColor(value, highLights[i][j].getValue()) << printColor(" |", colorBorder);
            }
        }
        if (h % 3 == 0)
        {
            std::cout << std::endl;
            std::cout << printColor("===========================================", colorBorder) << endl;
        }
        else
        {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
void Roulette::creatTable(){
    int sqrtN = sqrt(N);
    grid = new Square *[N];
    normalgrid = new Square *[N];
    highLights = new Square *[N];
    // Create a row for every pointer
    for (int i = 0; i < N; i++)
    {

        // Note : Rows may not be contiguous
        grid[i] = new Square[N];
        normalgrid[i] = new Square[N];
        highLights[i] = new Square[N];

        // Initialize all entries as false to indicate
        // that there are no edges initially
    }

    // Create 3 box on grid
    fillDiagonal();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] != 0)
            {
                // default white color
                highLights[i][j] = 37;
            }
            else
            {
                highLights[i][j] = 30;
            }
        }
    }
}
void Roulette::fillDiagonal(){
    int sqrtN = sqrt(N);

    for (int i = 0; i < N; i = i + sqrtN)
    {

        // for diagonal box, start coordinates->i==j
        fillTable(i, i);
    }
}
void Roulette::fillTable(int row, int col){
    int sqrtN = sqrt(N);
    int num;
    for(int i = 0; i<sqrtN; i++){
        for(int j = 0; j<sqrtN; j++){
            num = RandomNumber(N);
            grid[row+i][col+j] = num;
        }
    }
}


void Roulette::Play(){
    char setLevel = table();
    // CONDITION LEVEL
    if (setLevel == '4')
    {
        // GO TO MENU
        Menu();
    }
    else
    {
        // GAME START
        level = (int)setLevel - 48; // Initialize Level

        // Random level

        if (level == 1)
        {
            this->nums = 30;
        }
        else if (level == 2)
        {
            this->nums = 40;
        }
        else if (level == 3)
        {
            this->nums = 50;
        }

        pointerX = 0; // RESET POINTER
        pointerY = 0; // RESET POINTER

        creatTable();
        // Init Time
        timePlay->StartGame();

        mainGame(0);
    }

    // PAUSE
    getch();

    // // GO TO MAIN MENU
    // menu();
}
char Roulette::table(){
    char choice;
    do{
        clearSystem();
        std::cout << printColor("=========================================", 37) << std::endl;
        std::cout << setw(35) << right << printColor("ROULETTE", 36) << std::endl;
        std::cout << printColor("=========================================", 37) << std::endl;

        std::cout << setw(10) << right << "" << printColor("SELECT TABLE", 34) << std::endl;
        std::cout << printColor("[1] SMALL", 32) << std::endl;
        std::cout << printColor("[2] MEDIUM", 33) << std::endl;
        std::cout << printColor("[3] LARGE", 31) << std::endl;
        std::cout << printColor("[4] BACK", 35) << std::endl; // BACK TO MENU
        std::cout << std::endl;
        std::cout << printColor(" Press the number of your choice! ", 37) << std::endl;

        // GET USER CHOICE
        char select = getch();
        if (!(select < '1' || select > '4'))
        {
            choice = select;
            break;
        }
        else if ((int)select == 27)
        {
            choice = '4';
            break;
        }
    } while (true);

    return choice;
}
void Roulette::mainGame(int N){
    clearSystem();
    std::cout << printColor("=========================================", 37) << std::endl;
    std::cout << setw(35) << right << printColor("ROULETTE", 36) << endl;
    std::cout << printColor("=========================================", 37) << std::endl;
    std::cout << std::endl;
}


void Roulette::upKey()
{
    if (pointerX == 0)
    {
        pointerX = 8;
    }
    else
    {
        pointerX--;
    }
}
void Roulette::downKey()
{
    if (pointerX == 8)
    {
        pointerX = 0;
    }
    else
    {
        pointerX++;
    }
}
void Roulette::leftKey()
{
    if (pointerY == 0)
    {
        pointerY = 8;
    }
    else
    {
        pointerY--;
    }
}
void Roulette::rightKey()
{
    if (pointerY == 8)
    {
        pointerY = 0;
    }
    else
    {
        pointerY++;
    }
}
void Roulette::enterKey(){
    grid[pointerX][pointerY] = 10;
}
void Roulette::pauseKey()
{
    if (correct != N * N && incorrect > 0)
    {
        timePlay->StartPause();
    }
    clearSystem();
    std::cout << printColor("=========================================", 37) << std::endl;
    std::cout << setw(15) << right << "" << printColor("PAUSE GAME", 33) << std::endl;
    if (incorrect > 0 && correct != N * N)
    {
        std::cout << printColor("[1] RESUME", 32) << std::endl;
    }
    else if (incorrect <= 0)
    {
        std::cout << printColor("[1] GO TO MENU", 32) << std::endl;
    }
    else if (correct == N * N)
    {
        std::cout << printColor("[1] SAVE SCORE", 32) << std::endl;
    }

    std::cout << printColor("[2] EXIT TO MENU", 33) << std::endl;
    std::cout << printColor("=========================================", 37) << std::endl;

    while (true)
    {
        char select = getch();
        if ((select == '1' || select == '2' || select == 'p' || (int)select == 27))
        {
            std::cout << std::endl;
            if (select == '2')
            {
                clock_t currentTime = clock();
                timePlay->pauseEnd = currentTime;
                timePlay->end = currentTime;
                timePlay->EndPause();
                timePlay->EndGame();
                Menu();
            }
            else
            {
                if (incorrect > 0)
                {
                    if (select == '1' && correct == N * N)
                    {
                        saveInformation();
                    }
                    else if (select == '1' || select == 'p' || (int)select == 27)
                    {
                        if (correct != N * N)
                        {
                            clock_t currentTime = clock();
                            timePlay->pauseEnd = currentTime;
                            timePlay->EndPause();
                        }
                        mainGame(0);
                    }
                }
                else
                {
                    if (select == '1')
                    {
                        Menu();
                    }
                    else if (select == 'p' || (int)select == 27)
                    {
                        mainGame(0);
                    }
                }
            }
        }
    }
}

void Roulette::backSpaceKey()
{
    grid[pointerX][pointerY] = 0;
}