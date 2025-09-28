#include "webcamera.h"

WebCamera::WebCamera() = default;

WebCamera::WebCamera(const std::string& maxResolution, double megapixels, int maxFps):
maxResolution_(maxResolution), megapixels_(megapixels), maxFps_(maxFps) {}

void WebCamera::SetMaxResolution(const std::string& maxResolution){
    this->maxResolution_ = maxResolution;
}

std::string WebCamera::GetMaxResolution() const{
    return this->maxResolution_;
}

void WebCamera::SetMegapixels(double megapixels){
    this->megapixels_ = megapixels;
}

double WebCamera::GetMegapixels() const{
    return this->megapixels_;
}

void WebCamera::SetMaxFps(int maxFps){
    this->maxFps_ = maxFps;
}

int WebCamera::GetMaxFps() const{
    return this->maxFps_;
}

std::string WebCamera::MakeVideo(int seconds){
    if (!IsConnected()){
        std::cout << "Камера не подключена. Съемка видео невозможна.\n";
        return "";
    }
    int frames_count = seconds * maxFps_;

    for (int i = 0; i < frames_count; i++){
        std::string frames = "Frame " + std::to_string(i)
            + " | resolution=" + maxResolution_
            + " | mp=" + std::to_string(megapixels_)
            + " | fps=" + std::to_string(maxFps_) + "\n";

    }

    std::string video = "Съемка завершена:" + std::to_string(frames_count) + "кадров.";
    ReadInput(video);
    return video;
}