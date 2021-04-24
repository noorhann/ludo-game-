#include <bits/stdc++.h>
using namespace std;

const int N=15, M = 15;
int n_players = 4;
char grid[N][M];
string player_name[] = {"Red", "Blue", "Green", "Yellow"};
char players_soldiers[4] = {'R', 'B', 'G', 'Y'};
char goals_symbols[] = {'R', 'B', 'G', 'Y'};
vector<pair<int, int>>player_position = {{11,1},{2,1}, {2,10},{11,10}};
vector<pair<int, int>> boxes_boarders = {{9,0},{0,0},{0,9},{9,9}};
vector<pair<int, int>> home_players = {{11,1},{2,1},{2,10},{11,10}};
vector<pair<int, int>>goals = {{8,7},{7,6},{6,7},{7,8}};
vector<pair<int, int>>player1_path = {{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{13,7},{12,7},{11,7},{10,7},{9,7},{8,7}};
vector<pair<int, int>>player2_path = {{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{7,1},{7,2},{7,3},{7,4},{7,5},{7,6}};
vector<pair<int, int>>player3_path = {{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{1,7},{2,7},{3,7},{4,7},{5,7},{6,7}};
vector<pair<int, int>>player4_path = {{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{7,13},{7,12},{7,11},{7,10},{7,9},{7,8}};

//This function print box for each player
void print_player_box()
{
    for (int x=0; x<N; ++x)
    {
        for (int y=0; y<M; ++y)
        {
            for(int h=0; h<home_players.size(); ++h)
            {
                if(home_players[h].first==x&&home_players[h].second==y)
                {
                    grid[x][y]=players_soldiers[h];
                    break;
                }
            }
        }
    }
}
//This function print the goal box
void print_goal_box()
{

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            for(int h=0; h<goals.size(); ++h)
            {
                if(goals[h].first==i&&goals[h].second==j)
                {
                    grid[i][j] = goals_symbols[h];
                    // break;
                }
            }
        }
    }
}
//This function print the grid
void print_grid()
{
    for(int i=0; i<n_players; ++i)
    {
        cout<<"Player "<<i+1<<" : "<<player_name[i];
        if(i<n_players-1)
            cout<<" vs  ";
    }
    cout<<endl;
    print_goal_box();
    cout<<"--";
    int f=M+11;
    while(f--)
        cout<<"---";
    cout<<"--";
    cout<<endl;
    for(int i=0; i<N; ++i)
    {
        cout<<"|  ";
        for(int j=0; j<M; ++j)
        {
            int flag=0;
            for(int h=0; h<boxes_boarders.size(); ++h)
            {
                if(boxes_boarders[h].first==i&&boxes_boarders[h].second==j)
                {
                    //print_player_box(i,j);
                    cout<<grid[i][j]<<"    ";
                    flag=1;
                    if(j==5||j==8)
                        cout<<"|  ";
                    break;
                }
            }
            if(flag==0)
            {
                cout<<grid[i][j]<<"    ";
                if(j==5||j==8)
                    cout<<"|  ";
            }
        }
        cout<<"|"<<endl;
        if(i==5||i==8||i==14)
        {
            cout<<"--";
            f=M+11;
            while(f--)
                cout<<"---";
            cout<<"--"<<endl;

        }
    }
}
//This function generate a random dice face
int generate_dice_face()
{
    srand((unsigned) time(0));
    return (rand() % 6) + 1;

}
//This function prints the given dice face
string print_dice_face(int i)
{
    string s = "";
    if (i == 1)
    {
        s += " _____ \n";
        s += "|     |\n";
        s += "|  *  |\n";
        s += "|_____|\n";
    }
    if (i == 2)
    {
        s += " _____ \n";
        s += "|    *|\n";
        s += "|     |\n";
        s += "|*____|\n";
    }
    if (i == 3)
    {
        s += " _____ \n";
        s += "|    *|\n";
        s += "|  *  |\n";
        s += "|*____|\n";
    }
    if (i == 4)
    {
        s += " _____ \n";
        s += "|*   *|\n";
        s += "|     |\n";
        s += "|*___*|\n";
    }
    if (i == 5)
    {
        s += " _____ \n";
        s += "|*   *|\n";
        s += "|  *  |\n";
        s += "|*___*|\n";
    }
    if (i == 6)
    {
        s += " _____ \n";
        s += "|*   *|\n";
        s += "|*   *|\n";
        s += "|*___*|\n";
    }
    return s;
}
//This function check if the given player is win the game
bool check_win(int player)
{
    int i=player_position[player].first,j=player_position[player].second;
    if(i==goals[player].first&&j==goals[player].second)
    {
        grid[i][j] = 'W';
        return true;
    }
    else
        return false;
}
//Check empty
void check_empty(int i,int j,int player)
{
    if(grid[i][j]!='.'&&grid[i][j]!=players_soldiers[player])
    {
        if(grid[i][j]=='R')
        {
            grid[i][j] = players_soldiers[player];
            int x=home_players[0].first,y=home_players[0].second;
            grid[x][y] = 'R';
            player_position[0]=home_players[0];
            cout<<"Oops Player "<<player_name[player]<<" "<<"Kills Player Red";
        }
        else if(grid[i][j]=='B')
        {
            grid[i][j] = players_soldiers[player];
            int x=home_players[1].first,y=home_players[1].second;
            grid[x][y] = 'B';
            player_position[1] = home_players[1];
            cout<<"Oops Player "<<player_name[player]<<" "<<"Kills Player Blue";
        }
        else if(grid[i][j]=='G')
        {
            grid[i][j] = players_soldiers[player];
            int x=home_players[2].first,y=home_players[2].second;
            grid[x][y] = 'G';
            player_position[2] = home_players[2];
            cout<<"Oops Player "<<player_name[player]<<" "<<"Kills Player Green";
        }
        else if(grid[i][j]=='Y')
        {
            grid[i][j] = players_soldiers[player];
            int x=home_players[3].first,y=home_players[3].second;
            grid[x][y] = 'Y';
            player_position[3] = home_players[3];
            cout<<"Oops Player "<<player_name[player]<<" "<<"Kills Player Yellow";
        }
    }
}
//This function moves the given player by the given value
void move_player(int player,int moves)
{
    int i=player_position[player].first,j=player_position[player].second;
    if (home_players[player].first ==i&&home_players[player].second ==j && moves == 6)
    {
        if(player==0)
        {
            grid[i][j]='.';
            player_position[player] = player1_path[0];
            int x=player_position[player].first,y=player_position[player].second;
            grid[x][y] = players_soldiers[player];
        }
        else if(player==1)
        {
            grid[i][j]='.';
            player_position[player] = player2_path[0];
            int x=player_position[player].first,y=player_position[player].second;
            grid[x][y] = players_soldiers[player];
        }
        else if(player==2)
        {
            grid[i][j]='.';
            player_position[player] = player3_path[0];
            int x=player_position[player].first,y=player_position[player].second;
            grid[x][y] = players_soldiers[player];
        }
        else if(player==3)
        {
            grid[i][j]='.';
            player_position[player] = player4_path[0];
            int x=player_position[player].first,y=player_position[player].second;
            grid[x][y] = players_soldiers[player];
        }
    }
    else if(home_players[player].first!=i&& home_players[player].second!=j)
    {
        if(player==0)
        {
            grid[i][j] = '.';
            int position;
            for(int h=0; h<player1_path.size(); ++h)
            {
                if(player1_path[h].first==player_position[player].first&&player1_path[h].second==player_position[player].second)
                {
                    position=h;
                    break;
                }
            }
            position+=moves;
            player_position[player] = player1_path[position];
            int x=player_position[player].first,y=player_position[player].second;
            check_empty(x, y, player);
            grid[x][y] = players_soldiers[player];
        }
        else if(player==1)
        {
            grid[i][j] = '.';
            int position;
            for(int h=0; h<player2_path.size(); ++h)
            {
                if(player2_path[h].first==player_position[player].first&&player2_path[h].second==player_position[player].second)
                {
                    position=h;
                    break;
                }
            }
            position+=moves;
            player_position[player] = player2_path[position];
            int x=player_position[player].first,y=player_position[player].second;
            check_empty(x, y, player);
            grid[x][y] = players_soldiers[player];

        }
        else if(player==2)
        {
            grid[i][j] = '.';
            int position;
            for(int h=0; h<player3_path.size(); ++h)
            {
                if(player3_path[h].first==player_position[player].first&&player3_path[h].second==player_position[player].second)
                {
                    position=h;
                    break;
                }
            }
            position+=moves;
            player_position[player] = player3_path[position];
            int x=player_position[player].first,y=player_position[player].second;
            check_empty(x, y, player);
            grid[x][y] = players_soldiers[player];

        }
        else if(player==3)
        {
            grid[i][j] = '.';
            int position;
            for(int h=0; h<player4_path.size(); ++h)
            {
                if(player4_path[h].first==player_position[player].first&&player4_path[h].second==player_position[player].second)
                {
                    position=h;
                    break;
                }
            }
            position+=moves;
            player_position[player] = player4_path[position];
            int x=player_position[player].first,y=player_position[player].second;
            check_empty(x, y, player);
            grid[x][y] = players_soldiers[player];
        }
    }
}
//This function check if the given dice face is a valid dice face
bool check_valid_dice(int player,int diceface)
{
    int i=player_position[player].first,j=player_position[player].second;
    int flag=0;
    for(int h=0; h<home_players.size(); ++h)
    {
        if(i==home_players[h].first&&j==home_players[h].second)
        {
            flag=1;
            break;
        }
    }
    while(flag==0)
    {
        if(player==0)
        {
            int c_index,l_index;
            for(int h=0; h<player1_path.size(); ++h)
            {
                if(player1_path[h].first==i&&player1_path[h].second==j)
                {
                    c_index=h;
                    break;
                }
            }
            l_index=player1_path.size()-1;
            if(c_index + diceface <= l_index)
                return true;
            else return false;
        }
        else if(player==1)
        {
            int c_index,l_index;
            for(int h=0; h<player2_path.size(); ++h)
            {
                if(player2_path[h].first==i&&player2_path[h].second==j)
                {
                    c_index=h;
                    break;
                }
            }
            l_index=player2_path.size()-1;
            if(c_index + diceface <= l_index)
                return true;
            else return false;
        }
        else if(player==2)
        {
            int c_index,l_index;
            for(int h=0; h<player3_path.size(); ++h)
            {
                if(player3_path[h].first==i&&player3_path[h].second==j)
                {
                    c_index=h;
                    break;
                }
            }
            l_index=player3_path.size()-1;
            if(c_index + diceface <= l_index)
                return true;
            else return false;
        }
        else if(player==3)
        {
            int c_index,l_index;
            for(int h=0; h<player4_path.size(); ++h)
            {
                if(player4_path[h].first==i&&player4_path[h].second==j)
                {
                    c_index=h;
                    break;
                }
            }
            l_index=player4_path.size()-1;
            if(c_index + diceface <= l_index)
                return true;
            else return false;
        }
    }
    if(flag==1)return true;





}

//This function reads a valid input
int read_input()
{
    cout << "Press Enter To Get Random Number : ";
    int i;
    cin >> i;
    return i;
}
//clear the grid
void grid_clear()
{
    memset(grid,'.',sizeof(grid));
    home_players = {{11,1},{2,1},{2,10},{11,10}};
    player_position = {{11,1},{2,1}, {2,10},{11,10}};
}
void play_game()
{
    cout<<"-------LUDO Game!--------"<<endl<<"Welcome..."<<endl<<"============================";
    int player=0;
    print_player_box();
    print_goal_box();
    while(true)
    {
        // Prints the grid
        print_grid();
        // Read an input dice face from the player
        cout<<"Player "<<player_name[player]<<" is playing now"<<endl;
        int i=read_input();
        // Generate a dice face
        int dice_face = generate_dice_face();
        cout<<print_dice_face(dice_face)<<endl;
        //Check valid Move
        if(check_valid_dice(player,dice_face))
        {
            // Move the player position
            move_player(player,dice_face);
        }
        if(check_win(player))
        {
            // Prints the grid
            print_grid();
            cout<<"Congrats, Player "<<player_name[player]<<"  is won!"<<endl;
            break;
        }
        player += 1;
        if (player > 3)
            player = 0;
    }

}
int main()
{
    while(true)
    {
        grid_clear();
        play_game();
        char c;
        cout<<"Play Again [Y/N] ";
        cin>>c;
        if(c!='Y'||c!='y')
            break;

    }
}
