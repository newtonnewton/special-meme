#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <time.h>
#include "CAVE.h"
using namespace std;

class PLAYER{
    public:
    vector<int> POSITION;
    string FACING_STATUS [4] = {
        "LEFT" , "DOWN" , "RIGHT", "UP"
    };
    string FACING;
    int DIRECTION_TRACK;
    bool HAS_ARROW;
    string PLAYER_STATUS [4] = {
        "alive", "eaten by the wumpus", "fallen into a pit", "escaped"
    };
    int STATUS;
    bool HAS_GOLD;
    
    PLAYER();
    ~PLAYER();
    
    vector<int> Get_Position();
    string Get_Facing();
    void Turn_Right();
    void Turn_Left();
    vector<int> Get_Next_Square();
    
    
    vector<int> Get_NNext_Square();
    vector<int> Get_NNNext_Square();
    
    void Move_Forward();
    bool Shoot_Arrow(CAVE &cave);
    bool Has_Arrow();
    bool Pickup_Gold(CAVE &cave);
    void Climb_Ladder();
    bool Update_Player_Status(CAVE cave);
    bool Escaped();
    bool Eaten();
    bool Fell();
    bool Has_Gold();
    
    
};

#endif