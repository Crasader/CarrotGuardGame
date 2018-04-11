/** @Copyright   �����ܲ�
*   @author      �½���
*   @date        2018/2/28
*   @brief       CSV����ļ�����ͷ�ļ�
*/
#pragma once
#ifndef CSV_UTIL_H
#define CSV_UTIL_H

#include<vector>
#include<map>
#include<string>

typedef std::vector<std::string> StrVec;
typedef std::vector<StrVec> StrDict;
typedef std::map<std::string, StrDict> CsvMap;

class CsvUtil
{
public:
    /**
    @brief   ��ȡ��ʵ��
    @return  һ��ʵ��ָ��
    */
    static CsvUtil* getInstance();

    /**
    @brief   ���ٵ�ǰʵ��
    */
    static void destroyInstance();

    /**
    @brief             ����һ���ļ����ֵ���
    @param FilePath    �ļ�·��
    */
    virtual void addFileData(const std::string& FilePath);

    /**
    @brief              �ͷ��ļ������ֵ���ɾ�����ļ���Ӧ������
    @param FilePath     �ļ�·��
    */
    virtual void releaseFile(const std::string& FilePath);

    /**
    @brief           ��ĳ��csv�ļ��ж�ȡĳһ��ĳһ�е�����

    @param rRow      Ŀ������
    @param rCol      Ŀ������
    @param FilePath  �ļ�·��

    @return          �ɷ����ַ���std::string���������ݺ͸���������
    */
    virtual std::string getStr(const int& rRow, const int& rCol, const std::string &FilePath);
    virtual int getInt(const int& rRow, const int& rCol, const std::string &FilePath);
    virtual double getDouble(const int& rRow, const int& rCol, const std::string &FilePath);

    /**
    @brief           ��ȡһ���е�����
    @param rRow      Ŀ������
    @param FilePath  �ļ�·��
    */
    virtual StrVec getRowData(const int& rRow, const std::string& FilePath);

    /**
    @brief            ��ȡ���ļ�������������
    @param FilePath   �ļ�·��
    @return           һ��Ԫ�飬��һ�������������ڶ�����������
    */
    virtual std::tuple<int, int> getFileRowColNum(const std::string &FilePath);

    /**
    @brief               ��ĳ��csv�ļ���ĳһ����Ѱ��һ��ֵ����Ѱ�ҳɹ������ض�Ӧ������
    @param targetValue   Ŀ��ֵ
    @param col           ���ҷ�Χ
    @param FilePath      �ļ�·��
    @return              ��ֵ��Ӧ������
    */
    virtual int findVal(const std::string &targetValue, const int &col, const std::string &FilePath);

protected:
    /**
    @brief            ��ȡĳcsv�ļ���Ӧ��StrDict
    @param FilePath   �ļ�·��
    @return           �ļ���Ӧ��StrDict
    */
    virtual StrDict &getFileDict(const std::string &FilePath);
    virtual ~CsvUtil();

private:
    CsvUtil();  //�����������ⲿʹ�ù��캯������ʵ����
    CsvUtil(const CsvUtil &) = delete; //�������ƹ���
    CsvUtil &operator=(const CsvUtil&) = delete; //������ֵ


    static CsvUtil* _gInstance;
    CsvMap* _pCsvMap;
};

#endif //CSV_UTIL_H