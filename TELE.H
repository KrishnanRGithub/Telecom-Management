#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<iomanip.h>
void Draw_line()
{
	cout<<"================================================================================";

}
void Header()
{
	clrscr();
	cout<<"\n";
	Draw_line();
	cout<<"\n\t\t\t\tDETAILS\n";
	Draw_line();


}

char PhoneTemp[12];
int i=0;
void Options_Choice(char &choice)
{
	cout<<"\n";
	Draw_line();
	cout<<"\n\n\t\t\t\t  MENU";
	cout<<"\n\n";
	Draw_line();
	cout<<"\n\n\t\t\t1 DISPLAY ";
	cout<<"\n\n\t\t\t2 MODIFY";
	cout<<"\n\n\t\t\t3 ADD ";
	cout<<"\n\n\t\t\t4 SEARCH ";
	cout<<"\n\n\t\t\t5 DELETE";
	cout<<"\n\n\t\t\t6 PLANS";
	cout<<"\n\n\t\t\t7 GENERATE BILL";
	cout<<"\n\n\t\t\t8 EXIT";
	cout<<"\n\n\n\t\t\tENTER YOUR CHOICE : ";
	cin>>choice;
}
void Plan_Details()
{
	clrscr();
	cout<<"\n";
	Draw_line();
	cout<<"\n\n\t\t\t\t   PLANS";
	cout<<"\n\n";
	Draw_line();
	cout<<"\n\n\t\tPLAN \'A\' : Rs 100";
	cout<<"\n\n\t\tPLAN \'B\' : Rs 200";
	cout<<"\n\n\t\tPLAN \'C\' : Rs 350";

}
class Customers
{
	private:
		char Name[50];
		char Phone[12];
		char Address_1[50];
		char Address_2[50];
		char Address_3[50];
		char city[30];
		char state[20];
		char pincode[10];
		char plan;
	public:
		long int id;
		void Display_Full()
		{
			cout<<"\n\t\t\tNAME         : "<<Name;
			cout<<"\n\t\t\tPHONE NUMBER : "<<Phone;
			cout<<"\n\t\t\tADDRESS 1    : "<<Address_1;
			cout<<"\n\t\t\tADDRESS 2    : "<<Address_2;
			cout<<"\n\t\t\tADDRESS 3    : "<<Address_3;
			cout<<"\n\t\t\tCITY         : "<<city;
			cout<<"\n\t\t\tSTATE        : "<<state;
			cout<<"\n\t\t\tPINCODE      : "<<pincode;
			cout<<"\n\t\t\tID           : "<<id;
			cout<<"\n\t\t\tPLAN         : "<<plan;

		}
		void Customer_Details(fstream&Data)
		{
			int ph=0;       //to validate phone number
			cout<<"\n\t\t\tENTER CUSTOMER'S NAME   : ";
			do
			{
				Redisplay(1);
				gets(Name);

			}while(strlen(Name)<3);
			cout<<"\n\t\t\tENTER PHONE NUMBER      : ";
			while(ph==0)
			{
				Redisplay(2);
				ph=Input_Checker(Data);
			}
			cout<<"\n\t\t\tENTER ADDRESS 1         : ";
			do
			{
				Redisplay(3);
				gets(Address_1);

			}while(strlen(Address_1)<3);
			cout<<"\n\t\t\tENTER ADDRESS 2         : ";
			do
			{
				Redisplay(4);
				gets(Address_2);

			}while(strlen(Address_2)<3);
			cout<<"\n\t\t\tENTER ADDRESS 3         : ";
			do
			{
				Redisplay(5);
				gets(Address_3);

			}while(strlen(Address_3)==0);
			cout<<"\n\t\t\tENTER YOUR CITY         : ";
			do
			{       Redisplay(6);
				gets(city);

			}while(strlen(city)<3);
			cout<<"\n\t\t\tENTER YOUR STATE        : ";
			do
			{
				Redisplay(7);
				gets(state);

			}while(strlen(state)<3);
			cout<<"\n\t\t\tENTER THE PINCODE       : ";
			do
			{
				Redisplay(8);
				gets(pincode);

			}while(strlen(pincode)!=6);
			cout<<"\n\t\t\tENTER YOUR PLAN (A/B/C) : ";
			cin>>plan;
			while(plan!='A'&plan!='B'&plan!='C')
			{
				cout<<"\a";
				Redisplay(9); //to change the value of default arguement
				plan=getchar();
			}

		}
		char* Get_Phone();
		char* Get_Name();
		char* Get_ToAddress(int);
		void Display();
		char Get_Plan();
		void Phone_Null()
		{
			strcpy(Phone,"NULL");
		}
		int Input_Checker(fstream&Data);
		void Redisplay(int );


};
void Customers::Redisplay(int display_type=2)
{

	 int display_loop=1;
	 Header();
	 while(display_loop<=display_type)
	 {
		  switch(display_loop)
		  {
			 case 1:	cout<<"\n\t\t\tENTER CUSTOMER'S NAME   : ";
					break;

			 case 2:	cout<<Name;
					cout<<"\n\n\t\t\tENTER PHONE NUMBER      : ";
					break;

			 case 3:	cout<<Phone;
					cout<<"\n\n\t\t\tENTER ADDRESS 1         : ";
					break;

			 case 4:	cout<<Address_1;
					cout<<"\n\n\t\t\tENTER ADDRESS 2         : ";
					break;

			 case 5:	cout<<Address_2;
					cout<<"\n\n\t\t\tENTER ADDRESS 3         : ";
					break;

			 case 6:	cout<<Address_3;
					cout<<"\n\n\t\t\tENTER YOUR CITY         : ";
					break;

			 case 7:	cout<<city;
					cout<<"\n\n\t\t\tENTER YOUR STATE        : ";
					break;

			 case 8:	cout<<state;
					cout<<"\n\n\t\t\tENTER THE PINCODE       : ";
					break;

			 case 9:	cout<<pincode;
					cout<<"\n\n\t\t\tENTER YOUR PLAN (A/B/C) : ";
	       }
	       display_loop++;

	}


}
int Customers::Input_Checker(fstream&Data)
{

		i=0;
		Data.close();
		Data.open("DATA.dat",ios::binary|ios::in|ios::out);
		Customers Tempo;
		 //Vaiable PhoneTemp help the update function without which there will be loop holes
		gets(PhoneTemp);
		if(strcmp(PhoneTemp,Phone)==0)
		{
			return(1);
		}
		if(strlen(PhoneTemp)!=10)
		{
			cout<<"\a";
			return(0);

		}
		Data.seekg(ios::beg);
		Data.read((char*)&Tempo,sizeof(Tempo));
		while(!Data.eof())
		{
			if(strcmp(Tempo.Get_Phone(),PhoneTemp)==0)
			{
				cout<<"\a";
				return(0);
			}
			Data.read((char*)&Tempo,sizeof(Tempo));
		}
		if(PhoneTemp[0]=='0')
		{
			return(0);

		}
		while(i<10)
		{
			switch(PhoneTemp[i])
			{
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				case '0':   i++;
					    break;
				default:    cout<<"\a";
					    return(0);

			}
		}
		strcpy(Phone,PhoneTemp);
		return(1);
}

