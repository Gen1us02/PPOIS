#include "microphone.h"
#include "../Exceptions/exceptions.h"
#include <format>

Microphone::Microphone() : InputDevice() {
    port_ = PortType::MicIn;
};

Microphone::Microphone(const std::string &type, int maxFrequency, int signalNoiseRatio) : type_(type),
    maxFrequency_(maxFrequency), signalNoiseRatio_(signalNoiseRatio) {
    port_ = PortType::MicIn;
}

void Microphone::SetType(const std::string &type) {
    this->type_ = type;
}

std::string Microphone::GetType() const {
    return this->type_;
}

void Microphone::SetMaxFrequency(int maxFrequency) {
    this->maxFrequency_ = maxFrequency;
}

int Microphone::GetMaxFrequency() const {
    return this->maxFrequency_;
}

void Microphone::SetSignalNoiseRatio(int signalNoiseRatio) {
    this->signalNoiseRatio_ = signalNoiseRatio;
}

int Microphone::GetSignalNoiseRatio() const {
    return this->signalNoiseRatio_;
}

std::string Microphone::Mute() {
    if (isMute_) return "Микрофон уже заглушен";
    isMute_ = true;
    return "Микрофон заглушен";
}

std::string Microphone::Unmute() {
    if (!isMute_) return "Микрофон уже работает";
    isMute_ = false;
    return "Микрофон работает";
}

bool Microphone::IsMuted() const {
    return isMute_;
}

std::string Microphone::ReadSound() {
    try {
        if (!IsConnected()) {
            throw ExceptionConnection("Microphone is not connected");
        }
        std::string sound = "Microphone read: " + type_
                            + " freq=" + std::to_string(maxFrequency_)
                            + " snr=" + std::to_string(signalNoiseRatio_);

        ReadInput(sound);
        return sound;
    } catch (const ExceptionConnection &ex) {
        return ex.what();
    }
}
