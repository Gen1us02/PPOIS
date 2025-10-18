#ifndef HUMAN
#define HUMAN

class Human
{
public:
    virtual ~Human() = default;
    virtual void SetName(const std::string& name) = 0;
    virtual std::string GetName() const = 0;
    virtual void SetAge(int age) = 0;
    virtual int GetAge() const = 0;
};
#endif
