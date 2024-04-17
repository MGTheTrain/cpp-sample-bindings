# The MIT License
#
# Copyright (c) 2024 MGTheTrain
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

import ctypes
import pyaudio


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


class PaStreamCallbackTimeInfo(ctypes.Structure):
    """
    Structure to hold timing information for the audio playback callback.

    Attributes:
        inputBufferAdcTime (c_double): Time of the input buffer.
        currentTime (c_double): Current time.
        outputBufferDacTime (c_double): Time of the output buffer.
    """
    _fields_ = [
        ("inputBufferAdcTime", ctypes.c_double),
        ("currentTime", ctypes.c_double),
        ("outputBufferDacTime", ctypes.c_double)
    ]

class AudioWrapper:
    """
    A wrapper class for an audio library implemented in C/C++ using ctypes.

    Attributes:
        audio_lib (CDLL): The loaded audio library.
        pyaudio (PyAudio): PyAudio instance.
        audio_callback (PyAudio callback): The callback function for audio playback.
    """

    def __init__(self, path: str):
        """
        Initialize the AudioWrapper instance.

        Args:
            path (str): The path to the audio library.
        """
        self.audio_lib = ctypes.cdll.LoadLibrary(path)
        self.pyaudio = pyaudio.PyAudio()
        self.audio_callback = self._audio_callback  # Set the callback function for audio playback

        self.audio_lib.loadAudioFile.argtypes = [ctypes.c_char_p, ctypes.POINTER(AudioData)]
        self.audio_lib.loadAudioFile.restype = ctypes.c_bool

        self.audio_lib.startPlayback.argtypes = [ctypes.POINTER(AudioData)]
        self.audio_lib.startPlayback.restype = ctypes.c_bool

        self.audio_lib.closeAudioFile.argtypes = [ctypes.POINTER(AudioData)]
        self.audio_lib.closeAudioFile.restype = None

        self.audio_lib.playbackCallback.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_ulong,
                                                    ctypes.POINTER(PaStreamCallbackTimeInfo),
                                                    ctypes.c_int, ctypes.c_void_p]
        self.audio_lib.playbackCallback.restype = ctypes.c_int

    def _audio_callback(self, in_data, frame_count, time_info, status):
        """
        PyAudio callback function for audio playback.

        This function is called by PyAudio when it needs more audio data to play.

        Args:
            in_data: Input audio data (not used in playback).
            frame_count (int): Number of frames requested for playback.
            time_info (dict): Timing information for the callback.
            status (int): Status flags indicating possible errors or other information.

        Returns:
            tuple: A tuple containing the audio data and a flag indicating whether playback is complete.
        """
        audio_data = ctypes.create_string_buffer(frame_count * ctypes.sizeof(ctypes.c_float))
        status = self.audio_lib.playbackCallback(None, audio_data, frame_count, None, 0, None)
        return audio_data.raw, pyaudio.paContinue if status == 0 else pyaudio.paComplete

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
        stream = self.pyaudio.open(
            format=self.pyaudio.get_format_from_width(4), 
            channels=audio_data.info.channels,
            rate=audio_data.info.samplerate,
            output=True,
            stream_callback=self.audio_callback
        )
        stream.start_stream()
        return True

    def close_audio_file(self, audio_data: ctypes.POINTER(AudioData)):
        """
        Close the loaded audio file using the audio library.

        Args:
            audio_data (AudioData): The AudioData structure containing the audio data to close.
        """
        self.pyaudio.terminate()
        self.audio_lib.closeAudioFile(ctypes.byref(audio_data))


def playback_callback(input, output, frame_count, time_info, status_flags, user_data):
    """
    Callback function for audio playback.

    This function is called by the audio library when it needs more audio data to play.

    Args:
        input: Pointer to the input buffer (not used in playback).
        output: Pointer to the output buffer where audio data should be written.
        frame_count (int): Number of frames requested for playback.
        time_info (PaStreamCallbackTimeInfo): Timing information for the callback.
        status_flags (int): Flags indicating possible errors or other information.
        user_data: Pointer to user data provided when the stream was opened.

    Returns:
        int: paContinue if playback should continue, paComplete if playback is complete.
    """
    return AudioWrapper().audio_lib.playbackCallback(input, output, frame_count, ctypes.byref(time_info), status_flags, user_data)