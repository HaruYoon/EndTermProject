#ifndef PROGNOSIS_ANALYZER_H
#define PROGNOSIS_ANALYZER_H

#include <string>
#include <vector>

//주석: 추상 클래스 PrognosisAnalyzer 사용
class PrognosisAnalyzer {
public:
    //주석: 가상 함수 analyze() 사용
    virtual std::string analyze(const std::string& seq) = 0;
    //주석: 가상 소멸자
    virtual ~PrognosisAnalyzer() = default;
};
//예후 조건인 돌연변이 염기서열 목록
class Prognosis : public PrognosisAnalyzer {
private:
    std::vector<std::string> mutations = { "TP53", "KRAS", "BRAF", "RHOA", "SMAD4" };
//주석: 함수 중복 analyze() 추상 클래스 메서드 재정의
public:
    std::string analyze(const std::string& seq) override;
};
//증식속도 조건인 돌연변이 염기서열 목록
class GrowthRate : public PrognosisAnalyzer {
private:
    std::vector<std::string> mutations = { "FGFR2", "PIK3CA", "CTNNB1", "EGFR", "MYC" };
public:
    std::string analyze(const std::string& seq) override;
};
//발병시기 조건인 돌연변이 염기서열 목록
class EarlyOnset : public PrognosisAnalyzer {
private:
    std::vector<std::string> mutations = { "CDH1", "ARID1A", "MLH1", "BRCA1", "STK11" };
public:
    std::string analyze(const std::string& seq) override;
};

#endif
