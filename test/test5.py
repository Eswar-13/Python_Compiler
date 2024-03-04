class Batsman:
  def __init__(self, name):
    self.name = name
    self.runs_scored = 0
    self.balls_faced = 0

  def bat(self, outcome):
    if outcome == 6:
      print(self.name + " scored a SIX!")
    elif outcome == 4:
      print(self.name + " scored a FOUR!")
    elif outcome == "OUT":
      print(self.name + " is out!")
    else:
      self.runs_scored += outcome
      self.balls_faced += 1

class Umpire:
  def __init__(self):
    pass

  def raise_finger(self):
    print("OUT!")

class Fielder:
  def __init__(self, name):
    self.name = name

class Team:
  def __init__(self, name):
    self.name = name
    self.runs = 0
    self.wickets = 0
    self.batsmen = [Batsman("Batsman " + str(i+1)) for i in range(11)]
    self.umpire = Umpire()
    self.fielders = [Fielder("Fielder " + str(i+1)) for i in range(11)]

  def play_innings(self, outcomes):
    overs = 10
    balls_per_over = 6
    total_balls = overs * balls_per_over
    for ball in range(total_balls):
      for batsman in self.batsmen:
        batsman.bat(outcomes)
      if ball % balls_per_over == 0:
        print(self.name + " - Over " + str(ball // balls_per_over + 1) + ": " + str(self.runs) + "/" + str(self.wickets))
    print("\nInnings complete: " + self.name + " scored " + str(self.runs) + "/" + str(self.wickets))

def main():
  team1 = Team("Team 1")
  team2 = Team("Team 2")

  outcomes = [0, 1, 2, 3, 4, 6, "OUT"]

  print("Match started!")
  print("First Innings:")
  team1.play_innings(outcomes)

  print("\nSecond Innings:")
  team2.play_innings(outcomes)

  print("\nMatch ended!")

if __name__ == "__main__":
  main()
