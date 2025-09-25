#include "gpu.h"

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
    //Валидация количества вентиляторов(не больше 3)
    this->coolerCount_ = coolerCount;
    //Обработка уменьшения/увеличения вентиляторов в векторе
}

int GPU::GetCoolerCount() const{
    return this->coolerCount_;
}

void GPU::SetCoolerSpeed(int speed){
    for (GPUCooler& cooler : this->coolers_){
        cooler.SetCurrentSpeed(speed);
    }
}

std::string GPU::SetVsync(bool mode) const{
    return mode ? "Вертикальная синхронизация включена" : "Вертикальная синхронизация выключена";
}

std::string GPU::SetDlssMode(const std::string& dlssMode) const{
    //Валидация DLSS режима
    return "Dlss режим установлен на " + dlssMode;
}