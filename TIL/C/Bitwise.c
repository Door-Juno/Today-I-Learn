#include <stdio.h>

// Lab04-4
void check_students(char a, char b, char c){
    int x = 0x3FFFFFF;
    x &= ~( 1<< (a - 'A'));
    x &= ~( 1<< (b - 'A'));
    x &= ~( 1<< (c - 'A'));
    printf("%07x\n", x);
}

void hd(char a, char b){
    unsigned char c = a ^ b ; 
    int hd = 0;
    for ( int i = 0 ; i < sizeof(c)*8 ; i ++){
        hd += (c & ( 1 << i )) ? 1 : 0 ; 
    }
    printf("%d",hd);
}


int main() {
    check_students('A','B','C');

}