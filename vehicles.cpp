#include <vehicles.h>
#include <shapes.h>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <iostream>

CommercialVehicle::CommercialVehicle() : vehicleRegistration_(NULL), operatorID_(NULL), operatorCDL_(NULL), passengerCapacity_(0), verbose_(0)
{
  if (verbose_)
    std::cout << "CommercialVehicle(" << vehicleRegistration_ << operatorID_ << operatorCDL_ << passengerCapacity_ << verbose_ << ")" << std::endl;

  vehicleRegistration_ = new char[2];
  vehicleRegistration_[0] = '#';
  vehicleRegistration_[1] = '\0';

  operatorID_ = new char[2];
  operatorID_[0] = '#';
  operatorID_[1] = '\0';

  operatorCDL_ = new char[2];
  operatorCDL_[0] = '#';
  operatorCDL_[1] = '\0';
}

CommercialVehicle::CommercialVehicle(const char * registration, const char * operatorID, const char * operatorCDL, unsigned short passengerCapacity, bool verbose) : vehicleRegistration_(NULL), operatorID_(NULL), operatorCDL_(NULL), passengerCapacity_(passengerCapacity), verbose_(verbose)
{
  size_t size = strlen(registration);
  vehicleRegistration_ = new char[1 + size];
  vehicleRegistration_[size] = '\0';
  strcpy(vehicleRegistration_, registration);

  size_t size2 = strlen(operatorID);
  operatorID_ = new char [1 + size2];
  operatorID_[size2] = '\0';
  strcpy(operatorID_, operatorID);

  size_t size3 = strlen(operatorCDL);
  operatorCDL_ = new char [1 + size3];
  operatorCDL_[size3] = '\0';
  strcpy(operatorCDL_, operatorCDL);

  if (verbose_)
    std::cout << "CommercialVehicle(" << vehicleRegistration_ << "," << operatorID_ << "," << operatorCDL_ << "," << passengerCapacity_ << "," << verbose_ << ")" << std::endl;
}

CommercialVehicle::~CommercialVehicle()
{
  if (verbose_)
  {
    std::cout << "~CommercialVehicle()" << std::endl;
  }
  delete[] vehicleRegistration_;
  delete[] operatorID_;
  delete[] operatorCDL_;
}
const char * CommercialVehicle::Registration() const
{
  return vehicleRegistration_;
}

const char * CommercialVehicle::Operator() const
{
  return operatorID_;
}

const char * CommercialVehicle::CDL() const
{
  return operatorCDL_;
}

const char * CommercialVehicle::ShortName() const
{
  return "UNK";
}

unsigned int CommercialVehicle::PassengerCapacity() const
{
  return passengerCapacity_;
}

float CommercialVehicle::LoadCapacity() const
{
  return 0.0;
}

VehicleType CommercialVehicle::RegDecode(const char * sn)
{
  //VehicleType v;
  switch (sn[0])
  {
    case '0':
      return badReg;
      //v = badReg;
    case '1':
      return vehicle;
      //v = vehicle;
    case '2':
      return carriage;
      //v = carriage;
    case '3':
      return bus;
      //v = bus;
    case '4':
      return limo;
      //v = limo;
    case '5':
      return truck;
      //v = truck;
    case '6':
      return van;
      //v = van;
    case '7':
      return tanker;
      //v = tanker;
    case '8':
      return flatbed;
      //v = flatbed;
  }
  return badReg; 
  //return v;
}

Carriage::Carriage() : CommercialVehicle()
{
  if (verbose_)
  std::cout << "Carriage()" << std::endl;
}

Carriage::Carriage(const char * registration, const char * operatorID, const char * operatorCDL, unsigned short passengerCapacity, bool verbose) : CommercialVehicle(registration, operatorID, operatorCDL, passengerCapacity, verbose)
{
  if (CommercialVehicle::verbose_)
    std::cout << "Carriage(" << registration << "," << operatorID << "," << operatorCDL << "," << passengerCapacity << "," << verbose << ")" << std::endl; 
}

Carriage::~Carriage()
{
  if (CommercialVehicle::verbose_)
  {  
    std::cout << "~Carriage()" << std::endl;
  }  
}

const char* Carriage::ShortName() const
{
  return "CAR";
}

Bus::Bus() : Carriage()
{
}

Bus::~Bus()
{
  if (CommercialVehicle::verbose_)
  std::cout << "~Bus()" << std::endl;
}

Bus::Bus(const char * registration, const char * operatorID, const char * operatorCDL, unsigned short passengerCapacity, bool verbose) : Carriage(registration, operatorID, operatorCDL, passengerCapacity, verbose)
{
  if (CommercialVehicle::verbose_)
    std::cout << "Bus(" << registration << "," << operatorID << "," << operatorCDL << "," << passengerCapacity << "," << verbose << ")" << std::endl;
}

