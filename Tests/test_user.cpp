#include "gtest/gtest.h"
#include "../User/user.h"

class TestingUser : public ::testing::Test
{
protected:
    void SetUp() override
    {
        user = User("Евгений", "Кулик", 18, "example@mail.com", "dima kulak", "M40815m@");
    }

    User user;
};

TEST_F(TestingUser, TestSetName)
{
    ASSERT_EQ(user.GetName(), "Евгений");
    user.SetName("Дмитрий");
    ASSERT_EQ(user.GetName(), "Дмитрий");
}

TEST_F(TestingUser, TestGetName)
{
    ASSERT_EQ(user.GetName(), "Евгений");
}

TEST_F(TestingUser, TestSetSurname)
{
    ASSERT_EQ(user.GetSurname(), "Кулик");
    user.SetSurname("Бурбас");
    ASSERT_EQ(user.GetSurname(), "Бурбас");
}

TEST_F(TestingUser, TestGetSurname)
{
    ASSERT_EQ(user.GetSurname(), "Кулик");
}

TEST_F(TestingUser, TestSetAge)
{
    ASSERT_EQ(user.GetAge(), 18);
    user.SetAge(19);
    ASSERT_EQ(user.GetAge(), 19);
}

TEST_F(TestingUser, TestGetAge)
{
    ASSERT_EQ(user.GetAge(), 18);
}

TEST_F(TestingUser, TestSetEmail)
{
    ASSERT_EQ(user.GetEmail(), "example@mail.com");
    ASSERT_THROW(user.SetEmail("sdifjksfijk"), ExceptionInvalidEmail);
    user.SetEmail("dima_burbas@email.com");
    ASSERT_EQ(user.GetEmail(), "dima_burbas@email.com");
}

TEST_F(TestingUser, TestGetEmail)
{
    ASSERT_EQ(user.GetEmail(), "example@mail.com");
}

TEST_F(TestingUser, TestSetPassword)
{
    ASSERT_EQ(user.GetPassword(), "M40815m@");
    ASSERT_THROW(user.SetPassword("12345"), ExceptionInvalidPassword);
    user.SetPassword("adA12@lsal89");
    ASSERT_EQ(user.GetPassword(), "adA12@lsal89");
}

TEST_F(TestingUser, TestGetPassword)
{
    ASSERT_EQ(user.GetPassword(), "M40815m@");
}

TEST_F(TestingUser, TestSetUsername)
{
    ASSERT_EQ(user.GetUsername(), "dima kulak");
    user.SetUsername("DeBulka");
    ASSERT_EQ(user.GetUsername(), "DeBulka");
}

TEST_F(TestingUser, TestGetUsername)
{
    ASSERT_EQ(user.GetUsername(), "dima kulak");
}

TEST_F(TestingUser, TestGetUserInfo)
{
    ASSERT_EQ(user.GetUserInfo(),
              "Имя: Евгений\n"
              "Фамилия: Кулик\n"
              "Возраст: 18\n"
              "Имя пользователя: dima kulak\n"
              "Email: example@mail.com\n"
              "Пароль: M40815m@\n");
}

TEST(TestUser, TestConstructor)
{
    ASSERT_THROW(auto user1 = User("Евгений", "Кулик", 18, "iosjdfjk", "dima kulak", "M40815m@"), ExceptionInvalidEmail);
    ASSERT_THROW(auto user2 = User("Евгений", "Кулик", 18, "example@mail.com", "dima kulak", "43522"), ExceptionInvalidPassword);
    auto user3 = User("Евгений", "Кулик", 18, "example@mail.com", "dima kulak", "M40815m@");
    ASSERT_EQ(user3.GetName(), "Евгений");
    ASSERT_EQ(user3.GetSurname(), "Кулик");
    ASSERT_EQ(user3.GetAge(), 18);
    ASSERT_EQ(user3.GetPassword(), "M40815m@");
    ASSERT_EQ(user3.GetUsername(), "dima kulak");
    ASSERT_EQ(user3.GetEmail(), "example@mail.com");
}
