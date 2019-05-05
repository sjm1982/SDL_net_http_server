//http://localhost:88/

#include<stdio.h>
#include<SDL_net.h>

int main(int argc, char *argv[]){
    IPaddress ip;
    TCPsocket accepting,sock;
    const   char    bufsend[]=
        "HTTP/1.1 200 OK\n"
        "Accept-Ranges: bytes\n"
        "Content-Length: 42\n"
        "Connection: Keep-Alive\n"
        "Content-Type: text/html\n"
        "\n"
        "<html><body><p>success</p></body></html>\n";
    if(!SDLNet_Init()){
        if(!SDLNet_ResolveHost(&ip,NULL,88)){
            if((accepting=SDLNet_TCP_Open(&ip))){

                while((sock=SDLNet_TCP_Accept(accepting))==NULL){

                }
                SDLNet_TCP_Close(accepting);
                while(1){
                                SDLNet_TCP_Send(sock,bufsend,sizeof(bufsend));
                                SDL_Delay(100);
                            }
               SDLNet_TCP_Close(sock);
            }
        }
        SDLNet_Quit();
    }
    return  0;
}
