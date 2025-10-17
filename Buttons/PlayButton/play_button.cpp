#include "play_button.h"

PlayButton::PlayButton() = default;

PlayButton::~PlayButton() = default;

PlayButton::PlayButton(int width, int height) : width_(width), height_(height)
{
}

void PlayButton::SetWidth(int width)
{
    this->width_ = width;
}

int PlayButton::GetWidth() const
{
    return this->width_;
}

void PlayButton::SetHeight(int height)
{
    this->height_ = height;
}

int PlayButton::GetHeight() const
{
    return this->height_;
}

void PlayButton::PlayTrack(Track& track) const
{
    if (track.IsPlaying())
    {
        throw ExceptionTrackPlaying("Track is already playing");
    }
    std::vector<std::string> lines;
    track.Play();
    std::string text = track.GetText();
    char* token = std::strtok(text.data(), "\n");
    while (token != nullptr)
    {
        lines.push_back(token);
        token = std::strtok(nullptr, "\n");
    }
    for (int i = 0; i < lines.size(); i++)
    {
        for (int j = 0; j < lines[i].size(); j++)
        {
            std::cout << lines[i][j];
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
        std::cout << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

std::string PlayButton::PauseTrack(Track& track) const
{
    if (!track.IsPlaying())
    {
        throw ExceptionTrackPaused("Track is not playing");
    }
    track.Pause();
    return "Track paused";
}
