#include "PLAYER.h"

PLAYER::PLAYER(){
      POSITION = {1,1};
        DIRECTION_TRACK = 2;
        FACING = FACING_STATUS[2];
        HAS_ARROW = true;
        STATUS = 0;
        HAS_GOLD = false;
}
    
    
    PLAYER::~PLAYER(){
        
    }
    
    
    
    vector<int> PLAYER:: Get_Position(){
        return POSITION;
    }
    
    string PLAYER:: Get_Facing(){
        return FACING;
    } 
    
    void PLAYER:: Turn_Right(){
        DIRECTION_TRACK = (4 + (DIRECTION_TRACK - 1 ) % 4) % 4;
        FACING = FACING_STATUS[DIRECTION_TRACK];
    }
    
    void PLAYER:: Turn_Left(){
        DIRECTION_TRACK = (4 + (DIRECTION_TRACK + 1) % 4) %4;
         FACING = FACING_STATUS[DIRECTION_TRACK];
    }
    
    vector<int> PLAYER:: Get_Next_Square(){
        int x = POSITION[0];
        int y = POSITION[1];
        if(DIRECTION_TRACK == 0)
        return {x, y-1};
        
        else if (DIRECTION_TRACK == 1)
        return {x+1,y};
        
        else if(DIRECTION_TRACK == 2)
        return {x,y+1};
        
        else
        return {x-1,y};
    }
    
    vector<int> PLAYER:: Get_NNext_Square(){
        int x = POSITION[0];
        int y = POSITION[1];
        if(DIRECTION_TRACK == 0)
        return {x, y-2};
        
        else if (DIRECTION_TRACK == 1)
        return {x+2,y};
        
        else if(DIRECTION_TRACK == 2)
        return {x,y+2};
        
        else
        return {x-2,y};
    }
    
    vector<int> PLAYER:: Get_NNNext_Square(){
        int x = POSITION[0];
        int y = POSITION[1];
        if(DIRECTION_TRACK == 0)
        return {x, y-3};
        
        else if (DIRECTION_TRACK == 1)
        return {x+3,y};
        
        else if(DIRECTION_TRACK == 2)
        return {x,y+3};
        
        else
        return {x-3,y};
    }
    
    void PLAYER:: Move_Forward(){
        POSITION = Get_Next_Square();
    }
    
    bool PLAYER:: Shoot_Arrow(CAVE &cave){
        vector<int> next = this-> Get_Next_Square();
        vector<int> nnext = this-> Get_NNext_Square();
        vector<int> nnnext = this-> Get_NNNext_Square();
        
        HAS_ARROW = false;
        bool KILLED = cave.Shoot_Square(next)||cave.Shoot_Square(nnext)||cave.Shoot_Square(nnnext);
        // bool a = cave.Kill_Wumpus(nnnext);
        // bool b = cave.Kill_Wumpus(nnext);
        // bool c = cave.Kill_Wumpus(next);

        return KILLED;
    }
    
    bool PLAYER:: Has_Arrow(){
        return HAS_ARROW;
    }
    
    bool PLAYER:: Pickup_Gold(CAVE &cave){
        if(cave.Square_Contains_Gold(POSITION)){
            cave.Remove_Gold(POSITION);
            HAS_GOLD = true;
        }
        
        return cave.Square_Contains_Gold(POSITION);
    }
    
    void PLAYER:: Climb_Ladder(){
        STATUS = 3;
    }
    
    bool PLAYER:: Update_Player_Status(CAVE cave){
        if(STATUS == 1 || STATUS == 2 )
        return false;
        if(cave.Square_Contains_Living_Wumpus(POSITION))
        STATUS = 1;
        if(cave.Square_Contains_Pit(POSITION))
        STATUS = 2;
        if(STATUS == 1 || STATUS == 2 )
        return false;
        
        return true;
    }
    
    bool PLAYER:: Escaped(){
        if(STATUS == 3)
        return true;
        return false;
    }
    
    bool PLAYER:: Eaten(){
        return STATUS == 1;
    }
    
    bool PLAYER:: Fell(){
        return STATUS == 2;
    }
    
    bool PLAYER:: Has_Gold(){
        return HAS_GOLD;
    }
    
