#include "dataconfig.h"
#include<QDebug>
DataConfig::DataConfig(QObject *parent)
    : QObject{parent}
{
    //金币配置为1, 银币为0
    int arr1[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}};
    QVector< QVector<int>>  v;
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr1[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(1, v);


    int arr2[4][4] = {
                     {0, 0, 0, 0},
                     {0, 1, 1, 0},
                     {0, 1, 1, 0},
                     {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr2[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(2, v);

    int arr3[4][4] = {
                      {1, 0, 1, 1},
                      {0, 0, 1, 1},
                      {1, 1, 0, 0},
                      {1, 1, 0, 1}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr3[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(3, v);

    int arr4[4][4] = {
                      {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr4[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(4, v);

    int arr5[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr5[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(5, v);

    int arr6[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr6[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(6, v);

    int arr7[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr7[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(7, v);

    int arr8[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr8[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(8, v);

    int arr9[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr9[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(9, v);

    int arr10[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr10[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(10, v);

    int arr11[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr11[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(11, v);

    int arr12[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr12[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(12, v);

    int arr13[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr13[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(13, v);

    int arr14[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr14[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(14, v);

    int arr15[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr15[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(15, v);

    int arr16[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr16[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(16, v);

    int arr17[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr17[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(17, v);

    int arr18[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr18[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(18, v);

    int arr19[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr19[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(19, v);

    int arr20[4][4] = {
                      {0, 0, 0, 0},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 0, 0}};

    v.clear();
    for(int i = 0; i < 4; ++i)
    {
        QVector<int> v1;
        for(int j = 0; j < 4; ++j)
        {
            v1.push_back(arr20[i][j]);
        }
        v.push_back(v1);
    }
    m_data.insert(20, v);

}
