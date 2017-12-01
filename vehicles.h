// vehicles.h
#ifndef _VEHICLES_H
#define _VEHICLES_H

#include "shapes.h"

enum VehicleType{badReg = 0, vehicle, carriage, bus, limo, truck, van, tanker, flatbed};

class CommercialVehicle
{
public:
  CommercialVehicle();
  CommercialVehicle(const char*, const char*, const char*, unsigned short, bool verbose = false);
  virtual ~CommercialVehicle();
  
  const char* Registration() const;
  const char* Operator() const;
  const char* CDL() const;
  virtual const char* ShortName() const;

  unsigned int PassengerCapacity() const;
  virtual float LoadCapacity() const;
  
  static VehicleType RegDecode(const char* sn);

private:
  CommercialVehicle(const CommercialVehicle& v);
  CommercialVehicle& operator= (const CommercialVehicle v);
  char* vehicleRegistration_;
  char* operatorID_;
  char* operatorCDL_;
  unsigned int passengerCapacity_;
protected:
  bool verbose_;
};

class Carriage : public CommercialVehicle
{
public:
  Carriage();
  Carriage(const char*, const char*, const char*, unsigned short, bool verbose = false);
  virtual ~Carriage();
  virtual const char* ShortName() const;
private:
  Carriage(const Carriage& v);
  Carriage& operator= (const Carriage v);
};

class Bus : public Carriage
{
public:
  Bus();
  virtual ~Bus();
  Bus(const char*, const char*, const char*, unsigned short, bool verbose = false);
  virtual const char* ShortName() const;
private:
  Bus(const Bus& v);
  Bus& operator= (const Bus v);
};

class Limo : public Carriage
{
public:
  Limo();
  virtual ~Limo();
  Limo(const char*, const char*, const char*, unsigned short, bool verbose = false);
  virtual const char* ShortName() const;
private:
  Limo(const Limo& v);
  Limo& operator= (const Limo v);
};

class Truck : public CommercialVehicle
{
public: 
  Truck();
  virtual ~Truck();
  Truck(const char*, const char*, const char*, bool verbose = false);
  virtual const char* ShortName() const;
private:
  Truck(const Truck& v);
  Truck& operator= (const Truck v);
};

class Van : public Truck, public Box
{
public:
  Van();
  virtual ~Van();
  Van(const char*, const char*, const char*, float, float, float, bool verbose = false);
  float LoadCapacity() const;
  virtual const char* ShortName() const;
private:
  Van(const Van& v);
  Van& operator= (const Van v);
};

class Tanker : public Truck, public Cylinder
{
public:
  Tanker();
  virtual ~Tanker();
  Tanker(const char*, const char*, const char*, float, float, bool verbose = false);
  float LoadCapacity() const;
  virtual const char * ShortName() const;
private:
  Tanker(const Tanker& v);
  Tanker& operator= (const Tanker v);
};

class Flatbed : public Truck, public Rectangle
{
public:
  Flatbed();
  virtual ~Flatbed();
  Flatbed(const char *, const char*, const char*, float, float, bool verbose = false);
  float LoadCapacity() const;
  virtual const char* ShortName() const;
private:
  Flatbed(const Flatbed& v);
  Flatbed& operator= (const Flatbed v);
};
#endif
