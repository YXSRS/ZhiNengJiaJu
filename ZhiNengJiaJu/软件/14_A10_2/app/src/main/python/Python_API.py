import pymysql
from sqlalchemy import create_engine
import pandas as pd

config = {
    'host': '39.103.177.201',  # 域名
    'port': 3306,  # 端口号
    'user': 'root',
    'password': 'gccgcc',  # 密码
    'database': 'anquan_jiashi',  # 数据库名
    'charset': 'utf8mb4',  # 字符编码
    'cursorclass': pymysql.cursors.Cursor,  # 选择 Cursor 类型
}

IP = "39.103.177.201"
DuanKouHao = "3306"
YongHu = "root"
MiMa = "gccgcc"
ShuJuKu_Ming = "zhineng_jiaju_yuancheng_kongzhi"
charset = "utf8mb4"

zhaoming_biao = "zhaoming_biao"
nuantong_biao = "nuantong_biao"
anfang_biao = "anfang_biao"


# 照明灯源独立开关
# 参数：
#     qu_yu：区域
#     zhuang_tai：灯源的状态
def ZhaoMing_DengYuan_DuLi_KaiGuan(qu_yu, zhuang_tai):
    global config
    global ShuJuKu_Ming
    global zhaoming_biao

    conn = pymysql.connect(**config)  # 连接数据库
    conn.select_db(ShuJuKu_Ming)  # 定位到数据库的表
    cur = conn.cursor()  # 建立连接

    sql = "update " + zhaoming_biao + " set " + qu_yu + "=" + str(zhuang_tai) + " where id=1;"
    cur.executemany(sql, [()])  # 数据
    cur.close()
    conn.commit()
    conn.close()


# 照明灯源一键开关
# 参数：
#     zhuang_tai：灯源的状态
def ZhaoMing_DengYuan_YiJian_KaiGuan(zhuang_tai):
    global config
    global ShuJuKu_Ming
    global zhaoming_biao

    conn = pymysql.connect(**config)  # 连接数据库
    conn.select_db(ShuJuKu_Ming)  # 定位到数据库的表
    cur = conn.cursor()  # 建立连接

    sql = "update " + zhaoming_biao + " set KeTing=" + zhuang_tai + ", CanTing=" + zhuang_tai + ", ZhuWo=" + zhuang_tai + ", CiWo=" + zhuang_tai + ", ShuFang=" + zhuang_tai + ", ChuFang=" + zhuang_tai + ", WeiShengJian=" + zhuang_tai + " where id=1;"
    cur.executemany(sql, [()])  # 数据
    cur.close()
    conn.commit()
    conn.close()


# 获取照明数据
# 返回值;
#     str：客厅,餐厅,主卧,次卧,书房,厨房,卫生间
def get_ZhaoMing_ShuJu():
    global YongHu
    global MiMa
    global IP
    global DuanKouHao
    global ShuJuKu_Ming
    global charset
    global zhaoming_biao

    # 创建数据库连接对象
    db = pymysql.connect(host=IP,
                         user=YongHu,
                         password=MiMa,
                         database=ShuJuKu_Ming)
    # 创建游标对象
    cursor = db.cursor()

    sql = "SELECT * FROM " + zhaoming_biao
    str1 = ""
    try:
        cursor.execute(sql)  # 执行sql语句，也可执行数据库命令，如：show tables
        result = cursor.fetchall()  # 所有结果
        # print(result)
        str1 = str(result[0][1]) + "," + str(result[0][2]) + "," + str(result[0][3]) + "," + str(result[0][4]) + "," + str(result[0][5]) + "," + str(result[0][6]) + "," + str(
            result[0][7])
        cursor.close()  # 关闭当前游标
        db.close()  # 关闭数据库连接
        return str1
    except Exception as e:
        db.rollback()
        cursor.close()  # 关闭当前游标
        db.close()  # 关闭数据库连接
        print("查询失败")
        print(e)


# 获取暖通数据
# 返回值;
#     str：客厅,主卧,次卧,书房
def get_NuanTong_ShuJu():
    global YongHu
    global MiMa
    global IP
    global DuanKouHao
    global ShuJuKu_Ming
    global charset
    global nuantong_biao

    # 创建数据库连接对象
    db = pymysql.connect(host=IP,
                         user=YongHu,
                         password=MiMa,
                         database=ShuJuKu_Ming)
    # 创建游标对象
    cursor = db.cursor()

    sql = "SELECT * FROM " + nuantong_biao
    str1 = ""
    try:
        cursor.execute(sql)  # 执行sql语句，也可执行数据库命令，如：show tables
        result = cursor.fetchall()  # 所有结果
        # print(result)
        str1 = str(result[0][1]) + "," + str(result[0][2]) + "," + str(result[0][3]) + "," + str(result[0][4])
        cursor.close()  # 关闭当前游标
        db.close()  # 关闭数据库连接
        return str1
    except Exception as e:
        db.rollback()
        cursor.close()  # 关闭当前游标
        db.close()  # 关闭数据库连接
        print("查询失败")
        print(e)


