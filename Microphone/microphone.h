#ifndef MICROPHONE
#define MICROPHONE
#include "input_device.h"

class Microphone: public Input_Device{
private:
    std::string _type {"condenser"};
    int _max_frequency {8000};
    int _signal_noise_ratio {50};
    bool _is_mute {false};
public:
    Microphone();
    Microphone(const std::string&, int, int);
    void set_type(const std::string&);
    std::string get_type() const;
    void set_max_frequency(int);
    int get_max_frequency() const;
    void set_signal_noise_ratio(int);
    int get_signal_noise_ratio() const;
    std::string Mute();
    std::string Unmute();
    bool IsMuted() const;
    std::string ReadSound();
};

#endif