import random

N, M = 15 , 15
n_players = 4
player_name = ['Red', 'Blue', 'Green', 'Yellow']
players_soldiers = ['R', 'B', 'G', 'Y']
goals_symbols = ['R', 'B', 'G', 'Y']
player_position = [(11,1),(2,1), (2,10), (11,10)]
boxes_boarders = [[9,0],[0,0],[0,9],[9,9]]
home_players = [(11,1),(2,1), (2,10), (11,10)]
goals = [(8,7),(7,6),(6,7),(7,8)]
player1_path = [(13,6),(12,6),(11,6),(10,6),(9,6),(8,5),(8,4),(8,3),(8,2),(8,1),(8,0),(7,0),(6,0),(6,1),(6,2),(6,3),(6,4),(6,5),(5,6),(4,6),(3,6),(2,6),(1,6),(0,6),(0,7),(0,8),(1,8),(2,8),(3,8),(4,8),(5,8),(6,9),(6,10),(6,11),(6,12),(6,13),(6,14),(7,14),(8,14),(8,13),(8,12),(8,11),(8,10),(8,9),(9,8),(10,8),(11,8),(12,8),(13,8),(14,8),(14,7),(13,7),(12,7),(11,7),(10,7),(9,7),(8,7)]
player2_path = [(6,1),(6,2),(6,3),(6,4),(6,5),(5,6),(4,6),(3,6),(2,6),(1,6),(0,6),(0,7),(0,8),(1,8),(2,8),(3,8),(4,8),(5,8),(6,9),(6,10),(6,11),(6,12),(6,13),(6,14),(7,14),(8,14),(8,13),(8,12),(8,11),(8,10),(8,9),(9,8),(10,8),(11,8),(12,8),(13,8),(14,8),(14,7),(14,6),(13,6),(12,6),(11,6),(10,6),(9,6),(8,5),(8,4),(8,3),(8,2),(8,1),(8,0),(7,0),(7,1),(7,2),(7,3),(7,4),(7,5),(7,6)]
player3_path = [(1,8),(2,8),(3,8),(4,8),(5,8),(6,9),(6,10),(6,11),(6,12),(6,13),(6,14),(7,14),(8,14),(8,13),(8,12),(8,11),(8,10),(8,9),(9,8),(10,8),(11,8),(12,8),(13,8),(14,8),(14,7),(14,6),(13,6),(12,6),(11,6),(10,6),(9,6),(8,5),(8,4),(8,3),(8,2),(8,1),(8,0),(7,0),(6,0),(6,1),(6,2),(6,3),(6,4),(6,5),(5,6),(4,6),(3,6),(2,6),(1,6),(0,6),(0,7),(1,7),(2,7),(3,7),(4,7),(5,7),(6,7)]
player4_path = [(8,13),(8,12),(8,11),(8,10),(8,9),(9,8),(10,8),(11,8),(12,8),(13,8),(14,8),(14,7),(14,6),(13,6),(12,6),(11,6),(10,6),(9,6),(8,5),(8,4),(8,3),(8,2),(8,1),(8,0),(7,0),(6,0),(6,1),(6,2),(6,3),(6,4),(6,5),(5,6),(4,6),(3,6),(2,6),(1,6),(0,6),(0,7),(0,8),(1,8),(2,8),(3,8),(4,8),(5,8),(6,9),(6,10),(6,11),(6,12),(6,13),(6,14),(7,14),(7,13),(7,12),(7,11),(7,10),(7,9),(7,8)]

grid = [['.' for x in range(N)] for y in range(M)]

#player_1 = ['R1','R2','R3', 'R4']
#player_2 = ['B1','B2','B3', 'B4']
#player_3 = ['G1','G2','G3', 'G4']
#player_4 = ['Y1','Y2','Y3', 'Y4']

#box_player_1 = [9,0]
#box_player_2 = [0,0]
#box_player_3 = [0,9]
#box_player_4 = [9,9]

