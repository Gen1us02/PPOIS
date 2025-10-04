#include "gpu.h"
#include "../Exceptions/exceptions.h"

GPU::GPU() = default;

GPU::GPU(int minSpeed, int maxSpeed, bool rtxSupport, int videoMemory, int coolerCount):
rtxSupport_(rtxSupport),
videoMemory_(videoMemory),
coolerCount_(coolerCount),
coolers_(coolerCount, GPUCooler(minSpeed, maxSpeed)){}

void GPU::SetRtxSupport(bool rtxSupport){
    this->rtxSupport_ = rtxSupport;
}

bool GPU::GetRtxSupport() const{
    return this->rtxSupport_;
}

void GPU::SetVideoMemory(int videoMemory){
    this->videoMemory_ = videoMemory;
}

int GPU::GetVideoMemory() const{
    return this->videoMemory_;
}

int GPU::GetCoolerCount() const{
    return this->coolerCount_;
}

std::string GPU::SetCoolerCurrentSpeed(int speed){
    std::string result;
    for (GPUCooler& cooler : this->coolers_){
        result = cooler.SetCurrentSpeed(speed);
    }
    return result;
}

std::string GPU::SetVsync(bool mode) const{
    return mode ? "Vsync enabled" : "Vsync disabled";
}

std::string GPU::SetDlssMode(const std::string& dlssMode) const {
    try {
        const std::vector<std::string> validModes = {
            "Ultra Performance",
            "Performance",
            "Balanced",
            "Quality",
            "Ultra Quality"
        };
        
        if (dlssMode.empty()) {
            throw ExceptionIncorrectDLLSMode("DLSS mode cannot be empty");
        }

        if (std::find(validModes.begin(), validModes.end(), dlssMode) == validModes.end()) {
            throw ExceptionIncorrectDLLSMode("Invalid DLSS mode. Valid modes: Ultra Performance, Performance, Balanced, Quality, Ultra Quality");
        }

        return "DLSS mode is set to " + dlssMode;
    }
    catch (const ExceptionIncorrectDLLSMode& ex) {
        return ex.what();
    }
}