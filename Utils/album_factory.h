#ifndef ALBUM_FACTORY
#define ALBUM_FACTORY

#include <memory>
#include <string>
#include <vector>
#include "../BaseClasses/album.h"
#include "album_type.h"

std::shared_ptr<Album> AlbumFactory(AlbumType type,
                                   const std::string& albumTitle,
                                   const std::vector<Track>& tracks);

#endif