#include <stdio.h>
#include <math.h>
#define true 1
#define false 0
typedef unsigned long long long_t ;

// Lab04-4
void check_students(char a, char b, char c){
    int x = 0x3FFFFFF;
    x &= ~( 1<< (a - 'A'));
    x &= ~( 1<< (b - 'A'));
    x &= ~( 1<< (c - 'A'));
    printf("%07x\n", x);
}

// Lab04-05
void hd(char a, char b){
    unsigned char c = a ^ b ; 
    int hd = 0;
    for ( int i = 0 ; i < sizeof(c)*8 ; i ++){
        hd += (c & ( 1 << i )) ? 1 : 0 ; 
    }
    printf("%d",hd);
}

//lab06-02
void bitcount_two(long_t N){
    int leading = true , one = 0 , zero = 0 ;
    for ( int i = 63 ; i >= 0 ; i --){
        int bit =  (N>>i)&1;
        if(leading && bit == 0 ) 
            continue ;
        leading = false ; 
        (bit) ? one ++ : zero ++ ;
    }
    printf("%d\n", one);
    printf("%d\n", zero);
}

//Lab06-03
void bitcount_three(long_t N){
    int maxCount = 0 , curCount=0;

   while( N != 0 ){
        if( N & 1 ) {
            curCount++;
            if(curCount > maxCount){
                maxCount = curCount;
            }   
        }
        else{
            curCount = 0 ;
        }
        N >>= 1 ;
    }
    printf("%d\n",maxCount);
}


int main() {
    check_students('A','B','C');
    hd('A','B');
    bitcount_two(33);
    bitcount_three(222);
}
