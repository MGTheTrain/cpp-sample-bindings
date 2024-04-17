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

class AudioWrapper:
    def __init__(self, path: str):
        self.audio_lib = ctypes.cdll.LoadLibrary(path)

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

    def load_audio_file(self, filename, audio_data):
        return self.audio_lib.loadAudioFile(filename.encode('utf-8'), ctypes.byref(audio_data))

    def start_playback(self, audio_data):
        return self.audio_lib.startPlayback(ctypes.byref(audio_data))

    def close_audio_file(self, audio_data):
        return self.audio_lib.closeAudioFile(ctypes.byref(audio_data))

class AudioData(ctypes.Structure):
    _fields_ = [
        ("file", ctypes.c_void_p),
        ("info", SF_INFO),
        ("stream", ctypes.c_void_p)
    ]

class PaStreamCallbackTimeInfo(ctypes.Structure):
    _fields_ = [
        ("inputBufferAdcTime", ctypes.c_double),
        ("currentTime", ctypes.c_double),
        ("outputBufferDacTime", ctypes.c_double)
    ]

class SF_INFO(ctypes.Structure):
    _fields_ = [
        ("frames", ctypes.c_int),
        ("samplerate", ctypes.c_int),
        ("channels", ctypes.c_int),
        ("format", ctypes.c_int),
        ("sections", ctypes.c_int),
        ("seekable", ctypes.c_int)
    ]

def playback_callback(input, output, frame_count, time_info, status_flags, user_data):
    return AudioWrapper().audio_lib.playbackCallback(input, output, frame_count, ctypes.byref(time_info), status_flags, user_data)