#include "testlevel.h"
#include "InputSignal.h"
#include "LogicGate.h"
#include "LogicExceptions.h"
#if TEST_LEVEL > TEST_START


InputSignal::InputSignal(LogicGate& LocalGate,
                         const Point& Position,
                         bool InitialState)
:ColorBox(Position, Point(4,2), RGBColor(128,128,128)),
 LocalGate(LocalGate),
 RemoteOutput(nullptr),
 State(InitialState),
 Connected(false)
{
}

InputSignal::~InputSignal()
{
    disconnectInput();
}

void InputSignal::setState(bool NewState)
{
    State = NewState;
    LocalGate.updateOutput();
}

bool InputSignal::getState() const
{
    return State;
}


bool InputSignal::isConnected() const
{
    return Connected;
}

void InputSignal::disconnectInput()
{
    if(!Connected)
        return;
    Connected = false;
    OutputSignal* Remote = RemoteOutput;
    RemoteOutput = nullptr;
    if(Remote != nullptr)
        Remote->disconnectConsumer(*this);
}

InputSignal& InputSignal::connect(OutputSignal& From, bool InitialState)
{
    if (isConnected()== true) throw ExceptionInputConnected();

    RemoteOutput = &From;
    Connected = true;
    setState(InitialState);
    LocalGate.updateOutput();
    return *this;
}

#endif
