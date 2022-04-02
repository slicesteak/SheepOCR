# NEU-OCR

## 介绍
这是我们的OCR仓库，里面参考了主流OCR软件的设计，最终开发出令人竖起大拇指的OCR软件

## 需求分析
#### 功能性需求
1.  输入一张通用格式的图片(.jpg .png .gif .tiff)，在桌面输出图片识别结果
2.  对于识别结果，如果不是母语中文，自动翻译成中文（如果做得完的话
3.  支持登录注册，用云端存储用户信息。
4.  支持管理员对用户信息和权限的修改
5.  系统支持悬浮操作，可仅用鼠标完成识别功能

#### 非功能性需求
1.  单次识别结果响应时间在3s内
2.  系统支持识别的图片最大体积至少超过300KB
3.  使用数据库保存用户信息以及设定
4.  若用户担心个人隐私，则使用本地OCR识别（如果可以顺带加上的话
5.  兼容Windows10 和Windows 11，可移植性较好

## 常用的Git命令
每次写代码前建议先pull一遍，然后接着写。结束后先commit到本地，然后再push到远程仓库
git clone https://gitee.com/vfish/neu-ocr.git  
git push https://gitee.com/vfish/neu-ocr.git 或 git push origin
git pull https://gitee.com/vfish/neu-ocr.git 或 git pull origin