#home_player_1 = [(11,1), (11,4), (13,1), (13,4)]
#home_player_2 = [(2,1), (2,4), (4,1), (4,4)]
#home_player_3 = [(2,10), (2,13), (4,10), (4,13)]
#home_player_4 = [(11,10), (11,13), (13,10), (13,13)]


#goal_player_1 = (8,7)
#goal_player_2 = (7,6)
#goal_player_3 = (6,7)
#goal_player_4 = (7,8)
#-----This function print box for each player ----------
def print_player_box():
    for x in range(N):
        for y in range(M):
            for z in home_players:
                if (x,y) == z:
                    grid[x][y] = players_soldiers[home_players.index(z)]

#------ This function print the goal box ----------------
def print_goal_box():
    for i in range(N):
        for j in range(M):
            if (i,j) in goals:
                grid[i][j] = goals_symbols[goals.index((i,j))]
#------- This function print the grid -------------------
def print_grid():
    for i in range(n_players):
        print('Player %d: %s  ' % (i + 1, player_name[i]), end='')
        if i < n_players - 1:
            print('vs  ', end='')
    print()
    print('---' + '----' * (M) + '-------')
    for i in range(N):
        print(end='|  ')
        for j in range(M):
            if [i,j] in boxes_boarders:
                #print_player_box(i,j)
                print(grid[i][j],end ='   ')
                if j == 5 or j == 8 :
                    print(end='| ')
            else:
                print(grid[i][j],  end='   ')
                if j == 5 or j == 8 :
                    print(end='|  ')
        print(end='|')
        print()
        if i == 5 or i == 8 or i == 14:
            print('---' + '----' * (M) + '-------')


# ------- This function generate a random dice face ---------------------
def generate_dice_face():
    dice_face = random.randint(1, 6)
    return dice_face

#--------- This function prints the given dice face ---------------------
def print_dice_face(i):
    s = ''
    if i == 1:
        s += ' _____ \n'
        s += '|     |\n'
        s += '|  *  |\n'
        s += '|_____|\n'
    if i == 2:
        s += ' _____ \n'
        s += '|    *|\n'
        s += '|     |\n'
        s += '|*____|\n'
    if i == 3:
        s += ' _____ \n'
        s += '|    *|\n'
        s += '|  *  |\n'
        s += '|*____|\n'
    if i == 4:
        s += ' _____ \n'
        s += '|*   *|\n'
        s += '|     |\n'
        s += '|*___*|\n'
    if i == 5:
        s += ' _____ \n'
        s += '|*   *|\n'
        s += '|  *  |\n'
        s += '|*___*|\n'
    if i == 6:
        s += ' _____ \n'
        s += '|*   *|\n'
        s += '|*   *|\n'
        s += '|*___*|\n'
    return s
# ----------This function check if the given player is win the game:--------------
def check_win(player):
    i,j = player_position[player]
    if (i,j) == goals[player]:
        grid[i][j] = 'W'
        return True
    else:
        return False


#---------- Check empty ------------------

def check_empty(i,j,player):
    if grid[i][j] != '.' and grid[i][j] != players_soldiers[player]:
        if grid[i][j] == 'R':
            grid[i][j] = players_soldiers[player]
            x,y = home_players[0]
            grid[x][y] = 'R'
            player_position[0] = home_players[0]
            print('Oops Player  %s  Kills Player Red' % player_name[player])
        elif grid[i][j] == 'B':
            grid[i][j] = players_soldiers[player]
            x, y = home_players[1]
            grid[x][y] = 'B'
            player_position[1] = home_players[1]
            print('Oops Player  %s  Kills Player Blue' % player_name[player])
        elif grid[i][j] == 'G':
            grid[i][j] = players_soldiers[player]
            x, y = home_players[2]
            grid[x][y] = 'G'
            player_position[2] = home_players[2]
            print('Oops Player  %s  Kills Player Green' % player_name[player])
        elif grid[i][j] == 'Y':
            grid[i][j] = players_soldiers[player]
            x, y = home_players[3]
            grid[x][y] = 'Y'
            player_position[3] = home_players[3]
            print('Oops Player  %s  Kills Player Yellow' % player_name[player])


