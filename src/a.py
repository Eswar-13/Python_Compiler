class ShiftReduceParser:

  def __init__(self, name_: str):
    self.srname: str = name_
  def ast(self):
    x:int=0

class LR0Parser(ShiftReduceParser):
  def __init__(self, myname_: str, parentname_: str):
    self.lr0name: str = myname_
    self.srname = myname_
    ShiftReduceParser.__init__(self, parentname_)

a:ShiftReduceParser=ShiftReduceParser("asd")
a.ast()
b:LR0Parser=LR0Parser("a","b")
c:str=b.lr0name