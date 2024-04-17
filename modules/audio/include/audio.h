#include <portaudio.h>
#include <sndfile.h>

#include <cstring>
#include <iostream>

#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (64)

/**
 * @brief Struct to hold audio data, including file handle, information, and
 * playback stream.
 */
typedef struct {
  SNDFILE *file;    /**< Pointer to the opened audio file */
  SF_INFO info;     /**< Information about the audio file */
  PaStream *stream; /**< Pointer to the PortAudio stream for playback */
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