//
// Created by Pierre Roy on 02/12/17.
//

#ifndef EVENTHANDLER_DELEGATE_HPP
#define EVENTHANDLER_DELEGATE_HPP

#define LISTENER(thisType, handler, type)\
    class __L##handler##__ : public System::Delegate< type >\
    {\
        public:\
            __L##handler##__ ( thisType * obj )\
            : _obj(obj) {}\
            inline void operator()( type param )\
            {\
                _obj-> handler (param);\
            }\
            thisType * _obj;\
    };\
    __L##handler##__ L##handler;

namespace System
{

    template <typename T>
    class Delegate {
    public:
        virtual void operator()(T param) = 0;
    };

}

#endif //EVENTHANDLER_DELEGATE_HPP
