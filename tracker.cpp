// Nikolas Lennon
// tracker.cpp
#include <vehicles.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

void displayOutput(CommercialVehicle *); //prototype the function

const unsigned int 
  C1 = 6,    // short name
  C2 = 10,   // pass cap
  C3 = 10,   // load cap
  c4 = 2,    // variable C4 = max Operator ID length + c4
  c5 = 2,    // variable C5 = max Operator CDL length + c5
  c6 = 2,    // variable C6 = max Vehicle Registration Number length + c6
  maxShiftSize = 100, 
  maxStringSize = 50;

// bad message strings
const char* const badRegMsg = "BadRegistration";
const char* const badIDMsg  = "BadOperatorID";
const char* const badCDLMsg = "BadOperatorCDL";

//const size_t maxShiftSize = 100;
const int maxReg = 50;
const int maxID = 50;
const int maxCDL = 50;
char sn[1 + maxReg];
char id[1 + maxID];
char cdl[1 + maxCDL];

size_t shiftSize;

unsigned int
C4,
C5,
C6;

int main()
{

  CommercialVehicle *shift[maxShiftSize];
  VehicleType v;

  std::cout << "\nFastLane Tracker started... " << std::endl;

  int shiftCount = 1;

  do {
  
    unsigned int pc;

  float length;
  float width;
  float height;
  float radius; 
  
  int badRegTotal = 0;
  int commercialvehicleTotal = 0;
  int carriageTotal = 0;
  int limoTotal = 0;
  int busTotal = 0;
  int truckTotal = 0;
  int vanTotal = 0;
  int tankerTotal = 0;
  int flatbedTotal = 0;
  int passengerTotal = 0;
  float freightCap = 0.00;

  std::cin >> shiftSize;
  
  if(shiftSize == 0)
    break;
  
  if(shiftSize > maxShiftSize)
  {
    std::cerr << "** Tracker error: max shift size exceeded\n";
    break; 
  }
  
     for (size_t i = 0; i < shiftSize; ++i)
    {
      std::cin >> std::setw(maxReg) >> sn;
      v = CommercialVehicle::RegDecode(sn);

      switch(v)
      {
        case badReg:
          ++badRegTotal;
          shift[i] = new CommercialVehicle(badRegMsg, badIDMsg, badCDLMsg, 0, 0);
          break;
        case vehicle:
          ++commercialvehicleTotal;
          std::cin >> std::setw(maxID) >> id >> std::setw(maxCDL) >> cdl;
          shift[i] = new CommercialVehicle(sn, id, cdl, 0, 0);
          break;
        case truck:
          ++truckTotal;
          std::cin >> std::setw(maxID) >> id >> std::setw(maxCDL) >> cdl;
          shift[i] = new Truck(sn, id, cdl, 0);
          break;
        case carriage:
          ++carriageTotal;
          std::cin >> std::setw(maxID) >> id >> std::setw(maxCDL) >> cdl >> pc;
          shift[i] = new Carriage(sn, id, cdl, pc, 0);
          break;
        case bus:
          ++busTotal;
          std::cin >> std::setw(maxID) >> id >> std::setw(maxCDL) >> cdl >> pc;
          shift[i] = new Bus(sn, id, cdl, pc, 0);
          break;
        case limo:
          ++limoTotal;
          std::cin >> std::setw(maxID) >> id >> std::setw(maxCDL) >> cdl >> pc;
          shift[i] = new Limo(sn, id, cdl, pc, 0);
          break;
        case van:
          ++vanTotal;
          std::cin >> std::setw(maxID) >> id >> std::setw(maxCDL) >> cdl >> width >> length >> height;
          shift[i] = new Van(sn, id, cdl, width, length, height, 0);
          break;
        case tanker:
          ++tankerTotal;
          std::cin >> std::setw(maxID) >> id >> std::setw(maxCDL) >> cdl >> radius >> length;
          shift[i] = new Tanker(sn, id, cdl, radius, length, 0);
          break;
        case flatbed:
          ++flatbedTotal;
          std::cin >> std::setw(maxID) >> id >> std::setw(maxCDL) >> cdl >> width >> length;
          shift[i] = new Flatbed(sn, id, cdl, width, length, 0);
          break;
        default: 
          std::cout << "** Tracker error: unable to read shift size\n";
          break; 
      } // end switch
      
      if (shift[i] == 0)
      {
        std::cout << "Memory allocation issue.";
        break;
      } //end if
      
      passengerTotal += shift[i]->PassengerCapacity();
      freightCap += shift[i]->LoadCapacity();
    
    } // end for
     
  for(C4 = 0; id[C4] != '\0'; C4++);
  C4 += c4;

  for(C5 = 0; cdl[C5] != '\0'; C5++);
  C5 += c5;  

  for(C6 = 0; sn[C6] != '\0'; C6++);
  C6 += c6;

  /*
     std::cout << " Shift " << shiftCount << " Log\n"
               << " ===============\n";
     std::cout << '\n'
               << std::setw(C1) << "Type"
               << std::setw(C2) << "Pass Cap"
               << std::setw(C3) << "Load Cap"
               << std::left << "  "
               << std::setw(C4) << "Registration"
               << std::setw(C5) << "Operator ID"
               << std::setw(C6) << "Operator CDL"
               << std::right
               << '\n';

     std::cout 
       << std::setw(C1) << "----"
       << std::setw(C2) << "--------"
       << std::setw(C3) << "--------"
       << std::left << "  "
       << std::setw(C4) << "------------"
       << std::setw(C5) << "-----------"
       << std::setw(C6) << "------------"
       << std::right
       << '\n';
  */     
     
     std::cout << " Shift " << shiftCount << " Summary\n===============\n";
     std::cout << "\n Carriages: " << std::right << carriageTotal;
     std::cout << "\n Buses: " << std::right << busTotal;
     std::cout << "\n Limos: " << std::right << limoTotal;
     std::cout << "\n Trucks: " << std::right << truckTotal;
     std::cout << "\n Vans: " << std::right << vanTotal;
     std::cout << "\n Tankers: " << std::right  << tankerTotal;
     std::cout << "\n Flatbeds: " << std::right  << flatbedTotal;
     std::cout << "\n Unknowns: " << std::right << commercialvehicleTotal;
     std::cout << "\n Badregs: " << std::right << badRegTotal;
     std::cout << std::setprecision(2) << std::fixed;
     std::cout << "\n Total Passenger Cap: " << passengerTotal;
     std::cout << "\n Total Freight Cap: " << freightCap;
     std::cout << "\n\nShift " << shiftCount << " Log\n============\n\n";
     std::cout 
       << std::setw(C1) << "Type"
       << std::setw(C2) << "Pass Cap"
       << std::setw(C3) << "Load Cap"
       << std::left << "  " 
       << std::setw(C4) << "Registration"
       << std::setw(C5) << "Operator ID"
       << std::setw(C6) << "Operator CDL" 
       << std::right
       << '\n';
     std::cout 
       << std::setw(C1) << "----" 
       << std::setw(C2) << "--------" 
       << std::setw(C3) << "--------" 
       << std::left << "  "
       << std::setw(C4) << "------------" 
       << std::setw(C5) << "-----------" 
       << std::setw(C6) << "------------" 
       << std::right 
       << '\n';
     

    for (size_t i = 0; i < shiftSize; ++i) //shift spreadsheet
    {
      displayOutput(shift[i]);
      delete shift[i];
    } //end for

    shiftCount++;

  } while (shiftSize > 0); // end do while

  std::cout << "\n\n...Thank you for using FastLane Tracker.\n\n";
 
} //end main

void displayOutput(CommercialVehicle *v)
{

  for(C4 = 0; id[C4] != '\0'; C4++);
  C4 += c4;

  for(C5 = 0; cdl[C5] != '\0'; C5++);
  C5 += c5;

  for(C6 = 0; sn[C6] != '\0'; C6++);
  C6 += c6;

  

  std::cout << std::setw(0) << std::setprecision(2) << std::fixed << std::showpoint 
<< std::setw(C1) << v->ShortName() 
<< std::setw(C2) << v->PassengerCapacity() 
<< std::setw(C3) << v->LoadCapacity() 
<< std::setw(C4) << v->Registration() 
<< std::setw(C5) << v->Operator() 
<< std::setw(C6) << v->CDL() << std::endl;

}
