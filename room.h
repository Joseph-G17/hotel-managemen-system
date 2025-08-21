#ifndef ROOM_H
#define ROOM_H
#include <string>

using namespace std;

int firstFloor[11] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
int secondFloor[11] = {200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210};
int thirdFloor[11] = {300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310};
int fourthFloor[11] = {400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410};

class room
{
    protected:
        int roomNum;
        double price;
        bool availability;

    public: 
        room()
        {
            roomNum = 0;
            price = 0.0;
            availability = true;
        }
        room(int _roomNum, double _price, bool _availability) {roomNum = _roomNum; price = _price; availability = _availability;}
        int getRoomNum() {return roomNum;}
        double getPrice() {return price;}
        bool getAvailability() {return availability;}
        void setRoomNum(int _roomNum) {roomNum = _roomNum;}
        void setPrice(double _price) {price = _price;}
        void setAvailability(bool _availability) {availability = _availability;}
        virtual string getType() const = 0;
        virtual void roomPrint() const
        {
            cout << "Guest Room Number: " << to_string(roomNum) << endl;
            cout << "Guest Price Payment: " << to_string(price) << endl;
            cout << "Guest Room Availability: ";
            if(availability != true)
            {
                cout << "Room is reserved";
            }
        }
        bool setRoomAvailability(int roomNum)
        {
            if(roomNum < 200)
            {
                for(int i =0; i < 11; i++)
                {
                    if(firstFloor[i] == roomNum)
                    {
                        return false; 
                    } 
                }
            }
            if(roomNum < 300)
            {
                for(int i =0; i < 11; i++)
                {
                    if(secondFloor[i] == roomNum)
                    {
                        return false; 
                    }
                }
            }
            if(roomNum < 400)
            {
                for(int i =0; i < 11; i++)
                {
                    if(thirdFloor[i] == roomNum)
                    {
                        return false;
                    } 
                }
            }
            if(roomNum < 500)
            {
                for(int i =0; i < 11; i++)
                {
                    if(fourthFloor[i] == roomNum)
                    {
                        return false;
                    } 
                }
            }

            return true;
        }
        virtual void printAvailableRooms()
        {
            for(int i=0; i < 11;i++)
            {
                cout << firstFloor[i] << " ";
                cout << secondFloor[i] << " ";
                cout << thirdFloor[i] << " ";
                cout << fourthFloor[i] << " ";
                cout << endl;
            }
            cout << endl;
        }
        

};      
#endif 