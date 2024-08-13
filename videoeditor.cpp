#include "videoeditor.h"
#include <cstdlib>
#include <fstream>

bool VideoEditor::CutVideo(const std::string& inputFile, const std::string& outputFile, const std::string& startTime, const std::string& duration, const std::string& additionalOptions) {
    std::string command = "ffmpeg -i " + inputFile + " -ss " + startTime + " -t " + duration + " " + additionalOptions + " " + outputFile;
    return system(command.c_str()) == 0;
}

bool VideoEditor::CombineClips(const std::vector<std::string>& inputFiles, const std::string& outputFile, const std::string& additionalOptions) {
    std::string fileList = "filelist.txt";
    std::ofstream outFile(fileList);
    for (const auto& file : inputFiles) {
        outFile << "file '" << file << "'\n";
    }
    outFile.close();

    std::string command = "ffmpeg -f concat -safe 0 -i " + fileList + " " + additionalOptions + " " + outputFile;
    return system(command.c_str()) == 0;
}

bool VideoEditor::AddEffect(const std::string& inputFile, const std::string& outputFile, const std::string& effect, const std::string& additionalOptions) {
    std::string command = "ffmpeg -i " + inputFile + " -vf " + effect + " " + additionalOptions + " " + outputFile;
    return system(command.c_str()) == 0;
}

bool VideoEditor::ChangeFormat(const std::string& inputFile, const std::string& outputFile, const std::string& audioCodec, const std::string& videoCodec, const std::string& additionalOptions) {
    std::string command = "ffmpeg -i " + inputFile + " -c:a " + audioCodec + " -c:v " + videoCodec + " " + additionalOptions + " " + outputFile;
    return system(command.c_str()) == 0;
}
