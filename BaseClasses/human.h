#ifndef HUMAN
#define HUMAN

class Human
{
public:
    virtual ~Human() = default;

    void SetName(const std::string& name)
    {
        this->name_ = name;
    }

    std::string GetName() const
    {
        return this->name_;
    }

    void SetAge(int age)
    {
        this->age_ = age;
    }

    int GetAge() const
    {
        return this->age_;
    }

protected:
    std::string name_{""};
    int age_{0};
};
#endif
