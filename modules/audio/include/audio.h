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

#ifdef __cplusplus
extern "C" {
#endif

#include <portaudio.h>
#include <sndfile.h>

#include <cstring>
#include <iostream>

#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (64)

/**
 * @note Essential code snippets from:
 * https://github.com/hosackm/wavplayer/blob/master/src/wavplay.c
 */

/**
 * @brief Struct to hold audio data, including file handle, information, and
 * playback stream.
 */
typedef struct {
  SNDFILE *file;
  SF_INFO info;
  PaStream *stream;
} AudioData;

/**
 * @brief Loads an audio file specified by the filename into the AudioData
 * structure.
 *
 * @param filename The path to the audio file to load.
 * @param audioData Pointer to the AudioData structure to store the loaded audio
 * data.
 * @return true if the audio file was successfully loaded, false otherwise.
 */
bool loadAudioFile(const char *filename, AudioData *audioData);

/**
 * @brief Starts playback of the loaded audio file.
 *
 * This function initializes PortAudio, opens a stream for audio playback, and
 * starts the playback.
 *
 * @param audioData Pointer to the AudioData structure containing the loaded
 * audio data.
 * @return true if playback was successfully started, false otherwise.
 */
bool startPlayback(AudioData *audioData);

/**
 * @brief Closes the audio file and terminates PortAudio.
 *
 * This function stops the playback stream, closes the PortAudio stream,
 * terminates PortAudio, and closes the audio file.
 *
 * @param audioData Pointer to the AudioData structure containing the audio data
 * to close.
 */
void closeAudioFile(AudioData *audioData);

/**
 * @brief Callback function for audio playback.
 *
 * This function is called by PortAudio when it needs more audio data to play.
 * It reads audio data from the file into the output buffer.
 *
 * @param input Pointer to the input buffer (not used in playback).
 * @param output Pointer to the output buffer where audio data should be
 * written.
 * @param frameCount Number of frames requested for playback.
 * @param timeInfo Pointer to timing information for the callback (not used in
 * this function).
 * @param statusFlags Flags indicating possible errors or other information from
 * PortAudio.
 * @param userData Pointer to user data provided when the stream was opened.
 *                 In this function, it should be a pointer to the AudioData
 * struct.
 *
 * @return paContinue if playback should continue, paComplete if playback is
 * complete.
 */
static int playbackCallback(const void *input, void *output,
                            unsigned long frameCount,
                            const PaStreamCallbackTimeInfo *timeInfo,
                            PaStreamCallbackFlags statusFlags, void *userData);
#ifdef __cplusplus
}
#endif