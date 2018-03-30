/** @Copyright   �����ܲ�
*   @author      �½���
*   @date        2018/2/28 
*   @brief       �ַ���������ͷ�ļ�
*/

#pragma once
#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include<vector>

#ifndef StrVec
#define StrVec std::vector<std::string> //�궨��StrVec��string����
#endif // !1StrVec

class StringUtil
{
public:
    /**
    @brief   �ú������ڷָ��ַ����������ָ���
    @param   ��һ������target����Ҫ�и���ַ���, �ڶ�������rSSeq�Ƿָ���
    @return  �ָ����ַ�������(StrVec, ��std::vector<std::string>)
    *
    */
    StrVec split(const std::string& target, const std::string& rSSeq)
    {
        StrVec stringList;
        int size = target.size();
        std::string str_temp(target);
        int startIndex = 0, endIndex = 0;
        endIndex = str_temp.find(rSSeq);
        std::string splitStr = "";
        while (endIndex > 0)
        {
            splitStr = str_temp.substr(startIndex, endIndex);
            stringList.push_back(splitStr);
            str_temp = std::string(str_temp.substr(endIndex + 1), size);
            endIndex = str_temp.find(rSSeq);
        }
        if (str_temp != "")
            stringList.push_back(str_temp);

        return stringList;
    }
};

#endif // !STRINGUTIL_H
