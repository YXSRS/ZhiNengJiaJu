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
IPAddress local_IP(10, 3, 22, 10); // 设置ESP8266-NodeMCU联网后的IP
IPAddress gateway(10, 3, 22, 254);    // 设置网关IP（通常网关IP是WiFI路由IP）
IPAddress subnet(255, 255, 255, 0);   // 设置子网掩码
IPAddress dns(10, 3, 22, 254);           // 设置局域网DNS的IP（通常局域网DNS的IP是WiFI路由IP）

const char* host_KeTing="10.3.22.11";
const char* host_CanTing="10.3.22.12";
const char* host_ZhuWo="10.3.22.13";
const char* host_CiWo="10.3.22.14";
const char* host_ShuFang="10.3.22.15";
const char* host_ChuFang="10.3.22.16";
const char* host_WeiShengJian="10.3.22.17";
const char* host_MenSuo="10.3.22.19";
const int httpPort=80;

/* 连接您的WIFI SSID和密码 */
#define WIFI_SSID         "206"    
#define WIFI_PASSWD       "12345678"

String ZM_KeTing;
String ZM_CanTing;
String ZM_ZhuWo;
String ZM_CiWo;
String ZM_ShuFang;
String ZM_ChuFang;
String ZM_WeiShengJian;
String NT_KeTing;
String NT_ZhuWo;
String NT_CiWo;
String NT_ShuFang;
String AF_MenSuo;
String AF_ChuangHu;
String AF_JiaJuDianQi1;
String AF_JiaJuDianQi2;

