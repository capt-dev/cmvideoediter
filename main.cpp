#include <iostream>
#include <string>
#include <vector>
#include "videoeditor.h"

void PrintHelp() {
    std::cout << "Usage: Cmvideoediter <action> <options>\n\n";
    std::cout << "Actions:\n";
    std::cout << "  cut <inputFile> <outputFile> <startTime> <duration>\n";
    std::cout << "    Cuts a portion of the input video starting at <startTime> with the given <duration>.\n\n";
    std::cout << "  combine <outputFile> <inputFiles...>\n";
    std::cout << "    Combines multiple input video files into a single output file. Provide a list of input files.\n\n";
    std::cout << "  effect <inputFile> <outputFile> <effect>\n";
    std::cout << "    Applies a video effect to the input file and saves the result to the output file.\n\n";
    std::cout << "Options:\n";
    std::cout << "  --help\n";
    std::cout << "    Displays this help message.\n\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <action> <options>" << std::endl;
        return 1;
    }

    std::string action = argv[1];

    if (action == "--help") {
        PrintHelp();
        return 0;
    }

    if (action == "cut") {
        if (argc != 6) {
            std::cerr << "Usage: " << argv[0] << " cut <inputFile> <outputFile> <startTime> <duration>" << std::endl;
            return 1;
        }
        if (VideoEditor::CutVideo(argv[2], argv[3], argv[4], argv[5])) {
            std::cout << "Video cut successfully." << std::endl;
        } else {
            std::cerr << "Error cutting video." << std::endl;
        }
    } else if (action == "combine") {
        if (argc < 4) {
            std::cerr << "Usage: " << argv[0] << " combine <outputFile> <inputFiles...>" << std::endl;
            return 1;
        }
        std::vector<std::string> inputFiles(argv + 3, argv + argc - 1);
        if (VideoEditor::CombineClips(inputFiles, argv[2])) {
            std::cout << "Videos combined successfully." << std::endl;
        } else {
            std::cerr << "Error combining videos." << std::endl;
        }
    } else if (action == "effect") {
        if (argc != 5) {
            std::cerr << "Usage: " << argv[0] << " effect <inputFile> <outputFile> <effect>" << std::endl;
            return 1;
        }
        if (VideoEditor::AddEffect(argv[2], argv[3], argv[4])) {
            std::cout << "Effect added successfully." << std::endl;
        } else {
            std::cerr << "Error adding effect." << std::endl;
        }
    } else {
        std::cerr << "Unknown action: " << action << std::endl;
        return 1;
    }

    return 0;
}
