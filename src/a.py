class Transport:
  def __init__(self, f_name: str):
    self.name: str = f_name


class Train(Transport):
  def __init__(self, f_train_name: str, f_transport_name: str):
    self.train_name: str = f_train_name
    Transport.__init__(self, f_transport_name)


class Flight(Transport):
  def __init__(self, f_flight_name: str, f_transport_name: str):
    self.flight_name: str = f_flight_name
    Transport.__init__(self, f_transport_name)


class Car(Transport):
  def __init__(self, car_name: str, transport_name: str):
    self.car_name: str = car_name
    Transport.__init__(self, transport_name)


class Trip:
  def __init__(self, trip_name: str, transport: Transport):
    self.trip_name: str = trip_name
    self.transport: Transport = transport

  def print_trip(self):
    print("Trip Name:", self.trip_name)
    print("Transport Name:", self.transport.name)


def main():
  train_obj: Train = Train("Express", "Train")
  flight_obj: Flight = Flight("Boeing 747", "Flight")
  car_obj: Car = Car("SUV", "Car")

  # trip1: Trip = Trip("Train Trip", train_obj)
  # trip2: Trip = Trip("Flight Trip", flight_obj)
  # trip3: Trip = Trip("Car Trip", car_obj)

  # trip1.print_trip()
  # trip2.print_trip()
  # trip3.print_trip()


if __name__ == "__main__":
  main()
