#include "testlevel.h"
#include "SimpleGates.h"

#if TEST_LEVEL >= TEST_SIMPLEGATES

// NOT fertig
LogicGateNOT::LogicGateNOT(const Point& Position, const string& ID, unsigned NumInputs)
    :LogicGate("NOT", Position, ID, NumInputs)
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
LogicGateAND::LogicGateAND(const Point& Position, const string& ID, unsigned NumInputs)
    :LogicGate("AND", Position, ID, NumInputs)
{}

void LogicGateAND::updateOutput()
{
    bool result = true;
    for(auto& i : Input)
    {
        if(!i.getState())
            {
                result=false;
                break;
            }
    }
    setOutput(result);
}



// OR
LogicGateOR::LogicGateOR(const Point& Position, const string& ID, unsigned NumInputs)
    :LogicGate("OR", Position, ID, NumInputs)
{}

void LogicGateOR::updateOutput()
{
    bool result = false;
    for(auto& in : Input)
        result = result || in.getState();
    setOutput(result);
}



// XOR
LogicGateXOR::LogicGateXOR(const Point& Position, const string& ID, unsigned NumInputs)
    :LogicGate("XOR", Position, ID, NumInputs)
{}

void LogicGateXOR::updateOutput()
{
    bool result = false;
    for(auto& in : Input)
        result ^= in.getState();
    setOutput(result);
}

void LogicGateXOR::decorate() const
{
    LogicGate::decorate();
    FillCol(0,0,0);
    Point LO(getPosition()+getSize().scaleXY(1.0,.5)+Point(-8,-3));
    Point RU(getPosition()+getSize().scaleXY(1.0,.5)+Point(0,3));
    Rect(LO.X+5, LO.Y-32, RU.X+3, RU.Y+32);
}




// NAND
LogicGateNAND::LogicGateNAND(const Point& Position, const string& ID, unsigned NumInputs)
    :LogicGate("NAND", Position, ID, NumInputs)
{}

void LogicGateNAND::updateOutput()
{
    bool result = true;
    for(auto& in : Input)
        result = result && in.getState();
    setOutput(!result);
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
