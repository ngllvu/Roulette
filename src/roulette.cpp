#include"roulette.h"
#include<iostream>
#include<stdc++.h>

//ham thiet lap
Roulette::Roulette(int N){
    this->N = N;
    RegisterMenu();
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

//menu
void Roulette::RegisterMenu(){
    int auth;
    while(true){
        clearSystem();
        std::cout << printColor("=========================================", 37) << std::endl;
        std::cout << setw(35) << right << printColor("ROULETTE", 36) << std::endl;
        std::cout << printColor("=========================================", 37) << std::endl;
        std::cout << endl;
        std::cout << printColor("[1] REGISTER", 32) << std::endl;
        std::cout << printColor("[2] LOGIN", 32) << std::endl;
        std::cout << printColor("[3] FORGOT PASSWORD", 36) << std::endl;
        std::cout << printColor("[4] INSTRUCTIONS", 33) << std::endl;
        std::cout << printColor("[5] EXIT", 31) << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        char select = getch();
        if (!(select < '1' || select > '5'))
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
            registation();
            break;
        case '2':
            login();
            break;
        case '3':
            forgot();
            break;
        case '4':
            Rules("main");
            break;
        case '5':
            exit(0);
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
    cout << "Press 1 to search your id by username " << std::endl;
    cout << "press 2 to go to the main menu " << std::endl;
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
        std::cout << printColor("=========================================", 37) << std::endl;
        std::cout << setw(35) << right << printColor("ROULETTE", 36) << std::endl;
        std::cout << printColor("=========================================", 37) << std::endl;
        std::cout << endl;
        std::cout << printColor("[1] PLAY", 36) << std::endl;
        std::cout << printColor("[2] PROFILE", 33) << std::endl;
        std::cout << printColor("[3] EXIT", 31) << std::endl;
        std::cout << std::endl;
        char select = getch();
        if (!(select < '1' || select > '3'))
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
            Play();
            break;
        case '2':
            Rules("main");
            break;
        case '3':
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
                RegisterMenu();
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
    std::cout<<"\nThe minimum for the bet is 20$ , and the maximum is 100000$";
    std::cout<<"\n";
    std::cout<<"\nGood luck !";

    getch();
    // GO TO MAIN MENU
    if (located == "main")
    {
        RegisterMenu();
    }
}

//save player data
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

//roulette table
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
            else if (j == 3 || j == 7 || j == 11)
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
            std::cout << printColor("===========================================", colorBorder) << std::endl;
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
            grid[row+i][col+j] = num;
            num++;
        }
    }
}

//main game part
void Roulette::Play(){

        pointerX = 0; // RESET POINTER
        pointerY = 0; // RESET POINTER

        creatTable();
        // Init Time
        timePlay->StartGame();

        mainGame(0);
}
void Roulette::Bet(){
    int bet, deposit;
    std::cout << "Enter your bet: ";
    std::cin >> bet;
}
void Roulette::mainGame(int N){
    clearSystem();
    std::cout << printColor("=========================================", 37) << std::endl;
    std::cout << setw(35) << right << printColor("ROULETTE", 36) << std::endl;
    std::cout << printColor("=========================================", 37) << std::endl;
    std::cout << std::endl;


    //movement
    while (true)
    {
        int firstKey = getch();
        if (PLATFORM_NAME == "windows")
        {

            int key = firstKey;

            if (key == 112 || key == 27)
            {
                pauseKey();
            }
            else
            {
                if (incorrect > 0 && correct < N * N)
                {
                    // Get 1 - > 233
                    if (!(key <= 0 || key >= 224))
                    {
                        if (key == 8 || key == 83)
                        {
                            if (grid[pointerX][pointerY] !=
                                normalgrid[pointerX][pointerY])
                            {
                                backSpaceKey();
                                mainGame(0);
                            }
                        }
                        else if (key == 75 || key == 68 || key == 97)
                        {
                            leftKey();
                            mainGame(0);
                        }
                        else if (key == 72 || key == 65 || key == 119)
                        {
                            upKey();
                            mainGame(0);
                        }
                        else if (key == 80 || key == 66 || key == 115)
                        {
                            downKey();
                            mainGame(0);
                        }
                        else if (key == 77 || key == 67 || key == 100)
                        {
                            rightKey();
                            mainGame(0);
                        }
                        else if (grid[pointerX][pointerY] !=
                                     normalgrid[pointerX][pointerY] &&
                                 key - 48 > 0 && key - 48 < 10)
                        {
                            mainGame(key - 48);
                        }
                    }
                }
                else if (correct == N * N)
                {
                    if (key == 13)
                    {
                        saveInformation();
                    }
                }
            }
        }
        else
        {
            int key = firstKey;
            int second;
            if (firstKey == 27)
            {
                second = getch();
                if (second == 91)
                {
                    key = getch();
                }
                else
                {
                    key = firstKey;
                    if (key == 27)
                    {
                        pauseKey();
                    }
                }
            }
            if (key == 112)
            {
                pauseKey();
            }
            else
            {
                if (incorrect > 0 && correct < N * N)
                {
                    // Get 1 - > 233
                    if (!(key <= 0 || key >= 224))
                    {

                        if (key == 8 || key == 83)
                        {
                            if (grid[pointerX][pointerY] !=
                                normalgrid[pointerX][pointerY])
                            {
                                backSpaceKey();
                                mainGame(0);
                            }
                        }
                        else if (key == 75 || key == 68 || key == 97)
                        {
                            leftKey();
                            mainGame(0);
                        }
                        else if (key == 72 || key == 65 || key == 119)
                        {
                            upKey();
                            mainGame(0);
                        }
                        else if (key == 80 || key == 66 || key == 115)
                        {
                            downKey();
                            mainGame(0);
                        }
                        else if (key == 77 || key == 67 || key == 100)
                        {
                            rightKey();
                            mainGame(0);
                        }
                        else if (grid[pointerX][pointerY] !=
                                     normalgrid[pointerX][pointerY] &&
                                 key - 48 > 0 && key - 48 < 10)
                        {
                            mainGame(key - 48);
                        }
                    }
                }
                else if (correct == N * N)
                {
                    if (key == 13)
                    {
                        saveInformation();
                    }
                }
            }
        }
    }
}

//movement key
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