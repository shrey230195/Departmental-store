











/************************************************************************

 ***                               HEADER FILES                      ***
 *************************************************************************/

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<dos.h>
/************************************************************************

 ***                               CLASSES                            ***
 *************************************************************************/
class menu_class
{
	public:
		void menu();
		void card_edit_menu();
		void customer_edit_menu();
};
class card                                       //class for card details
{
	private:
		char cardname[15];
		int cardcode;
		int limit;

	public:
		void input(int c,char n[],int l)
		{
			cardcode=c;
			strcpy(cardname,n);
			limit=l;
		}
		void addcard();
		void deletecard();
		void display_cardrecord();
		void display_cardlist();
		void searchcardname();
		void modify();
		void modifycard();
		int returncode();
		int returncardcode()
		{
			return cardcode;
		}
		int returnlimit()
		{
			return limit;
		}
		char *returncardname()
		{
			return cardname;
		}
};
class customer
{
	public:
		void addcust();
		void deletecustomer();
		void modify();
		void modifycustomer();
		void display_customerrecord();
		void searchname();
		void display_customerlist();
		int returncardno();
	private:
		int cardno,t_cardcode,t_limit;
		char name[20], phone[12], address[50];
};
/************************************************************************

 ***                               FUNCTIONS                         ***
 *************************************************************************/


void menu_class::menu()                           //MAIN MENU
{
		char ch;
		clrscr();

		cout<<"\t\t\t*****WELCOME TO MAIN MENU*****\n";
		cout<<"\t\t\t\t1. Customer\n";
		cout<<"\t\t\t\t2. Credit Card\n";
		cout<<"\t\t\t\t0. Exit \n";
		cout<<"\t\t\t\tEnter Your Choice :\n";
		ch=getch();
		switch(ch)
		{
				case '1':
					customer_edit_menu();
					break;
				case '2':
					card_edit_menu();
					break;

				case '0': exit(0);
		}
}

void menu_class::card_edit_menu()                 //card editing
{
	char ch;
	card r;
	do
	{
	clrscr();
	cout<<"\t\t\t\t1. Add New Card\n";
	cout<<"\t\t\t\t2. Delete Card Records\n";
	cout<<"\t\t\t\t3. Display Card Records\n";
	cout<<"\t\t\t\t4. Search By Card Name\n";
	cout<<"\t\t\t\t5. Modify Card \n";
	cout<<"\t\t\t\t0. Exit\n";
	cout<<"\t\t\t\tEnter Your Choice\n";
	ch=getch();
	if (ch=='1')
		r.addcard();
	else if(ch=='2')
		r.deletecard();
	else if(ch=='3')
		r.display_cardrecord();
	else if(ch=='4')
		r.searchcardname();
	else if(ch=='5')
		r.modifycard();
	else if (ch=='0')
		menu();
	else
	{

		cout<<"Wrong choice\n";
	}

	}while(ch!='0');
}

void menu_class::customer_edit_menu()
{
		char ch;
		customer c;
		do
		{
		clrscr();
		cout<<"\t\t\t\t1. New Customer\n";
		cout<<"\t\t\t\t2. Delete Customer\n";
		cout<<"\t\t\t\t3. Modify Customer\n";
		cout<<"\t\t\t\t4. Display Customer Record By Card No\n";
		cout<<"\t\t\t\t5. Search Customer Record By Name\n";
		cout<<"\t\t\t\t0. EXIT\n";
		cout<<"\t\t\t\tEnter Your Choice\n";
		ch=getch();
		if(ch == '1')
			c.addcust();
		else if(ch=='2')
			 c.deletecustomer();
		else if(ch=='3')
			c.modifycustomer();
		else if(ch=='4')
			c.display_customerrecord();
		else if(ch=='5')
			c.searchname();

		else if (ch=='0')
			menu();
		else
		{
			cout<<"Wrong choice\n";
		}

		}while(ch!='0');
}
int card::returncode()
{
			fstream file;
			int code=0;
			file.open("CARD.DAT",ios::in|ios::binary);
			while(file.read((char *)this,sizeof(card)))
			{
				  code++;
			}
			file.close();
			return code;
}

