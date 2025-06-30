#include "testlevel.h"
#include "OutputSignal.h"
#include "ColorBox.h"
#include "InputSignal.h"
#include "LogicGate.h"
#include "LogicExceptions.h"
#include <algorithm>



OutputSignal::OutputSignal(const Point& Position,
                           bool InitialState)
:ColorBox(Position, Point(2,4), RGBColor(128,128,128)),
 LastState(InitialState)
{
}

OutputSignal::~OutputSignal()
{
    while(!FanOut.empty())
    {
        FanOut.back()->disconnectInput();
    }
}

void OutputSignal::sendState(bool NewState)
{
    for(auto peer : FanOut)
    {
        peer->setState(NewState);
    }
    LastState=NewState;
}

bool OutputSignal::getLastState() const
{
    return LastState;
}

void OutputSignal::connectToConsumer(LogicGate& Consumer, unsigned Port)
{
    FanOut.push_back(&Consumer.connectInput(*this, getLastState(), Port));
}

void OutputSignal::disconnectConsumer(InputSignal& Consumer)
{
    Consumer.disconnectInput();
    for(auto it = FanOut.begin(); it != FanOut.end(); ++it)
    {
        if(*it == &Consumer)
        {
            FanOut.erase(it);
            break;
        }
    }
}

void OutputSignal::show() const
{
    //draw all the wires
    Point My=getPosition();
    for (auto Peer : FanOut)
    {
        Point PeerPosition=Peer->getPosition();
        Point Mid((My + PeerPosition)/2);
        Line(My.X, My.Y, Mid.X, My.Y);
        Line(Mid.X, My.Y, Mid.X, PeerPosition.Y);
        Line(Mid.X, PeerPosition.Y,
             PeerPosition.X, PeerPosition.Y);
    }
    //draw connector
    ColorBox::show();
}



