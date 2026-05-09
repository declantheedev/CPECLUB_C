#include <stdio.h>
#include <stdlib.h>




struct Packet{
    int serialNo;
    int priority;
};

int main()
{
    struct Packet buffer[10];
    FILE *file;

    file = fopen("packets.txt", "r");

    if (file == NULL){
        printf("Error: File is Empty. Also make sure file exists");
        return 1;
    }

    int count = 0;
    while(count < 10 && fscanf(file, "%d, %d", &buffer[count].serialNo, &buffer[count].priority) == 2){
        count++;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {


            int swapNeeded = 0;

            if (buffer[j].priority > buffer[j+1].priority) {
                swapNeeded = 1;
            }
            else if (buffer[j].priority == buffer[j+1].priority) {
                if (buffer[j].serialNo > buffer[j+1].serialNo) {
                    swapNeeded = 1;
                }
            }

            if (swapNeeded) {
                struct Packet temp = buffer[j];
                buffer[j] = buffer[j+1];
                buffer[j+1] = temp;
            }
        }
    }


    printf("Firewall Processing Order (Serial Numbers):\n");
    for (int i = 0; i < count; i++) {
        printf("Packet Serial: %d (Priority: %d)\n", buffer[i].serialNo, buffer[i].priority);
    }

    fclose(file);
    return 0;
}