int customer::returncardno()
{
			fstream file;
			int n=0;
			file.open("CUST.DAT",ios::in|ios::binary);
			while(file.read((char *)this,sizeof(customer)))
			{
				  n++;
			}
			file.close();
			return n;
}

void card::addcard()                              //function to add card
{
	char ch;
	clrscr();
	cout<<"\t\t\t*****WELCOME TO ADD CARD RECORD FORM*****\n";
	A:
	int code;
	code=returncode();
	cout<<"Enter the Card Name :\n";
	gets(cardname);
	if (strlen(cardname)<=0 || strlen(cardname)>15)
	{
		cout<<"IT SHOULD NOT BE ZERO OR GREATER THAN 15\n";
		cout<<"Press any key to continue...\n";
		getche();
		clreol();
		clreol();
		clreol();
		goto A;
	}
	B:
	cout<<"Enter the Limit for Card :\n";
	cin>>limit;
	if(limit<=0)
	{
		cout<<"limit is greater than 0\n";
		cout<<"Press any key to continue...\n";
		clreol();
		clreol();
		clreol();
		goto B;
	 }
	cardcode=code+1;
	fstream file;
	file.open("CARD.DAT",ios::app|ios::binary);
	file.write((char *)this,sizeof(card));
	file.close();
}

void card::modify()                               /*function to modify
							 card details*/
{
	char ch;
	clrscr();
	cout<<"\t\t\t*****WELCOME TO MODIFY CARD RECORD FORM*****\n";
	A:
	cout<<"Enter the Card Name :\n";
	gets(cardname);
	if (strlen(cardname)<=0 || strlen(cardname)>15)
	{
		cout<<"IT SHOULD NOT BE ZERO OR GREATER THAN 15\n";
		cout<<"Press any key to continue...\n";
		getche();
		clreol();
		clreol();
		clreol();
		goto A;
	}
	B:
	cout<<"Enter the Limit for Card :\n";
	cin>>limit;
	if(limit<=0)
	{
		cout<<"Limit is greater than 0\n";
		cout<<"Press any key to continue...\n";
		clreol();
		clreol();
		clreol();
		goto B;
	 }
}
void card::modifycard()
{
	clrscr();
	int flag=1;
	char ch;
	int n;
	cout<<"\t\t\t*****WELCOME TO MODIFY CARD RECORD FORM***** \n";
	cout<<"Enter the card code to be modified :\n";
	cin>>n;

	fstream file;
	file.open("CARD.DAT",ios::in|ios::out|ios::binary);
	int record=0;
	while(file.read((char *)this,sizeof(card)))
	{
		if(cardcode==n)
		{
			modify();
			file.seekp(record*sizeof(card));
			file.write((char *)this,sizeof(card));
			flag=0;
			break;
		}
	}
	file.close();
	if(flag==0)
	{
		cout<<"RECORD MODIFIED...\n";
	}
	else
	{
		cout<<"RECORD NOT FOUND...\n";
	}
	cout<<"PRESS ANY KEY TO CONTINUE...\n";
	getch();

}

void card::deletecard()                       //function to delete card
{
	clrscr();
	int flag=1;
	char ch;
	int n;
	cout<<"\t\t\t*****WELCOME TO DELETE CARD RECORD FORM***** \n";
	cout<<"Enter the card code to be deleted :\n";
	cin>>n;

	fstream file;
	file.open("CARD.DAT",ios::in|ios::binary);
	fstream tempfile;
	tempfile.open("TCARD.DAT",ios::out|ios::binary);

	while(file.read((char *)this,sizeof(card)))
	{
		if(cardcode!=n)
			tempfile.write((char *)this,sizeof(card));
		if(cardcode==n)
			flag=0;
	}
	file.close();
	tempfile.close();

	if(flag==0)
	{
		fstream f1;
		f1.open("TCARD.DAT",ios::in|ios::binary);
		fstream t1;
		t1.open("CARD.DAT",ios::out|ios::binary);
		while(f1.read((char *)this,sizeof(card)))
		{
			t1.write((char *)this,sizeof(card));
		}
		cout<<"RECORD DELETED...\n";
	}
	else
	{
		cout<<"RECORD NOT FOUND...\n";
	}
	cout<<"PRESS ANY KEY TO CONTINUE \n";
	getch();

}

