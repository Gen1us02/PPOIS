#include "speakers.h"
#include "../Exceptions/exceptions.h"

Speakers::Speakers() {
    port_ = PortType::LineOut;
};

Speakers::Speakers(int dynamicCount, int power, double weight, int maxRate) : dynamicCount_(dynamicCount),
                                                                              power_(power), weight_(weight),
                                                                              maxRate_(maxRate) {
    port_ = PortType::LineOut;
}

void Speakers::SetDynamicCount(int dynamicCount) {
    this->dynamicCount_ = dynamicCount;
}

int Speakers::GetDynamicCount() const {
    return this->dynamicCount_;
}

void Speakers::SetPower(int power) {
    this->power_ = power;
}

int Speakers::GetPower() const {
    return this->power_;
}

void Speakers::SetWeight(double weight) {
    this->weight_ = weight;
}

double Speakers::GetWeight() const {
    return this->weight_;
}

void Speakers::SetMaxRate(int maxRate) {
    this->maxRate_ = maxRate;
}

int Speakers::GetMaxRate() const {
    return this->maxRate_;
}

std::string Speakers::DisplayInput(const InputDevice &microphone) const {
    if (!(typeid(microphone) == typeid(Microphone))) {
        throw ExceptionIncorrectInstance("Device isn't microphone");
    }
    return "User volume:\n" + microphone.GetInput();
}

std::string Speakers::ChangeVolume(int volumeValue) const {
    if (volumeValue > 100 || volumeValue < 0) {
        throw ExceptionIncorrectVolume("Incorrect volume value");
    }
    return "Volume change on " + std::to_string(volumeValue);
}
