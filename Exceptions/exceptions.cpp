#include "exceptions.h"

Exception::Exception(const char *message) : message_(message) {
}

const char *Exception::what() const noexcept {
    return message_.c_str();
}

ExceptionConnection::ExceptionConnection(const char *message) : Exception(message) {
}

ExceptionIncorrectCoolerCount::ExceptionIncorrectCoolerCount(const char *message) : Exception(message) {
}

ExceptionIncorrectDLLSMode::ExceptionIncorrectDLLSMode(const char *message) : Exception(message) {
}

ExceptionIncorrectInstance::ExceptionIncorrectInstance(const char *message) : Exception(message) {
}

ExceptionIncorrectSpeed::ExceptionIncorrectSpeed(const char *message) : Exception(message) {
}

ExceptionIncorrectVoltage::ExceptionIncorrectVoltage(const char *message) : Exception(message) {
}

ExceptionIncorrectVolume::ExceptionIncorrectVolume(const char *message) : Exception(message) {
}

ExceptionIsOccupiedError::ExceptionIsOccupiedError(const char *message) : Exception(message) {
}

ExceptionManyKeysPressed::ExceptionManyKeysPressed(const char *message) : Exception(message) {
}

ExceptionNotIsOccupiedError::ExceptionNotIsOccupiedError(const char *message) : Exception(message) {
}

ExceptionRAMStatusError::ExceptionRAMStatusError(const char *message) : Exception(message) {
}
