#include <camera.h>

Camera::Camera() = default;

Camera::Camera(const std::string& max_resolution, double megapixels, int max_fps):
_max_resolution(max_resolution), _megapixels(megapixels), _max_fps(max_fps) {}

void Camera::set_max_resolution(const std::string& max_resolution){
    this->_max_resolution = max_resolution;
}

std::string Camera::get_max_resolution() const{
    return this->_max_resolution;
}

void Camera::set_megapixels(double megapixels){
    this->_megapixels = megapixels;
}

double Camera::get_megapixels() const{
    return this->_megapixels;
}

void Camera::set_max_fps(int max_fps){
    this->_max_fps = max_fps;
}

int Camera::get_max_fps() const{
    return this->_max_fps;
}

void Camera::Connect(){
    this->_is_connected = true;
}

void Camera::Disconnect(){
    this->_is_connected = false;
}

bool Camera::IsConnected() const{
    return this->_is_connected;
}

void Camera::MakeVideo(int seconds){
    if (!IsConnected()){
        std::cout << "Камера не подключена. Съемка видео невозможна.\n";
        return;
    }
    int frames_count = seconds * _max_fps;

    std::cout << "Съемка началась: " << seconds << "секунды, " << frames_count << " кадров, разрешение: " << _max_resolution << "\n";

    for (int i = 0; i < frames_count; i++){
        std::string frame = "Frame " + std::to_string(i)
            + " | resolution=" + _max_resolution
            + " | mp=" + std::to_string(_megapixels)
            + " | fps=" + std::to_string(_max_fps);

        std::cout << frame << '\n';
    }

    std::cout << "Съемка завершена: " << frames_count << " кадров.\n";
}