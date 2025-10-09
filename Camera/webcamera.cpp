#include "webcamera.h"
#include "../Exceptions/exceptions.h"
#include <format>

WebCamera::WebCamera() = default;

WebCamera::WebCamera(const std::string &maxResolution, double megapixels, int maxFps) : maxResolution_(maxResolution),
    megapixels_(megapixels), maxFps_(maxFps) {
}

void WebCamera::SetMaxResolution(const std::string &maxResolution) {
    this->maxResolution_ = maxResolution;
}

std::string WebCamera::GetMaxResolution() const {
    return this->maxResolution_;
}

void WebCamera::SetMegapixels(double megapixels) {
    this->megapixels_ = megapixels;
}

double WebCamera::GetMegapixels() const {
    return this->megapixels_;
}

void WebCamera::SetMaxFps(int maxFps) {
    this->maxFps_ = maxFps;
}

int WebCamera::GetMaxFps() const {
    return this->maxFps_;
}

std::string WebCamera::MakeVideo(int seconds) {
    if (!IsConnected()) {
        throw ExceptionConnection("WebCamera is not connected");
    }
    int frames_count = seconds * maxFps_;

    std::string video = "Record stopped: " + std::to_string(frames_count) + " frames.\nresolution=" + maxResolution_
                        + " | mp=" + std::format("{:.1f}", megapixels_)
                        + " | fps=" + std::to_string(maxFps_);
    ReadInput(video);
    return video;
}
