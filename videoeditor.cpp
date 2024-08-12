#include "videoeditor.h"
#include <cstdlib> // for system()
#include <fstream>

bool VideoEditor::CutVideo(const std::string& inputFile, const std::string& outputFile, const std::string& startTime, const std::string& duration) {
    std::string command = "ffmpeg -i " + inputFile + " -ss " + startTime + " -t " + duration + " -c copy " + outputFile;
    return system(command.c_str()) == 0;
}

bool VideoEditor::CombineClips(const std::vector<std::string>& inputFiles, const std::string& outputFile) {
    std::string fileList = "filelist.txt";
    std::ofstream outFile(fileList);
    for (const auto& file : inputFiles) {
        outFile << "file '" << file << "'\n";
    }
    outFile.close();

    std::string command = "ffmpeg -f concat -safe 0 -i " + fileList + " -c copy " + outputFile;
    return system(command.c_str()) == 0;
}

bool VideoEditor::AddEffect(const std::string& inputFile, const std::string& outputFile, const std::string& effect) {
    std::string command = "ffmpeg -i " + inputFile + " -vf " + effect + " " + outputFile;
    return system(command.c_str()) == 0;
}
