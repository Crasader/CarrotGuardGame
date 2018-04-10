/** @Copyright   �����ܲ�
*   @author      �½���
*   @date        2018/2/28
*   @brief       CSV����ļ�����cpp�ļ�
*/

#include "CsvUtil.h"
#include "FileLoadUtil.hpp"
#include "StringUtil.h"

CsvUtil* CsvUtil::_gInstance;


int CsvUtil::findVal(const std::string & targetValue, const int & col, const std::string & FilePath)
{
    int rowNum = std::get<0>(getFileRowColNum(FilePath));
    int res = -1;
    for (int i = 0; i < rowNum; ++i)
    {
        if (getStr(i, col, FilePath) == targetValue)
        {
            res = i;
            return res;
        }
    }
    return res;
}

StrDict & CsvUtil::getFileDict(const std::string & FilePath)
{
    return _pCsvMap->at(FilePath);
}

CsvUtil::~CsvUtil()
{
    CC_SAFE_DELETE(_pCsvMap);
}

CsvUtil::CsvUtil()
{
    _pCsvMap = new CsvMap();
}

CsvUtil * CsvUtil::getInstance()
{
    if (!_gInstance)
        _gInstance = new CsvUtil();
    return _gInstance;
}

void CsvUtil::destroyInstance()
{
    if (_gInstance)
        CC_SAFE_DELETE(_gInstance);
}

void CsvUtil::addFileData(const std::string& FilePath) //����һ���ļ����ֵ���
{
    if (FilePath == "") return;

    auto linesVec = FileLoadUtil().getDataLines(FilePath); //����FileLoadUtil().getDataLines ������һ���н��зָ�
    StrVec strvec;
    StrDict dict;
    StringUtil stringUtil;
    for (const auto& lineIter4Vec : linesVec) //����ÿһ���ַ������Զ���Ϊ�ָ����ٷָ�һ��
    {
        strvec = stringUtil.split(lineIter4Vec, ",");
        dict.push_back(strvec); //�ָ����ַ��������Ž�dict��
    }
    _pCsvMap->insert(std::make_pair(std::string(FilePath), dict)); //�����ļ�����dict�Ķ�Ӧ��ϵ����������Ĳ��ҡ�ɾ������
}

void CsvUtil::releaseFile(const std::string & FilePath)
{
    _pCsvMap->erase(FilePath); //ֱ�Ӳ�������
}

std::string CsvUtil::getStr(const int & rRow, const int & rCol, const std::string & FilePath)
{
    const auto tDict = getFileDict(FilePath);
    const auto lineData = tDict.at(rRow);
    return lineData.at(rCol);
}

int CsvUtil::getInt(const int & rRow, const int & rCol, const std::string & FilePath)
{
    return atoi(getStr(rRow, rCol, FilePath).c_str());
}

double CsvUtil::getDouble(const int & rRow, const int & rCol, const std::string & FilePath)
{
    return atof(getStr(rRow, rCol, FilePath).c_str());
}

StrVec CsvUtil::getRowData(const int & rRow, const std::string & FilePath)
{
    auto tRow = std::get<0>(getFileRowColNum(FilePath));
    if (rRow > tRow)
        return StrVec(); //����һ���յ�����
    return _pCsvMap->at(FilePath).at(rRow);
}


std::tuple<int, int> CsvUtil::getFileRowColNum(const std::string & FilePath)
{
    const auto tDict = getFileDict(FilePath);
    int rowNum = tDict.size();
    int colNum = (*tDict.begin()).size(); //bug fixed
    return std::make_tuple(rowNum, colNum);
}



