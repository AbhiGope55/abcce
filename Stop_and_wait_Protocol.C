/*implementing stop and wait Protocol*/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
int main()
{

	char sen_data[30], rec_data[30];
	int t, i, j, bit = 0, flag, k, l, index[6], count;
	system("cls");
	printf("\nEnter a String ");
	scanf("%s", sen_data);
	l = strlen(sen_data);
	for (i = 0; i < l; i++)
	{
		index[i] = '\0';
	}
	for (k = 0, i = 0; sen_data[i] != '\0'; i++)
	{
		t = sen_data[i];
		if (t == 'b' || t == 'B')
		{
			flag = 1;
			index[k] = i;
			k++;
		}
	}
	count = k;
	system("cls");
	for (i = 50; i >= 0; i--)
	{
		system("cls");
		if (i % 2 == 0)
			printf("\n\n***Working of Stop and Wait Protocol***\n\n");
		else
			printf("\n\n****Working of Stop and Wait Protocol***\n\n");
		Sleep(10);
	}
	Sleep(1500);
	printf("\n\nThe data to be Transmitted is : '%s'", sen_data);
	printf("\n\n\nTransmission Starting ");
	for (i = 0; i < 8; i++)
	{
		printf(". ");
		Sleep(500);
	}
	//working logic
	i = 0;
	k = 0;
	while (sen_data[i] != '\0')
	{

		Sleep(1500);
		for (j = 100; j >= 0; j--)
		{
			system("cls");
			printf("\n\n\nTransmitting F[%d] (i.e; '%c') ", bit, sen_data[i]);
			printf("\n\nTimer : %d", j);
			Sleep(40);
		}
		Sleep(1500);
		system("cls");
	label:
		if (bit == 0)
			bit = 1;
		else
			bit = 0;
		rec_data[i] = sen_data[i];
		for (j = 100; j >= 0; j--)
		{
			system("cls");
			printf("\n\n\n Waiting for Ack[%d] ", bit);
			printf("\n\nTimer : %d", j);
			Sleep(40);
		}
		//to make error
		if (flag == 1 && k < count)
		{
			if (index[k] == i)
			{
				if (bit == 1)
					bit = 0;
				else
					bit = 1;
				printf("\n\nTimed out (that is data or ack lost) ...");
				Sleep(3000);
				for (j = 100; j >= 0; j--)
				{
					system("cls");
					printf("\n\nRetransmitting F[%d] (that is '%c') :", bit, sen_data[i]);
					printf("\n\n\nTimer : %d", j);
					Sleep(30);
				}
				k++;
				index[k] = '\0';
				goto label;
			} //inner if block closing
		}	  //error creating if block closing
		i++;
	} //while loop closing
	printf("\n\nProtocol completed successfully ");
	printf("\n\nData received at Receiver side is: '%s' ", rec_data);
	getch();
	return 0;

}