void card::searchcardname()                  //function to search cardbyname
{
	int n,flag=1;
	char str[50];
	clrscr();
	cout<<"\t\t\t*****WELCOME TO CARD DISPLAY RECORD FORM*****\n";
	cout<<"Enter the card name :";
	gets(str);
	fstream file;
	file.open("CARD.DAT",ios::in|ios::binary);
	while(file.read((char *)this,sizeof(card)))
	{
		  if(strcmpi(cardname,str)==0)
		  {
			cout<<"CARD NUMBER ="<<cardcode<<endl;
			cout<<"CARD LIMIT ="<<limit<<endl;
			flag=0;
		  }
	}
	if(flag==1)
	{
		cout<<"CARD NAME NOT EXIST :\n";
	}
	cout<<"PRESS ANY KEY TO CONTINUE \n";
	getch();
	file.close();

}

void card::display_cardrecord()           //display card info by cardcode
{
	int n,flag=1;
	clrscr();
	cout<<"\t\t\t*****WELCOME TO CARD DISPLAY RECORD FORM*****\n";
	cout<<"Enter the card code :";
	cin>>n;
	fstream file;
	file.open("CARD.DAT",ios::in|ios::binary);
	while(file.read((char *)this,sizeof(card)))
	{
		  if(n==cardcode)
		  {
			cout<<"CARD NAME ="<<cardname<<endl;
			cout<<"CARD LIMIT ="<<limit<<endl;
			flag=0;
		  }
	}
	if(flag==1)
	{
		cout<<"CARD CODE NOT EXIST :\n";
	}
	cout<<"PRESS ANY KEY TO CONT...\n";
	getch();
	file.close();

}

void card::display_cardlist(void)
{
	fstream file;
	file.open("card.dat",ios::in|ios::binary);
	int row=5, pageno=1;
	C:
	clrscr();
	cout<<"LIST OF CARDS ";
	cout<<"Card Code ";
	cout<<"Card Name ";
	cout<<"Limit ";
	while (file.read((char *)this, sizeof(card)))
	{
		row++;
			cout<<cardcode<<endl;
		cout<<cardname<<endl;
		cout<<limit<<endl;
		if(row==22)
		{
			  row=6;
			  cout<<"Page no.: \n" <<pageno;
			  pageno++;
			  cout<<"Press any key to continue...\n";
			  getch();
			  goto C;
		}
	}
	cout<<"Page No. : \n" <<pageno<<endl;
	cout<<"Press any key to continue...\n";
	getch();
	file.close();
}

