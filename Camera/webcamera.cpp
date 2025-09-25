#include "webcamera.h"

WebCamera::WebCamera() = default;

WebCamera::WebCamera(const std::string& max_resolution, double megapixels, int max_fps):
_max_resolution(max_resolution), _megapixels(megapixels), _max_fps(max_fps) {}

void WebCamera::set_max_resolution(const std::string& max_resolution){
    this->_max_resolution = max_resolution;
}

std::string WebCamera::get_max_resolution() const{
    return this->_max_resolution;
}

void WebCamera::set_megapixels(double megapixels){
    this->_megapixels = megapixels;
}

double WebCamera::get_megapixels() const{
    return this->_megapixels;
}

void WebCamera::set_max_fps(int max_fps){
    this->_max_fps = max_fps;
}

int WebCamera::get_max_fps() const{
    return this->_max_fps;
}

std::string WebCamera::MakeVideo(int seconds){
    if (!IsConnected()){
        std::cout << "Камера не подключена. Съемка видео невозможна.\n";
        return "";
    }
    int frames_count = seconds * _max_fps;

    for (int i = 0; i < frames_count; i++){
        std::string frames = "Frame " + std::to_string(i)
            + " | resolution=" + _max_resolution
            + " | mp=" + std::to_string(_megapixels)
            + " | fps=" + std::to_string(_max_fps) + "\n";

    }

    std::string video = "Съемка завершена:" + std::to_string(frames_count) + "кадров.";
    readInput(video);
    return video;
}

void WebCamera::readInput(const std::string& video){
    this->_input = video;
}