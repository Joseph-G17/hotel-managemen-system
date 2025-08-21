#ifndef SUITEROOM_H //reserved for 4th floor
#define SUITEROOM_H
#include "room.h"
#include <iostream>

using namespace std;

class suiteroom : public room //inheritance
{
    private: 
        char roomService;
        char poolAccess;
        
    public:
        suiteroom()
        {
            roomNum = 0;
            price = 0.0;
            availability = true;
            roomService = '\0';
            poolAccess = '\0';
        }
        suiteroom(int _roomNum, double _price, bool _availability, char _roomService, char _poolAccess) : room(_roomNum, _price, _availability)
        {
            roomService = _roomService;
            poolAccess = _poolAccess;
        }
        virtual string getType() const
        {
            return "Suite-room";
        };
        virtual ~suiteroom() {};
        virtual void roomPrint()
        {
            room::roomPrint();
            cout << "Room type: Suite room" << endl;
            cout << "Pool access: " << to_string(poolAccess) << endl;
            cout << "Requires room service: " << to_string(roomService) << endl;

        }
        void setGuestPool(char _poolAccess)
        {
            poolAccess = _poolAccess;
        } 
        char getGuestPool() {return poolAccess;}    
        void setGuestService(char _roomService)
        {
            roomService = _roomService;
        } 
        char getGuestService() {return roomService;}   
        virtual void printAvailableRooms()
        {
            for(int i=0; i < 11;i++)
            {
                
                cout << fourthFloor[i] << " ";
                cout << endl;
            }
            cout << endl;
        } 
};

#endif 