# Author:Eric
# -*- codeing = utf-8 -*-
# @Time : 2023-04-09 10:58
# @Author : 86136
# @File : TuiYan1.py
# @Software: PyCharm

import threading  # 导入线程模块
import cv2
import wiringpi
from wiringpi import GPIO
import time

KaiMen_flag = 0


# 准备识别的图片，识别模块
def face_ShiBie(image, names, MoXing_date, face_ShiBieQi):
    global KaiMen_flag
    hui_du = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)  # 转换为灰度
    # face_ShiBieQi = cv2.CascadeClassifier('/home/orangepi/WaiBao/14/MoXing/haarcascade_frontalface_alt2.xml')  # 加载识别器
    face = face_ShiBieQi.detectMultiScale(hui_du)  # 进行检测
    for x, y, w, h in face:  # 框出人脸
        # cv2.rectangle(image, (x, y), (x + w, y + h), color=(0, 0, 255), thickness=2)
        cv2.circle(image, center=(x + w // 2, y + h // 2), radius=w // 2, color=(0, 255, 0), thickness=2)
        # 人脸识别
        ids, ping_fen = MoXing_date.predict(hui_du[y:y + h, x:x + w])  # 预测和评分
        if (100 - ping_fen) < 60:  # 评分较高，可疑人员
            cv2.putText(image, 'unkonw', (x + 10, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0, 255, 0), 1)
            print("unkonw")
        else:
            cv2.putText(image, str(names[ids - 1]) + ":" + str(100 - ping_fen), (x + 10, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0, 255, 0), 1)
            print(str(names[ids - 1]), ":", 100 - ping_fen)
            KaiMen_flag = 1
    cv2.imshow('xian_shi', image)
    cv2.waitKey(1)


def main1():
    cap = cv2.VideoCapture("/dev/video10")
    names = ['tai', 'nan']
    print(names)

    # 加载训练数据文件
    MoXing_date = cv2.face.LBPHFaceRecognizer_create()

    # 加载数据
    MoXing_date.read('/home/orangepi/WaiBao/14/MoXing/MoXing.yml')

    face_ShiBieQi = cv2.CascadeClassifier('/home/orangepi/WaiBao/14/MoXing/haarcascade_frontalface_alt2.xml')  # 加载识别器

    while True:
        flag, zhen = cap.read()
        if not flag:
            break
        face_ShiBie(zhen, names, MoXing_date, face_ShiBieQi)

    cap.release()
    cv2.destroyAllWindows()


def main2():
    global KaiMen_flag
    # GPIO引脚
    wiringpi.wiringPiSetup()  # 初始化所有GPIO引脚
    wiringpi.pinMode(5, GPIO.OUTPUT)  # 配置GPIO wPi 5 引脚作为输出模式
    wiringpi.digitalWrite(5, GPIO.HIGH)
    while True:
        if KaiMen_flag == 1:
            wiringpi.digitalWrite(5, GPIO.LOW)
            time.sleep(0.25)
            wiringpi.digitalWrite(5, GPIO.HIGH)
            KaiMen_flag = 0
            time.sleep(2)
        else:
            wiringpi.digitalWrite(5, GPIO.HIGH)


if __name__ == '__main__':
    main_1 = threading.Thread(target=main1)
    main_2 = threading.Thread(target=main2)

    main_1.start()
    main_2.start()
