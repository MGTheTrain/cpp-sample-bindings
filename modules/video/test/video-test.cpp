// The MIT License
//
// Copyright (c) 2024 MGTheTrain
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software. THE SOFTWARE IS PROVIDED
// "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
// LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
