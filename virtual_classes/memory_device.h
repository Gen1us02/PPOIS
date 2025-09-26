#ifndef MEMORYDEVICE
#define MEMORYDEVICE
#include <string>

class MemoryDevice{
public:
    virtual ~MemoryDevice() = default;
    virtual void SetMemorySize(int) = 0;
    virtual int GetMemorySize() const = 0;
    void WriteData(const std::string& data){
        this->data_ += data + "\n";
    }
    std::string ReadData() const{
        return this->data_;
    }
    void ClearData(){
        this->data_ = "";
    }
protected:
    std::string data_ {""};
};


#endif