char* Customers::Get_ToAddress(int ch)
/*
	ch=1       Address1
	ch=2       Address2
	ch=3       Address3
	ch=4       City
	ch=5       State
	ch=6       Pincode
*/
{
	switch(ch)
	{
		case 1 :return(Address_1);
		case 2 :return(Address_2);
		case 3 :return(Address_3);
		case 4 :return(city);
		case 5 :return(state);
		case 6 :return(pincode);

	}

	return("ERROR");
}
char * Customers::Get_Phone()
{
	return(Phone);
}

char* Customers::Get_Name()
{

	return (Name);
}

char Customers::Get_Plan()
{
	return(plan);

}

void Customers::Display()
{

	cout.setf(ios::left);
	cout<<"\n "<<setw(7)<<this->id;
	cout<<"|   "<<setw(33)<<this->Get_Name();
	cout<<" | "<<"  "<<setw(13)<<this->Get_Phone();
	cout<<"| "<<"   "<<this->Get_Plan();
	cout<<"\n";
	Draw_line();

}
void Insert(long int NewId,fstream& Data)
{

	Customers T;
	char add_choice;
	clrscr();
	Plan_Details();
	cout<<"\n\n\t\t\tPRESS ANY KEY TO CONTINUE.....";
	getch();
	clrscr();
	Header();
	T.Phone_Null();
	T.Customer_Details(Data);
	T.id = NewId;
	T.Display_Full();
	Data.close();
	Data.open("DATA.dat",ios::binary|ios::in|ios::out);
	Data.seekp(0,ios::end);
	cout<<"\n\t\tDO YOU WANT TO ADD THIS TO THE FILE (y/n) : " ;
	cin>>add_choice;
	if(add_choice=='y'||add_choice=='Y')
	{
		Data.write((char*)&T,sizeof(Customers));
		cout<<"\n\t\t\tDATA SUCCESSFULLY ADDED TO THE FILE ";
		getch();

	}
	else
	{
		cout<<"\n\t\t\tDATA NOT ADDED TO THE FILE ";
		cout<<"\n\t\t\tPLEASE TRY AGAIN";
		getch();
	}
}
void FileDisplay(fstream& Data)
{
	Customers A;
	Data.seekg(0);
	Data.seekp(0);
	clrscr();
	Draw_line();
	cout<<"\n\n\t\t\t     CUSTOMERS DETAILS\n";
	cout.setf(ios::left);
	cout<<"\n";
	Draw_line();
	cout<<"\n    ID  | "<<setw(35)<<"               NAME";
	cout<<" | "<<setw(15)<<"    PHONE";
	cout<<"|    PLAN ";
	cout<<"\n";
	Draw_line();
	Data.read((char*)&A,sizeof(Customers));
	while(!Data.eof())
	{
		A.Display();
		Data.read((char*)&A,sizeof(Customers));

	}
	getch();
}
int Search(fstream&  Data, long int Search_Id,char search_phone[12])
{
	Data.seekg(0);
	Customers A;
	Data.read((char*)&A,sizeof(Customers));
	if(Search_Id==0)
	{
		while(!Data.eof())
		{
			if(strcmp(A.Get_Phone(),search_phone)==0)
			{
				cout<<"\n\t\t\t\tDATA  \n";
				A.Display_Full();
				return (1);
			}
			Data.read((char*)&A,sizeof(Customers));
		}

	}
	else
	{
		while(!Data.eof())
		{
			if(A.id==Search_Id)
			{
				cout<<"\n\t\t\t\tDATA  \n";
				A.Display_Full();
				return (1);
			}
			Data.read((char*)&A,sizeof(Customers));

		}

	}
	cout<<"\n\n\t\t\tNO RECORD FOUND... ";
	return(0);

}
void Update_data(fstream&  Data)
{
	Customers A;
	int pos,Temp_id;
	int size=sizeof(Customers);
	Data.seekg(-size,ios::cur);
	pos=Data.tellg();
	Header();
	Data.seekg(pos);
	Data.read((char*)&A,sizeof(A));
	Temp_id=A.id;
	A.Customer_Details(Data);
	Data.close();
	Data.open("DATA.dat",ios::binary|ios::in|ios::out);
	Data.seekp(pos);
	A.id=Temp_id;
	A.Display_Full();
	getch();
	Data.write((char*)&A,sizeof(A));
	return;
}
void Delete_data(fstream&  Data)
{
	Customers A;
	int pos=Data.tellg();  //end of the data that needs to be deleted
	fstream NewData;
	Data.seekg(0);
	Data.read((char*)&A,sizeof(Customers));
	NewData.open("NewData.dat",ios::binary|ios::in|ios::out);
	while(!Data.eof())
	{

		if(pos==Data.tellg())                          //after reading if the end points are same
		{
			Data.read((char*)&A,sizeof(Customers));
			continue;

		}
		NewData.write((char*)&A,sizeof(A));
		Data.read((char*)&A,sizeof(Customers));

	}
	remove("DATA.dat");
	rename("NewData.dat","Data.dat");

}

