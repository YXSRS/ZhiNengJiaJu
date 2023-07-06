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

int i=0;

// Create an instance of the cursor passing in the connection
MySQL_Cursor cur = MySQL_Cursor(&conn);
//固定IP地址
ESP8266WiFiMulti wifiMulti;     // 建立ESP8266WiFiMulti对象,对象名称是'wifiMulti'
ESP8266WebServer esp8266_server(80);// 建立网络服务器对象，该对象用于响应HTTP请求。监听端口（80）
IPAddress local_IP(10, 3, 22, 19); // 设置ESP8266-NodeMCU联网后的IP
IPAddress gateway(10, 3, 22, 254);    // 设置网关IP（通常网关IP是WiFI路由IP）
IPAddress subnet(255, 255, 255, 0);   // 设置子网掩码
IPAddress dns(10, 3, 22, 254);           // 设置局域网DNS的IP（通常局域网DNS的IP是WiFI路由IP）

/* 连接您的WIFI SSID和密码 */
#define WIFI_SSID         "206"    
#define WIFI_PASSWD       "12345678"

int AF_MenSuo=-1;
int AF_MenSuo_old=-1;
int MenSuo_ZhuangTai=-1;
int last=-1;

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
    Serial.println("MenSuo_esp8266_server,启动");

    
    pinMode(D1, OUTPUT);
    digitalWrite(D1,LOW);
    pinMode(D2, INPUT_PULLUP);

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
    delay(1);
    if(AF_MenSuo_old!=AF_MenSuo){
        if(AF_MenSuo==0){
            digitalWrite(D1,LOW);
        }
        else if(AF_MenSuo==1){
            digitalWrite(D1,HIGH);
        }
        Serial.println("a");
        AF_MenSuo_old=AF_MenSuo;
        
    }
    //Post_MenSuo_ZhuangTai();
    bool pin;
    i++;
    if(i>=10){
        i=0;
        pin=digitalRead(D2);
        if(pin==HIGH){
            MenSuo_ZhuangTai=1;
        }
        else{
            MenSuo_ZhuangTai=0;
        }
    }
    Serial.print("MenSuo_ZhuangTai:");
    Serial.println(MenSuo_ZhuangTai);

    if(last!=MenSuo_ZhuangTai)
    {
      last=MenSuo_ZhuangTai;
      PostData();
    }
    else{
        delay(100);
        //Serial.println("1) Demonstrating using a cursor dynamically allocated.");
        // Initiate the query class instance
        MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
        // Execute the query
        char sql[100];
        sprintf(sql,"SELECT KeTing FROM zhaoming_biao;");
        //sql="update anfang_biao set ShiNei_WenDu="+String(ShiNei_WenDu)+", ShiNei_ShiDu="+String(ShiNei_ShiDu)+" where id=1;";
        cur_mem->execute(sql);
        delete cur_mem;
        Serial.println("查询OK");
        delay(100);
    }
}

void XiangYing_FWQ(){
    AF_MenSuo=esp8266_server.arg("AF_MenSuo").toInt();
    Serial.print("AF_MenSuo:");
    Serial.println(AF_MenSuo);
}

void Post_MenSuo_ZhuangTai(){
    //static int i=0;
    bool pin;
    i++;
    if(i>=2200){
        i=0;
        pin=digitalRead(D2);
        if(pin==HIGH){
            MenSuo_ZhuangTai=1;
        }
        else{
            MenSuo_ZhuangTai=0;
        }
        //Serial.print("MenSuo_ZhuangTai:");
        //Serial.println(MenSuo_ZhuangTai);
    }
}

void PostData(){
    delay(100);

    //Serial.println("1) Demonstrating using a cursor dynamically allocated.");
    // Initiate the query class instance
    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
    // Execute the query
    char sql[100];
    sprintf(sql,"update anfang_biao set MenSuo=%d where id=1;",MenSuo_ZhuangTai);
    //sql="update anfang_biao set ShiNei_WenDu="+String(ShiNei_WenDu)+", ShiNei_ShiDu="+String(ShiNei_ShiDu)+" where id=1;";
    cur_mem->execute(sql);
    delete cur_mem;
    delay(100);
}
