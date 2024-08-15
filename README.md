# Cmvideoediter

`Cmvideoediter` is a command-line-based video editor designed for use with Termux. It allows users to perform basic video editing tasks such as cutting, combining, and applying effects to video files directly from the terminal.

## Features
- **Cut Video**: Extract a specific portion of a video.
- **Combine Videos**: Merge multiple video files into one.
- **Apply Effects**: Add visual effects to videos.

## Installation

To compile and install `Cmvideoediter`, follow these steps:

### Prerequisites
Make sure you have the following dependencies installed:
- `clang`
- `ffmpeg`
- `make`
- `cmake`
- `pkg-config`
- `git`
they can be installed via
```sh
apt update && apt upgrade && apt install clang ffmpeg make cmake pkg-config git
```
### Build
1. Clone the repository:
```sh
git clone https://github.com/capt-dev/cmvideoediter.git && cd cmvideoediter
```
2. build the program:
```sh
mkdir build && cd build && cmake ..
```
3. Compile the program:
```sh
make
```
4. install the program:
```sh
make install
```
# Usage
Run cmvideoediter from the terminal with the following syntax:
### cmvideoediter <action> <options>
# Actions
### Cut:
### cmvideoediter cut <inputFile> <outputFile> <startTime> <duration> <other_ffmpeg_options>
Cuts a portion of the input video starting at <startTime> with the given <duration>.
### Combine:
### cmvideoediter combine <outputFile> <inputFiles...> <other_ffmpeg_options>
Combines multiple input video files into a single output file. Provide a list of input files.
### Effect:
### cmvideoediter effect <inputFile> <outputFile> <effect> <other_ffmpeg_options>
Applies a video effect to the input file and saves the result to the output file.
### changing Codec:
### change-format <inputFile> <outputFile> --audio=<audioCodec> --video=<videoCodec> <other_ffmpeg_options>
Changes the format of the input file, specifying audio and video codecs.
### Options --help: Displays the help message.
# License
This project is licensed under the MIT License. See the LICENSE file for details.
