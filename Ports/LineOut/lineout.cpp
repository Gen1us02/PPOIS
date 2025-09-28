#include "lineout.h"

LineOut::LineOut() = default;

bool LineOut::ConnectDevice(const Speakers& speakers){
    if (this->speakers_.has_value()) return false;
    if (!CanAccept(speakers)) return false;
    this->speakers_.emplace(speakers);
    return true;
}

bool LineOut::DisconnectDevice(){
    if (!this->speakers_.has_value()) return false;
    this->speakers_.reset();
    return true;
}

bool LineOut::IsOccupied() const{
    return this->speakers_.has_value();
}

bool LineOut::CanAccept(const Speakers& speakers) const{
    return speakers.SupportsPort(this->type_);
}

std::string LineOut::GetType() const{
    return ToString(this->type_);
}

bool LineOut::DetectSpeakers() const{
    return this->speakers_.has_value();
}