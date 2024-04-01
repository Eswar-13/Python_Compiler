class Batsman:
  def __init__(self, name:str):
    self.name:str = name
    self.runs_scored:int = 0
    self.balls_faced:int = 0

  def bat(self, outcome:int):
    if outcome == 6:
      print(self.name + " scored a SIX!")
    elif outcome == 4:
      print(self.name + " scored a FOUR!")
    else:
      self.runs_scored += outcome
      self.balls_faced += 1

class Umpire:
  def __init__(self):
    a:int=0

  def raise_finger(self):
    print("OUT!")

class Fielder:
  def __init__(self, name:str):
    self.name:str = name

class Team:
  def __init__(self, name:str):
    self.name:str = name
    self.runs:int = 0
    self.wickets:int = 0
    self.batsmen:Batsman = Batsman("Batsman 1")
    self.umpire:Umpire = Umpire()
    self.fielders:Fielder = Fielder("Fielder 1")

  def play_innings(self, outcomes:int):
    overs:int = 10
    balls_per_over:int = 6
    total_balls:int = overs * balls_per_over
    ball:int=0
    for ball in range(total_balls):
      i:int=0
      batsman:Batsman=Batsman("Ak")
      for i in range(2):
        batsman.bat(outcomes)
      if ball % balls_per_over == 0:
        print(self.name)
    print("Innings complete: " + self.name + " scored ")

def main():
  team1:Team = Team("Team 1")
  team2:Team = Team("Team 2")

  outcomes:int = 1

  print("Match started!")
  print("First Innings:")
  team1.play_innings(outcomes)

  print("\nSecond Innings:")
  team2.play_innings(outcomes)

  print("\nMatch ended!")

if __name__ == "__main__":
  main()
