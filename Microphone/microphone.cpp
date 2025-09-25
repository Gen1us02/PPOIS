#include "microphone.h"
#include <format>

Microphone::Microphone() = default;

Microphone::Microphone(const std::string& type, int maxFrequency, int signalNoiseRatio):
type_(type), maxFrequency_(maxFrequency), signalNoiseRatio_(signalNoiseRatio) {}

void Microphone::SetType(const std::string& type){
    this->type_ = type;
}

std::string Microphone::GetType() const{
    return this->type_;
}

void Microphone::SetMaxFrequency(int maxFrequency){
    this->maxFrequency_ = maxFrequency;
}

int Microphone::GetMaxFrequency() const{
    return this->maxFrequency_;
}

void Microphone::SetSignalNoiseRatio(int signalNoiseRatio){
    this->signalNoiseRatio_ = signalNoiseRatio;
}

int Microphone::GetSignalNoiseRatio() const{
    return this->signalNoiseRatio_;
}

std::string Microphone::Mute() {
    if (isMute_) return;
    isMute_ = true;
    return "Микрофон заглушен\n";
}

std::string Microphone::Unmute() {
    if (!isMute_) return;
    isMute_ = false;
    return "Микрофон работает";
}

bool Microphone::IsMuted() const {
    return isMute_;
}

std::string Microphone::ReadSound(){
    if (!IsConnected()) {
        return "Микрофон не подключен";
        return;
    }
    std::string sound = "Microphone read: " + type_ 
        + "freq=" + std::to_string(maxFrequency_) 
        + "snr=" + std::to_string(signalNoiseRatio_);

    ReadInput(sound);
    return sound;
}