#ifndef PORT_TYPE
#define PORT_TYPE

enum class PortType {None, HDMI, USB, DisplayPort, M2, MicIn, LineOut};

std::string ToString(PortType port){
    switch (port){
        case PortType::HDMI: return "HDMI";
        case PortType::USB: return "USB";
        case PortType::DisplayPort: return "DisplayPort";
        case PortType::M2: return "M2";
        case PortType::MicIn: return "MicIn";
        case PortType::LineOut: return "LineOut";
        default: return "Unknown";  
    }
}

#endif