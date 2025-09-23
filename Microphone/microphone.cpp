#include "microphone.h"
#include <format>

Microphone::Microphone() = default;

Microphone::Microphone(const std::string& type, int max_frequency, int signal_noise_ratio):
_type(type), _max_frequency(max_frequency), _signal_noise_ratio(signal_noise_ratio) {}

void Microphone::set_type(const std::string& type){
    this->_type = type;
}

std::string Microphone::get_type() const{
    return this->_type;
}

void Microphone::set_max_frequency(int max_frequency){
    this->_max_frequency = max_frequency;
}

int Microphone::get_max_frequency() const{
    return this->_max_frequency;
}

void Microphone::set_signal_noise_ratio(int signal_noise_ratio){
    this->_signal_noise_ratio = signal_noise_ratio;
}

int Microphone::get_signal_noise_ratio() const{
    return this->_signal_noise_ratio;
}

std::string Microphone::Mute() {
    if (_is_mute) return;
    _is_mute = true;
    return "Микрофон заглушен\n";
}

std::string Microphone::Unmute() {
    if (!_is_mute) return;
    _is_mute = false;
    return "Микрофон работает";
}

bool Microphone::IsMuted() const {
    return _is_mute;
}

std::string Microphone::ReadSound(){
    if (!IsConnected()) {
        return "Микрофон не подключен";
        return;
    }
    std::string sound = "Microphone read: " + _type 
        + "freq=" + std::to_string(_max_frequency) 
        + "snr=" + std::to_string(_signal_noise_ratio);

    readInput(sound);
    return sound;
}