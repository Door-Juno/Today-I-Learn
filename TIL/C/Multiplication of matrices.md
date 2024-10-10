# Multiplication of matrices - 행렬의 곱셈
### 행렬의 정의
행렬의 곱셈은 '크기가 맞는 경우'에만 정의된다.  
이때 '크기가 맞는 경우' 라는 것은 앞 행렬의 열의 수와 뒷 행렬의 행의 수가 같다는 것이다.  

**(앞 행렬의 행의 수) X (뒤 행렬의 열의 수)**  
즉, 앞 행렬의 크기가 m X k 이고, 뒷 행렬의 k X n인 경우, 곱의 행렬의 크기는 m X n 이 된다.  
![Matrix_mul](https://lh5.googleusercontent.com/proxy/zBeApXFBLOMQoB1A3lhZf9R1YPJsNFRMaaFypLEvMUxHrjD3CYsZgIuTK0z6Zil5yRNM4s6yAxZPmIuu2xU)  
행렬의 곱은 다음과 같이 앞 행렬의 열과 뒷 행렬의 행 관계로 이루어져 각 원소의 곱의 합으로 표현된다. <u>앞 행렬의 가로 와 뒷 행렬의 세로 관계 잊지말자...!</u>  
![Matrix_mul2](https://codegsgh.com/upload/codegsgh.com/20230628//1427_1_20230628000914_36206.png)  
다음과 같이 행과 열의 각각 1번째끼리, 2번째끼리 곱하고.. 합하는것이다.
![Matrix_mul3](https://gaussian37.github.io/assets/img/math/la/block_matrix_multiplication/0.png)  
다음 사진을 보자. 앞 행렬은 4 X 2 이고 뒷 행렬은 2 X 3이다.   
이 행렬의 곱은 그럼 4 X 3 행렬이 되는걸 가시적으로 볼 수 있다.

### 이를 코드로 옮겨보자 !
- 행렬이므로 2차원 배열
- 행렬의 크기를 결정하기위해 3개 변수가 필요하며, 3중 반복문 사용해야할거같다.  
``` cpp 
int matrix1[n][k] = {{1,2,3},{4,5,6}};
int matrix2[k][m] = {{7,8},{9,10},{11,12}};

// n=2,k=3,m=2 이므로, 곱의 행렬의 크기는 2X2이다.

int result[n][m] ={0};

for(int i = 0 ; i < n ; i++ ){ //곱 행렬의 행
    for(int j = 0 ; j < m ; j++ ){// 곱 행렬의 열
        for(int z = 0 ; z < k ; z ++){
            result[i][j]+=matrix1[i][z]+matrix2[z][j] ; 
            // 곱의 합이므로 연산자는 += 이다.
        }
    }
}
```
다음과 같이 3중 for문으로 구성할수있다. 이때 제어변수와 실제 행렬의 행,열 변수를 잘 매치시키자.  

### 수업 중 나온 행렬곱 코드
```cpp
#include <stdio.h> //행렬 곱

int main() {
    int N,K,M;
    scanf("%d %d %d",&N,&K,&M);

    int A[N][K], B[N][M], C[N][M];
    //A 입력
    for(int i = 0 ; i < N; i++){ 
        for(int j = 0 ; j < K; j++){
            scanf("%d",&A[i][j]); 
        }
    }

    //B입력
    for(int i = 0 ; i < K; i++){
        for(int j = 0 ; j < M; j++){
            scanf("%d",&B[i][j]);
        }
    }
    
    // C초기화 및 입력
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < M ; j ++){
            C[i][j] = 0 ;
            for(int k = 0; k < K; k++){
                C[i][j] += A[i][k] * B[k][j]; 
            }
        }
    }
    for(int i = 0; i < N; i ++){
        for(int j = 0 ; j < M; j ++){
            printf("%d", C[i][j]);
            if(j < M-1 ) printf(" ");
        }
        printf("\n");
    }
}
```