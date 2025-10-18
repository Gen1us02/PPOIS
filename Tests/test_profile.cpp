#include "gtest/gtest.h"
#include "../Profile/profile.h"

class TestingProfile : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::unordered_set<GenreType> preferences = {GenreType::Phonk, GenreType::Rap};
        user = User("Евгений", "Кулик", 18, "example@mail.com", "dima kulak", "M40815m@");
        profile = Profile(user, "", "Male", preferences);
        
    }

    User user;
    Profile profile;
};

TEST_F(TestingProfile, TestSetDescription)
{
    ASSERT_EQ(profile.GetDescription(), "");
    profile.SetDescription("Меня зовут Женя");
    ASSERT_EQ(profile.GetDescription(), "Меня зовут Женя");
}

TEST_F(TestingProfile, TestGetDescription)
{
    ASSERT_EQ(profile.GetDescription(), "");
}

TEST_F(TestingProfile, TestSetGender)
{
    ASSERT_EQ(profile.GetGender(), "Male");
    profile.SetGender("Female");
    ASSERT_EQ(profile.GetGender(), "Female");
}

TEST_F(TestingProfile, TestGetGender)
{
    ASSERT_EQ(profile.GetGender(), "Male");
}

TEST_F(TestingProfile, TestSetPreferences)
{
    std::unordered_set<GenreType> preferences = {GenreType::Blues, GenreType::Jazz, GenreType::Rap};
    ASSERT_EQ(profile.GetPreferences().size(), 2);
    profile.SetPreferences(preferences);
    ASSERT_EQ(profile.GetPreferences().size(), 3);
}

TEST_F(TestingProfile, TestGetPreferences)
{
    ASSERT_EQ(profile.GetPreferences().size(), 2);
}

TEST_F(TestingProfile, TestGetProfileInfo)
{
    std::string result = profile.GetProfileInfo();

    ASSERT_TRUE(result.find("Имя: Евгений") != std::string::npos);
    ASSERT_TRUE(result.find("Фамилия: Кулик") != std::string::npos);
    ASSERT_TRUE(result.find("Возраст: 18") != std::string::npos);
    ASSERT_TRUE(result.find("Имя пользователя: dima kulak") != std::string::npos);
    ASSERT_TRUE(result.find("Email: example@mail.com") != std::string::npos);
    ASSERT_TRUE(result.find("Пароль: M40815m@") != std::string::npos);
    ASSERT_TRUE(result.find("Описание профиля:") != std::string::npos);
    ASSERT_TRUE(result.find("Пол: Male") != std::string::npos);
    ASSERT_TRUE(result.find("Phonk") != std::string::npos);
    ASSERT_TRUE(result.find("Rap") != std::string::npos);
}

TEST(TestProfile, TestConstructor)
{
    std::unordered_set<GenreType> preferences = {GenreType::Phonk, GenreType::Rap};
    auto user = User("Евгений", "Кулик", 18, "example@mail.com", "dima kulak", "M40815m@");
    auto profile = Profile(user, "", "Male", preferences);
    ASSERT_EQ(profile.GetDescription(), "");
    ASSERT_EQ(profile.GetGender(), "Male");
    ASSERT_EQ(profile.GetPreferences().size(), 2);
}
