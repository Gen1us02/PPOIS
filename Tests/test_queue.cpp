#include "gtest/gtest.h"
#include "../Queue/queue.h"

class TestingQueue : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::vector<Track> tracks = {
            Track("Killer", "", 1823479, "Artemdjdj", 96, GenreType::Blues),
            Track("Kerosene", "", 408600, "Artemdjdj", 153, GenreType::Blues),
        };
        queue = Queue(tracks);
    }

    Queue queue;
};

TEST_F(TestingQueue, TestSetTracks)
{
    std::vector<Track> tracks = {
        Track("The Farewell", "", 1823479, "Artemdjdj", 96, GenreType::Blues),
        Track("Appreciate life", "", 408600, "DeBulka", 153, GenreType::Rap),
        Track("DYSTOPIA", "", 813910, "famous", 240, GenreType::Phonk)
    };
    ASSERT_EQ(queue.GetTracks().size(), 2);
    ASSERT_EQ(queue.GetTracks()[0].GetName(), "Killer");
    ASSERT_EQ(queue.GetTracks()[1].GetName(), "Kerosene");
    queue.SetTracks(tracks);
    ASSERT_EQ(queue.GetTracks().size(), 3);
    ASSERT_EQ(queue.GetTracks()[0].GetName(), "The Farewell");
    ASSERT_EQ(queue.GetTracks()[1].GetName(), "Appreciate life");
    ASSERT_EQ(queue.GetTracks()[2].GetName(), "DYSTOPIA");
}

TEST_F(TestingQueue, TestGetTracks)
{
    ASSERT_EQ(queue.GetTracks().size(), 2);
    ASSERT_EQ(queue.GetTracks()[0].GetName(), "Killer");
    ASSERT_EQ(queue.GetTracks()[1].GetName(), "Kerosene");
}

TEST_F(TestingQueue, TestAddTrack)
{
    queue.AddTrack(Track("28 Days Later", "", 1341515, "Artemdjdj", 146, GenreType::Blues));
    ASSERT_EQ(queue.GetTracks().size(), 3);
    ASSERT_THROW(queue.AddTrack(Track("Killer", "", 148249213, "Artemdjdj",163, GenreType::Rock)),
                 ExceptionIncorrectTrack);
}

TEST_F(TestingQueue, TestRemoveTrack)
{
    queue.RemoveTrack(Track("Killer", "", 148249213, "Artemdjdj", 163, GenreType::Rock));
    ASSERT_EQ(queue.GetTracks().size(), 1);
    ASSERT_THROW(queue.RemoveTrack(Track("jfsjfji", "", 148249213, "Artemdjdj",163, GenreType::Rock)),
                 ExceptionIncorrectTrack);
}

TEST_F(TestingQueue, TestGetTrackList)
{
    ASSERT_EQ(queue.GetTrackList(), "Killer\nKerosene\n");
}

TEST(TestQueue, TestConstructor)
{
    std::vector<Track> tracks = {
        Track("Boys Interface", "", 2884789, "Artemdjdj", 106, GenreType::Jazz),
        Track("OneShot", "", 408600, "Artemdjdj", 123, GenreType::Jazz),
    };
    auto queue = Queue(tracks);
    ASSERT_EQ(queue.GetTracks().size(), 2);
    ASSERT_EQ(queue.GetTrackList(), "Boys Interface\nOneShot\n");
}
