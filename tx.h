#ifndef TX_H_
#define TX_H_



#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
using namespace std ;

    struct sockaddr_rc addr = { 0 };

    int s, status;
    

    //functions declaration

    int Tx_setup();

    int Tx_send(char Data);

 //functions definations

    int Tx_setup(){


    	 	float data ;
  
            //set receiving device Mac address 
        	char dest[18] = "98:D3:33:80:91:F0";
           // allocate a socket
           s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

           // set the connection parameters (who to connect to)
           addr.rc_family = AF_BLUETOOTH;
           addr.rc_channel = (uint8_t) 1; // specify the Bluetooth address and port number to connect to,
           str2ba( dest, &addr.rc_bdaddr );  

           // connect to HC05
           status = connect(s, (struct sockaddr *)&addr, sizeof(addr));
           if(status){
                                perror(" failed to connect the device!\n");
                      }
                       if( status == 0 ) return status ; // return 0 if connection established


            }


    int Tx_send(char Data){


               // send a message

                   status = write(s, Data,1);  //send data type ,data,data length 
                   perror("I'm sending ");




               return status;  //return 0 if data is sent 
            }





#endif /* TX_H_ */