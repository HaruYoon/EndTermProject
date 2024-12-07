#ifndef CANCER_CELL_H
#define CANCER_CELL_H

#include <string>
#include "PrognosisAnalyzer.h"

//주석: 상속, 가상함수, 다형성 사용
class CancerCell {
protected:
    std::string id;    // 환자 ID
    std::string name;  // 환자 이름
    std::string seq;   // 염기서열

public:
    //주석: 생성자로 환자 정보 초기화
    CancerCell(const std::string& id, const std::string& name, const std::string& seq)
        : id(id), name(name), seq(seq) {}

    //주석: 가상함수 사용해서 암 유형 판단
    virtual std::string identifyType() = 0;
    //가상 소멸자
    virtual ~CancerCell() = default;
};
// 상속 간암 판별
class LiverCancerCell : public CancerCell {
public:
    //주석: 객체 생성에서 부모 클래스 생성자 활용
    using CancerCell::CancerCell;
    std::string identifyType() override;
};
// 상속 대장암 판별
class ColonCancerCell : public CancerCell {
public:
    using CancerCell::CancerCell;
    std::string identifyType() override;
};
// 상속 위암 판별
class StomachCancerCell : public CancerCell {
public:
    using CancerCell::CancerCell;
    std::string identifyType() override;
};

#endif
