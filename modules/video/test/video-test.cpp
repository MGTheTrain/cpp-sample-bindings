#ifdef MGTT_VIDEO_TEST

#include <gtest/gtest.h>
#include <video.h>

// Test fixture for video functions
class VideoPlaybackTest : public ::testing::Test {
 protected:
  virtual void SetUp() { initVideoPlayer(player); }

  virtual void TearDown() { closeVideoPlayer(player); }

  VideoPlayer player;
};

// Test case for loading a video file
TEST_F(VideoPlaybackTest, LoadVideoFileTest) {
  const char* filename = "assets/mp4/file_example_MP4_1280_10MG.mp4";
  EXPECT_TRUE(loadVideo(player, filename));
}

// Test case for starting video playback
TEST_F(VideoPlaybackTest, StartPlaybackTest) {
  const char* filename = "assets/mp4/file_example_MP4_1280_10MG.mp4";
  EXPECT_TRUE(loadVideo(player, filename));
  playVideo(player);
}

// Test case for closing video file and terminating video player
TEST_F(VideoPlaybackTest, CloseVideoFileTest) {
  const char* filename = "assets/mp4/file_example_MP4_1280_10MG.mp4";
  EXPECT_TRUE(loadVideo(player, filename));
  playVideo(player);
}

#endif
