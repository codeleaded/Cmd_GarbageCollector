#include "/home/codeleaded/System/Static/Library/HttpServer.h"

int main() {
    HttpServer hs = HttpServer_New(8080);
    if(hs.running){
        HttpServer_Listen(&hs);
    }
    HttpServer_Free(&hs);

    return 0;
}
