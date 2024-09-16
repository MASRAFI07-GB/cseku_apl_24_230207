
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
struct players
{
    int score;
    string name;
};

void print_info(struct players scoreboard[], int current_size)
{
    for (int i = 0; i < current_size; i++)
    {
        cout << scoreboard[i].name << " " << scoreboard[i].score << endl;
    }
}

void add_player(struct players scoreboard[], struct players player[], int &current_size_scoreboard, int sc_length, string n, int s)
{
    int flag;
    int i = 0;
    player[i].name = n;
    player[i].score = s;

    if (current_size_scoreboard == 0)
    {
        scoreboard[0] = player[i];
        current_size_scoreboard++;
    }
    else
    {
        if (player[i].score <= scoreboard[current_size_scoreboard - 1].score && current_size_scoreboard < sc_length)
        {
            scoreboard[current_size_scoreboard] = player[i];
            current_size_scoreboard++;
        }

        else if (player[i].score > scoreboard[current_size_scoreboard - 1].score)
        {

            flag = 0;
            for (int j = current_size_scoreboard - 1; j >= 0; j--)
            {
                if (player[i].score > scoreboard[j].score)
                {
                    scoreboard[j + 1] = scoreboard[j];
                }
                else
                {

                    scoreboard[j + 1] = player[i];
                    flag = 1;
                    break;
                }
            }
            if (flag != 1)
                scoreboard[0] = player[i];
            if (current_size_scoreboard < sc_length)
                current_size_scoreboard++;
        }
    }
}

// delete player
void delete_player(struct players scoreboard[], struct players player[], int current_size_scoreboard, int d_index)
{
    for (int i = d_index; i < current_size_scoreboard - 1; i++)
    {
        scoreboard[i] = scoreboard[i + 1];
    }
}

// update player
void update_player(string s, int score, struct players scoreboard[], struct players player[], int current_size_scoreboard, int sc_length)
{
    for (int i = 0; i < (current_size_scoreboard); i++)
    {
        if (scoreboard[i].name == s)
        {
            delete_player(scoreboard, player, current_size_scoreboard, i);
            break;
        }
    }
    current_size_scoreboard -= 1;

    add_player(scoreboard, player, current_size_scoreboard, sc_length, s, score);
}

int main()
{
    // sc_length means scoreboard_length
    int sc_length, flag;
    cout << "Enter the size of your scoreboard:" << endl;
    cin >> sc_length;

    struct players scoreboard[100];

    int total_players;
    cout << "Enter the number of players:" << endl;
    cin >> total_players;

    struct players player[100];

    int current_size_scoreboard = 0;
    for (int i = 0; i < total_players; i++)
    {

        cout << "Enter the info of non existing player " << i + 1 << " th player:" << endl;
        cin >> (player[i]).name >> player[i].score;

        // add player to the score board
        add_player(scoreboard, player, current_size_scoreboard, sc_length, player[i].name, player[i].score);

        cout << "after" << i + 1 << " number of  player have played:" << endl;
        print_info(scoreboard, current_size_scoreboard);

        int wish;
        cout << "do you want to update info of an existing player? if YES [PRESS 1] else [PRESS 0]:" << endl;
        cin >> wish;
        if (wish == 1)
        {
            cout << "do the change:" << endl;
            string s;
            int score;
            cin >> s >> score;
            update_player(s, score, scoreboard, player, current_size_scoreboard, sc_length);
            cout << "after updating the scoreboard:" << endl;
            print_info(scoreboard, current_size_scoreboard);
        }
        else
        {
            cout << "scoreboard remains unchanged!" << endl;
        }
    }
}
