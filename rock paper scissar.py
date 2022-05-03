rock = 1
paper = 2
scissar = 3
user = ""
thisIspython = 0

while True: 
  user = input("Enter rock, paper, scissar or break: ")
  import random
  thisIspython = random.randint(1,3)

  if user.upper() == "ROCK":
    if thisIspython == 1:
      print("Draw both are rock.")
    elif thisIspython == 2:
      print("You lose computer was paper.")
    elif thisIspython == 3:
      print("You win computer throw scissars and you smased them.")
    else:
      pass
  elif user.upper() == "PAPER":
    if thisIspython == 2:
      print("Draw both are paper.")
    elif thisIspython == 3:
      print("You lose computer was scissar.")
    elif thisIspython == 1:
      print("You win computer throw rock and covered it.")
    else:
      pass   
  elif user.lower() == "scissar":
    if thisIspython == 3:
      print("Draw both are scissar.")
    elif thisIspython == 1:
      print("You lose computer was rock.")
    elif thisIspython == 2:
      print("You win computer had paper and you cut it up.")
    else:
      pass

  elif user.upper() == "BREAK":
    break
  else:
    print("invalid input!")
