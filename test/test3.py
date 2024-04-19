class ShiftReduceParser:

  def __init__(self, name_: str):
    self.srname: str = name_
  def print_name(self):
    print("SLR name:")
    print(self.srname)

class LR0Parser(ShiftReduceParser):
  
  def __init__(self, myname_: str, sr_name: str):
    self.lr0name: str = myname_
    ShiftReduceParser.__init__(self, sr_name)
    return


class CLRParser(LR0Parser):

  def __init__(self, myname_: str, lr_name: str, sr_name:str):
    self.clrname: str = myname_
    LR0Parser.__init__(self, lr_name,sr_name)


class LALRParser(CLRParser):

  def __init__(self, myname_: str, clrname_: str,lr_name:str, srname_: str):
    self.lalrname: str = myname_
    CLRParser.__init__(self, clrname_,lr_name, srname_)

  def print_all(self):
    print("SLR name:")
    print(self.srname)
    print("CLR name:")
    print(self.clrname)
    print("LR0 name:")
    print(self.lr0name)
    print("LALR name:")
    print(self.lalrname)


def main():
  obj: LALRParser = LALRParser("LALR", "CLR","LR0","Shift-Reduce")
  obj.print_all()
  obj.print_name()


if __name__ == "__main__":
  main()

