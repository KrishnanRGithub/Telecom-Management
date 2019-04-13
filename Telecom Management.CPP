#include<fstream.h>
#include<conio.h>
#include"TELE.h"
#include<string.h>
#include<stdio.h>
void main()
{
	long int NewId;
	Customers Temp;
       //	Loading();
	long int  Search_Id;
	char search_choice,task_choice,search_phone[12];
	int size = sizeof(Customers),record_exists;
	fstream Data;
	do
	{
		clrscr();
		Data.open("data.dat",ios::binary|ios::in|ios::out);
		Options_Choice(task_choice);
		if (task_choice == '1')			//Display option
		{
			FileDisplay(Data);
		}
		else if (task_choice == '2'||task_choice == '4'||task_choice == '5')          //2-Modify  4-Search	5-Delete
		{

			clrscr();
			Header();        //draws line and heading
			cout<<"\n\n\t\tDO YOU WANT TO SEARCH USING ID OR PHONE NUMBER (i/p) : ";
			cin>>search_choice;
			if(search_choice=='i'||search_choice=='I')
			{
				cout<<"\n\n\t\t\tENTER CUSTOMER ID  : ";
				cin>>Search_Id;
				strcpy(search_phone,"NULL");
			}
			else if(search_choice=='p'||search_choice=='P')
			{
				cout<<"\n\n\t\t\tENTER PHONE NUMBER : ";
				cin>>search_phone;
				Search_Id=0;
			}
			else
			{
				cout<<"\n\n\n\t\t\t\tWRONG OPTION ";
				Data.close();
				getch();
				continue;
			}
			if(task_choice=='2')
			{
				record_exists =Search(Data,Search_Id,search_phone);    //after search , the get pointer moves to end of the data
				if(record_exists ==1)    //record_exists = 1 when data exists
				{
					cout<<"\n\n\n\t\t\tPRESS ANY KEY TO ENTER NEW DATA...";
					getch();
					clrscr();
					Update_data(Data);  //Modify
				}
			}
			else if(task_choice == '4')
			{

				cout<<"\n\n";
				record_exists=Search(Data,Search_Id,search_phone);       //4 is Search

			}
			else
			{

				record_exists=Search(Data,Search_Id,search_phone);        //after search, the get pointer moves to the data

				if(record_exists==1)   //record_exists==1 when data exits in the file
				{
					char delete_choice;
					cout<<"\n\n\t\t\tDO YOU SURE WANT TO DELETE (y/n): ";
					cin>>delete_choice;
					if(delete_choice=='y'||delete_choice=='Y')
					{
						Delete_data(Data);
						cout<<"\n\n\t\t\tDATA SUCCESSFULLY DELETED ! ";
						getch();
					}
				}										//Delete
			}
			getch();

		}
		else if(task_choice=='7')        //Billing
		{
			cout<<"\n\n\n\t\t\tPRESS ANY KEY TO PRINT THE BILL....";
			getch();
			Bill_Generator(Data);
		}
		else if (task_choice == '3') 	      //Add
		{
			Header();
			Data.seekg(0,ios::end);
			if(0==Data.tellg())
			{
				NewId=1;
			}
			else
			{
				Data.seekg(-size,ios::end);
				Data.read((char*)&Temp,sizeof(Customers));
				//cout<<"\n\t\t\tTEMP ID : "<<Temp.id;
				NewId = Temp.id+1;
				//cout<<"\n\t\t\t\tNEW ID : "<<NewId;
			}
			Insert(NewId,Data);
			cout<<"\n\n";
			Draw_line();
		}
		else if (task_choice =='8')
		{
			char exit_choice;
			cout<<"\n\n\t\t\tDO YOU WANT TO CLOSE THIS PROGRAM (y/n) : ";
			cin>>exit_choice;
			if(exit_choice=='n'||exit_choice=='N')
			{
				task_choice=0;    //can be any value
			}


		}
		else if(task_choice=='6')
		{

			Plan_Details();
			getch();

		}
		else
		{
			cout<<"\n\n\n\t\t\t\tINCORRECT OPTION  ";
			getch();
			Data.close();
			continue;
		}
		Data.close();
	}while(task_choice!='8');
	Data.close();
	getch();

}
