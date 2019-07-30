#include<stdio.h>
#include<net.h>

int main(int argc, char **argv){
    printf("%s start\n",*argv);

    udpService(1314);
    
    printf("%s close\n",*argv);
    return 0;
}