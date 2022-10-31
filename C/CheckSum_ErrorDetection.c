#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sender()
{
    int arr[5][4];
    printf("Enter a 16 bit binary data in blocks of four:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("Enter Block%d: ", i + 1);
        for (int j = 0; j < 4; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    int sumArr[4] = {0};
    int carryBit = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 3; j >= 0; j--)
        {
            sumArr[j] = arr[i][j] ^ sumArr[j] ^ carryBit;
            carryBit = arr[i][j] & sumArr[j] | (arr[i][j] ^ sumArr[j]) & carryBit;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        arr[4][i] = sumArr[i];
    }
    printf("The dataBlock generated: ");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf(" ");
    }
}

void reciever()
{
    int arr[5][4];
    printf("Enter the dataBlock generated by the sender:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Enter Block%d: ", i + 1);
        for (int j = 0; j < 4; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    int sumArr[4] = {0};
    int carryBit = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 3; j >= 0; j--)
        {
            sumArr[j] = arr[i][j] ^ sumArr[j] ^ carryBit;
            carryBit = arr[i][j] & sumArr[j] | (arr[i][j] ^ sumArr[j]) & carryBit;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        sumArr[i] ^= 1;
        arr[4][i] ^= sumArr[i];
    }

    for (int j = 0; j < 4; j++)
    {
        if (arr[4][j] == 0)
        {
            printf("\ndataBlock invalid!\n");
            exit(0);
        }
    }
    printf("dataBlock Accepted!\n");
}
int main()
{
    printf("CheckSum\n\n");
    int n;
    printf("Enter 1. for Sender 2. for reciever: ");
    scanf("%d", &n);
    if (n == 1)
        sender();
    else if (n == 2)
        reciever();
    else
    {
        printf("Invalid Input!\n");
        exit(0);
    }

    return 0;
}