const char * Bus::ShortName() const
{
  return "BUS";
}

Limo::Limo() : Carriage()
{
}

Limo::~Limo()
{
  if (CommercialVehicle::verbose_)
  std::cout << "~Limo()" << std::endl;
}

Limo::Limo(const char* registration, const char* operatorID, const char* operatorCDL, unsigned short passengerCapacity, bool verbose) : Carriage(registration, operatorID, operatorCDL, passengerCapacity, verbose)
{
  if (CommercialVehicle::verbose_)
    std::cout << "Limo(" << registration << "," << operatorID << "," << operatorCDL << "," << passengerCapacity << "," << verbose << ")" << std::endl;
}

const char* Limo::ShortName() const
{
  return "LIM";
}

Truck::Truck() : CommercialVehicle()
{
}

Truck::~Truck()
{
  if (CommercialVehicle::verbose_)
  std::cout << "~Truck()" << std::endl;
}

Truck::Truck(const char * registration, const char* operatorID, const char* operatorCDL, bool verbose) : CommercialVehicle(registration, operatorID, operatorCDL, 0, verbose)
{
  if (CommercialVehicle::verbose_)
    std::cout << "Truck(" << registration << "," << operatorID << "," << operatorCDL << "," << verbose << ")" << std::endl; 
}

const char * Truck::ShortName() const
{
  return "TRK";
}

Van::Van() : Truck(), Box()
{
}

Van::~Van()
{
  if (CommercialVehicle::verbose_) {
  std::cout << "~Van()" << std::endl;
  std::cout << "~Box()" << std::endl;
  std::cout << "~Shape()" << std::endl;
  } 
}

Van::Van(const char * registration, const char* operatorID, const char*
         operatorCDL, float width, float length, float height, bool verbose) : Truck(registration, operatorID, operatorCDL, verbose), Box(width, length, height)
{
  if (CommercialVehicle::verbose_) {
    std::cout << "Shape(" << width << "," << length << "," << height << "," << verbose << ")" << std::endl;
  if (CommercialVehicle::verbose_)
    std::cout << "Box(" << width << "," << length << "," << height << "," << verbose << ")" << std::endl;
  if (CommercialVehicle::verbose_)
    std::cout << "Van(" << registration << "," << operatorID << "," << operatorCDL << "," << width << "," << length << "," << height << "," << verbose << ")" << std::endl; 
  }
}

float Van::LoadCapacity() const
{
  return Box::Volume();
}

const char * Van::ShortName() const
{
  return "VAN";
}

Tanker::Tanker() : Truck(), Cylinder()
{
}

Tanker::~Tanker()
{
  if (CommercialVehicle::verbose_) {
  std::cout << "~Tanker()" << std::endl;
  std::cout << "~Cylinder()" << std::endl;
  std::cout << "~Shape()" << std::endl;
  }
}

Tanker::Tanker(const char * registration, const char* operatorID, const char* operatorCDL, float radius, float height, bool verbose) : Truck(registration, operatorID, operatorCDL, verbose), Cylinder(radius, height)
{
  if (CommercialVehicle::verbose_) {
    std::cout << "Shape(" << radius << "," << 0.00 << "," << height << "," << verbose << ")" << std::endl;
  std::cout << "Cylinder(" << radius << "," << height << "," << verbose << ")" << std::endl;
  std::cout << "Tanker(" << registration << "," << operatorID << "," << operatorCDL << "," << radius << "," << height << "," << verbose << ")" << std::endl;
  }
}

float Tanker::LoadCapacity() const
{
  return Cylinder::Volume();
}

const char * Tanker::ShortName() const
{
  return "TNK";
}

Flatbed::Flatbed() : Truck(), Rectangle()
{
}

Flatbed::~Flatbed()
{
  if (CommercialVehicle::verbose_) {
  std::cout << "~Flatbed()" << std::endl;
  std::cout << "~Rectangle()" << std::endl;
  std::cout << "~Shape()" << std::endl;
  }
}

Flatbed::Flatbed(const char * registration, const char * operatorID, const char* operatorCDL, float width, float length, bool verbose) : Truck(registration, operatorID, operatorCDL, verbose), Rectangle(width, length, 0)
{
  if (CommercialVehicle::verbose_) {
    std::cout << "Shape(" << width << "," << length << "," << 0.00 << "," << verbose << ")" << std::endl;
  std::cout << "Rectangle(" << width << "," << length << "," << verbose << ")" << std::endl;
  std::cout << "Flatbed(" << registration << "," << operatorID << "," << operatorCDL << "," << width << "," << length << "," << verbose << ")" << std::endl;
  }
}

float Flatbed::LoadCapacity() const
{
  return Rectangle::Area();
}

const char * Flatbed::ShortName() const
{
  return "FLT";
}
