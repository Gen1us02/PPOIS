#ifndef BAR
#define BAR

class Bar
{
public:
    virtual ~Bar() = default;
    virtual void SetLength(int length) = 0;
    virtual int GetLength() const = 0;
};

#endif
