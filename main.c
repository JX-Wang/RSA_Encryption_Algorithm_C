#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long item;
/*
* RSA 加密算法
* @author:  WUD
*/
int prime(int seed){
        int prime_counter;
        int i;
        int j;
        int stmp;
        char flag;
        //seed = rand()%100000+100;
        //printf("%d\n",seed);
        for (i=seed; ; i++){
                flag='false';
                stmp = sqrt(i);
                //printf("%d \n", stmp);
                //exit(0);
                for (j=2;j<=stmp;j++){
                        if (i%j==0){
                                break;
                        }
                        if (i%j!=0 && j==stmp){
                                prime_counter = i;
                                return prime_counter;
                        }

        }
}
}

int e_counter(int the_n){
        int e;
        e = 5;
        // 17 关于40的逆为33;
        return e;
}

int qiuni(int e, int n){
        int a[100], i, b[100];
        int stmp_n;
        int stmp_e, stmp;
        int counter, stmp_d;
        stmp_n = n;
        stmp_e = e;
        // 求出
        for (i=0; i<100; i++){
                stmp = stmp_n%stmp_e;
                if (stmp!=0){
                        a[i] = (stmp_n - stmp)/stmp_e;  // long型向上取整，-1
                        stmp_n = stmp_e;
                        stmp_e = stmp;
                }
                else if(stmp==0){
                        a[i] = 0;
                        //printf("%d\n", i);
                        break;
                }
        }
        counter = i;
        // inv_e
        if(counter!=2){
                b[0] = a[counter-1];
                b[1] = a[counter-2]*b[0] + 1;
                for (i=2; i<counter; i++){
                        if (counter==i)
                        b[i] = a[counter-i-1]*b[i-1] +b[i-2];
                        stmp_d = b[i];
                }
        }
        else if(counter==2){
                stmp_d = a[counter-2]*a[counter-1] + 1;
        }
        else{
                printf("Warning: prime E or D is too short!\n");
                exit(0);
        }
        if(counter%2==0){
                return stmp_d;
        }
        else if (counter%2!=0){
                return n - stmp_d;
        }
}

int cipher(int m, int rand_e, int the_n, int c){
        int stmp;
        //int m = 2;
        stmp = pow(m, rand_e);
        c = stmp%the_n;
        printf("Message is : %d\n", m);
        printf("AES cipher: %d\n\n\n\n\n", c);
        return c;
}

void inv_cipher(int c, int d_counter, int the_n, int m){
        int stmp;
        printf("Cipher is : %d\n", c);
        stmp = pow(c, d_counter);
        m = stmp%the_n;
        printf("AES inv_cipher: %d\n", m);
}

int main(){
        int prime_p;
        int prime_q;
        int rand_e;
        int d_counter;
        int the_n;
        int n;
        int m,c;
        m = 2; //明文为2
        prime_p = prime(1);
        prime_q = prime(6);
        printf("生成素数p: %d     q: %d\n", prime_p, prime_q);
        n = prime_p * prime_q;
        printf("n is: %d\n", n);
        the_n = (prime_q-1) * (prime_p-1);
        printf("f(n) is: %d \n", the_n);
        rand_e = e_counter(the_n);
        printf("e is: %d \n", rand_e);
        printf("对e求逆");
        d_counter = qiuni(rand_e, the_n);
        printf("e^-1 is: %d\n", d_counter);
        // AES 加密
        c = cipher(m, rand_e, n, c);
        // AES 解密
        inv_cipher(c, d_counter, n, m);
}
