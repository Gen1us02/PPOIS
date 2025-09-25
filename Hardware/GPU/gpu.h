#ifndef GPUDEVICE
#define GPUDEVICE
#include <iostream>
#include <string>
#include <vector>
#include "hardware.h"
#include "gpu_cooler.h"

class GPU: public Hardware{
public:
    GPU();
    GPU(int, int, bool, int, int);
    void SetRtxSupport(bool);
    bool GetRtxSupport() const;
    void SetVideoMemory(int);
    int GetVideoMemory() const;
    void SetCoolerCount(int);
    int GetCoolerCount() const;
    void SetCoolerSpeed(int speed);
    std::string SetVsync(bool mode) const;
    std::string SetDlssMode(const std::string& dlssMode) const;
private:
    bool rtxSupport_ {false};
    int videoMemory_ {0};
    int coolerCount_ {0};
    std::vector<GPUCooler> coolers_;
};

#endif