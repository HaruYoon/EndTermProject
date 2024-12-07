#include "CancerCell.h"
// 주석: CancerCell의 파생 클래스에서 가상 함수 identifyType 구현부
std::string LiverCancerCell::identifyType() {
    if (seq.find("TERT") != std::string::npos && seq.find("AXIN1") != std::string::npos) // TERT와 AXIN1 문자열 모두 발견시 간암으로 판별
        return "Liver Cancer";
    return "Unknown";
}

std::string ColonCancerCell::identifyType() {
    if (seq.find("CTNNB1") != std::string::npos && seq.find("APC") != std::string::npos) // CTNNB1와 APC 문자열 모두 발견시 대장암으로 판별
        return "Colon Cancer";
    return "Unknown";
}

std::string StomachCancerCell::identifyType() {
    if (seq.find("CDH1") != std::string::npos && seq.find("APC") != std::string::npos) // CDH1와 APC 문자열 모두 발견시 위암으로 판별
        return "Stomach Cancer";
    return "Unknown";
}