void customer::addcust()                      //function to add customer
{
		clrscr();
		int n=returncardno();
		cout<<"\t\t\t*****WELCOME TO CUSTOMER ADD RECORD FORM*****\n";
		cout<<"Enter the name of the customer :";
		gets(name);
		cout<<"Enter the Address of the Customer :";
		gets(address);
		CC:
	cout<<"ENTER THE PHONE NO. :";
	cin>>phone;
		for(int i=0;i<strlen(phone);i++)
		{
			if(isalpha(phone[i]))
			{
			cout<<"ONLY NUMBERS\n ";
			getch();
		clreol();
		clreol();
			goto CC;
			}
		}
		D:
		char str[10];
	cout<<"Enter the Card Code\n(1 for Diner Card\n2 for Classic Card\n3 for Gold Card\n4 for Executive Card) \n";
	cin>>str;
		for(i=0;i<strlen(str);i++)
		{
			if(isalpha(str[i]))
			{
				cout<<"ONLY NUMBERS \n";
				getch();
				clreol();
				clreol();
				goto D;
			}
		}
		t_cardcode=atoi(str);

		fstream file;
		file.open("CARD.DAT",ios::in|ios::binary);
		int found=0;
		card r;
		while(file.read((char *)&r,sizeof(card)))
		{
			if(t_cardcode==r.returncardcode())
			{
					found=1;
					break;
			}
		}
		if(found==0)
		{
			cout<<"Card Code Does Not Exist \n ";
			cout<<"Enter Again \n";
		getch();
			clreol();
		clreol();
		clreol();
			goto D;
		}
		cardno=n+1;
		t_limit=r.returnlimit();
		cout<<"Your Card Number.\n"<<cardno<<endl;
		cout<<"Avaliable Cash Limit (Rs.)\n"<<t_limit<<endl;
		fstream file1;
		file1.open("CUST.DAT",ios::app|ios::binary);
		file1.write((char *)this,sizeof(customer));
		file1.close();
		file.close();
		cout<<"PRESS ANY KEY TO CONTINUE...\n";
		getch();
}

void customer::modify()                     /*function to modify details
						  of customer*/
{
		cout<<"Enter the name of the customer :\n";
		gets(name);
		cout<<"Enter the Address of the Customer :\n";
		gets(address);
		CC:
		cout<<"ENTER THE PHONE NO. :\n";
		cin>>phone;
		for(int i=0;i<strlen(phone);i++)
		{
			if(isalpha(phone[i]))
			{
		cout<<"ONLY NUMBERS\n ";
			getch();
			clreol();
			clreol();
			goto CC;
			}
		}
		D:
		char str[10];
		cout<<"Enter the Card Code\n ";
		cin>>str;
		for(i=0;i<strlen(str);i++)
		{
			if(isalpha(str[i]))
			{
				cout<<"ONLY NUMBERS \n";
				getch();
				clreol();
			clreol();
				goto D;
			}
		}
		t_cardcode=atoi(str);

		fstream file;
		file.open("CARD.DAT",ios::in|ios::binary);
		int found=0;
		card r;
		while(file.read((char *)&r,sizeof(card)))
		{
			if(t_cardcode==r.returncardcode())
			{
					found=1;
					break;
			}
		}
		if(found==0)
		{
			cout<<"Card Code Does Not Exist \n";
			cout<<"Enter Again \n";
			getch();
			clreol();
			clreol();
			clreol();
			goto D;
		}
		t_limit=r.returnlimit();

}
void customer:: modifycustomer()           /*function to modify customer-
						details on cardno.*/
{
		clrscr();
		int n,flag=0;
		char str[10];
		cout<<"\t\t\t****WELCOME TO CUSTOMER MODIFY RECORD FORM*****\n";
		AA:
		cout<<"Enter Card Number\n ";
	cin>>str;
		for(int i=0;i<strlen(str);i++)
		{
		if(isalpha(str[i]))
		{
			cout<<"ONLY NUMBERS\n ";
			getch();
			clreol();
			clreol();
			goto AA;
		}
		}
		n=atoi(str);
		fstream file;
		file.open("CUST.DAT",ios::in|ios::out|ios::binary);
		int record=0;
		while(file.read((char *)this,sizeof(customer)))
		{
			if(n==cardno)
			{
				modify();
				file.seekp(record*sizeof(customer));
				file.write((char *)this,sizeof(customer));
				flag=1;
				break;
			}
			++record;
		}
		if(flag==1)
		{
			cout<<"RECORD MODIFIED..\n";
		}
		else
		{

			cout<<"RECORD NOT FOUND...\n";
		}

		cout<<"PRESS ANY KEY TO CONTINUE\n";
		getch();
		file.close();

}
void customer:: deletecustomer()                    //to delete customer on cardno.
{
		clrscr();

		int n,flag=0;
		char str[10];

		cout<<"\t\t\t****WELCOME TO CUSTOMER DELETE RECORD FORM*****\n";
		AA:

		cout<<"Enter Card Number\n ";

		cin>>str;
		for(int i=0;i<strlen(str);i++)
		{
		if(isalpha(str[i]))
		{

			cout<<"ONLY NUMBERS \n";
			getch();
			clreol();

			clreol();
			goto AA;
		}
		}
		n=atoi(str);
		fstream file;
		file.open("CUST.DAT",ios::in|ios::binary);
		fstream temp;
		temp.open("TEMP.DAT",ios::out|ios::binary);

		while(file.read((char *)this,sizeof(customer)))
		{
			if(n!=cardno)
			       temp.write((char *)this,sizeof(customer));
			if(n==cardno)
				flag=1;
		}
		file.close();
		temp.close();
		if(flag==1)
		{

			fstream f1;
			f1.open("TEMP.DAT",ios::in|ios::binary);
			fstream t1;
			t1.open("CUST.DAT",ios::out|ios::binary);
			while(f1.read((char *)this,sizeof(customer)))
			{
				t1.write((char *)this,sizeof(customer));
			}

			cout<<"RECORD DELETED...\n";
			f1.close();
			t1.close();
		}
		else
		{

			cout<<"RECORD NOT FOUND...\n";
		}

		cout<<"PRESS ANY KEY TO CONTINUE \n";
		getch();
		file.close();
		temp.close();
}

