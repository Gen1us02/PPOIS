#include <microphone.h>


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

void Microphone::Connect(){
    this->_is_connected = true;
}

void Microphone::Disconnect(){
    this->_is_connected = false;
}

bool Microphone::IsConnected() const{
    return this->_is_connected;
}

void Microphone::Mute() {
    if (_is_mute) return;
    _is_mute = true;
    std::cout << "Микрофон заглушен\n";
}

void Microphone::Unmute() {
    if (!_is_mute) return;
    _is_mute = false;
    std::cout << "Микрофон работает\n";
}

bool Microphone::IsMuted() const {
    return _is_mute;
}

void Microphone::ReadSound(){
    if (!IsConnected()) {
        std::cout << "Microphone not connected\n";
        return;
    }
    std::cout << "Microphone read: type=" << _type
              << ", max_freq=" << _max_frequency
              << ", snr=" << _signal_noise_ratio << "\n";
}