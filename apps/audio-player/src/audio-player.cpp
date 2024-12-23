#ifdef AUDIO_PLAYER
#include <audio-player.h>

int main(int argc, char *argv[]) {
    const char * path = "assets/mp3/file_example_MP3_700KB.mp3"; 
    AudioData audioData;
    if (!loadAudioFile(path, &audioData)) {
        return 1;
    }

    if (!startPlayback(&audioData)) {
        closeAudioFile(&audioData);
        return 1;
    }

    std::cout << "Playing " << path << ". Press Enter to stop..." << std::endl;
    std::cin.get();

    closeAudioFile(&audioData);

    return 0;
}
#endif