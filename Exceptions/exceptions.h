#ifndef EXCEPTIONS
#define EXCEPTIONS
#include "string"
#include <exception>

class Exception : public std::exception{
public:
    explicit Exception(const char*);
    const char* what() const noexcept override;
private:
    std::string message_;
};

class ExceptionIncorrectInstance : public Exception{
public:
    explicit ExceptionIncorrectInstance(const char*);
};

class ExceptionIncorrectSpeed : public Exception{
public:
    explicit ExceptionIncorrectSpeed(const char*);
};

class ExceptionConnection : public Exception{
public:
    explicit ExceptionConnection(const char*);
};

class ExceptionManyKeysPressed : public Exception{
public:
    explicit ExceptionManyKeysPressed(const char*);
};

class ExceptionRAMStatusError : public Exception{
public:
    explicit ExceptionRAMStatusError(const char*);
};

class ExceptionIncorrectVoltage : public Exception{
public:
    explicit ExceptionIncorrectVoltage(const char*);
};

class ExceptionIncorrectDLLSMode : public Exception{
public:
    explicit ExceptionIncorrectDLLSMode(const char*);
};

class ExceptionIncorrectCoolerCount : public Exception{
public:
    explicit ExceptionIncorrectCoolerCount(const char*);
};

class ExceptionIncorrectVolume : public Exception{
public: 
    explicit ExceptionIncorrectVolume(const char*);
};

class ExceptionIsOccupiedError : public Exception{
public:
    explicit ExceptionIsOccupiedError(const char*);
};

class ExceptionNotIsOccupiedError : public Exception{
public:
    explicit ExceptionNotIsOccupiedError(const char*);
};

#endif