#ifndef CANCER_CELL_H
#define CANCER_CELL_H

#include <string>
#include "PrognosisAnalyzer.h"

//�ּ�: ���, �����Լ�, ������ ���
class CancerCell {
protected:
    std::string id;    // ȯ�� ID
    std::string name;  // ȯ�� �̸�
    std::string seq;   // ���⼭��

public:
    //�ּ�: �����ڷ� ȯ�� ���� �ʱ�ȭ
    CancerCell(const std::string& id, const std::string& name, const std::string& seq)
        : id(id), name(name), seq(seq) {}

    //�ּ�: �����Լ� ����ؼ� �� ���� �Ǵ�
    virtual std::string identifyType() = 0;
    //���� �Ҹ���
    virtual ~CancerCell() = default;
};
// ��� ���� �Ǻ�
class LiverCancerCell : public CancerCell {
public:
    //�ּ�: ��ü �������� �θ� Ŭ���� ������ Ȱ��
    using CancerCell::CancerCell;
    std::string identifyType() override;
};
// ��� ����� �Ǻ�
class ColonCancerCell : public CancerCell {
public:
    using CancerCell::CancerCell;
    std::string identifyType() override;
};
// ��� ���� �Ǻ�
class StomachCancerCell : public CancerCell {
public:
    using CancerCell::CancerCell;
    std::string identifyType() override;
};

#endif
