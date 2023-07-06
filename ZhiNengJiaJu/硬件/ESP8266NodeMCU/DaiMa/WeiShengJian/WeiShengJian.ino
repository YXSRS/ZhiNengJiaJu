#include <Arduino.h>
#include <ESP8266WiFi.h>        // 本程序使用 ESP8266WiFi库
#include <ESP8266WiFiMulti.h>   //  ESP8266WiFiMulti库
#include <ESP8266WebServer.h>   //  ESP8266WebServer库

#include <MySQL_Connection.h>    // Arduino连接Mysql的库
#include <MySQL_Cursor.h>

WiFiClient client;//建立WiFi客户端对象
MySQL_Connection conn(&client);
MySQL_Cursor* cursor;    // 创建一个游标
IPAddress server_addr(39,103,177,201);   // 安装Mysql
char user[] = "root";              // Mysql的用户名
char password[] = "gccgcc";        // 登陆Mysql的密码

// Create an instance of the cursor passing in the connection
MySQL_Cursor cur = MySQL_Cursor(&conn);

//固定IP地址
ESP8266WiFiMulti wifiMulti;     // 建立ESP8266WiFiMulti对象,对象名称是'wifiMulti'
ESP8266WebServer esp8266_server(80);// 建立网络服务器对象，该对象用于响应HTTP请求。监听端口（80）
IPAddress local_IP(10, 3, 22, 17); // 设置ESP8266-NodeMCU联网后的IP
IPAddress gateway(10, 3, 22, 254);    // 设置网关IP（通常网关IP是WiFI路由IP）
IPAddress subnet(255, 255, 255, 0);   // 设置子网掩码
IPAddress dns(10, 3, 22, 254);           // 设置局域网DNS的IP（通常局域网DNS的IP是WiFI路由IP）

/* 连接您的WIFI SSID和密码 */
#define WIFI_SSID         "206"    
#define WIFI_PASSWD       "12345678"

int ZM_WeiShengJian = -1;
int ZM_WeiShengJian_old = -1;
int AF_CO = -1;
int AF_PaiQiShan = -1;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);          // 启动串口通讯
    delay(10);
    Serial.println("");
    // 初始化 wifi
    wifiInit(WIFI_SSID, WIFI_PASSWD);
    Serial.println(WiFi.SSID());              // 连接的WiFI名称
    Serial.print("IP address:\t");            // 以及
    Serial.println(WiFi.localIP());           // NodeMCU的IP地址

    esp8266_server.on("/FWQ",XiangYing_FWQ);
    esp8266_server.begin();
    Serial.println("WeiShengJian_esp8266_server,启动");

    pinMode(D1, OUTPUT);
    digitalWrite(D1, LOW);
    pinMode(D2, OUTPUT);
    digitalWrite(D2, LOW);
    pinMode(D5, INPUT); // 一氧化碳
    pinMode(D6, OUTPUT);  // 排气扇
    digitalWrite(D6, LOW);

    if (conn.connect(server_addr, 3306, user, password,"zhineng_jiaju_yuancheng_kongzhi"))         // 连接数据库
    {
        Serial.println("成功连接数据库---OK.");   
    }else{
        Serial.println("连接数据库失败---FAILED.");
    }
    cursor = new MySQL_Cursor(&conn);    // 创建一个数据库游标实例
}

// 初始化 wifi 连接
void wifiInit(const char *ssid, const char *passphrase)
{
    // 设置开发板网络环境
    if (!WiFi.config(local_IP, gateway, subnet)) {
        Serial.println("Failed to ESP8266 IP"); 
    } 
    WiFi.mode(WIFI_AP_STA);
    WiFi.begin(ssid, passphrase);
    int i=0;
    while (WiFi.status() != WL_CONNECTED){
        delay(1000);
        i++;
        Serial.print("i");
    }
    Serial.println("Connected to AP");
}

void loop() {
    // put your main code here, to run repeatedly:
    esp8266_server.handleClient();// 处理http服务器访问

    if(ZM_WeiShengJian_old != ZM_WeiShengJian){
        if(ZM_WeiShengJian == 0){
            digitalWrite(D1,LOW);
            digitalWrite(D2,LOW);
        }
        else if(ZM_WeiShengJian == 1){
            digitalWrite(D1,HIGH);
            digitalWrite(D2,LOW);
        }
        else if(ZM_WeiShengJian == 2){
            digitalWrite(D1,LOW);
            digitalWrite(D2,HIGH);
        }
        else if(ZM_WeiShengJian == 3){
            digitalWrite(D1,HIGH);
            digitalWrite(D2,HIGH);
        }
        ZM_WeiShengJian_old = ZM_WeiShengJian;
    }
    AF_WeiShengJian();

}

void XiangYing_FWQ(){
    ZM_WeiShengJian = esp8266_server.arg("ZM_WeiShengJian").toInt();
    Serial.print("ZM_WeiShengJian:");
    Serial.println(ZM_WeiShengJian);
}

void AF_WeiShengJian(){
    static int i=0;
    i++;
    if(i>=2200){
        i=0;
        AF_CO = digitalRead(D5);
        Serial.print("AF_CO:");
        Serial.println(AF_CO);

        if(AF_CO == 0){  // 如果检测到有CO
            digitalWrite(D6, 1);  // D6给高电平，打开排气扇
            AF_PaiQiShan = 1;
            Serial.print("AF_PaiQiShan:");
            Serial.println(AF_PaiQiShan);
        }else {
            digitalWrite(D6, 0);
            AF_PaiQiShan = 0;
            Serial.print("AF_PaiQiShan:");
            Serial.println(AF_PaiQiShan);
        }
        PostData();
    }
}

void PostData(){
    delay(100);

    Serial.println("1) Demonstrating using a cursor dynamically allocated.");
    // Initiate the query class instance
    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
    // Execute the query
    char sql[100];
    sprintf(sql,"update anfang_biao set CO=%d, PaiQiShan=%d where id=1;", !AF_CO, AF_PaiQiShan);
    //sql="update anfang_biao set ShiNei_WenDu="+String(ShiNei_WenDu)+", ShiNei_ShiDu="+String(ShiNei_ShiDu)+" where id=1;";
    cur_mem->execute(sql);
    delete cur_mem;
    delay(100);
}
