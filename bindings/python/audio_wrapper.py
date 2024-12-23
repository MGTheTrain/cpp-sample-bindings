import ctypes

class SF_INFO(ctypes.Structure):
    """
    Structure to hold information about an audio file.

    Attributes:
        frames (c_int64): Total frames.
        samplerate (c_int): Sample rate.
        channels (c_int): Number of channels.
        format (c_int): Format of the audio data.
        sections (c_int): Sections.
        seekable (c_int): Seekable flag.
    """
    _fields_ = [
        ("frames", ctypes.c_int64),   
        ("samplerate", ctypes.c_int), 
        ("channels", ctypes.c_int),   
        ("format", ctypes.c_int),     
        ("sections", ctypes.c_int),   
        ("seekable", ctypes.c_int)    
    ]

class AudioData(ctypes.Structure):
    """
    Structure to hold audio data, including file handle, information, and playback stream.

    Attributes:
        file (c_void_p): File handle.
        info (SF_INFO): Audio file information.
        stream (c_void_p): Playback stream.
    """
    _fields_ = [
        ("file", ctypes.c_void_p),
        ("info", SF_INFO),
        ("stream", ctypes.c_void_p)
    ]

class AudioWrapper:
    """
    A wrapper class for an audio library implemented in C/C++ using ctypes.

    Attributes:
        audio_lib (CDLL): The loaded audio library.
    """

    def __init__(self, path: str):
        """
        Initialize the AudioWrapper instance.

        Args:
            path (str): The path to the audio library.
        """
        self.audio_lib = ctypes.cdll.LoadLibrary(path)

        self.audio_lib.loadAudioFile.argtypes = [ctypes.c_char_p, ctypes.POINTER(AudioData)]
        self.audio_lib.loadAudioFile.restype = ctypes.c_bool

        self.audio_lib.startPlayback.argtypes = [ctypes.POINTER(AudioData)]
        self.audio_lib.startPlayback.restype = ctypes.c_bool

        self.audio_lib.closeAudioFile.argtypes = [ctypes.POINTER(AudioData)]
        self.audio_lib.closeAudioFile.restype = None

    def load_audio_file(self, filename: str, audio_data: ctypes.POINTER(AudioData)) -> bool:
        """
        Load an audio file using the audio library.

        Args:
            filename (str): The path to the audio file.
            audio_data (AudioData): The AudioData structure to store the loaded audio data.

        Returns:
            bool: True if the audio file was successfully loaded, False otherwise.
        """
        return self.audio_lib.loadAudioFile(filename.encode('utf-8'), ctypes.byref(audio_data))

    def start_playback(self, audio_data: ctypes.POINTER(AudioData)) -> bool:
        """
        Start playback of the loaded audio file using the audio library.

        Args:
            audio_data (AudioData): The AudioData structure containing the loaded audio data.

        Returns:
            bool: True if playback was successfully started, False otherwise.
        """
        return self.audio_lib.startPlayback(ctypes.byref(audio_data))

    def close_audio_file(self, audio_data: ctypes.POINTER(AudioData)):
        """
        Close the loaded audio file using the audio library.

        Args:
            audio_data (AudioData): The AudioData structure containing the audio data to close.
        """
        self.audio_lib.closeAudioFile(ctypes.byref(audio_data))