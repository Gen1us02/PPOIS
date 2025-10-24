#include <gtest/gtest.h>
#include <vector>
#include "../AlbumFactory/album_factory.h"

TEST(AlbumFactoryTest, CreateStudioAlbum) {
    std::vector<Track> tracks = {
            Track("Killer", "", 1000000, "Artemdjdj",96, GenreType::Phonk),
            Track("Kerosene", "", 408600, "Artemdjdj",153, GenreType::Phonk),
    };
    auto album = AlbumFactory::CreateAlbum(AlbumType::StudioAlbum, "Test Studio", tracks);
    
    ASSERT_NE(album, nullptr);
    ASSERT_EQ(album->GetTitle(), "Test Studio");
    ASSERT_EQ(album->GetAlbumType(), "Studio Album");
}

TEST(AlbumFactoryTest, CreateCompilationAlbum) {
    std::vector<Track> tracks = {
            Track("Killer", "", 1000000, "Artemdjdj",96, GenreType::Phonk),
            Track("Kerosene", "", 408600, "Artemdjdj",153, GenreType::Phonk),
    };
    auto album = AlbumFactory::CreateAlbum(AlbumType::CompilationAlbum, "Test Compilation", tracks);
    
    ASSERT_NE(album, nullptr);
    ASSERT_EQ(album->GetTitle(), "Test Compilation");
    ASSERT_EQ(album->GetAlbumType(), "Compilation Album");
}

TEST(AlbumFactoryTest, CreateConcertAlbum) {
    std::vector<Track> tracks = {
            Track("Killer", "", 1000000, "Artemdjdj",96, GenreType::Phonk),
            Track("Kerosene", "", 408600, "Artemdjdj",153, GenreType::Phonk),
    };
    auto album = AlbumFactory::CreateAlbum(AlbumType::ConcertAlbum, "Test Concert", tracks);
    
    ASSERT_NE(album, nullptr);
    ASSERT_EQ(album->GetTitle(), "Test Concert");
    ASSERT_EQ(album->GetAlbumType(), "Concert Album");
}

TEST(AlbumFactoryTest, CreateExtendedPlayAlbum) {
    std::vector<Track> tracks = {
            Track("Killer", "", 1000000, "Artemdjdj",96, GenreType::Phonk),
            Track("Kerosene", "", 408600, "Artemdjdj",153, GenreType::Phonk),
    };
    auto album = AlbumFactory::CreateAlbum(AlbumType::ExtendedAlbum, "Test EP", tracks);
    
    ASSERT_NE(album, nullptr);
    ASSERT_EQ(album->GetTitle(), "Test EP");
    ASSERT_EQ(album->GetAlbumType(), "Extended Play Album");
}

TEST(AlbumFactoryTest, ThrowsOnInvalidAlbumType) {
    std::vector<Track> tracks = {
            Track("Killer", "", 1000000, "Artemdjdj",96, GenreType::Phonk),
            Track("Kerosene", "", 408600, "Artemdjdj",153, GenreType::Phonk),
    };
    
    ASSERT_THROW(
        AlbumFactory::CreateAlbum(static_cast<AlbumType>(100), "Invalid", tracks),
        ExceptionIncorrectAlbum
    );
}

TEST(AlbumFactoryTest, HandlesEmptyTrackList) {
    std::vector<Track> emptyTracks;
    auto album = AlbumFactory::CreateAlbum(AlbumType::StudioAlbum, "Empty Album", emptyTracks);
    
    ASSERT_NE(album, nullptr);
    ASSERT_EQ(album->GetTrackCount(), 0);
}
