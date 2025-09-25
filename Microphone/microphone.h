#ifndef MICROPHONE
#define MICROPHONE
#include "input_device.h"

class Microphone: public InputDevice{
public:
    Microphone();
    Microphone(const std::string&, int, int);
    void SetType(const std::string&);
    std::string GetType() const;
    void SetMaxFrequency(int);
    int GetMaxFrequency() const;
    void SetSignalNoiseRatio(int);
    int GetSignalNoiseRatio() const;
    std::string Mute();
    std::string Unmute();
    bool IsMuted() const;
    std::string ReadSound();
private:
    std::string type_ {""};
    int maxFrequency_ {8000};
    int signalNoiseRatio_ {50};
    bool isMute_ {false};
};

#endif