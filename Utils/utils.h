#ifndef UTILS
#define UTILS

#include <memory>
#include <string>
#include <vector>
#include <regex>
#include "../BaseClasses/album.h"
#include "album_type.h"

std::shared_ptr<Album> AlbumFactory(AlbumType type,
                                   const std::string& albumTitle,
                                   const std::vector<Track>& tracks);

bool PasswordValidator(const std::string& password);

bool EmailValidator(const std::string& email);

#endif