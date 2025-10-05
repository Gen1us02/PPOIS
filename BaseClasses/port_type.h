/*! \file port_type.h
 *  \brief Заголовочный файл с перечислением типов портов
 *  \details Содержит определение перечисления PortType, используемого для описания
 *           физических интерфейсов системы, а также
 *           вспомогательную функцию ToString для получения текстового представления типа порта.
 *           Файл предназначен для включения в модули, работающие с портами и проверяющие
 *           совместимость подключаемых устройств.
 */
#ifndef PORT_TYPE
#define PORT_TYPE

/*! \enum PortType
 *  \brief Перечисление типов аппаратных портов
 *  \details Используется для идентификации доступных интерфейсов подключения устройств.
 *           Значения включают основные распространённые разъёмы и служебное значение None.
 */
enum class PortType {None, HDMI, USB, DisplayPort, M2, MicIn, LineOut};

/*! \brief Преобразовать PortType в строковое представление
 *  \param port Тип порта для преобразования
 *  \return Строка с названием порта
 *  \details Функция возвращает стандартные текстовые имена для известных типов портов.
 *           Для неизвестных или значения None возвращается "Unknown".
 */
inline std::string ToString(PortType port){
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