void customer :: searchname()                 /*function to searchdetails
						     by customer name*/
{
	clrscr();
	int n,flag=0;
	char str[50];

	cout<<"\t\t\t****WELCOME TO CUSTOMER DISPLAY RECORD FORM*****\n";
	BB:
	cout<<"Enter the Customer Name :\n";
		gets(str);
	for(int i=0;i<strlen(str);i++)
	{
		if(isalpha(str[i])||str[i]==' ')
		{
		}
		else
		{

			cout<<"ONLY CHARACTERS\n ";
			getch();
			clreol();
			clreol();
			goto BB;
		}
	}

	fstream file;
	file.open("CUST.DAT",ios::in|ios::binary);
	while(file.read((char *) this, sizeof(customer)))
	{
		  if(strcmpi(name,str)==0)
		  {
			cout<<"Card Number is "<<cardno<<endl;
			cout<<"Customer's Address is "<<address<<endl;
			cout<<"Customer's phone is "<<phone<<endl;
			cout<<"Card Code is "<<t_cardcode<<endl;
			card r;
			fstream file1;
			file1.open("CARD.DAT",ios::in|ios::binary);
			while(file1.read((char *)&r,sizeof(card)))
			{
				if(t_cardcode==r.returncardcode())
				{
					cout<<"Card Name is "<<r.returncardname()<<endl;
				}
			}

			cout<<"Card Limit is "<<t_limit<<endl;
			flag=1;
		  }
	}
	if(flag==0)
	{

		cout<<"CUSTOMER NAME DOES NOT EXIST :\n";
	}
	cout<<"PRESS ANY KEY TO CONTINUE...\n";
	getch();
	file.close();
	getch();
}

