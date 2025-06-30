#include "testlevel.h"
#include <vector>
using std::vector;
#include "LogicGate.h"
#include "RGBColor.h"
#include "InputSignal.h"
#include "LogicExceptions.h"
#if TEST_LEVEL > TEST_START


LogicGate::LogicGate(const string & Operation,
                     const Point& Position,
                     const string& ID,
                     unsigned NumInputs)
:TextBox(Position, Point(100,70), Operation),
 Input(NumInputs, InputSignal(*this, Point(0,0), false)),
 Output(Position+getSize().scaleY(.5), false),
 Indicator(getPosition()+getSize()-Point(15,15), Point(10,10),RGBColor(255,0,0)),
 ID(ID)
{
    positionElements();
}

LogicGate::~LogicGate()
{
}

bool LogicGate::operator==(const string& ID)
{
      return LogicGate::ID==ID;
}

unsigned LogicGate::getNumInputs() const
{
    return Input.size();
}

unsigned LogicGate::getNumOutputs() const
{
    return 1;
}

const string& LogicGate::getID() const
{
    return ID;
}

void LogicGate::show() const
{
    Output.show();
    for(const auto& in : Input)
        in.show();

    TextBox::show();
    ::Text(getPosition().X+5, getPosition().Y+50, ID.c_str());
    decorate();

}

void LogicGate::updateIndicator()
{
    if (Output.getLastState() == false) Indicator.setColor(RGBColor(255,0,0));
    if (Output.getLastState() == true) Indicator.setColor(RGBColor(0,128,0));
}

bool LogicGate::getOutput(unsigned Index) const
{
    return Output.getLastState();
}

void LogicGate::setOutput(bool NewState, unsigned Port)
{
    Output.sendState(NewState);
    updateIndicator();
}


InputSignal& LogicGate::connectInput(OutputSignal& From, bool CurrentState, unsigned Index)
{
    if (Index >= getNumInputs()) throw ExceptionIllegalInputChannel();

    return Input[Index].connect(From, CurrentState);
}

void LogicGate::connectOutput(LogicGate& Peer, unsigned Index)
{
    Output.connectToConsumer(Peer, Index);
}

void LogicGate::decorate() const
{
    Indicator.show();
}

void LogicGate::setPosition(const Point& Position)
{
    Output.setPosition(Position);
    Indicator.setPosition(Position);
    for (unsigned int i=0; i<=getNumInputs(); i++)
    {
        Input[i].setPosition(Position);
    }

    positionElements();
}

void LogicGate::setSize(const Point& Size)
{
    TextBox::setSize(Size);
    positionElements();
}

void LogicGate::positionElements()
{
    Indicator.setPosition(getPosition()+getSize()-Point(15,15));

    Point outPos(getPosition().X + getSize().X,
                 getPosition().Y + getSize().Y/2 - Output.getSize().Y/2);
    Output.setPosition(outPos);


    double step=getSize().Y/(Input.size()+1);
    for(size_t i=0;i<Input.size();++i)
    {
        Point pos(getPosition().X - Input[i].getSize().X,
                   getPosition().Y + step*(i+1) - Input[i].getSize().Y/2);
        Input[i].setPosition(pos);
    }
}

#endif
