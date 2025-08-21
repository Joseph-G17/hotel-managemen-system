#ifndef DELUXEROOM_H
#define DELUXEROOM_H
#include "room.h"
#include <iostream>

using namespace std;

class deluxeroom : public room //inheritance
{
    private: 
        char poolAccess;

    public:
        deluxeroom()
        {
            roomNum = 0;
            price = 0.0;
            availability = true;
            poolAccess = '\0';
        }
        deluxeroom(int _roomNum, double _price, bool _availability, char _poolAccess) :room(_roomNum, _price, _availability)
        {
            poolAccess = _poolAccess;
        }
        virtual string getType() const
        {
            return "Deluxe-room";
        };
        virtual ~deluxeroom() {};
        virtual void roomPrint()
        {
            room::roomPrint();
            cout << "Room type: Deluxe room" << endl;
            cout << "Pool Access: " << to_string(poolAccess) << endl;

        }
        void setGuestPool(char _poolAccess)
        {
            poolAccess = _poolAccess;
        } 
        char getGuestPool() {return poolAccess;}
        virtual void printAvailableRooms()
        {
            for(int i=0; i < 11;i++)
            {
                
                cout << thirdFloor[i] << " ";
               
                cout << endl;
            }
            cout << endl;
        }

};

#endif 