void customer :: display_customerrecord()       //function to display
						 //  customer name
{
	clrscr();
	int n,flag=0;
	char str[10];

	cout<<"\t\t\t****WELCOME TO CUSTOMER DISPLAY RECORD FORM*****\n";
	BB:
	cout<<"Enter the Card Number :\n";
	cin>>str;
	for(int i=0;i<strlen(str);i++)
	{
		if(isalpha(str[i]))
		{
			cout<<"ONLY NUMBERS \n";
			getch();
			clreol();
		clreol();
			goto BB;
		}
	}
	n=atoi(str);
	fstream file;
	file.open("CUST.DAT",ios::in|ios::binary);
	while(file.read((char *) this, sizeof(customer)))
	{
		  if(n==cardno)
		  {
			cout<<"Customer Name ="<<name<<endl;
			cout<<"Customer Address ="<<address<<endl;
			cout<<"Customer phone ="<<phone<<endl;
			cout<<"Card Code ="<<t_cardcode<<endl;

			card r;
			fstream file1;
			file1.open("CARD.DAT",ios::in|ios::binary);
			while(file1.read((char *)&r,sizeof(card)))
			{
				if(t_cardcode==r.returncardcode())
				{
					cout<<"Card Name ="<<r.returncardname()<<endl;
				}
			}
			cout<<"Card Limit ="<<t_limit<<endl;
			flag=1;
		  }
	}
	if(flag==0)
	{
		cout<<"CARD NUMBER DOES NOT EXIST :\n";
	}
	cout<<"PRESS ANY KEY TO CONTINUE...\n";
	getch();
	file.close();
	getch();
}

void customer :: display_customerlist()                /* to display
							 customer list*/
{
	clrscr();
	fstream file;
	file.open("CUST.DAT", ios::in|ios::binary);
	card r;
	int row=3,pageno=1;
	cout<<"LIST OF CUSTOMERS ";
	cout<<"Card No.";
	cout<<"Name ";
	cout<<"Phone ";
	cout<<"Card Code ";
	cout<<"Card Name ";
	cout<<"Card Limit ";
	while(file.read((char *)this,sizeof(customer)))
	{
		row++;
		cout<<cardno<<endl;
		cout<<name<<endl;
		cout<<phone<<endl;
		cout<<t_cardcode<<endl;
		fstream file1;
		file1.open("CARD.DAT",ios::in|ios::binary);
		while(file1.read((char *)&r,sizeof(card)))
		{
			if(t_cardcode==r.returncardcode())
			{
				cout<<r.returncardname()<<endl;
			}
		}
	cout<<t_limit<<endl;

		if(row==22)
		{
			row=5;
			cout<<"Page no.:\n"<<pageno;
			pageno++;
			cout<<"Press any key to continue...\n";
			getch();
		}
	}
	cout<<"Page No.: \n"<<pageno;
	cout<<"Press any key to continue...:\n";
	getch();
	file.close();
}

void madeby()                                  /*name of project  										developers*/
{
	clrscr();
	cout<<"				"<<"PROJECT MADE BY:";
	delay(300);
	cout<<"\n	          		"<<"*Shubhi ang Shubhangi*";
	delay(200);
	cout<<endl<<"    	           	   "<<"PRESS ANY KEY TO CONTINUE...\n";
	getch();

}
void welcome()                                //welcome screen
{
	clrscr();
	cout<<"			WELCOME TO CREDIT CARD MANAGEMENT SYSTEM\n";
	delay(300);
	cout<<"			     PRESS ANY KEY TO CONTINUE...\n";
	getch();
	madeby();
}
void writecard()                              //default cards available
{
	fstream file;
	card r[4];
	r[0].input(1,"Diner card",20000);
	r[1].input(2,"Classic card",30000);
	r[2].input(3,"Gold card",40000);
	r[3].input(4,"Executive card",50000);

	file.open("CARD.DAT",ios::out|ios::binary);
	for(int i=0;i<=3;i++)
	{
		file.write((char *)&r[i],sizeof(card));
	}
	file.close();
}
/*************************************************************************
 ***                               MAIN FUNCTION                              ***
 *************************************************************************/

void main(void)
{
	clrscr();
	char str[4];
	menu_class m;
	cout<<"\t\t\t****ENTER PASSWORD*****\n";
	delay(300);
	for(int j=0;j<3;j++)
	{
	     str[j]=getch();
	     cout<<"*";
	}
	str[j]='\0';
	if(strcmp(str,"ccm")==0)
	{
	welcome();
	writecard();
	m.menu();
	}
	else
	{
		cout<<"WRONG PASSWORD\n";
   }
	getch();
}

