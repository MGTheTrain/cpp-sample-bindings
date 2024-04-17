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
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifdef MGTT_AUDIO_TEST

#include <gtest/gtest.h>
#include <audio.h>

// Test fixture for audio functions
class AudioPlaybackTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}

  virtual void TearDown() {}
};

// Test case for loading an audio file
TEST_F(AudioPlaybackTest, LoadAudioFileTest) {
  const char *filename = "path/to/your/audio/file.mp3";
  AudioData audioData;
  EXPECT_TRUE(loadAudioFile(filename, &audioData));
}

// Test case for starting audio playback
TEST_F(AudioPlaybackTest, StartPlaybackTest) {
  const char *filename = "path/to/your/audio/file.mp3";
  AudioData audioData;
  ASSERT_TRUE(loadAudioFile(filename, &audioData));
  EXPECT_TRUE(startPlayback(&audioData));
}

// Test case for closing audio file and terminating PortAudio
TEST_F(AudioPlaybackTest, CloseAudioFileTest) {
  const char *filename = "path/to/your/audio/file.mp3";
  AudioData audioData;
  ASSERT_TRUE(loadAudioFile(filename, &audioData));
  ASSERT_TRUE(startPlayback(&audioData));
  closeAudioFile(&audioData);
}

#endif 