#-------- This function moves the given player by the given value -----------------
def move_player(player, moves):
    i, j = player_position[player]
    if home_players[player] == (i, j) and moves == 6:
        if player == 0:
                    grid[i][j] = '.'
                    player_position[player] = player1_path[0]
                    x, y = player_position[player]
                    grid[x][y] = players_soldiers[player]

        elif player == 1:
                    grid[i][j] = '.'
                    player_position[player] = player2_path[0]
                    x, y = player_position[player]
                    grid[x][y] = players_soldiers[player]

        elif player == 2:
                    grid[i][j] = '.'
                    player_position[player] = player3_path[0]
                    x, y = player_position[player]
                    grid[x][y] = players_soldiers[player]

        elif player == 3:
                    grid[i][j] = '.'
                    player_position[player] = player4_path[0]
                    x, y = player_position[player]
                    grid[x][y] = players_soldiers[player]

    elif home_players[player] != (i,j):
        if player == 0:
                    grid[i][j] = '.'
                    position = player1_path.index(player_position[player])
                    position += moves
                    player_position[player] = player1_path[position]
                    x, y = player_position[player]
                    check_empty(x, y, player)
                    grid[x][y] = players_soldiers[player]


        elif player == 1:
                    grid[i][j] = '.'
                    position = player2_path.index(player_position[player])
                    position += moves
                    player_position[player] = player2_path[position]
                    x, y = player_position[player]
                    check_empty(x, y, player)
                    grid[x][y] = players_soldiers[player]

        elif player == 2:
                    grid[i][j] = '.'
                    position = player3_path.index(player_position[player])
                    position += moves
                    player_position[player] = player3_path[position]
                    x, y = player_position[player]
                    check_empty(x,y,player)
                    grid[x][y] = players_soldiers[player]

        elif player == 3:
                    grid[i][j] = '.'
                    position = player4_path.index(player_position[player])
                    position += moves
                    player_position[player] = player4_path[position]
                    x, y = player_position[player]
                    check_empty(x,y,player)
                    grid[x][y] = players_soldiers[player]


#------- This function check if the given dice face is a valid dice face------------
def check_valid_dice(player, diceface):
    i, j = player_position[player]
    while (i,j) not in home_players:
        if player == 0:
            c_index = player1_path.index((i,j))
            l_index = len(player1_path)-1
            if c_index + diceface <= l_index:
                return True
            else:
                return False
        elif player == 1:
            c_index = player2_path.index((i, j))
            l_index = len(player2_path) - 1
            if c_index + diceface <= l_index:
                return True
            else:
                return False
        elif player == 2:
            c_index = player3_path.index((i, j))
            l_index = len(player3_path) - 1
            if c_index + diceface <= l_index:
                return True
            else:
                return False
        elif player == 3:
            c_index = player4_path.index((i, j))
            l_index = len(player4_path) - 1
            if c_index + diceface <= l_index:
                return True
            else:
                return False
    else:
        return True


#---------- This function reads a valid input-------------
def read_input():
    i = input('Press Enter To Get Random Number : ')
    return i

#--------- This function clear the grid ------------------
def grid_clear():
    for i in range(N):
        for j in range(M):
            grid[i][j] = '.'
    player_position[:] = home_players
def play_game():
    print("-------LUDO Game!--------")
    print("Welcome...")
    print("============================")
    player = 0
    print_player_box()
    print_goal_box()
    while True:
        # Prints the grid
        print_grid()
        # Read an input dice face from the player
        print('Player %s is playing now' % player_name[player])
        i = read_input()
        # Generate a dice face
        dice_face = generate_dice_face()
        print(print_dice_face(dice_face))
        #Check valid Move
        if check_valid_dice(player,dice_face):
            # Move the player position
            move_player(player,dice_face)
        if check_win(player):
            # Prints the grid
            print_grid()
            print('Congrats, Player %s is won!' % player_name[player])
            break
        player += 1
        if player > 3:
            player = 0


while True:
    grid_clear()
    play_game()
    c = input('Play Again [Y/N] ')
    if c not in 'yY':
        break