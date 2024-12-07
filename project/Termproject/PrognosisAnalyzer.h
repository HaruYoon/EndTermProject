#ifndef PROGNOSIS_ANALYZER_H
#define PROGNOSIS_ANALYZER_H

#include <string>
#include <vector>

//�ּ�: �߻� Ŭ���� PrognosisAnalyzer ���
class PrognosisAnalyzer {
public:
    //�ּ�: ���� �Լ� analyze() ���
    virtual std::string analyze(const std::string& seq) = 0;
    //�ּ�: ���� �Ҹ���
    virtual ~PrognosisAnalyzer() = default;
};
//���� ������ �������� ���⼭�� ���
class Prognosis : public PrognosisAnalyzer {
private:
    std::vector<std::string> mutations = { "TP53", "KRAS", "BRAF", "RHOA", "SMAD4" };
//�ּ�: �Լ� �ߺ� analyze() �߻� Ŭ���� �޼��� ������
public:
    std::string analyze(const std::string& seq) override;
};
//���ļӵ� ������ �������� ���⼭�� ���
class GrowthRate : public PrognosisAnalyzer {
private:
    std::vector<std::string> mutations = { "FGFR2", "PIK3CA", "CTNNB1", "EGFR", "MYC" };
public:
    std::string analyze(const std::string& seq) override;
};
//�ߺ��ñ� ������ �������� ���⼭�� ���
class EarlyOnset : public PrognosisAnalyzer {
private:
    std::vector<std::string> mutations = { "CDH1", "ARID1A", "MLH1", "BRCA1", "STK11" };
public:
    std::string analyze(const std::string& seq) override;
};

#endif