void setup(){
    Serial.begin(115200);          // 启动串口通讯
    delay(10);
    Serial.println("");
    // 初始化 wifi
    wifiInit(WIFI_SSID, WIFI_PASSWD);
    Serial.println(WiFi.SSID());              // 连接的WiFI名称
    Serial.print("IP address:\t");            // 以及
    Serial.println(WiFi.localIP());           // NodeMCU的IP地址

    if (conn.connect(server_addr, 3306, user, password,"zhineng_jiaju_yuancheng_kongzhi"))         // 连接数据库
    {
        //isConnection=1;
        Serial.println("成功连接数据库---OK.");   
    }else{
        //isConnection=0;
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
    WiFi.mode(WIFI_STA);
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
    GetData_ZhaoMing1();
    GetData_ZhaoMing2();
    GetData_NuanTong();
    GetData_AnFang();
    wifiClientRequest_KeTing();
    wifiClientRequest_CanTing();
    wifiClientRequest_ZhuWo();
    wifiClientRequest_CiWo();
    wifiClientRequest_ShuFang();
    wifiClientRequest_ChuFang();
    wifiClientRequest_WeiShengJian();
    wifiClientRequest_MenSuo();
}

void GetData_ZhaoMing1(){
    row_values *row = NULL;
    delay(10);

    Serial.println("1) Demonstrating using a cursor dynamically allocated.");
    // Initiate the query class instance
    //KeTing,CanTing,ZhuWo,CiWo,ShuFang,ChuFang,WeiShengJian
    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
    // Execute the query
    cur_mem->execute("SELECT KeTing,CanTing,ZhuWo,CiWo,ShuFang FROM zhaoming_biao;");
    // Fetch the columns (required) but we don't use them.
    column_names *columns = cur_mem->get_columns();

    // Read the row (we are only expecting the one)
    do {
        row = cur_mem->get_next_row();
        if (row != NULL) {
            ZM_KeTing = atol(row->values[0]);
            ZM_CanTing= atol(row->values[1]);
            ZM_ZhuWo= atol(row->values[2]);
            ZM_CiWo= atol(row->values[3]);
            ZM_ShuFang= atol(row->values[4]);
        }
    } while (row != NULL);
    // Deleting the cursor also frees up memory used
    delete cur_mem;
    Serial.println("GetData_ZhaoMing1:");
    Serial.print(ZM_KeTing);
    Serial.print(" ");
    Serial.print(ZM_CanTing);
    Serial.print(" ");
    Serial.print(ZM_ZhuWo);
    Serial.print(" ");
    Serial.print(ZM_CiWo);
    Serial.print(" ");
    Serial.println(ZM_ShuFang);
    delay(10);
}

void GetData_ZhaoMing2(){
    row_values *row = NULL;
    delay(10);

    Serial.println("1) Demonstrating using a cursor dynamically allocated.");
    // Initiate the query class instance
    //KeTing,CanTing,ZhuWo,CiWo,ShuFang,ChuFang,WeiShengJian
    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
    // Execute the query
    cur_mem->execute("SELECT ChuFang,WeiShengJian FROM zhaoming_biao;");
    // Fetch the columns (required) but we don't use them.
    column_names *columns = cur_mem->get_columns();

    // Read the row (we are only expecting the one)
    do {
        row = cur_mem->get_next_row();
        if (row != NULL) {
            ZM_ChuFang = atol(row->values[0]);
            ZM_WeiShengJian= atol(row->values[1]);
        }
    } while (row != NULL);
    // Deleting the cursor also frees up memory used
    delete cur_mem;
    Serial.println("GetData_ZhaoMing2:");
    Serial.print(ZM_ChuFang);
    Serial.print(" ");
    Serial.println(ZM_WeiShengJian);
    delay(10);
}

void GetData_NuanTong(){
    row_values *row = NULL;
    delay(10);

    Serial.println("1) Demonstrating using a cursor dynamically allocated.");
    // Initiate the query class instance
    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
    // Execute the query
    //KeTing,ZhuWo,CiWo,ShuFang
    cur_mem->execute("SELECT KeTing,ZhuWo,CiWo,ShuFang FROM nuantong_biao;");
    // Fetch the columns (required) but we don't use them.
    column_names *columns = cur_mem->get_columns();

    // Read the row (we are only expecting the one)
    do {
        row = cur_mem->get_next_row();
        if (row != NULL) {
            NT_KeTing = atol(row->values[0]);
            NT_ZhuWo= atol(row->values[1]);
            NT_CiWo= atol(row->values[2]);
            NT_ShuFang= atol(row->values[3]);
        }
    } while (row != NULL);
    // Deleting the cursor also frees up memory used
    delete cur_mem;
    Serial.println("GetData_NuanTong:");
    Serial.print(NT_KeTing);
    Serial.print(" ");
    Serial.print(NT_ZhuWo);
    Serial.print(" ");
    Serial.print(NT_CiWo);
    Serial.print(" ");
    Serial.println(NT_ShuFang);
    delay(10);
}

void GetData_AnFang(){
    row_values *row = NULL;
    delay(10);

    Serial.println("1) Demonstrating using a cursor dynamically allocated.");
    // Initiate the query class instance
    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
    // Execute the query
    cur_mem->execute("SELECT MenSuo,ChuangHu,JiaJu_DianQi1,JiaJu_DianQi2 FROM anfang_biao;");
    // Fetch the columns (required) but we don't use them.
    column_names *columns = cur_mem->get_columns();

    // Read the row (we are only expecting the one)
    do {
        row = cur_mem->get_next_row();
        if (row != NULL) {
            AF_MenSuo = atol(row->values[0]);
            AF_ChuangHu= atol(row->values[1]);
            AF_JiaJuDianQi1= atol(row->values[2]);
            AF_JiaJuDianQi2= atol(row->values[3]);
        }
    } while (row != NULL);
    // Deleting the cursor also frees up memory used
    delete cur_mem;
    Serial.println("GetData_AnFang:");
    Serial.print(AF_MenSuo);
    Serial.print(" ");
    Serial.print(AF_ChuangHu);
    Serial.print(" ");
    Serial.print(AF_JiaJuDianQi1);
    Serial.print(" ");
    Serial.println(AF_JiaJuDianQi2);
    delay(10);
}

//向客厅请求
void wifiClientRequest_KeTing(){
    WiFiClient client1;//建立WiFi客户端对象
    if(client1.connect(host_KeTing, httpPort)){
        String url="?ZM_KeTing="+String(ZM_KeTing)+"&NT_KeTing="+String(NT_KeTing);

        // 建立客户端请求信息
        String httpRequest =  String("GET /FWQ") +url+ " HTTP/1.1\r\n" +
            "Host: " + host_KeTing + "\r\n" +
            "Connection: close\r\n" +
            "\r\n";
    
        // 发送客户端请求
        client1.print(httpRequest);
        //client.stop();    // 停止客户端
        Serial.println("KeTing_OK");
    }
    else{
        Serial.println("KeTing_NO");
    }
}

//向餐厅请求
void wifiClientRequest_CanTing(){
    WiFiClient client1;//建立WiFi客户端对象
    if(client1.connect(host_CanTing, httpPort)){
        String url="?ZM_CanTing="+String(ZM_CanTing);

        // 建立客户端请求信息
        String httpRequest =  String("GET /FWQ") +url+ " HTTP/1.1\r\n" +
            "Host: " + host_CanTing + "\r\n" +
            "Connection: close\r\n" +
            "\r\n";
    
        // 发送客户端请求
        client1.print(httpRequest);
        //client.stop();    // 停止客户端
        Serial.println("CanTing_OK");
    }
    else{
        Serial.println("CanTing_NO");
    }
}

//向主卧请求
void wifiClientRequest_ZhuWo(){
  WiFiClient client1;//建立WiFi客户端对象
    if(client1.connect(host_ZhuWo, httpPort)){
        String url="?ZM_ZhuWo="+String(ZM_ZhuWo)+"&NT_ZhuWo="+String(NT_ZhuWo)+"&AF_ChuangHu="+String(AF_ChuangHu)+"&AF_JiaJuDianQi1="+String(AF_JiaJuDianQi1);

        // 建立客户端请求信息
        String httpRequest =  String("GET /FWQ") +url+ " HTTP/1.1\r\n" +
            "Host: " + host_ZhuWo + "\r\n" +
            "Connection: close\r\n" +
            "\r\n";
    
        // 发送客户端请求
        client1.print(httpRequest);
        //client.stop();    // 停止客户端
        Serial.println("ZhuWo_OK");
    }
    else{
        Serial.println("ZhuWo_NO");
    }
}

//向次卧请求
void wifiClientRequest_CiWo(){
    WiFiClient client1;//建立WiFi客户端对象
    if(client1.connect(host_CiWo, httpPort)){
        String url="?ZM_CiWo="+String(ZM_CiWo)+"&NT_CiWo="+String(NT_CiWo)+"&AF_JiaJuDianQi2="+String(AF_JiaJuDianQi2);

        // 建立客户端请求信息
        String httpRequest =  String("GET /FWQ") +url+ " HTTP/1.1\r\n" +
            "Host: " + host_CiWo + "\r\n" +
            "Connection: close\r\n" +
            "\r\n";
    
        // 发送客户端请求
        client1.print(httpRequest);
        //client.stop();    // 停止客户端
        Serial.println("CiWo_OK");
    }
    else{
        Serial.println("CiWo_NO");
    }
}

//向书房请求
void wifiClientRequest_ShuFang(){
    WiFiClient client1;//建立WiFi客户端对象
    if(client1.connect(host_ShuFang, httpPort)){
        String url="?ZM_ShuFang="+String(ZM_ShuFang)+"&NT_ShuFang="+String(NT_ShuFang);

        // 建立客户端请求信息
        String httpRequest =  String("GET /FWQ") +url+ " HTTP/1.1\r\n" +
            "Host: " + host_ShuFang + "\r\n" +
            "Connection: close\r\n" +
            "\r\n";
    
        // 发送客户端请求
        client1.print(httpRequest);
        //client.stop();    // 停止客户端
        Serial.println("ShuFang_OK");
    }
    else{
        Serial.println("ShuFang_NO");
    }
}

//向厨房请求
void wifiClientRequest_ChuFang(){
    WiFiClient client1;//建立WiFi客户端对象
    if(client1.connect(host_ChuFang, httpPort)){
        String url="?ZM_ChuFang="+String(ZM_ChuFang);

        // 建立客户端请求信息
        String httpRequest =  String("GET /FWQ") +url+ " HTTP/1.1\r\n" +
            "Host: " + host_ChuFang + "\r\n" +
            "Connection: close\r\n" +
            "\r\n";
    
        // 发送客户端请求
        client1.print(httpRequest);
        //client.stop();    // 停止客户端
        Serial.println("ChuFang_OK");
    }
    else{
        Serial.println("ChuFang_NO");
    }
}

//向卫生间请求
void wifiClientRequest_WeiShengJian(){
    WiFiClient client1;//建立WiFi客户端对象
    if(client1.connect(host_WeiShengJian, httpPort)){
        String url="?ZM_WeiShengJian="+String(ZM_WeiShengJian);

        // 建立客户端请求信息
        String httpRequest =  String("GET /FWQ") +url+ " HTTP/1.1\r\n" +
            "Host: " + host_WeiShengJian + "\r\n" +
            "Connection: close\r\n" +
            "\r\n";
    
        // 发送客户端请求
        client1.print(httpRequest);
        //client.stop();    // 停止客户端
        Serial.println("WeiShengJian_OK");
    }
    else{
        Serial.println("WeiShengJian_NO");
    }
}

//向门锁请求
void wifiClientRequest_MenSuo(){
    WiFiClient client1;//建立WiFi客户端对象
    if(client1.connect(host_MenSuo, httpPort)){
        String url="?AF_MenSuo="+String(AF_MenSuo);

        // 建立客户端请求信息
        String httpRequest =  String("GET /FWQ") +url+ " HTTP/1.1\r\n" +
            "Host: " + host_MenSuo + "\r\n" +
            "Connection: close\r\n" +
            "\r\n";
    
        // 发送客户端请求
        client1.print(httpRequest);
        //client.stop();    // 停止客户端
        Serial.println("MenSuo_OK");
    }
    else{
        Serial.println("MenSuo_NO");
    }
}