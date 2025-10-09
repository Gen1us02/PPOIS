#include "../Exceptions/exceptions.h"
#include "../Camera/webcamera.h"
#include "gtest/gtest.h"

class TestingWebCamera : public ::testing::Test {
protected:
    void SetUp() override {
        web_camera = WebCamera("1920x1080", 4.1, 120);
    }

    WebCamera web_camera;
};

TEST_F(TestingWebCamera, TestConnect) {
    web_camera.Connect();
    ASSERT_TRUE(web_camera.IsConnected());
}

TEST_F(TestingWebCamera, TestDisconnect) {
    web_camera.Connect();
    ASSERT_TRUE(web_camera.IsConnected());
    web_camera.Disconnect();
    ASSERT_FALSE(web_camera.IsConnected());
}

TEST_F(TestingWebCamera, TestSetMaxResolution) {
    ASSERT_EQ(web_camera.GetMaxResolution(), "1920x1080");
    web_camera.SetMaxResolution("3840x2160");
    ASSERT_EQ(web_camera.GetMaxResolution(), "3840x2160");
}

TEST_F(TestingWebCamera, TestGetMaxResolution) {
    ASSERT_EQ(web_camera.GetMaxResolution(), "1920x1080");
}

TEST_F(TestingWebCamera, TestSetMaxFps) {
    ASSERT_EQ(web_camera.GetMaxFps(), 120);
    web_camera.SetMaxFps(90);
    ASSERT_EQ(web_camera.GetMaxFps(), 90);
}

TEST_F(TestingWebCamera, TestGetMaxFps) {
    ASSERT_EQ(web_camera.GetMaxFps(), 120);
}

TEST_F(TestingWebCamera, TestSetMegapixels) {
    ASSERT_EQ(web_camera.GetMegapixels(), 4.1);
    web_camera.SetMegapixels(5.1);
    ASSERT_EQ(web_camera.GetMegapixels(), 5.1);
}

TEST_F(TestingWebCamera, TestGetType) {
    ASSERT_EQ(web_camera.GetMegapixels(), 4.1);
}

TEST_F(TestingWebCamera, TestMakeVideoCorrect) {
    web_camera.Connect();
    ASSERT_EQ(web_camera.MakeVideo(10), "Record stopped: 1200 frames.\nresolution=1920x1080 | mp=4.1 | fps=120");
}

TEST_F(TestingWebCamera, TestMakeVideoIncorrect) {
    ASSERT_THROW(web_camera.MakeVideo(10), ExceptionConnection);
}

TEST(TestWebCamera, TestConstructor) {
    auto web_camera = WebCamera("1920x1080", 6.0, 240);
    ASSERT_EQ(web_camera.GetMaxResolution(), "1920x1080");
    ASSERT_EQ(web_camera.GetMegapixels(), 6.0);
    ASSERT_EQ(web_camera.GetMaxFps(), 240);
}
