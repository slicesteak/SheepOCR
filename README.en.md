# SheepOCR

#### Description
SheepOCR, an OCR software developed by our team, combined with [Baidu cloud AI open platform](https://ai.baidu.com/tech/ocr/) and [Huawei cloud database](https://activity.huaweicloud.com/) according to the contents learned in the software engineering, users can provide online text extraction function. It is simple and beautiful, easy to expand and easy to use. While meeting the basic OCR use requirements, it optimizes the use experience as much as possible.

In terms of design, the classic panel design is adopted. After users log in, they choose the functions they need to use here. Enter the file path and click identify to complete the basic operation.
![](./README_imgs/主面板.png)

In order to simplify user operation and reduce screen space, we also designed the suspended ball mode. The levitation ball is a sheep like a cloud, and users can drag it to any position. Double click the lamb to use the screenshot function for subsequent identification. Right click the lamb to select other functions.
![](./README_imgs/最小化2.png)  ![](./README_imgs/最小化3.png)

In terms of development, loosely coupled development makes it possible for subsequent expansion. We encapsulate each function into a module separately. Whenever there is a new change, it will not affect other modules. It is easy to add, delete or modify. If we have a chance in the future, we will add more functions to it.

#### Installation
To compile and run our software, we need to configure the compilation environment. If you want to experience our lamb baa OCR immediately, you can directly install the release version of our software. We have packaged the program, but the installed version only supports running on windows.

#### How to build
If you want to compile and run from the source code, make sure to configure the following environment:
- This project is developed based on QT 5.14.2. When compiling and running, please ensure that the QT version is greater than or equal to 5.14.2.
- This software sends the request with HTTPS, so you need to install OpenSSL library. Click [here](https://www.openssl.org/) to download. (if QT is installed through Downloader, you can also download QT from```...(QT installation directory)/Qt/tools/mingw730_ In the 64/opt/bin``` directory, put the ```libeay32 DLL``` and ```ssleay32.dll```  to the generation directory
- This software takes MySQL database as the storage part. Please copy from the ```(MySQL installation directory)/lib/libmysql.dll```  into the build directory. Click [here](https://blog.csdn.net/ysyut/article/details/108038100?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165081046816782390548548%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=165081046816782390548548&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-7-108038100.142%5ev9%5epc_search_result_cache,157%5ev4%5econtrol&utm_term=qt%E9%85%8D%E7%BD%AEmysql&spm=1018.2226.3001.4187) for detailed configuration information

#### Runtime Notice
the online database is  supported until 4:30 on May 10, 2022. If you run this program before this date, you can directly use the following account:

- Account：vfish  | password：myOCR666
- Account：xuexue | password：123456
- Account：Sugi  | password：13579alsk
- Account：lan  | password：lan123456
- Account：ljm | password：ljm

Of course, if you don't want to register and log in, you can choose "guest mode" to enter directly.
