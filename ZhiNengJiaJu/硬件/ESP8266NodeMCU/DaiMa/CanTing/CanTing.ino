#include <Arduino.h>
#include <ESP8266WiFi.h>        // 本程序使用 ESP8266WiFi库
#include <ESP8266WiFiMulti.h>   //  ESP8266WiFiMulti库
#include <ESP8266WebServer.h>   //  ESP8266WebServer库

WiFiClient client;//建立WiFi客户端对象

//固定IP地址
ESP8266WiFiMulti wifiMulti;     // 建立ESP8266WiFiMulti对象,对象名称是'wifiMulti'
ESP8266WebServer esp8266_server(80);// 建立网络服务器对象，该对象用于响应HTTP请求。监听端口（80）
IPAddress local_IP(10, 3, 22, 12); // 设置ESP8266-NodeMCU联网后的IP
IPAddress gateway(10, 3, 22, 254);    // 设置网关IP（通常网关IP是WiFI路由IP）
IPAddress subnet(255, 255, 255, 0);   // 设置子网掩码
IPAddress dns(10, 3, 22, 254);           // 设置局域网DNS的IP（通常局域网DNS的IP是WiFI路由IP）

/* 连接您的WIFI SSID和密码 */·
#define WIFI_SSID         "206"    
#define WIFI_PASSWD       "12345678"

int ZM_CanTing=-1;
int ZM_CanTing_old=-1;

void setup(){
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
    Serial.println("CanTing_esp8266_server,启动");
    
    pinMode(D1, OUTPUT);
    digitalWrite(D1,LOW);
    pinMode(D2, OUTPUT);
    digitalWrite(D2,LOW);
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
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        i++;
        Serial.print("i");
    }
    Serial.println("Connected to AP");
}

void loop() {
    esp8266_server.handleClient();// 处理http服务器访问

    if(ZM_CanTing_old!=ZM_CanTing){
        if(ZM_CanTing==0){
            digitalWrite(D1,LOW);
            digitalWrite(D2,LOW);
        }
        else if(ZM_CanTing==1){
            digitalWrite(D1,HIGH);
            digitalWrite(D2,LOW);
        }
        else if(ZM_CanTing==2){
            digitalWrite(D1,LOW);
            digitalWrite(D2,HIGH);
        }
        else if(ZM_CanTing==3){
            digitalWrite(D1,HIGH);
            digitalWrite(D2,HIGH);
        }
        ZM_CanTing_old=ZM_CanTing;
    }
}

void XiangYing_FWQ(){
    ZM_CanTing=esp8266_server.arg("ZM_CanTing").toInt();
    Serial.print("ZM_CanTing:");
    Serial.println(ZM_CanTing);
}
