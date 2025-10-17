#ifndef BUTTON
#define BUTTON

class Button
{
public:
    virtual ~Button() = default;
    virtual void SetWidth(int width) = 0;
    virtual int GetWidth() const = 0;
    virtual void SetHeight(int height) = 0;
    virtual int GetHeight() const = 0;
};

#endif
