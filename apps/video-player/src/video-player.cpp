#ifdef VIDEO_PLAYER
#include <video-player.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <video_file>\n", argv[0]);
        return -1;
    }

    const char* videoFileName = argv[1];

    VideoPlayer player;

    if (!initVideoPlayer(player)) {
        std::cerr << "Failed to initialize video player\n";
        return -1;
    }

    if (!loadVideo(player, videoFileName)) {
        std::cerr << "Failed to load video: " << videoFileName << "\n";
        closeVideoPlayer(player);
        return -1;
    }

    playVideo(player);

    closeVideoPlayer(player);

    return 0;
}
#endif