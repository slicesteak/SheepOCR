// OCR-test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include<json/json.h>
#include"ocr.h"
#include<CURL/curl.h>
using namespace std;
using namespace Json;

int main()
{
    std::cout << "Hello World!\n";
    // 设置APPID/AK/SK
    std::string app_id = "25882743";
    std::string api_key = "6rkXHclKC0LKkSsm4GZTlySz";
    std::string secret_key = "tISesOCtKxrIyjMD5uHpnubxgkhBm6fW";

    aip::Ocr client(app_id, api_key, secret_key);

    Json::Value result;

    std::string image;
    aip::get_file_content("C:/Users/lenov/Desktop/大数据作业1.png", &image);

    // 调用通用文字识别, 图片参数为本地图片
    result = client.general_basic(image, aip::null);

    // 如果有可选参数
    std::map<std::string, std::string> options;
    options["language_type"] = "CHN_ENG";
    options["detect_direction"] = "true";
    options["detect_language"] = "true";
    options["probability"] = "true";

    // 带参数调用通用文字识别, 图片参数为本地图片
    result = client.general_basic(image, options);
    int n = result["words_result_num"].asInt();
    cout << "total is " << n << endl;
    for (int i = 0; i < n; i++)  // 遍历数组  
    {
        cout<<result["words_result"][i]["words"].asString();
    }

    /*Json::Value result;

    std::string url = "C:\Users\lenov\Desktop>";

     调用通用文字识别, 图片参数为远程url图片
    result = client.general_basic_url(url, aip::null);

     如果有可选参数
    std::map<std::string, std::string> options;
    options["language_type"] = "CHN_ENG";
    options["detect_direction"] = "true";
    options["detect_language"] = "true";
    options["probability"] = "true";

     带参数调用通用文字识别, 图片参数为远程url图片
    result = client.general_basic_url(url, options);*/
    return 0;


}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
