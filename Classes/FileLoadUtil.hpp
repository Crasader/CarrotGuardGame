/** @Copyright   �����ܲ�
*   @author      �½���
*   @date        2018/2/28
*   @brief       �ļ����ظ�������ͷ�ļ�
*/

#pragma once
#ifndef FILE_LOAD_UTIL_HPP
#define FILE_LOAD_UTIL_HPP

#include "cocos2d.h"
#include "StringUtil.h"

/** @brief �ļ����ظ�������ͷ�ļ������ڼ���csv�ļ���Ȼ���䰴�зָ��ȡ����ÿһ�е����ݲ�����ÿһ�ж�Ӧ���ַ�����
*   @author �½���
*/

class FileLoadUtil
{
public:
    /**
    @brief   �ú������ڶ�ȡһ���ļ������ֱ𽫸��ļ�ÿһ�е�������std::vector<std::string>����ʽ���沢���ء�
    @param   FilePath �ļ�·��
    @return  �ָ����ַ�������(StrVec, ��std::vector<std::string>)
    *
    */
    StrVec getDataLines(const std::string& FilePath)
    {
        StrVec res;

        //����Ҳ������ļ���ֱ�ӷ���
        if (!cocos2d::FileUtils::getInstance()->isFileExist(FilePath))
            return res;

        ssize_t pSize = 0; //pSize���ڴ���
        unsigned char* chDatas = cocos2d::FileUtils::getInstance()->getFileData(FilePath, "r", &pSize); //����cocos2d��API�����ظ��ļ����ַ�������

        if (chDatas) //���chDatas��Ϊ�գ���ζ���ļ��иɻ�
            res = StringUtil().split((char*)chDatas, "\n"); //�����и�
        return res; //�������յõ����ַ�����

    }
};
#endif // !FILE_LOAD_UTIL_HPP

