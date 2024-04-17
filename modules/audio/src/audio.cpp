#include <audio.h>

/**
 * @brief Loads an audio file specified by the filename into the AudioData
 * structure.
 *
 * @param filename The path to the audio file to load.
 * @param audioData Pointer to the AudioData structure to store the loaded audio
 * data.
 * @return true if the audio file was successfully loaded, false otherwise.
 */
bool loadAudioFile(const char *filename, AudioData *audioData) {
  audioData->file = sf_open(filename, SFM_READ, &audioData->info);
  if (!audioData->file) {
    std::cerr << "Error: Failed to open MP3 file." << std::endl;
    return false;
  }
  return true;
}

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
bool startPlayback(AudioData *audioData) {
  PaError err;

  err = Pa_Initialize();
  if (err != paNoError) {
    std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
    return false;
  }

  PaStreamParameters outputParameters;
  outputParameters.device = Pa_GetDefaultOutputDevice();
  if (outputParameters.device == paNoDevice) {
    std::cerr << "Error: No default output device." << std::endl;
    return false;
  }
  outputParameters.channelCount = audioData->info.channels;
  outputParameters.sampleFormat = paFloat32;
  outputParameters.suggestedLatency =
      Pa_GetDeviceInfo(outputParameters.device)->defaultHighOutputLatency;
  outputParameters.hostApiSpecificStreamInfo = nullptr;

  err = Pa_OpenStream(&audioData->stream,
                      nullptr,  // No input
                      &outputParameters, SAMPLE_RATE, FRAMES_PER_BUFFER,
                      paClipOff,  // No clipping
                      nullptr,    // No callback
                      nullptr);   // No user data

  if (err != paNoError) {
    std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
    Pa_Terminate();
    return false;
  }

  err = Pa_StartStream(audioData->stream);
  if (err != paNoError) {
    std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
    Pa_Terminate();
    return false;
  }

  return true;
}

/**
 * @brief Closes the audio file and terminates PortAudio.
 *
 * This function stops the playback stream, closes the PortAudio stream,
 * terminates PortAudio, and closes the audio file.
 *
 * @param audioData Pointer to the AudioData structure containing the audio data
 * to close.
 */
void closeAudioFile(AudioData *audioData) {
  Pa_StopStream(audioData->stream);
  Pa_CloseStream(audioData->stream);
  Pa_Terminate();
  sf_close(audioData->file);
}