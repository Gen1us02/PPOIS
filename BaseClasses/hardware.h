#ifndef HARDWARE
#define HARDWARE
#include <string>

class Hardware{
public:
    virtual ~Hardware() = default;
    bool IsInstaled() const{
        return this->isInstalled_;
    };
    void Install(){
        if(isInstalled_) return;
        this->isInstalled_ = true;
    }
    void Uninstall(){
        if(!isInstalled_) return;
        this->isInstalled_ = false;
    }
protected:
    bool isInstalled_ {false};
};


#endif