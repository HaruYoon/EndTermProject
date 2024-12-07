#include "PrognosisAnalyzer.h"

//특정 돌연변이들 개수를 계산한다.
int countMutations(const std::string& seq, const std::vector<std::string>& mutations) {
    int count = 0;
//for문을 순회하면서 염기서열에 존재하는지 확인한다
    for (const auto& mut : mutations) {
        if (seq.find(mut) != std::string::npos) {
            count++;
        }
    }
    return count; //개수를 반환
}

//개수에 따라서 결과 판단
//주석: 함수 중복, 상속, 가상 함수
std::string Prognosis::analyze(const std::string& seq) {
    int count = countMutations(seq, mutations);
    if (count == 0) return "좋음";
    else if (count <= 2) return "나쁨";
    return "매우 나쁨";
}

std::string GrowthRate::analyze(const std::string& seq) {
    int count = countMutations(seq, mutations);
    if (count == 0) return "느림";
    else if (count <= 2) return "빠름";
    return "매우 빠름";
}

std::string EarlyOnset::analyze(const std::string& seq) {
    int count = countMutations(seq, mutations);
    if (count == 0) return "낮음";
    else if (count <= 2) return "중간";
    return "높음";
}
