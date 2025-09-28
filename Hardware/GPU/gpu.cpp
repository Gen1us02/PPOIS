#include "gpu.h"
#include "exceptions.h"

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

void GPU::SetCoolerCount(int coolerCount){
    try{
        if (coolerCount > 3 || coolerCount < 0){
        throw ExceptionIncorrectCoolerCount("Невалидное количечтво вентиляторов");
    }
        std::vector<GPUCooler> oldCoolers = coolers_;
        coolers_.resize(coolerCount);
        
        for (int i = 0; i < std::min(coolerCount, static_cast<int>(oldCoolers.size())); i++) {
            coolers_[i] = oldCoolers[i];
        }
        
    this->coolerCount_ = coolerCount;
    }
    catch (const ExceptionIncorrectCoolerCount& ex){
        std::cout << ex.what();
    }
}

int GPU::GetCoolerCount() const{
    return this->coolerCount_;
}

void GPU::SetCoolerCurrentSpeed(int speed){
    for (GPUCooler& cooler : this->coolers_){
        cooler.SetCurrentSpeed(speed);
    }
}

std::string GPU::SetVsync(bool mode) const{
    return mode ? "Вертикальная синхронизация включена" : "Вертикальная синхронизация выключена";
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
            throw ExceptionIncorrectDLLSMode("DLSS режим не может быть пустым");
        }

        if (std::find(validModes.begin(), validModes.end(), dlssMode) == validModes.end()) {
            throw ExceptionIncorrectDLLSMode("Недопустимый DLSS режим. Допустимые режимы: Ultra Performance, Performance, Balanced, Quality, Ultra Quality");
        }

        return "DLSS режим установлен на " + dlssMode;
    }
    catch (const ExceptionIncorrectDLLSMode& ex) {
        return ex.what();
    }
}