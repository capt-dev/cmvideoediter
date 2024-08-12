#ifndef VIDEOEDITOR_H
#define VIDEOEDITOR_H

#include <string>
#include <vector>

class VideoEditor {
public:
    static bool CutVideo(const std::string& inputFile, const std::string& outputFile, const std::string& startTime, const std::string& duration);
    static bool CombineClips(const std::vector<std::string>& inputFiles, const std::string& outputFile);
    static bool AddEffect(const std::string& inputFile, const std::string& outputFile, const std::string& effect);
};

#endif // VIDEOEDITOR_H