void Bill_Generator(fstream&Data)
{
	Customers B_Temp;	  //billing temporary variable
	int size = sizeof(B_Temp);
	char Month[7],Year[7],Final[20],User_Name[30];
	Final[0]='\0';
	User_Name[0]='\0';
	Data.seekg(ios::beg);
	Data.read((char*)&B_Temp,size);      //size holds the size of the class
	fstream Bill;
	fstream Details;
	Details.open("Details.txt",ios::in|ios::out);
	Details.getline(Month,5);
	Details.getline(Year,5);
	strcpy(Final,Month);
	strcat(Final,Year);
	strcat(Final,".txt");
	remove(Final); //so that new bill can be replacedd with old one when generated again, doesnt affect if the bill hasnt generated yet
	Bill.open(Final,ios::in|ios::out);
	while(!Data.eof())
	{
		Bill<<"FROM:\n";
		Bill<<"\tABC Telecom Service ,\n\tKelambakkam ,\n\tChennai - 603101 .";
		Bill<<"\n\TO:\n";
		/*
			for function  Get_ToAddress(int)
			ch=1       Address1
			ch=2       Address2
			ch=3       Address3
			ch=4       City
			ch=5       State
			ch=6       Pincode
		*/
		Bill<<"\t"<<B_Temp.Get_Name()<<"\n\t"<<B_Temp.Get_ToAddress(1);
		Bill<<" ,\n\t"<<B_Temp.Get_ToAddress(2);
		Bill<<" ,\n\t"<<B_Temp.Get_ToAddress(3);
		Bill<<" ,\n\t"<<B_Temp.Get_ToAddress(4);
		Bill<<"  - "<<B_Temp.Get_ToAddress(6);
		Bill<<" ,\n\t"<<B_Temp.Get_ToAddress(5);
		Bill<<" .\n\nRespected sir / madam , ";
		Bill<<"\n\n\tYour phone bill for the mobile number "<<B_Temp.Get_Phone()<<" ,\n";
		Bill<<"for the month "<<Month<<" of the year "<<Year;
		Bill<<" is Rs";
		switch(B_Temp.Get_Plan())
		{
			case 'A':Bill<<"100";
				 break;

			case 'B':Bill<<"200";
				 break;

			case 'C':Bill<<"350";

				 break;

			default :cout<<"\n\n\n\t\t\t\ERROR";
				 getch();
		}
		Bill<<".Please pay the bill\nbefore 15th of this month to avoid fines";
		Bill<<"\n\n\n\n";
		Data.read((char*)&B_Temp,size);

	}
	Data.close();
	Bill.close();



}

/*=============================================================================*/

//TO TRY LIKE GUI

void load(char j)
{
	long int i=0;
	while(i!=40000000)
	{
		i++;
	}
	cout<<j;
}
void Loading()
{
	char word[5]={"...."};
	int a,j;

	for(j=0;j<=5;j++)
	{
		clrscr();
		Draw_line();
		Draw_line();
		cout<<"\n\n\n\t\t\tWELCOME TO TELECOME PORTAL\n\n\n";
		Draw_line();
		Draw_line();
		cout<<"\n\n\t\t\t\tLOADING";
		for(a=0;a<5;a++)
		{
			load(word[a]);

		}
	}

}




