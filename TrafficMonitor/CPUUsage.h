#pragma once
#include <Pdh.h>
#include <PdhMsg.h>

class CCPUUsage
{
public:
    CCPUUsage()
    {}

    ~CCPUUsage()
    {}

    void SetUseCPUTimes(bool use_get_system_times);		//设置获取CPU利用率的方式，是通过GetSystemTimes还是Pdh
    int GetCPUUsage();

private:
    int GetCPUUsageByGetSystemTimes();
    int GetCPUUsageByPdh();

private:
    bool m_use_get_system_times{ true };		//是否使用GetSysTime这个API来获取CPU利用率

    PDH_RAW_COUNTER m_last_rawData{};//保存计算CPU使用率的上一次数据
    bool m_first_get_CPU_utility{ true };

    FILETIME m_preidleTime{};
    FILETIME m_prekernelTime{};
    FILETIME m_preuserTime{};

};

class CCpuFreq
{
public:
    CCpuFreq();
    ~CCpuFreq();
    bool Initialize();

    // 调用此函数获取CPU频率。
    // 注意：第二次调用此函数开始才能获取到值，两次调用的时间不应过短，最好大于200毫秒
    bool GetCpuFreq(float& freq);

private:
    float max_cpu_freq = 0;
    HQUERY query = nullptr;
    HCOUNTER counter = nullptr;
    bool isInitialized = false;
};