# 暖通独立控制
# 参数：
#     qu_yu：区域
#     zhuang_tai：空调的状态
def NuanTong_DuLi_KongZhi(qu_yu, zhuang_tai):
    global config
    global ShuJuKu_Ming
    global nuantong_biao

    conn = pymysql.connect(**config)  # 连接数据库
    conn.select_db(ShuJuKu_Ming)  # 定位到数据库的表
    cur = conn.cursor()  # 建立连接

    sql = "update " + nuantong_biao + " set " + qu_yu + "=" + str(zhuang_tai) + " where id=1;"
    cur.executemany(sql, [()])  # 数据
    cur.close()
    conn.commit()
    conn.close()


# 暖通一键控制
# 参数：
#     NuanTong_KeTing_ShuJu：暖通客厅数据
#     NuanTong_ZhuWo_ShuJu：暖通主卧数据
#     NuanTong_CiWo_ShuJu：暖通次卧数据
#     NuanTong_ShuFang_ShuJu：暖通书房数据
def NuanTong_YiJian_KongZhi(NuanTong_KeTing_ShuJu, NuanTong_ZhuWo_ShuJu, NuanTong_CiWo_ShuJu, NuanTong_ShuFang_ShuJu):
    global config
    global ShuJuKu_Ming
    global nuantong_biao

    conn = pymysql.connect(**config)  # 连接数据库
    conn.select_db(ShuJuKu_Ming)  # 定位到数据库的表
    cur = conn.cursor()  # 建立连接

    sql = "update " + nuantong_biao + " set KeTing=" + str(NuanTong_KeTing_ShuJu) + ", ZhuWo=" + str(NuanTong_ZhuWo_ShuJu) + ", CiWo=" + str(
        NuanTong_CiWo_ShuJu) + ", ShuFang=" + str(NuanTong_ShuFang_ShuJu) + " where id=1;"
    cur.executemany(sql, [()])  # 数据
    cur.close()
    conn.commit()
    conn.close()


# 获取安防数据
# 返回值;
#     str：门锁,CO,雨滴,火焰,室内温度,室内湿度,排气扇,窗户,灭火器.家居电器1,家居电器2
def get_AnFang_ShuJu():
    global YongHu
    global MiMa
    global IP
    global DuanKouHao
    global ShuJuKu_Ming
    global charset
    global anfang_biao

    # 创建数据库连接对象
    db = pymysql.connect(host=IP,
                         user=YongHu,
                         password=MiMa,
                         database=ShuJuKu_Ming)
    # 创建游标对象
    cursor = db.cursor()

    sql = "SELECT * FROM " + anfang_biao
    str1 = ""
    try:
        cursor.execute(sql)  # 执行sql语句，也可执行数据库命令，如：show tables
        result = cursor.fetchall()  # 所有结果
        # print(result)
        str1 = str(result[0][1]) + "," + str(result[0][2]) + "," + str(result[0][3]) + "," + str(result[0][4]) + "," + str(result[0][5]) + "," + str(result[0][6]) + "," + str(
            result[0][7]) + "," + str(result[0][8]) + "," + str(result[0][9])+ "," + str(result[0][10]) + "," + str(result[0][11])
        cursor.close()  # 关闭当前游标
        db.close()  # 关闭数据库连接
        return str1
    except Exception as e:
        db.rollback()
        cursor.close()  # 关闭当前游标
        db.close()  # 关闭数据库连接
        print("查询失败")
        print(e)


# 安防控制
# 参数：
#     qu_yu：区域
#     zhuang_tai：状态
def AnFang_KongZhi(qu_yu, zhuang_tai):
    global config
    global ShuJuKu_Ming
    global anfang_biao

    conn = pymysql.connect(**config)  # 连接数据库
    conn.select_db(ShuJuKu_Ming)  # 定位到数据库的表
    cur = conn.cursor()  # 建立连接

    sql = "update " + anfang_biao + " set " + qu_yu + "=" + str(zhuang_tai) + " where id=1;"
    cur.executemany(sql, [()])  # 数据
    cur.close()
    conn.commit()
    conn.close()