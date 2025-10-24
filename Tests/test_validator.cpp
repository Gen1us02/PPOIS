#include "../Validator/validator.h"
#include "gtest/gtest.h"

TEST(TestValidator, TestValidatePassword) {
    ASSERT_TRUE(Validator::PasswordValidator("M40815m@"));
    ASSERT_FALSE(Validator::PasswordValidator("12345"));
}

TEST(TestValidator, TestValidateEmail) {
    ASSERT_TRUE(Validator::EmailValidator("example@email.com"));
    ASSERT_FALSE(Validator::EmailValidator("12345.com"));
}
