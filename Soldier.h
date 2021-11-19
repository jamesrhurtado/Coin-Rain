#pragma once
#include "Base.h"
class Soldier :
    public Base
{

public:
    Soldier();
    Soldier(int x, int y);
    void move(Graphics^ g, char i);
    ~Soldier(); 


};

