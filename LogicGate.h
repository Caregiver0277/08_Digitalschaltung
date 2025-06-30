#ifndef LOGICGATE_H
#define LOGICGATE_H

#include <string>
using std::string;
#include <vector>
using std::vector;
#include "ColorBox.h"
#include "TextBox.h"
#include "WinAdapt.h"
#include "OutputSignal.h"
#include "InputSignal.h"
#include "testlevel.h"

class InputSignal;

class LogicGate :public TextBox
{
    public:
        LogicGate(const string & Operation,
                     const Point& Position,
                     const string& ID,
                     unsigned NumInputs=2);
        virtual ~LogicGate();
        bool operator==(const string& ID);
        const string& getID() const;
        virtual void setPosition(const Point& Position);
        virtual void setSize(const Point& Size);
        virtual void show() const;
        virtual void updateOutput(){};
        virtual bool getOutput(unsigned Port=0) const;
        unsigned getNumOutputs() const;
        unsigned getNumInputs() const ;
        void connectOutput(LogicGate& Peer, unsigned Port=0);
        InputSignal& connectInput(OutputSignal& From, bool CurrentState, unsigned Port=0);

        LogicGate(const LogicGate& orig)=delete;
        LogicGate& operator=(const LogicGate& rhs)=delete;

    protected:
        virtual void decorate() const;
        void setOutput(bool NewState, unsigned Port=0);
        vector<InputSignal> Input;

    private:
        OutputSignal Output;
        ColorBox Indicator;
        string ID;
        void updateIndicator();
        void positionElements();
};


#endif
