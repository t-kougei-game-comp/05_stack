#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum{
    STACK_SIZE = 10,
};

typedef struct{
    int top;
    int buf[STACK_SIZE];
} stack;

// スタックの初期化
void statc_initialize(stack *p){
    p->top = 0;
}
// スタックに値を追加(失敗したらfalse)
bool stack_push(stack *p, int n){
    if(STACK_SIZE <= p->top) return false;
    p->buf[p->top++] = n;
    return true;
}
// スタックから取り出す（-1はデータがなかった場合）
int stack_pop(stack *p){
    if(p->top <= 0) return false;
    return p->buf[--p->top];
}
// スタックの上から数えたデータを参照する（-1はデータがなかった場合）
int stack_get(stack *p, int idx){
    int i = p->top - idx - 1;
    if(i < 0 || STACK_SIZE <= i) return -1;
    return p->buf[i];
}


int main(int argc, char *argv[]) 
{
    char str[7];
    
    stack s;
    statc_initialize(&s);
    
    while(fgets(str, sizeof(str), stdin)){
        int n = atoi(str);
        switch(n){
        default:
            // スタックに追加
            stack_push(&s ,n);
            break;
        case -1:
            // スタックから取り出す
            int v = stack_pop(&s);
            if(v != -1) printf("%d", n);
            printf("\n");
            break;
        case 0:
            // スタックを表示
            for(int i = 0; i < STACK_SIZE; i++){
                int v = stack_get(&s, i);
                if(v == -1) break;
                if(i != -1) printf(",");
                printf("%d", n);
            }
            printf("\n");
            break;
        }
    }

    return 0;
}
