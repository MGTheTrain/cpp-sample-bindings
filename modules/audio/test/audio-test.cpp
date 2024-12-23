#ifdef MGTT_AUDIO_TEST

#include <audio.h>
#include <gtest/gtest.h>

// Test fixture for audio functions
class AudioPlaybackTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}

  virtual void TearDown() {}
};

// Test case for loading an audio file
TEST_F(AudioPlaybackTest, LoadAudioFileTest) {
  const char *filename = "assets/mp3/file_example_MP3_700KB.mp3";
  AudioData audioData;
  EXPECT_TRUE(loadAudioFile(filename, &audioData));
}

// Test case for starting audio playback
TEST_F(AudioPlaybackTest, StartPlaybackTest) {
  const char *filename = "assets/mp3/file_example_MP3_700KB.mp3";
  AudioData audioData;
  ASSERT_TRUE(loadAudioFile(filename, &audioData));
  EXPECT_TRUE(startPlayback(&audioData));
}

// Test case for closing audio file and terminating PortAudio
TEST_F(AudioPlaybackTest, CloseAudioFileTest) {
  const char *filename = "assets/mp3/file_example_MP3_700KB.mp3";
  AudioData audioData;
  ASSERT_TRUE(loadAudioFile(filename, &audioData));
  ASSERT_TRUE(startPlayback(&audioData));
  closeAudioFile(&audioData);
}

#endif