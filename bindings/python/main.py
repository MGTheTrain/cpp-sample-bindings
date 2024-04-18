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

import argparse
import os

from core_wrapper import CoreWrapper
from audio_wrapper import AudioWrapper, AudioData

def main(path, wrapper_type, audio_file_path):
    """
    Main function to demonstrate the usage of wrapper libraries.

    Args:
        path (str): Path to the wrapper library.
        wrapper_type (str): Type of wrapper to use: 'core' or 'audio'.
        audio_file_path (str): Path to the audio file (required if wrapper_type is 'audio').
    """
    abs_path = os.path.realpath(path)

    if wrapper_type == 'core':
        core_wr = CoreWrapper(abs_path)

        result_add = core_wr.add(10, 5)
        print("Addition result:", result_add)

        result_subtract = core_wr.subtract(10, 5)
        print("Subtraction result:", result_subtract)

        result_multiply = core_wr.multiply(10, 5)
        print("Multiplication result:", result_multiply)

        result_divide = core_wr.divide(10.0, 2.0)
        print("Division result:", result_divide)

        radius = 5.0

        area = core_wr.get_circle_area(radius)
        print("Circle area:", area)

        circumference = core_wr.get_circle_circumference(radius)
        print("Circle circumference:", circumference)
    elif wrapper_type == 'audio':
        audio_wr = AudioWrapper(abs_path)
        
        audio_data = AudioData()
        if not audio_wr.load_audio_file(audio_file_path, audio_data):
            print("Failed to load audio file:", audio_file_path)
            return
    
        if not audio_wr.start_playback(audio_data):
            print("Failed to start playback.")
            return

        audio_wr.close_audio_file(audio_data)
    else:
        print("Unsupported wrapper type provided.")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Process some integers.')
    parser.add_argument('--path', type=str, help='Path to the wrapper library')
    parser.add_argument('--wrapper', type=str, choices=['core', 'audio'], help='Select wrapper type: core or audio')
    parser.add_argument('--audio_file_path', type=str, help='Path to the audio file')
    args = parser.parse_args()

    if not args.path:
        parser.error('Please provide the path to the wrapper library using --path')
    if not args.wrapper:
        parser.error('Please select the wrapper type using --wrapper')
    if args.wrapper == 'audio' and not args.audio_file_path:
        parser.error('Please provide the path to the audio file using --audio_file_path')

    main(args.path, args.wrapper, args.audio_file_path)
