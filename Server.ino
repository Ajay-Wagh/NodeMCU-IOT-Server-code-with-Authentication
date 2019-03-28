#include<ESP8266WiFi.h>
#include<WiFiClient.h>
WiFiServer server(80);
String s;
char b[500];
WiFiClient client;
//String p="HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n<head>\r\n<title>AjayIOT</title>\r\n</head>\r\n<body text=\"red\"> <form method=\"post\" action=\"http://192.168.4.1/ledon\"><pre><center><h1>ControlPanel</h1></center>                             <h3> LED :  <input type=\"submit\" value=\"Turn ON\" > </h3></pre></body>\r\n</html>\r\n";
void setup()
{
  WiFi.mode(WIFI_AP);
  Serial.begin(115200);
  WiFi.softAP("AjayIOT","ajayajay");
  Serial.println("created");
  Serial.println(WiFi.softAPIP());
  server.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  
}
void loop()
{
  client = server.available();
  while(!client.available());
  if(client)
  {
    Serial.println("client connected...");
    while(!client.available());
    if (checkbuff())
    {
      Serial.println(s);
      checkbuff();
      if(s.indexOf("Name=a%40s.co&pass=ajay",350)!=(-1))
      {
        checkbuff();
        client.write("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n<head>\r\n<title>AjayIOT</title>\r\n</head>\r\n<body text=\"red\"> <form  action=\"http://192.168.4.1/ledon\"><pre><center><h1>ControlPanel</h1></center>                             <h3> LED :  <input type=\"submit\" value=\"Turn ON\" > </h3></pre></body>\r\n</html>\r\n");
        checkbuff();
      }
      else if(s.indexOf("ledon")!=(-1))
      {
        digitalWrite(LED_BUILTIN,HIGH);
        checkbuff();
        client.write("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n<head>\r\n<title>AjayIOT</title>\r\n</head>\r\n<body text=\"red\"> <form  action=\"http://192.168.4.1/ledoff\"><pre><center><h1>ControlPanel</h1></center>                             <h3> LED :  <input type=\"submit\" value=\"Turn OFF\" > </h3></pre></body>\r\n</html>\r\n");
        checkbuff();
        checkbuff();
      }
      else if(s.indexOf("ledoff")!=(-1))
      {
        checkbuff();
        checkbuff();
        digitalWrite(LED_BUILTIN,LOW);
        checkbuff();
        client.write("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n<head>\r\n<title>AjayIOT</title>\r\n</head>\r\n<body text=\"red\"> <form  action=\"http://192.168.4.1/ledon\"><pre><center><h1>ControlPanel</h1></center>                             <h3> LED :  <input type=\"submit\" value=\"Turn ON\" > </h3></pre></body>\r\n</html>\r\n");
        checkbuff();
      }
      else
      {
        client.write("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n<head>\r\n<title>SmartCook</title>\r\n</head>\r\n<body text=\"gray\">\r\n<marquee><h1>  .  .  .  .  .        WELCOME TO IOT PORTAL       .  .  .  .  .  </h1></marquee><br><br><center><font face=\"Times New Roman\" size=\"+5\" color=\"#ff0000\">Authentication Required : </font></center> <hr width=\"50%\" size=\"3\" /><br><br><br><center><form method=\"post\"> User : <input type=\"email\" maxlength=\"10\" name=\"Name\" value=\"\" size=\"15\"></center><br><br><center> Pass : <input type=\"password\" name=\"pass\" value=\"\" size=\"15\"></center> <br>  <br> <center><input type=\"submit\" value=\"LogMeIn\"></center>\r\n</form></body>\r\n</html>\r\n");
        checkbuff();
      }
      client.readString();
      checkbuff();
      client.flush();
      checkbuff();
    }
     checkbuff();
  }
 }


 int checkbuff()
 {
  if(client.available())
  {
    s=client.readString();
    return 1;
  }
  return 0;
 }
