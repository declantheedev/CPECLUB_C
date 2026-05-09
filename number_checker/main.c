#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isEven(int users_num);


int main(){
    int users_num;
    printf("Enter your number: ");
    if(scanf("%d", &users_num) != 1){
        printf("Invalid input....");
        return 0;
    }
    if (isEven(users_num)){
        printf("The number you entered is Even\n");
    } else{
        printf("The number you entered is odd.");
    }
    return 0;

}

bool isEven(int users_num){
    return (users_num % 2 == 0);
}
