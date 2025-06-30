#include "testlevel.h"
#include "SimpleGates.h"

#if TEST_LEVEL >= TEST_SIMPLEGATES

// NOT fertig
LogicGateNOT::LogicGateNOT(const Point& Position, const string& ID)
:LogicGate("NOT", Position, ID, 1)
{}

void LogicGateNOT::updateOutput()
{
    setOutput(!Input[0].getState());
}

void LogicGateNOT::decorate() const
{
    LogicGate::decorate();
    FillCol(0,0,0);
    Point LO(getPosition()+getSize().scaleXY(1.0,.5)+Point(0,-4));
    Point RU(getPosition()+getSize().scaleXY(1.0,.5)+Point(8,4));
    Elli(LO.X, LO.Y, RU.X, RU.Y);
}



// AND
LogicGateAND::LogicGateAND(const Point& Position,const string& ID)
:LogicGate("AND", Position, ID, 1)
{}

void LogicGateAND::updateOutput()
{
    setOutput(!Input[0].getState());
}

void LogicGateAND::decorate() const
{
    LogicGate::decorate();
    FillCol(0,0,0);
    Point LO(getPosition()+getSize().scaleXY(1.0,.5)+Point(0,-4));
    Point RU(getPosition()+getSize().scaleXY(1.0,.5)+Point(8,4));
    Elli(LO.X, LO.Y, RU.X, RU.Y);
}



// OR
LogicGateOR::LogicGateOR(const Point& Position, const string& ID)
:LogicGate("OR", Position, ID, 1)
{}

void LogicGateOR::updateOutput()
{
    setOutput(!Input[0].getState());
}

void LogicGateOR::decorate() const
{
    LogicGate::decorate();
    FillCol(0,0,0);
    Point LO(getPosition()+getSize().scaleXY(1.0,.5)+Point(0,-4));
    Point RU(getPosition()+getSize().scaleXY(1.0,.5)+Point(8,4));
    Elli(LO.X, LO.Y, RU.X, RU.Y);
}



// XOR
LogicGateXOR::LogicGateXOR(const Point& Position,const string& ID)
:LogicGate("XOR", Position, ID, 1)
{}

void LogicGateXOR::updateOutput()
{
    setOutput(!Input[0].getState());
}

void LogicGateXOR::decorate() const
{
    LogicGate::decorate();
    FillCol(0,0,0);
    Point LO(getPosition()+getSize().scaleXY(1.0,.5)+Point(0,-4));
    Point RU(getPosition()+getSize().scaleXY(1.0,.5)+Point(8,4));
    Elli(LO.X, LO.Y, RU.X, RU.Y);
}




// NAND
LogicGateNAND::LogicGateNAND(const Point& Position,const string& ID)
:LogicGate("NAND", Position, ID, 1)
{}

void LogicGateNAND::updateOutput()
{
    setOutput(!Input[0].getState());
}

void LogicGateNAND::decorate() const
{
    LogicGate::decorate();
    FillCol(0,0,0);
    Point LO(getPosition()+getSize().scaleXY(1.0,.5)+Point(0,-4));
    Point RU(getPosition()+getSize().scaleXY(1.0,.5)+Point(8,4));
    Elli(LO.X, LO.Y, RU.X, RU.Y);
}






#endif
