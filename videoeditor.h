#ifndef VIDEOEDITOR_H
#define VIDEOEDITOR_H

#include <string>
#include <vector>

class VideoEditor {
public:
    static bool CutVideo(const std::string& inputFile, const std::string& outputFile, const std::string& startTime, const std::string& duration, const std::string& additionalOptions = "");
    static bool CombineClips(const std::vector<std::string>& inputFiles, const std::string& outputFile, const std::string& additionalOptions = "");
    static bool AddEffect(const std::string& inputFile, const std::string& outputFile, const std::string& effect, const std::string& additionalOptions = "");
    static bool ChangeFormat(const std::string& inputFile, const std::string& outputFile, const std::string& audioCodec, const std::string& videoCodec, const std::string& additionalOptions = "");
};

#endif // VIDEOEDITOR_H
