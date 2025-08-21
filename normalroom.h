#ifndef NORMALROOM_H //reserved for 1st and 2nd floor
#define NORMALROOM_H
#include "room.h"
#include <iostream>
using namespace std;



class normalroom : public room //inheritance
{
    private: 
        
    public:
        normalroom()
        {
            roomNum = 0;
            price = 0.0;
            availability = true;
        }
        normalroom(int _roomNum, double _price, bool _availability) :room(_roomNum, _price, _availability)
        {}
        virtual string getType() const
        {
            return "Normal-room";
        };
        virtual ~normalroom() {};
        virtual void roomPrint() 
        {
            room::roomPrint();
            cout << "Roomtype: Normal room";
            
        }
        virtual void printAvailableRooms()
        {
            for(int i=0; i < 11;i++)
            {
                cout << firstFloor[i] << " ";
                cout << secondFloor[i] << " ";
                cout << endl;
            }
            cout << endl;
        }
};

#endif 