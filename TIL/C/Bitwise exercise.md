# Bitwise Operation 연습문제 풀어보기  
### 1.출석체크  
수강생들에게 A, B, C, … , Z 까지 고유 코드를 부여하고,
A는 2^0, B는 2^1, C는 2^2, … , Z 는 2^25 의 값으로 각 학생의 고유번호를 관리하기로 했다.  
<u>수강생들은 매번 3명이 결석한다.</u>  
교수는 출석학생의 고유번호의 합을 그 수업의 출석번호로 기록한다.  세 명의 학생이 결석을 한  수업의 출석번호를 출력하여라.   

**#입력**  
첫번째 줄에 결석한 세 학새의 고유 코드가 알파벳 대문자로 주어진다.  

**#출력**  
출석번호를 16진수로 출력한다.  
***
**Thinking**  
- 모든 학생이 출석한 경우에서 a,b,c를 빼면 될거같음.   
    2^25 = 0x3FFFFFF
- 비트 변환을 이용하여 문제를 풀수있지 않을까 ?   
```cpp 
    x &= ~( 1<< (a - 'A')); 
    // x & a번째 비트만 0 ( ... 111101111...)
    // 즉 위 식으로 a-'A'번째 비트만 0으로 바꿀수있음.
```  
**Solve Code**
```cpp
#include <stdio.h>

int main() {
    char a,b,c ;
    scanf("%c %c %c", &a, &b, &c);
    int x = 0x3FFFFFF;
    x &= ~( 1<< (a - 'A'));
    x &= ~( 1<< (b - 'A'));
    x &= ~( 1<< (c - 'A'));
    printf("%07x\n", x);
}
```
***
### 2.Hamming Distance  
해밍 거리는 두 이진수의 서로 다른 비트의 개수이다.  
hd(0101,0011) = 2 이다.  
**#입력**  
첫 번째 줄에 두개의 알파벳 문자가 주어진다.

**#출력**  
두 알파벳 문자의 ASCII code값으로 해밍거리를 계산하여 출력하시오.
***
**Thinking**  
- 비트 끼리의 직접 비교 필요. 반복문으로 해결해도 될거같음.  
- 서로 다른 비트가 있다 -> 결과값 +1 이므로 Xor연산 사용하자.  
- 두 수를 Xor연산 하고 1의 갯수를 세주면 된다. 
```cpp
char c = a ^ b ; 
int hd = 0 ;

for ( int i = 0 ; i < sizeof(c)*8 ; i ++ ){
    // 삼항연산자 이용
    hd += (c & (1 << i ))? 1 : 0 ;

    //if문 이용
    if ((c & (1 << i ))== 1){
        hd ++ ; 
    }
}
```


**Solve Code**
```cpp
#include <stdio.h>

int main () {
    unsigned char a,b;
    scanf("%c %c",&a,&b);
    unsigned char c = a ^ b ; 
    int hd = 0;
    for ( int i = 0 ; i < sizeof(c)*8 ; i ++){
        hd += (c & ( 1 << i )) ? 1 : 0 ; 
    }
    printf("%d",hd);
}
```
***
### 3. Bit Counting (1)
양의 정수 N을 입력으로 받아 , N의 이진수 표현에서 1과 0의 개수를 각각 세서 출력하라.  
단 , 맨 앞자리에 오는 0은 카운트 하지 않는다.  

**#입력**  
첫 번째 줄에 양의 정수 N이 주어진다.  
1 <= N <= 2^64 -1 

**#출력**  
첫 번째 줄에 양의 정수 N의 이진수 표현에서 1의 개수를 출력한다.  
두 번째 줄에 양의 정수 N의 이진수 표현에서 0의 개수를 출력한다.  
단, 맨 앞자리에 오는 0은 카운트하지 않는다. (Don't count leading zeros)
***
**Thinking**  
- 비트카운트의 정석.  
- 맨 앞에서부터 값을 보다가 첫번째 1이 나오는 순간부터 카운트 시작. (Flag를 활용하자.)
- 반복문의 인덱스가 최고값에서 낮아지는 구조로 갈까 ..?   
```cpp 
int flag = true ;  // flag가 true 이면 , 맨 앞자리에 오는 0을 읽는중.
for(int i = 63 ; i >= 0 ; i --) { // 맨 앞자리 비트부터 읽기 시작
    int bit = ( n >> i ) & 1 ; //비트 추출
    // 이때 flag가 true 이면서, 비트가 0이라면 - count하지 않음.
    if ( flag == true && bit == 0 )
        continue ; // continue 때문에 아래 코드 실행안됨. 
    
    // 비트가 처음 0이 아닌 순간부터 카운트 시작
    flag = false ; 
    (bit) ? one ++ : zero ++;
}
```

**Solve Code**
```cpp
#include <stdio.h>
#define true 1 
#define false 0 
typedef unsigned long long long_t;

int main () {
    long_t N ;
    scanf("%llu",&N);
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
```
***
### 4. Bit Counting (2)
양의 정수 N을 입력으로 받아 , N의 이진수 표현에서 연속된 1비트의 최장 길이를 출력하라.  

**#입력**  
첫 번째 줄에 양의 정수 N이 주어진다.  
1 <= N <= 2^64 -1 

**#출력**  
첫 번째 줄에 양의 정수 N의 이진수 표현에서 연속된 1비트의 최장 길이를 출력한다.  

***
**Thinking**  
- n의 비트가 1이라면 curcount ++ 을 해준다.
- cur > maxcount라면, max = cur을 해준다.
- n의 비트가 0이라면 curcount = 0 이다.
```cpp
// 반복문 내부
if(N & 1){ // 아래 N >>= 1에 의해 매순간 마지막 자리만 비교하면됨. for문처럼 임의로 이동시킬 소요 X
    curCount ++ ;
    if(curCount > maxCount){
        maxCount = curCount;
    }
    else {
        curCount = 0 ;
    }
}
N >>= 1 ;
```

**Solve Code**  
while 문을 이용하여 n의 비트를 직접 하나씩 제거하고 이동시킴.
```cpp
void solve() {
    long_t N ;
    scanf("%llu",&N);

    int maxCount = 0, curCount=0;

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
```  
다른 풀이로, for문을 할수도 있음.   
근데 개인적으로, while문이 더 범용적이고 넓게 사용할수있을거같음.
```cpp
void solve() {
    long_t N ;
    scanf("%llu",&N);

    int maxCount = 0, curCount=0;

    for ( int i = 63 ; i >= 0 ; i --){
        if ( (N >> i)& 1 ){
            curCount ++ ;
            if(curCount > maxCount ){
                maxCount = curCount ; 
            }
        }
        else {
            curCount = 0 ;
        }
    }

    printf("%d\n",maxCount);
}
```