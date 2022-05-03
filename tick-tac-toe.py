import random as rand
 
def check_win(board):
  if board[0] == board[1] == board[2]:
    return board[0]
  if board[3] == board[4] == board[5]:
    return board[3]
  if board[6] == board[7] == board[8]:
    return board[6]
  if board[0] == board[3] == board[6]:
    return board[0]
  if board[1] == board[4] == board[7]:
    return board[1]
  if board[2] == board[5] == board[8]:
    return board[2]
  if board[0] == board[4] == board[8]:
    return board[0]
  if board[2] == board[4] == board[6]:
    return board[2]
  
def print_board(board):
  print(board[0] + ' | ' + board[1] + ' | ' + board[2])
  print('---+---+---')
  print(board[3] + ' | ' + board[4] + ' | ' + board[5])
  print('---+---+---')
  print(board[6] + ' | ' + board[7] + ' | ' + board[8])
 
name = input('What is your name? \n')
print(name, 'you are X')
print('computer is O')
board = [str(i) for i in range(1, 10)]
x_count = 0
print(board)
 
while True:
  print_board(board)
  while True:
    move_x = int(input('Make your move!'))
 
    if board[move_x-1] not in ["X", "O"]:
      board[move_x-1] = 'X'
      x_count += 1
      break
    else:
      print('Invalid move.')
  if check_win(board) == 'X':
    print('You Won!')
    break
  if x_count == 5:
    print('It\'s a tie!')
  while True:
    move_o = rand.randint(0, 8)
 
    if board[move_o] not in ["X", "O"]:
      board[move_o] = "O"
      break
  if check_win(board) == 'O':
    print(name, 'You Lost!')
    break
 
 
