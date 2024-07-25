#include "ListPlayer.h"

void ListPlayer::printPlayers()
{
    for (int i = 0; i < length; i++)
    {
        std::cout << players[i].name << " " << players[i].money << std::endl;
    }
}
void ListPlayer::getRankingToFile()
{
    int length = 0;
    std::string name;
    double money = 0;
    fstream file;
    Player *players;
    std::ofstream myfile;
    myfile.open("src/Ranking.txt");

    file >> length;
    std::cout << length;
    players = new Player[length];
    for (int i = 0; i < length; i++)
    {

        file >> name;
        file >> money;
        Player player(name, money);
        players[i] = player;
    }
    this->players = players;
    this->length = length;
    file.close();
}

ListPlayer::ListPlayer()
{
    getRankingToFile();
    ShellSortPlayer();
}

ListPlayer::ListPlayer(Player *players, int length)
{
    this->players = players;
    this->length = length;
    ShellSortPlayer();
}

ListPlayer::~ListPlayer()
{
}

void ListPlayer::addRankingToFile()
{
    fstream file;
    file.open("src/Ranking.txt", ios::out);
    file << length << std::endl;
    for (int i = 0; i < length; i++)
    {
        file << players[i].name << " " << players[i].money << endl;
    }
    file.close();
}

Player *ListPlayer::getList()
{
    return this->players;
}
int ListPlayer::getLength()
{
    return length;
}
void ListPlayer::AddPlayer(Player player)
{
    Player *newPlayers = new Player[length + 1];
    memcpy(newPlayers, players, sizeof(Player) * length);
    newPlayers[length++] = player;

    delete[] players;
    players = newPlayers;

    ShellSortPlayer();
    addRankingToFile();
}

Player *ListPlayer::Ranking()
{
    Player *vt = new Player[10];
    int size;
    length < 10 ? size = this->length : size = 10;

    for (int i = 0; i < size; i++)
    {
        vt[i] = players[i];
    }
    return vt;
}

void ListPlayer::ShellSortPlayer()
{
    int n = length;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            Player temp = players[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && players[j - gap].money < temp.money; j -= gap)
                players[j] = players[j - gap];

            //  put temp (the original a[i]) in its correct location
            players[j] = temp;
        }
    }
}