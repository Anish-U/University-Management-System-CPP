#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<fstream>
#include<process.h>
#include<limits>
#include<ios>
#include<windows.h>
using namespace std;


int studentid[50]={-1};
int s_count=0;


HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

//Some variables needed for checking date format
const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;
int s_size=9;
int f_size=5;
int w_size=1;
int a_size=1;

//classes marks, leave, profile and book are part of class student
class marks
{
	char sub[4][10];
	double cat1[4],cat2[4],fat[4];
	public:
	   	
		   
		marks()
		{
			strcpy(sub[0],"MAT2001");
			strcpy(sub[1],"CSE2004");
			strcpy(sub[2],"ECE2001");
			strcpy(sub[3],"BIT1020");
			
			for(int i=0;i<4;i++)
			{
				cat1[i]=cat2[i]=fat[i]=-1;
			}
		}
		
		
		void enter_marks(char c[])//for getting input from the teacher for the marks of a particular subject
		{
			char code[10];
			int pos=-1;
			strcpy(code,c);
			for(int i=0;i<4;i++)
			{
				if(strcmp(code,sub[i])==0)
				{
					pos=i;
					break;
				}
			}
			if(pos>=0)
			{
				SetConsoleTextAttribute(h,14);
				cout<<endl<<"\n\t\t\tEnter the marks for subject ";
				SetConsoleTextAttribute(h,12);
				cout<<sub[pos]<<endl;
				SetConsoleTextAttribute(h,14);
				int n;
				cout<<"\n\t\t\t1:CAT 1\t\t2:CAT 2\t\t3:FAT"<<endl;
				cout<<"\n\n\t\t\tEnter your option:";
				cin>>n;
				switch(n)
				{
					case 1:
						SetConsoleTextAttribute(h,14);
						cout<<"\n\t\t\tEnter CAT-1 marks : ";
						SetConsoleTextAttribute(h,12);
						cin>>cat1[pos];
						SetConsoleTextAttribute(h,14);
						if(cat1[pos]>50.00 || cat1[pos]<0.00){
							cat1[pos]=-1;
							SetConsoleTextAttribute(h,4);
							cout<<"\n\t\t\tCAT-1 marks must be between 0 and 50";
							SetConsoleTextAttribute(h,14);
						}
						cout<<endl;
						break;
					case 2:
						SetConsoleTextAttribute(h,14);
						cout<<"\n\t\t\tEnter CAT-2 marks : ";
						SetConsoleTextAttribute(h,12);
						cin>>cat2[pos];
						SetConsoleTextAttribute(h,14);
						if(cat2[pos]>50.00 || cat2[pos]<0.00){
							cat2[pos]=-1;
							SetConsoleTextAttribute(h,4);
							cout<<"\n\t\t\tCAT-2 marks must be between 0 and 50";
							SetConsoleTextAttribute(h,14);
						}
						cout<<endl;
						break;
					case 3:
						SetConsoleTextAttribute(h,14);
						cout<<"\n\t\t\tEnter FAT marks : ";
						SetConsoleTextAttribute(h,12);
						cin>>fat[pos];
						SetConsoleTextAttribute(h,14);
						if(fat[pos]>100.00 || fat[pos]<0.00){
							fat[pos]=-1;
							SetConsoleTextAttribute(h,4);
							cout<<"\n\t\t\tFAT marks must be between 0 and 100";
							SetConsoleTextAttribute(h,14);
						}
						cout<<endl;
						break;
					default:
						SetConsoleTextAttribute(h,4);
						cout<<"\n\n\t\t\tYou have entered the wrong option. Pls start from the begining."<<endl;
						SetConsoleTextAttribute(h,14);
						break;
					}
					//system("cls");
					
				}
				else{
					SetConsoleTextAttribute(h,4);
					cout<<"You have entered the wrong option. Pls start from the begining."<<endl;
					SetConsoleTextAttribute(h,14);
				}
			}//input marks
		
		
		void print_marks(char a[]="Nil")//a contains teacher code if displaying for teacher
		{
			int pos=-1;
			if(strcmp(a,"Nil")!=0)
			{
				for(int i=0;i<f_size;i++)
				{
					if(strcmp(a,sub[i])==0)
					{
						pos=i;
						break;
					}
				}
				if(pos!=-1)
				{
					if(cat1[pos]!=-1)
					{
						SetConsoleTextAttribute(h,14);
						cout<<"\n\n\t\t\t\tCAT-1 : ";
						SetConsoleTextAttribute(h,10);
						cout<<cat1[pos];
						SetConsoleTextAttribute(h,14);
					}
					else
					{
						SetConsoleTextAttribute(h,14);
						cout<<"\n\n\t\t\tCAT-1 : ";
						SetConsoleTextAttribute(h,4);
						cout<<"Nil";
						SetConsoleTextAttribute(h,14);	
					}
					

				if(cat2[pos]!=-1)
					{
						SetConsoleTextAttribute(h,14);
						cout<<"\tCAT-2 : ";
						SetConsoleTextAttribute(h,10);
						cout<<cat2[pos];
						SetConsoleTextAttribute(h,14);
					}
					else{
						SetConsoleTextAttribute(h,14);
						cout<<"\tCAT-2 : ";
						SetConsoleTextAttribute(h,4);
						cout<<"Nil";
						SetConsoleTextAttribute(h,14);
					}
				if(fat[pos]!=-1)
					{
						SetConsoleTextAttribute(h,14);
						cout<<"\tFAT : ";
						SetConsoleTextAttribute(h,10);
						cout<<fat[pos]<<endl;
						SetConsoleTextAttribute(h,14);
					}
					else{
						SetConsoleTextAttribute(h,14);
						cout<<"\tFAT : ";
						SetConsoleTextAttribute(h,4);
						cout<<"Nil"<<endl;
						SetConsoleTextAttribute(h,14);
					}
				}
				else
					cout<<"\n\t\tYou have entered the wrong subject code. Pls start from the begining."<<endl;
			}
			else
			{
				for(int i=0;i<4;i++)
				{
					pos=i;
					cout<<"\n\t\t\t"<<sub[pos];
					if(cat1[pos]!=-1)
					{
						cout<<"\t\tCAT-1 : "<<cat1[pos];
					}
					else
					cout<<"\t\tCAT-1 : "<<"Nil";

				if(cat2[pos]!=-1)
					{
						cout<<"\tCAT-2 : "<<cat2[pos];
					}
					else
					cout<<"\tCAT-2 : "<<"Nil";
				if(fat[pos]!=-1)
					{
						cout<<"\tFAT : "<<fat[pos]<<endl;
					}
					else
					cout<<"\tFAT : "<<"Nil"<<endl;
				}
			}
		}
};
class leave
{
	public:
		char frm[10],tt[10];
		char from[10],to[10],reason[200];
		bool permission,applied;
		leave()
		{
			permission=false;
			applied=false;
		}
		/*check1(char a[],char b[])
		{
			strcpy(from,a);
			strcpy(to,b);
		}*/
		bool isLeap(int year)
		{
		  // Return true if year is a multiple pf 4 and
		  // not multiple of 100.
		  // OR year is multiple of 400.
		  return (((year%4==0) && (year%100!=0)) ||
		           (year%400==0));
		}
		 
		// Returns true if given year is valid or not.
		bool check(char fr[])
		{
			int d, m, y;
			d=((fr[0]-48)*10)+(fr[1]-48);
			m=((fr[3]-48)*10)+(fr[4]-48);
			y=((fr[6]-48)*1000)+((fr[7]-48)*100)+((fr[8]-48)*10)+(fr[9]-48);
		    // If year, month and day are not in given range
		    if (y > MAX_VALID_YR || y < MIN_VALID_YR)
		      return false;
		    if (m < 1 || m > 12)
		      return false;
		    if (d < 1 || d > 31)
		      return false;
		 
		    // Handle February month with leap year
		    if (m == 2)
		    {
		        if (isLeap(y))
		           return (d <= 29);
		        else
		           return (d <= 28);
		    }
		 
		    // Months of April, June, Sept and Nov
		    // must have number of days less than
		    // or equal to 30.
		    if (m==4 || m==6 || m==9 || m==11)
		        return (d <= 30);
		 
		    return true;
		}
			
		bool check_duration(char fr[],char to[])
		{
			int dayf,dayt,mf,mt;
			bool chk=true;
			dayf=((fr[0]-48)*10)+(fr[1]-48);
			dayt=((to[0]-48)*10)+(to[1]-48);
			mf=((fr[3]-48)*10)+(fr[4]-48);
			mt=((to[3]-48)*10)+(to[4]-48);
			if((mf==mt))
			{
				if(dayf>dayt)
					chk=false;
			}
			if(mt<mf)
				chk=false;
			return chk;
		}
		bool find()
		{
			if((check(from)==true)&&(check(to)==true)&&(check_duration(from,to)==true))
			{
				return true;
			}
			else
			return false;
		}
		/*void copydate()
		{
			strcpy(from,date1);
			strcopy(to,date2);
		}*/


	void apply_leave(int n=0)
	{
	
	char date1[10];
	char temp[2],yr[4];
	char date2[10];
	int fd,fm,fy,td,tm,ty;
	if(n==1)
	{
		permission=false;
		cout<<"\n\t\t\t\t    Enter from date(dd)   : ";
		SetConsoleTextAttribute(h,12);
		cin>>temp;
		SetConsoleTextAttribute(h,14);
		strcpy(date1,temp);
		strcat(date1,"-");
		cout<<"\n\t\t\t\t    Enter from month(mm)  : ";
		SetConsoleTextAttribute(h,12);
		cin>>temp;
		SetConsoleTextAttribute(h,14);
		strcat(date1,temp);
		strcat(date1,"-");
		cout<<"\n\t\t\t\t    Enter from year(yyyy) : ";
		SetConsoleTextAttribute(h,12);
		cin>>yr;
		SetConsoleTextAttribute(h,14);
		strcat(date1,yr);
		strcpy(from,date1);
		//strcpy(frm,from);
		cout<<"\n\t\t\t\t    Enter to date(dd)     : ";
		SetConsoleTextAttribute(h,12);
		cin>>temp;
		SetConsoleTextAttribute(h,14);
		strcpy(date2,temp);
		strcat(date2,"-");
		cout<<"\n\t\t\t\t    Enter to month(mm)    : ";
		SetConsoleTextAttribute(h,12);
		cin>>temp;
		SetConsoleTextAttribute(h,14);
		strcat(date2,temp);
		strcat(date2,"-");
		cout<<"\n\t\t\t\t    Enter to year(yyyy)   : ";
		SetConsoleTextAttribute(h,12);
		cin>>yr;
		SetConsoleTextAttribute(h,14);
		strcat(date2,yr);
		strcpy(from,date1);
		strcpy(to,date2);
		fd=((from[0]-48)*10)+(from[1]-48);
		fm=((from[3]-48)*10)+(from[4]-48);
		fy=((from[6]-48)*1000)+((from[7]-48)*100)+((from[8]-48)*10)+(from[9]-48);
		td=((to[0]-48)*10)+(to[1]-48);
		tm=((to[3]-48)*10)+(to[4]-48);
		ty=((to[6]-48)*1000)+((to[7]-48)*100)+((to[8]-48)*10)+(to[9]-48);
			if(check(from)==false)
				{
					SetConsoleTextAttribute(h,4);
					cout<<endl<<"\n\t\t\tWrong input for from date";
					SetConsoleTextAttribute(h,14);
					return;
				}
			if(check(to)==false)
				{
					SetConsoleTextAttribute(h,4);
					cout<<endl<<"\n\t\t\tWrong input for to date";
					SetConsoleTextAttribute(h,14);
					return;
				}
			if(find()==true)
			{
				SetConsoleTextAttribute(h,14);
				cout<<"\n\t\t\t\t    Enter Reason for Leave : ";
				SetConsoleTextAttribute(h,12);
				cin.ignore();
				cin.getline(reason,200);
				applied=true;
				SetConsoleTextAttribute(h,10);
				cout<<endl<<"\n\t\t\tLeave Saved."<<endl;
				SetConsoleTextAttribute(h,14);
			}
			else
			{
				SetConsoleTextAttribute(h,4);
				cout<<endl<<"\n\t\t\tFrom date cannot be greater than to date";
				SetConsoleTextAttribute(h,14);
				return;
			}
		
	}
	
			
			if((find()==true))
			{
				//cout<<"From: "<<fd<<"-"<<fm<<"-"<<fy<<endl;
				//cout<<"To: "<<td<<"-"<<tm<<"-"<<ty<<endl;
				cout<<"\n\n\t\t\tReason       : ";
				SetConsoleTextAttribute(h,12);
				cout<<reason<<endl;
				SetConsoleTextAttribute(h,14);
				cout<<"\n\n\t\t\tLeave status : ";
				SetConsoleTextAttribute(h,12);
				cout<<((permission!=true)?"Not Approved":"Approved")<<endl;
			}
			else{
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\tleave not yet appplied"<<endl;
			SetConsoleTextAttribute(h,14);
			}
	}		
};

class profile
{
	public:
	char father[50],mother[50],address[100],phone[15],blood[4],email[50],name[50];
	
		
		//functios for input 
		void get_profile()
		{
			char temp_name[50],temp_phone[15],temp_blood[4],temp_email[50],temp_father[50],temp_mother[50];
			int r=1;
			cout<<"\n\t\t\tEnter details of the Student mentioned as below, in the same order"<<endl;
			cout<<"\n\t\t\tStudent's name, Father's name, Mother's name, Address, phone, blood group, Email-ID"<<endl;
			cin.ignore();
			SetConsoleTextAttribute(h,12);
			
			//Student Name
			cout<<"\n\t\t\t\t    ";
			cin.getline(temp_name,50);
			for(int p=0;temp_name[p]!='\0';++p)
			{
				if(!isalpha(temp_name[p]))
				{
					r=0;
					cout<<"\n\t\t\t";
					SetConsoleTextAttribute(h,4);
					cout<<"Invalid Name format"<<endl;
					SetConsoleTextAttribute(h,14);
				}
				if(r==0){
					return;
				}
			}
			strcpy(name,temp_name);	
			
			//Father Name
			cout<<"\n\t\t\t\t    ";
			cin.getline(temp_father,50);
			for(int p=0;temp_father[p]!='\0';++p)
			{
				if(!isalpha(temp_father[p]))
				{
					r=0;
					cout<<"\n\t\t\t";
					SetConsoleTextAttribute(h,4);
					cout<<"Invalid Name format"<<endl;
					SetConsoleTextAttribute(h,14);
				}
				if(r==0){
					return;
				}
			}
			strcpy(father,temp_father);
			
			//Mother Name
			cout<<"\n\t\t\t\t    ";
			cin.getline(temp_mother,50);
			for(int p=0;temp_mother[p]!='\0';++p)
			{
				if(!isalpha(temp_mother[p]))
				{
					r=0;
					cout<<"\n\t\t\t";
					SetConsoleTextAttribute(h,4);
					cout<<"Invalid Name format"<<endl;
					SetConsoleTextAttribute(h,14);
				}
				if(r==0){
					return;
				}
			}
			strcpy(mother,temp_mother);
			
			//Address
			cout<<"\n\t\t\t\t    ";
			cin.getline(address,100);
			
			//Phone No
			cout<<"\n\t\t\t\t    ";
			cin.getline(temp_phone,15);
			for(int p=0;temp_phone[p]!='\0';++p)
			{
				if(!isdigit(temp_phone[p]))
				{
					r=0;
					cout<<"\n\t\t\t";
					SetConsoleTextAttribute(h,4);
					cout<<"Invalid Phone format"<<endl;
					SetConsoleTextAttribute(h,14);
				}
				if(r==0){
					return;
				}
			}
			strcpy(phone,temp_phone);
			
			//Blood Group
			cout<<"\n\t\t\t\t    ";
			cin.getline(temp_blood,4);
			if((strcmp(temp_blood,"A-")!=0&&strcmp(temp_blood,"B-")!=0&&strcmp(temp_blood,"A+")!=0&&strcmp(temp_blood,"B+")!=0&&strcmp(temp_blood,"AB+")!=0&&strcmp(temp_blood,"AB-")!=0&&strcmp(temp_blood,"O+")!=0&&strcmp(temp_blood,"O+")!=0&&strcmp(temp_blood,"Hh")!=0))
			{
				cout<<"\n\t\t\t";
				SetConsoleTextAttribute(h,4);
				cout<<"Invalid Blood Group"<<endl;
				SetConsoleTextAttribute(h,14);
				return;
			}
			strcpy(blood,temp_blood);
			
			//Email
			cout<<"\n\t\t\t\t    ";
			cin.getline(temp_email,50);
//			r = 1;
//			if(strlen(temp_email)<9)
//			{
//				r = 0;
//				cout<<"\n\t\t\t";
//				SetConsoleTextAttribute(h,4);
//				cout<<"Invalid Email format"<<endl;
//				SetConsoleTextAttribute(h,14);
//			}
//			else{
//				
//				char b[50];
//				int i;
//				for(i=0;i<8;++i)
//				{
//					b[i]=temp_email[strlen(temp_email)-i-1];
//				}
//				b[i]='\0';	
//				if(strcmp(b,"moc.zyx@")!=0)
//				{
//					r = 0;
//					cout<<"\n\t\t\t";
//					SetConsoleTextAttribute(h,4);
//					cout<<"Invalid Email format"<<endl;
//					SetConsoleTextAttribute(h,14);
//				}
//			}
//			if(r==0){
//				return;
//			}
			strcpy(email,temp_email);
			
			//If No Error Add
			if(r==1){
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,10);
				cout<<"Student Added Successfully";
				SetConsoleTextAttribute(h,14);		
			}
		}
		void print_profile()//??to print the details
		{
			cout<<"\n\t\t\t\t    Student's name : ";
			SetConsoleTextAttribute(h,12);
			cout<<name<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Father's name  : ";
			SetConsoleTextAttribute(h,12);
			cout<<father<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Mother's name  : ";
			SetConsoleTextAttribute(h,12);
			cout<<mother<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Address        : ";
			SetConsoleTextAttribute(h,12);
			cout<<address<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Phone Number   : ";
			SetConsoleTextAttribute(h,12);
			cout<<phone<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Blood group    : ";
			SetConsoleTextAttribute(h,12);
			cout<<blood<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Email-ID       : ";
			SetConsoleTextAttribute(h,12);
			cout<<email<<endl;
			SetConsoleTextAttribute(h,14);
		}
		void modify_profile()
		{
			char a[50];
			char detail[20];
			cout<<"\n\t\t";
			cout<<"Enter the detail name you want to modify as given in the profile : ";
			cin.ignore();
			SetConsoleTextAttribute(h,12);
			cin.getline(detail,20);
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t";
			cout<<"Enter the changes you want to make                               : ";
			//cin.ignore();
			SetConsoleTextAttribute(h,12);
			cin.getline(a,50);
			SetConsoleTextAttribute(h,14);
			cout<<endl;
			if(strcmpi(detail,"Father's name")==0)
			{
				int r=1;
				for(int p=0;a[p]!='\0';++p)
				{
					if(!isalpha(a[p]))
					{
						r=0;
						cout<<"\n\t\t";
						SetConsoleTextAttribute(h,4);
						cout<<"Invalid Name format"<<endl;
						SetConsoleTextAttribute(h,14);
						break;
					}
				}
			if(r==1)
			{
				strcpy(father,a);
				SetConsoleTextAttribute(h,10);
				cout<<"\n\t\t";
				cout<<"Changes Saved."<<endl;
				SetConsoleTextAttribute(h,14);
		}
			}
			else if(strcmpi(detail,"mother's name")==0)
			{
				int r=1;
				for(int p=0;a[p]!='\0';++p)
				{
					if(!isalpha(a[p]))
					{
						r=0;
						cout<<"\n\t\t";
						SetConsoleTextAttribute(h,4);
						cout<<"Invalid Name format"<<endl;
						SetConsoleTextAttribute(h,14);
						break;
					}
				}
			if(r==1)
			{
				strcpy(mother,a);
				cout<<"\n\t\t\t";
				SetConsoleTextAttribute(h,10);
				cout<<"Changes Saved."<<endl;
				SetConsoleTextAttribute(h,14);
		}
			}
			else if(strcmpi(detail,"Student's name")==0)
			{
				int r=1;
				for(int p=0;a[p]!='\0';++p)
				{
					if(!isalpha(a[p]))
					{
						r=0;
						cout<<"\n\t\t";
						SetConsoleTextAttribute(h,4);
						cout<<"Invalid Name format"<<endl;
						SetConsoleTextAttribute(h,14);
						break;
					}
				}
				if(r==1)
				{
				strcpy(name,a);
				cout<<"\n\t\t\t";
				SetConsoleTextAttribute(h,10);
				cout<<"Changes Saved."<<endl;
				SetConsoleTextAttribute(h,14);
			}
			}
			else if(strcmpi(detail,"Address")==0)
			{

				strcpy(address,a);
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,10);
				cout<<"Changes Saved."<<endl;
				SetConsoleTextAttribute(h,14);
			}
				else if(strcmpi(detail,"Phone number")==0)
			{
				int z=1;
				for(int q=0;a[q]!='\0';++q)
				{
					if(!isdigit(a[q]))
					{
						z=0;
						cout<<"\n\t\t";
						SetConsoleTextAttribute(h,4);
						cout<<"Invalid number"<<endl;
						SetConsoleTextAttribute(h,14);
						break;
					}
						
				}
				if(z==1)
				{
			
				strcpy(phone,a);
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,10);
				cout<<"Changes Saved."<<endl;
				SetConsoleTextAttribute(h,14);
			}
			}
				else if(strcmpi(detail,"Blood group")==0)
			{
				if(strcmp(a,"A-")!=0&&strcmp(a,"B-")!=0&&strcmp(a,"A+")!=0&&strcmp(a,"B+")!=0&&strcmp(a,"AB+")!=0&&strcmp(a,"AB-")!=0&&strcmp(a,"O+")!=0&&strcmp(a,"O+")!=0&&strcmp(a,"Hh")!=0)
				{	
					cout<<"\n\t\t";
					SetConsoleTextAttribute(h,4);
					cout<<"Invalid Blood group"<<endl;
					SetConsoleTextAttribute(h,14);
				}
				else
				{
				strcpy(blood,a);
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,10);
				cout<<"Changes Saved."<<endl;
				SetConsoleTextAttribute(h,14);
				}
			}
				else if(strcmpi(detail,"Email-ID")==0)
			{
				if(strlen(a)<9)
				{
					cout<<"\n\t\t";
					SetConsoleTextAttribute(h,4);
					cout<<"Invalid Email format"<<endl;
					SetConsoleTextAttribute(h,14);
				}else{
				
					char b[50];
					int i;
					for(i=0;i<8;++i)
					{
						b[i]=a[strlen(a)-i-1];
					}
					b[i]='\0';
					
				if(strcmp(b,"moc.zyx@")!=0)
				{
					cout<<"\n\t\t";
					SetConsoleTextAttribute(h,4);
					cout<<"Invalid Email format"<<endl;
					SetConsoleTextAttribute(h,14);
				}else{
				
				strcpy(email,a);
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,10);
				cout<<"Changes Saved."<<endl;
				SetConsoleTextAttribute(h,14);
				 }}
			}
			
			else
			{
				cout<<"\n\t\t";
				SetConsoleTextAttribute(h,4);
				cout<<"Entered detail is not same as given in the profile"<<endl;
				SetConsoleTextAttribute(h,14);
			}
			
		}
	};

class book{
	public:
		int bookid;
		char title[30];
		char category[30];
		float penalty;
		book(){
			bookid=-1;
			strcpy(title,"no title");
			strcpy(category,"no category");
			penalty = 0;
		}
		void get_book(){
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Bookid     : ";
			SetConsoleTextAttribute(h,12);
			cin>>bookid;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Book Title : ";
			SetConsoleTextAttribute(h,12);
			cin.ignore();
			cin.getline(title,29);
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Category   : ";
			SetConsoleTextAttribute(h,12);
			cin>>category;
			SetConsoleTextAttribute(h,14);			
			cout<<"\n\t\t\t\t    Penalty    : ";
			SetConsoleTextAttribute(h,12);
			cin>>penalty;
			SetConsoleTextAttribute(h,14);
		}
		void print_book(){
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Bookid     : ";
			SetConsoleTextAttribute(h,12);
			cout<<bookid<<endl<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Book Title : ";
			SetConsoleTextAttribute(h,12);
			cout<<title<<endl<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Category   : ";
			SetConsoleTextAttribute(h,12);
			cout<<category<<endl<<endl;
			SetConsoleTextAttribute(h,14);			
			cout<<"\n\t\t\t\t    Penalty    : ";
			SetConsoleTextAttribute(h,12);
			cout<<penalty<<endl<<endl;
			SetConsoleTextAttribute(h,15);
			cout<<"\t\t\t\t---------------------------------------"<<endl;
			SetConsoleTextAttribute(h,14);
		}
};

struct nodeb{
	book x;
	nodeb *next;
}*topb=NULL;

bool search(int a[],int n, int e){
	int i=0;
	for(i = 0; i < n; i++){
        if(a[i] == e){
            return true;
            break;
        }
    }
    if(i == n){
		return false;
    }
}

int bookid[50]={-1};
int count=0;

extract_to_node(book b){
	ifstream fin("book.dat",ios::in|ios::binary);
	fin.seekg(ios::beg);
	while(fin.read((char*)&b,sizeof(b))){
		if(search(bookid,50,b.bookid)){
		}
		else{
			bookid[count]=b.bookid;
			count++;
			nodeb *tempb;
			tempb = new nodeb;
			tempb->x=b;
			tempb->next=topb;
			topb = tempb;
		}
	}
	fin.close();
}


//All student related functions and classes

//class student contains all student info
class student
{
	public:
	profile p;
	marks m;
	leave l;
	book b;
	char reg[20];
	int room_no;
	char password[20];
	bool b_applied,b_permission;
	int temp_bookid;
	char temp_bookname[30];
	char reason[50];
//	int pcount;
//	int acount;
	student *next;
	student()
	{
		b_applied=false;
		b_permission=false;
		}	
	void get_student()
	{
		cout<<"\n\t\t\t\t    Reg No   : ";
		SetConsoleTextAttribute(h,12);
		cin>>reg;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Password : ";
		SetConsoleTextAttribute(h,12);
		cin>>password;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Room No  : ";
		SetConsoleTextAttribute(h,12);
		cin>>room_no;
		SetConsoleTextAttribute(h,14);
		p.get_profile();
	}
	void change_password(){
		char current_pass[20];
		char new_pass[20];
		cout<<"\n\t\t\t\t    Enter current password : ";
		SetConsoleTextAttribute(h,12);
		cin>>current_pass;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Enter the new password : ";
		SetConsoleTextAttribute(h,12);
		cin>>new_pass;
		SetConsoleTextAttribute(h,14);
		if(strcmpi(current_pass,password)==0){
			if(strcmpi(new_pass,password)==0){
				SetConsoleTextAttribute(h,4);
				cout<<"\n\t\t\tYou have entered the same password."<<endl;
				SetConsoleTextAttribute(h,14);
				return;				
			}
			strcpy(password,new_pass);
			SetConsoleTextAttribute(h,10);
			cout<<"\n\t\t\tPassword Saved."<<endl;
			SetConsoleTextAttribute(h,14);
		}
		else{
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\tPassword doesnot match"<<endl;
			SetConsoleTextAttribute(h,14);
		}
	}
	
	void view_books(){
		book b1;
		extract_to_node(b1);
		nodeb *tempb = topb;
		while(tempb){
			tempb->x.print_book();
			tempb=tempb->next;
		}
	}
	
	void search_book(char *t){
		book b1;
		int bcounter=0;
		extract_to_node(b1);
		nodeb *tempb = topb;
		while(tempb){
			if(!strcmp(tempb->x.title,t)){
				tempb->x.print_book();
				tempb=tempb->next;
				bcounter=1;
			}
			tempb=tempb->next;		
		}
		if(bcounter == 0){
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\t\t    No Books Found"<<endl;
			SetConsoleTextAttribute(h,14);
		}
	}
	
	void apply_book(int n=0)
	{
		int c=0;
	if(n==1)
	{
		b_permission=false;
		cout<<"\n\t\t\t\t    Enter Book Id   : ";
		SetConsoleTextAttribute(h,12);
		cin>>temp_bookid;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Enter Book name : ";
		SetConsoleTextAttribute(h,12);
		cin.ignore();
		cin.getline(temp_bookname,29);
//		cin>>temp_bookname;
		SetConsoleTextAttribute(h,14);
		
		if(search(bookid,50,temp_bookid)){
		
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Enter Reason : ";
			SetConsoleTextAttribute(h,12);
			cin>>reason;
			b_applied=true;
			SetConsoleTextAttribute(h,10);
			cout<<endl<<"\n\t\t\tApplication Saved."<<endl;
			SetConsoleTextAttribute(h,14);
		}
		else{
			SetConsoleTextAttribute(h,4);
			cout<<endl<<"\n\t\t\tBook Not Found."<<endl;
			SetConsoleTextAttribute(h,14);
			return;
			c=1;
		}
				
	}		
	
		if(c==1){
			return;
		}
			if(search(bookid,50,temp_bookid))
			{
				cout<<"\n\n\t\t\tReason       : ";
				SetConsoleTextAttribute(h,12);
				cout<<reason<<endl;
				SetConsoleTextAttribute(h,14);
				cout<<"\n\n\t\t\tIssue status : ";
				SetConsoleTextAttribute(h,12);
				cout<<((b_permission==true)?"Approved":"Not Approved")<<endl;
			}
			else{
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\tApplication not yet appplied"<<endl;
			SetConsoleTextAttribute(h,14);
			}
	}
	
//	void print_attendence()
//	{
//		cout<<"\n\t\t\t\t    Number of days present : "<<pcount<<endl;
//		cout<<"\n\t\t\t\t    Number of days absent  : "<<acount<<endl;
//		cout<<"\n\t\t\t\t    Attendance Percentage  : "<<((pcount*100)/(pcount+acount))<<"%";
//	}
	
	
};

struct node
{
	student x;
	node *next;
}*top=NULL;



bool s_search(int a[],int n, int e){
	int i=0;
	for(i = 0; i < n; i++){
        if(a[i] == e){
            return true;
            break;
        }
    }
    if(i == n){
		return false;
    }
}


//extracts all the data in the student file to an array of type student(s[])
void extract_to(student s[])
{
	
	ifstream in("student.dat",ios::in|ios::binary|ios::app);
	in.seekg(ios::beg);
	int i;
	while(in.read((char*)&s[i],sizeof(s[i])))
	{
		if(s_search(studentid,50,s[i].room_no)){
		}
		else{
			studentid[s_count]=s[i].room_no;
			s_count++;
			node *temp;
			temp=new node;
			temp->x=s[i];
			temp->next=top;
			top=temp;
		}	
	}
	in.close();
	
}	

//returns position of the object in student file with reg_no=rno
/* int find_student(int rno)
{
	student s;
	ifstream fin;
	fin.open("student.dat",ios::in|ios::binary);
	while(fin.read((char*)&s,sizeof(s)))
	{
		if(rno==s.reg)
		{
			return(fin.tellg()-sizeof(s));
		}
	}
	fin.close();
	
} */
node* search(node *a,char r[])
{
	node* temp1=a;
	int n=s_size;
	int m=sqrt(n);
	int i;
	int order=0;
	//cout<<a->x.reg<<"a";
	a=a->next->next->next;
	
	if(strcmp(temp1->x.reg,temp1->next->x.reg)>=0)
	  order=-1;
	else 
	  order=1;
	  
	if(order>0)
	{	
	while(m<n&&strcmp(r,a->x.reg)>=0)
	{
		//cout<<"entered asc while";
		for(i=0; i<sqrt(n); i++)
		{
			if(a!=NULL)
		      a=a->next;
		  temp1=temp1->next;
		}
		m+=sqrt(n);
	}
	for(i=0; i<sqrt(n); i++)
	{
	  if(strcmp(r,temp1->x.reg)==0)
		  return temp1;
		temp1=temp1->next;
	}
	}
    
    else
	{
	while(m<n&&strcmp(r,a->x.reg)<=0)
	{
		//cout<<"entered des while";
		//cout<<"value of temp1"<<temp1->x.reg<<"\n";
		for(i=0; i<sqrt(n); i++)
		{
			if(a!=NULL)
		      a=a->next;
		  	temp1=temp1->next;
		}
		//cout<<"for over";
		m+=sqrt(n);
	}
	//cout<<"value of temp1"<<temp1->x.reg<<"\n";
	for(i=0; i<sqrt(n); i++)
	{
	  if(strcmp(r,temp1->x.reg)==0)
		  return temp1;
		temp1=temp1->next;
	}
	}

	cout<<"Not found";
	system("pause");
	return NULL;		
}
//the student login page(asks for password and shows the student menu) 
void s_login()
{
	char r[20];char p[20],pos;
	student s1[s_size],s;
	
	SetConsoleTextAttribute(h,14);
	cout<<"\n\t\t\t\tReg No   : ";
	SetConsoleTextAttribute(h,12);
	cin>>r;
	SetConsoleTextAttribute(h,14);
	
	/*ifstream in("student.dat",ios::in|ios::binary|ios::app);
	in.seekg(ios::beg);
	int i;
	for(i=0;i<3;i++)
	{
		in.read((char*)&s1[i],sizeof(s1[i]));
	}
	in.close();*/
	extract_to(s1);
	
	/*ifstream i("student.dat",ios::in|ios::binary);
	i.seekg(pos);
	i.read((char*)&s,sizeof(s));
	i.close();
	if(strcmp(s.p.name,"Nil")==0)
	{
		cout<<"Reg number not found!!";
		return;
	}*/
	node *temp=top;
	while(temp)
	{
		if(strcmp(r,temp->x.reg)==0)
		{
			s=temp->x;
			break;
		}
		temp=temp->next;
			
	}
//	temp=search(temp,r);
//	if(temp==NULL)
//		return;
//	s=temp->x;
	cout<<"\n\t\t\t\tPassword : ";
	SetConsoleTextAttribute(h,12);
	cin>>p;
	SetConsoleTextAttribute(h,14);
	if(strcmp(p,s.password)!=0)
	{
		SetConsoleTextAttribute(h,4);
		cout<<"\n\n\t\tWrong Reg no/Password combination!!"<<endl;
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t";
		system("pause");
		SetConsoleTextAttribute(h,14);
		return;
	}
		int ch=0;
		while(ch!=9)
		{
		system("cls");
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n";
		SetConsoleTextAttribute(h,6);
		cout<<"\t\t\t\t            WELCOME "<<s.p.name;
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,14);
//		cout<<"\n\t\t\t\tSTUDENT LOGIN\n"<<endl;
//		cout<<"Student reg no: "<<s.reg<<endl<<endl;
		cout<<"\n\n\t\t\t\t    1\t:\tVIEW PROFILE\n\n\t\t\t\t    2\t:\tMODIFY PROFILE\n\n\t\t\t\t    3\t:\tVIEW MARKS\n\n\t\t\t\t    4\t:\tAPPLY LEAVE\n\n\t\t\t\t    5\t:\tVIEW BOOKS\n\n\t\t\t\t    6\t:\tSEARCH BOOK\n\n\t\t\t\t    7\t:\tAPPLY BOOK\n\n\t\t\t\t    8\t:\tCHANGE PASSWORD\n\n\t\t\t\t    9\t:\tRETURN TO MAIN MENU\n\n\t\t\t\t"<<endl;
//		cout<<"1-View profile\n2-Modify profile\n3-View marks\n4-Apply leave\n5-To view leave\n6-To view attendance\n7-To change password\n8-Return to main menu\n\nEnter your choice : ";
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t\tEnter Your Choice : ";	
		SetConsoleTextAttribute(h,12);
		cin>>ch;
		SetConsoleTextAttribute(h,14);
        switch(ch)
		{
			case 1:
				cout<<endl;
				s.p.print_profile();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case 2:
				cout<<endl;
				s.p.print_profile();
				cout<<endl;
				s.p.modify_profile();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case 3:
				cout<<endl;
				s.m.print_marks();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case 4:
				cout<<endl;
			   	s.l.apply_leave(1);
			   	cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
			   	system("pause");
			   	SetConsoleTextAttribute(h,14);
			    break;
			case 5:
				cout<<endl;
				s.view_books();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case 6:
				cout<<endl;
				char t[30];
				SetConsoleTextAttribute(h,14);
				cout<<"\n\n\t\t\tEnter the Book Name : ";
				cin.ignore();
				SetConsoleTextAttribute(h,12);
				cin.getline(t,29);
				SetConsoleTextAttribute(h,14);
				s.search_book(t);
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case 7:
				cout<<endl;
			   	s.apply_book(1);
			   	cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
			   	system("pause");
			   	SetConsoleTextAttribute(h,14);
			    break;
			case 8:
				cout<<endl;
				s.change_password();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case 9:
			    break;
		    default:
		    	//cout<<endl;
		    	//cout<<"You have entered Invalid option";
		    	//cout<<endl;
		    	//system("pause");
		    	break;
				    
		}		
    }
        temp->x=s;
		ofstream o("student.dat",ios::out|ios::binary);
		//o.seekp(pos);
		temp=top;
        while(temp)
        {
        	s=temp->x;
			o.write((char*)&s,sizeof(s));
			temp=temp->next;
		}
		o.close();
}




//All faculty related functions and classes

//class faculty contains all faculty info
class faculty
{
	public:
	char fac_no[20];
	char sub_code[10];
	char name[50];
	char password[20];
	//student s[100];
				
	
	
	void get_faculty()
	{
		cout<<"\n\t\t\t\t    Faculty No   : ";
		SetConsoleTextAttribute(h,12);
		cin>>fac_no;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Subject Code : ";
		SetConsoleTextAttribute(h,12);
		cin>>sub_code;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Faculty Name : ";
		SetConsoleTextAttribute(h,12);
		cin.ignore();
		cin.getline(name,50);
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Password     : ";
		SetConsoleTextAttribute(h,12);
		cin>>password;	
		SetConsoleTextAttribute(h,14);
	}
	
	void change_password(){
		char current_pass[20];
		char new_pass[20];
		cout<<"\n\t\t\t\t    Enter current password : ";
		SetConsoleTextAttribute(h,12);
		cin>>current_pass;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Enter the new password : ";
		SetConsoleTextAttribute(h,12);
		cin>>new_pass;
		SetConsoleTextAttribute(h,14);
		if(strcmpi(current_pass,password)==0){
			if(strcmpi(new_pass,password)==0){
				SetConsoleTextAttribute(h,4);
				cout<<"\n\t\t\tYou have entered the same password."<<endl;
				SetConsoleTextAttribute(h,14);
				return;				
			}
			strcpy(password,new_pass);
			SetConsoleTextAttribute(h,10);
			cout<<"\n\t\t\tPassword Saved."<<endl;
			SetConsoleTextAttribute(h,14);
		}
		else{
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\tPassword doesnot match"<<endl;
			SetConsoleTextAttribute(h,14);
		}
	}
	
	void print_faculty()
	{
		cout<<"\n\t\t\t\t    Faculty No   : ";
		SetConsoleTextAttribute(h,12);
		cout<<fac_no<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Subject Code : ";
		SetConsoleTextAttribute(h,12);
		cout<<sub_code<<endl;
		SetConsoleTextAttribute(h,14);
	    cout<<"\n\t\t\t\t    Faculty Name : ";
	    SetConsoleTextAttribute(h,12);
		cout<<name<<endl;	
		SetConsoleTextAttribute(h,14);
	}
	
	void view_marks()
	{
//		student s[s_size];
//		extract_to(s);
//		for(int i=0;i<s_size;i++)
//		{
//			cout<<"Reg no:"<<s[i].reg<<'\t';
//			s[i].m.print_marks(sub_code);
//		}
		student s[s_size];
		node* temp = top;
//		ifstream in("student.txt",ios::in);
//		in.seekg(ios::beg);
//		while(in.read((char*)&s,sizeof(s)))
//		{
//			cout<<"Reg no:"<<s.reg<<'\t';
//			s.m.print_marks(sub_code);
//		}
//		in.close();
		while(temp){
			cout<<"\n\t\t\tReg No : "<<temp->x.reg;
			temp->x.m.print_marks(sub_code);
			temp = temp->next;
		}
	}
	void enter_marks()
	{
		student s[s_size];
//		extract_to(s);
		
		char reg_no[20]="0";
		while(strcmp(reg_no,"-1")!=0)
		{
//			view_marks();
//			cout<<endl<<"Enter the Reg no of the student to enter marks or -1 to quit: ";
//			cin>>reg_no;
//			for(int i=0;i<s_size;i++)
//			{
//				if(strcmp(reg_no,s[i].reg)==0)
//				{
//					s[i].m.enter_marks(sub_code);
//				}
//			}
//			ofstream o("student.dat",ios::out|ios::binary);
//			int i;
//			for(i=0;i<s_size;i++)
//			{
//				o.write((char*)&s[i],sizeof(s[i]));
//			}

			view_marks();
			SetConsoleTextAttribute(h,15);
			cout<<"\t\t-----------------------------------------------------------------"<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<endl<<"\n\t\t\tEnter Reg No of the Student to Enter Marks or -1 to Quit : ";
			SetConsoleTextAttribute(h,12);
			cin>>reg_no;
			SetConsoleTextAttribute(h,14);
			node* temp = top;
			while(temp)
			{
				if(strcmp(reg_no,temp->x.reg)==0)
				{
					temp->x.m.enter_marks(sub_code);
				}
				temp=temp->next;
			}
			ofstream o("student.dat",ios::out|ios::binary);
			int i;
			while(o.write((char*)&s[i],sizeof(s[i])))
			{
				
			}
			
		}
		
	}
	//void check_reval()//mark correction
};

struct nodef
{
	faculty y;
	nodef *next;
}*topf=NULL;

nodef* search(nodef *tempf,char r[])
{
	if(tempf==NULL)
		return NULL;
	if(strcmp(tempf->y.fac_no,r)==0)
		return tempf;
	search(tempf->next,r);
}
//the faculty login page(asks for password and shows the faculty menu) 
void f_login()
{
	/*ifstream in("faculty.dat",ios::in|ios::binary);
	faculty f1;
	in.seekg(ios::beg);
	for(int i=0;i<f_size;i++)
	{
		in.read((char*)&f1,sizeof(f1));
		f1.print_faculty();
	}
	in.close();
	system("pause");*/
	
	
//	cout<<"\n\t\t\t\tReg No   : ";
//	
//	cin>>r;
//	SetConsoleTextAttribute(h,14);
//	
	
	char p[20],r[20];
	faculty f;
	SetConsoleTextAttribute(h,14);
	cout<<"\n\t\t\t\tFaculty no : "; 
	SetConsoleTextAttribute(h,12);
	cin>>r;
	SetConsoleTextAttribute(h,14);
	
	ifstream in("faculty.dat",ios::in|ios::binary);
	in.seekg(ios::beg);
	int i;
	nodef *tempf;
	while(in.read((char*)&f,sizeof(f)))
	{
		tempf=new nodef;
		tempf->y=f;
		tempf->next=topf;
		topf=tempf;
	}
	in.close();
	
	while(tempf){
		if(strcmp(r,tempf->y.fac_no)==0)
		{
			f=tempf->y;
			break;
		}
		tempf=tempf->next;
	}
	
//	tempf=search(tempf,r);
//	f=tempf->y;
	cout<<"\n\t\t\t\tPassword   : ";
	SetConsoleTextAttribute(h,12);
	cin>>p;
	SetConsoleTextAttribute(h,14);
	if(strcmp(p,f.password)!=0)
	{
		SetConsoleTextAttribute(h,4);
		cout<<"\n\t\t\tWrong Reg no/Password combination!!"<<endl;
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t\t";
		system("pause");
		SetConsoleTextAttribute(h,14);
		return;
	}

		char ch='0';
		while(ch!='5')
		{
		system("cls");
		
		
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n";
		SetConsoleTextAttribute(h,6);
		cout<<"\t\t\t\t            WELCOME "<<f.name;
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\n\t\t\t\t    1\t:\tVIEW PROFILE\n\n\t\t\t\t    2\t:\tVIEW STUDENT MARKS\n\n\t\t\t\t    3\t:\tENTER STUDENT MARKS\n\n\t\t\t\t    4\t:\tCHANGE PASSWORD\n\n\t\t\t\t    5\t:\tRETURN TO MAIN MENU\n\n\t\t\t\t"<<endl;
//		cout<<"1-View profile\n2-View Students Marks\n3-Enter student marks\n4-To change password\n5-Return to main menu\n\nEnter your choice : ";
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t\tEnter Your Choice : ";	
		SetConsoleTextAttribute(h,12);
		cin>>ch;
		SetConsoleTextAttribute(h,14);
		switch(ch)
		{
			case '1':
				cout<<endl;
				f.print_faculty();
				SetConsoleTextAttribute(h,6);
				cout<<"\n\t\t\t";
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case '2':
				cout<<endl;
				f.view_marks();
				SetConsoleTextAttribute(h,6);
				cout<<"\n\t\t\t";
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case '3':
				cout<<endl;
				f.enter_marks();
				SetConsoleTextAttribute(h,6);
				cout<<"\n\t\t\t";
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case '4':
				cout<<endl;
				f.change_password();
				SetConsoleTextAttribute(h,6);
				cout<<"\n\t\t\t";
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case '5':
			    break;
		    default: ;
		    	//cout<<endl;
		    	//cout<<"You have entered Invalid option";
		    	//cout<<endl;
				//system("pause");
			}		
        }
        /*ofstream o("faculty.dat",ios::out|ios::binary);
		o.seekp(pos);
		o.write((char*)&f,sizeof(f));
		o.close();*/
		tempf->y=f;
		ofstream o("faculty.dat",ios::out|ios::binary);
		tempf=topf;
		while(tempf)
		{
			f=tempf->y;
			o.write((char*)&f,sizeof(f));
			tempf=tempf->next;
		}
		o.close();
		
}


//All warden related functions and classes
//class warden contains all warden info
class warden
{
	
	
	//student s[100];
	
	public:
	char ward_no[20];
	char name[20];
	char password[20];
	
	/*void extract_to(student& a[])
	{			
	}*/	
	void get_warden()
	{
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Warden no : ";
		SetConsoleTextAttribute(h,12);	
		cin>>ward_no;
		cout<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Name      : ";	
		SetConsoleTextAttribute(h,12);
		cin>>name;
		cout<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Password  : ";	
		SetConsoleTextAttribute(h,12);
		cin>>password;
		cout<<endl;
		SetConsoleTextAttribute(h,14);
	}
	
	void change_password(){
		char current_pass[20];
		char new_pass[20];
		cout<<"\n\t\t\t\t    Enter current password : ";
		SetConsoleTextAttribute(h,12);
		cin>>current_pass;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Enter the new password : ";
		SetConsoleTextAttribute(h,12);
		cin>>new_pass;
		SetConsoleTextAttribute(h,14);
		if(strcmpi(current_pass,password)==0){
			if(strcmpi(new_pass,password)==0){
				SetConsoleTextAttribute(h,4);
				cout<<"\n\t\t\tYou have entered the Same Password."<<endl;
				SetConsoleTextAttribute(h,14);
				return;				
			}
			strcpy(password,new_pass);
			SetConsoleTextAttribute(h,10);
			cout<<"\n\t\t\tPassword Saved."<<endl;
			SetConsoleTextAttribute(h,14);
		}
		else{
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\tPassword doesnot match"<<endl;
			SetConsoleTextAttribute(h,14);
		}
	}
	
	void print_warden()
	{
//		cout<<"Warden no: "<<ward_no<<endl;
//		cout<<"Name: "<<name<<endl;
		cout<<"\n\t\t\t\t    Warden No :\t";
		SetConsoleTextAttribute(h,12);
		cout<<ward_no<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Name      :\t";
		SetConsoleTextAttribute(h,12);
		cout<<name<<endl;
		SetConsoleTextAttribute(h,14);
	}
//	void mark_attendance()
//	{
//		struct q
//		{
//			int pcount;
//			int acount;
//			q *next;
//		}*f=NULL,*r=NULL;
//	
//		student s[s_size];
//		extract_to(s);
//		q *temp;
//		
//		//has the object of the students from the file 
//		//input to the student object is done here
//		(temp)
//		{	
//			cout<<"Enter if Reg no: "<<s[i].reg<<" is present or absent (p/a): ";
//			char a;
//			temp=new q;
//			cin>>a;
//			if(a=='p')
//			{
//				temp->pcount=(++s[i].pcount);
//				temp->acount=s[i].acount;
//		}
//		   	else
//		   	
//		{
//				temp->acount=(++s[i].acount);
//				temp->pcount=s[i].pcount;
//		}
//			temp->next=NULL;
//			if (r==NULL)
//				f=temp;
//			else
//				r->next=temp;
//			r=temp;
//	   	}
//	   	int i=0;
//	   	q *temp1=f;
//	   	ofstream o("student.dat",ios::out|ios::binary);
//		o.seekp(ios::beg);
//		while(temp1)
//		{
//			s[i].pcount=temp1->pcount;
//			s[i].acount=temp1->acount;
//			o.write((char*)&s[i],sizeof(s[i]));
//			temp1=temp1->next;
//			++i;
//		}
//		o.close(); 
//	}
	void approve_leave()
	{
		student s[s_size];
		extract_to(s);
		char l;
		int flag=0;
		for(int i=0;i<s_size;i++)
		{
			if(s[i].l.applied==true)
			{
				flag=1;
				SetConsoleTextAttribute(h,14);
				cout<<"\n\n\t\t\tReg no : "<<s[i].reg<<" has applied leave."<<endl;
				s[i].l.apply_leave();
				SetConsoleTextAttribute(h,14);
				cout<<"\n\n\t\t\tDo you want to approve the leave? (y/n) "<<endl;
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t";
				cin>>l;
				SetConsoleTextAttribute(h,14);
				if(l=='y')
				{
					s[i].l.permission=true;
					s[i].l.applied=false;
				}
				else
				{
					s[i].l.permission=true;
					s[i].l.applied=false;
				}
				
			}
		}
		if(flag==0)
		{
			SetConsoleTextAttribute(h,4);
			cout<<endl<<"\n\t\t\t\t    No leave applications yet"<<endl;
			SetConsoleTextAttribute(h,14);
		}
		ofstream o("student.dat",ios::out|ios::binary);
		o.seekp(ios::beg);
		for(int i=0;i<s_size;i++)
		{
		o.write((char*)&s[i],sizeof(s[i]));
		}
		extract_to(s);
		o.close();
	}
	void warden_search()
	{
		student s[s_size];
		node *temp = top;
		extract_to(s);
		while(temp){
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Reg: ";
			SetConsoleTextAttribute(h,12);
			cout<<temp->x.reg;
			SetConsoleTextAttribute(h,14);
			cout<<"\tName : ";
			SetConsoleTextAttribute(h,12);
			cout<<temp->x.p.name;
			SetConsoleTextAttribute(h,14);
			cout<<"\tRoom No : ";
			SetConsoleTextAttribute(h,12);
			cout<<temp->x.room_no<<endl;
			SetConsoleTextAttribute(h,14);
			temp = temp->next;	
		}
//		for(int i=0;i<s_size;i++)
//		{
//			cout<<"Reg no: "<<s[i].reg<<"\tName :"<<s[i].p.name<<endl;
//		}
//		cout<<endl<<"Enter the reg no of the student whose profile you want to view: ";
//		char temp_reg[20];
//		cin>>temp_reg;
//		cout<<endl;
//		for(int i=0;i<s_size;i++)
//		{
//			if(strcmp(s[i].reg,temp_reg)==0)
//			{
//				s[i].p.print_profile();
//				cout<<"Room no: "<<s[i].room_no<<endl;
//				s[i].print_attendence();
//			}
//		}


//		ifstream in("student.dat",ios::binary|ios::in);
//		in.seekg(ios::beg);
//		while(in.read((char*)&s,sizeof(s)))
//		{
//			SetConsoleTextAttribute(h,14);
//			cout<<"\n\t\t\t\t    Reg: ";
//			SetConsoleTextAttribute(h,12);
//			cout<<s.reg;
//			SetConsoleTextAttribute(h,14);
//			cout<<"\tName : ";
//			SetConsoleTextAttribute(h,12);
//			cout<<s.p.name;
//			SetConsoleTextAttribute(h,14);
//			cout<<"\tRoom No : ";
//			SetConsoleTextAttribute(h,12);
//			cout<<s.room_no<<endl;
//			SetConsoleTextAttribute(h,14);
//		}
//		in.close();
//		
//		student s[s_size];
//		node* temp = top;
//		while(temp){
//			cout<<"Reg no: "<<temp->x.reg<<"\tName: "<<temp->x.p.name<<"\tRoom No: "<<temp->x.room_no<<endl;
//			temp = temp->next;
//		}
	}
};



struct nodew
{
	warden z;
	nodew *next;
}*topw=NULL;
//the warden login page(asks for password and shows the warden menu) 
void w_login()
{
	char r[20];char p[20];
	warden w;
	student s[s_size];
	extract_to(s);
	SetConsoleTextAttribute(h,14);
	cout<<"\n\t\t\t\tWarden no : "; 
	SetConsoleTextAttribute(h,12);
	cin>>r;
	SetConsoleTextAttribute(h,14);
	nodew *tempw;
	ifstream in("warden.dat",ios::in|ios::binary);
	in.seekg(ios::beg);
	int i;
	while(in.read((char*)&w,sizeof(w)))
	{
		tempw=new nodew;
		tempw->z=w;
		tempw->next=topw;
		topw=tempw;
	}
	in.close();
	
	while(tempw)
	{
		if(strcmp(r,tempw->z.ward_no)==0)
		{
			w=tempw->z;
			break;
		}
		tempw=tempw->next;
			
	}
	SetConsoleTextAttribute(h,14);
	cout<<"\n\t\t\t\tPassword  : ";
	SetConsoleTextAttribute(h,12);
	cin>>p;
	SetConsoleTextAttribute(h,14);
	if(strcmp(p,w.password)!=0)
	{
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,4);
		cout<<"Wrong Reg no/Password combination!!"<<endl;
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,6);
		system("pause");
		SetConsoleTextAttribute(h,14);
		return;
	}

		char ch='0';
		
		while(ch!='5')
		{
		system("cls");
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n";
		SetConsoleTextAttribute(h,6);
		cout<<"\t\t\t\t            WELCOME "<<w.name;
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
//		cout<<"\n\t\t\t\tWARDEN LOGIN\n"<<endl;
		SetConsoleTextAttribute(h,14);
//		cout<<"Warden no: "<<w.ward_no<<endl<<endl;
		cout<<"\n\n\t\t\t\t    1\t:\tVIEW PROFILE\n\n\t\t\t\t    2\t:\tAPPROVE LEAVE\n\n\t\t\t\t    3\t:\tVIEW STUDENT DETAILS\n\n\t\t\t\t    4\t:\tCHANGE PASSWORD\n\n\t\t\t\t    5\t:\tRETURN TO MAIN MENU\n\n"<<endl;
//		cout<<"1-View Profile\n2-Approve leave\n3-View student detail\n4-To change password\n5-Return to main menu\n\nEnter your choice : ";
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t\tEnter Your Choice : ";	
		SetConsoleTextAttribute(h,12);
		cin>>ch;
		SetConsoleTextAttribute(h,14);
		switch(ch)
		{
			case '1':
				cout<<endl;
				w.print_warden();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '2':
				cout<<endl;
				w.approve_leave();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '3':
				cout<<endl;
			    w.warden_search();
			    cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '4':
				cout<<endl;
			    w.change_password();
			    cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '5':
				break;
		    default: ;
		    	//cout<<endl;
		    	//cout<<"You have entered Invalid option";
		    	//cout<<endl;
				//system("pause");
				    
				}		
        }
        ofstream o("warden.dat",ios::out|ios::binary);
		tempw->z=w;
		tempw=topw;
        while(tempw)
        {
        	w=tempw->z;
		o.write((char*)&w,sizeof(w));
		tempw=tempw->next;
	}
		o.close();
}


//All librarian related functions and classes
//class libraian contains all librarian info

class librarian
{

	public:
	char lib_no[20];
	char name[20];
	char password[20];
	
	/*void extract_to(student& a[])
	{			
	}*/	
	void get_lib()
	{
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Librarian no   : ";
		SetConsoleTextAttribute(h,12);	
		cin>>lib_no;
		cout<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Librarian Name : ";	
		SetConsoleTextAttribute(h,12);
		cin>>name;
		cout<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Password       : ";	
		SetConsoleTextAttribute(h,12);
		cin>>password;
		cout<<endl;
		SetConsoleTextAttribute(h,14);
	}
	
	void change_password(){
		char current_pass[20];
		char new_pass[20];
		cout<<"\n\t\t\t\t    Enter current password : ";
		SetConsoleTextAttribute(h,12);
		cin>>current_pass;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Enter the new password : ";
		SetConsoleTextAttribute(h,12);
		cin>>new_pass;
		SetConsoleTextAttribute(h,14);
		if(strcmpi(current_pass,password)==0){
			if(strcmpi(new_pass,password)==0){
				SetConsoleTextAttribute(h,4);
				cout<<"\n\t\t\tYou have entered the Same Password."<<endl;
				SetConsoleTextAttribute(h,14);
				return;				
			}
			strcpy(password,new_pass);
			SetConsoleTextAttribute(h,10);
			cout<<"\n\t\t\tPassword Saved."<<endl;
			SetConsoleTextAttribute(h,14);
		}
		else{
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\tPassword doesnot match"<<endl;
			SetConsoleTextAttribute(h,14);
		}
	}
	
	void print_lib()
	{
		cout<<"\n\t\t\t\t    Librarian No   :\t";
		SetConsoleTextAttribute(h,12);
		cout<<lib_no<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Librarian Name :\t";
		SetConsoleTextAttribute(h,12);
		cout<<name<<endl;
		SetConsoleTextAttribute(h,14);
	}
	
	void add_book(){
		book b;
		b.get_book();
		if(b.bookid == 0 && b.penalty == 0 && strcpy(b.title,"no title")){
			return;
		}
		else{
			ofstream fout;
			fout.open("book.dat",ios::binary|ios::app);
			fout.write((char*)&b,sizeof(b));
			fout.close();
			cout<<"\n\n\t\t\t";
			SetConsoleTextAttribute(h,10);
			cout<<"Book Added Successfully";
			SetConsoleTextAttribute(h,14);
		}
	}
	
	void view_books(){
		book b1;
		extract_to_node(b1);
		nodeb *tempb = topb;
		while(tempb){
			tempb->x.print_book();
			tempb=tempb->next;
		}
	}
	
	void search_book(char *t){
		book b1;
		int bcounter=0;
		extract_to_node(b1);
		nodeb *tempb = topb;
		while(tempb){
			if(!strcmp(tempb->x.title,t)){
				tempb->x.print_book();
				tempb=tempb->next;
				bcounter=1;
			}
			tempb=tempb->next;		
		}
		if(bcounter == 0){
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\t\t    No Books Found"<<endl;
			SetConsoleTextAttribute(h,14);
		}
	}
	
	
	void issue_book()
	{
		student s[s_size];
		extract_to(s);
		char l;
		int flag=0;
		for(int i=0;i<s_size;i++)
		{
			if(s[i].b_applied==true)
			{
				flag=1;
				SetConsoleTextAttribute(h,14);
				cout<<"\n\n\t\t\tReg no : "<<s[i].reg<<" has applied for Book "<<s[i].temp_bookid<<endl;
				s[i].apply_book();
				SetConsoleTextAttribute(h,14);
				cout<<"\n\n\t\t\tDo you want to approve the request? (y/n) "<<endl;
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t";
				cin>>l;
				SetConsoleTextAttribute(h,14);
				if(l=='y')
				{
					s[i].b_permission=true;
					s[i].b_applied=false;
				}
				else
				{
					s[i].b_permission=false;
					s[i].b_applied=false;
				}
				
			}
		}
		if(flag==0)
		{
			SetConsoleTextAttribute(h,4);
			cout<<endl<<"\n\t\t\t\t    No Book Applications Yet"<<endl;
			SetConsoleTextAttribute(h,14);
		}
		ofstream o("student.dat",ios::out|ios::binary);
		o.seekp(ios::beg);
		for(int i=0;i<s_size;i++)
		{
		o.write((char*)&s[i],sizeof(s[i]));
		
		}
		o.close();
	}
	
	
//	void approve_leave()
//	{
//		student s[s_size];
//		extract_to(s);
//		char l;
//		int flag=0;
//		for(int i=0;i<s_size;i++)
//		{
//			if(s[i].l.applied==true)
//			{
//				flag=1;
//				SetConsoleTextAttribute(h,14);
//				cout<<"\n\t\t\t\t   Reg no : "<<s[i].reg<<" has applied leave."<<endl;
//				s[i].l.apply_leave();
//				SetConsoleTextAttribute(h,14);
//				cout<<"\n\t\t\t\t   Do you want to approve the leave? (y/n) "<<endl;
//				SetConsoleTextAttribute(h,12);
//				cin>>l;
//				SetConsoleTextAttribute(h,14);
//				if(l=='y'||l=='Y')
//				{
//					s[i].l.permission=true;
//					s[i].l.applied=false;
//				}
//				else
//				{
//					s[i].l.permission=false;
//					s[i].l.applied=false;
//				}
//				
//			}
//		}
//		if(flag==0)
//		{
//			SetConsoleTextAttribute(h,4);
//			cout<<endl<<"\n\t\t\t\t    No leave applications yet"<<endl;
//			SetConsoleTextAttribute(h,14);
//		}
//		ofstream o("student.dat",ios::out|ios::binary);
//		o.seekp(ios::beg);
//		for(int i=0;i<s_size;i++)
//		{
//		o.write((char*)&s[i],sizeof(s[i]));
//		
//		}
//		o.close();
//	}
};



struct nodel
{
	librarian x;
	nodel *next;
}*topl=NULL;
//the librarian login page(asks for password and shows the librarian menu) 
void l_login()
{
	char r[20];char p[20];
	librarian l;
	SetConsoleTextAttribute(h,14);
	cout<<"\n\t\t\t\tLibrarian no : "; 
	SetConsoleTextAttribute(h,12);
	cin>>r;
	SetConsoleTextAttribute(h,14);
	nodel *templ;
	ifstream in("lib.dat",ios::in|ios::binary);
	in.seekg(ios::beg);
	int i;
	while(in.read((char*)&l,sizeof(l)))
	{
		templ=new nodel;
		templ->x=l;
		templ->next=topl;
		topl=templ;
	}
	in.close();
	
	while(templ)
	{
		if(strcmp(r,templ->x.lib_no)==0)
		{
			l=templ->x;
			break;
		}
		templ=templ->next;
			
	}
	SetConsoleTextAttribute(h,14);
	cout<<"\n\t\t\t\tPassword  : ";
	SetConsoleTextAttribute(h,12);
	cin>>p;
	SetConsoleTextAttribute(h,14);
	if(strcmp(p,l.password)!=0)
	{
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,4);
		cout<<"Wrong Reg no/Password combination!!"<<endl;
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,6);
		system("pause");
		SetConsoleTextAttribute(h,14);
		return;
	}

		char ch='0';
		
		while(ch!='7')
		{
		system("cls");
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n";
		SetConsoleTextAttribute(h,6);
		cout<<"\t\t\t\t            WELCOME "<<l.name;
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\n\t\t\t\t    1\t:\tVIEW PROFILE\n\n\t\t\t\t    2\t:\tISSUE BOOK\n\n\t\t\t\t    3\t:\tADD BOOK\n\n\t\t\t\t    4\t:\tVIEW ALL BOOKS\n\n\t\t\t\t    5\t:\tSEARCH BOOK\n\n\t\t\t\t    6\t:\tCHANGE PASSWORD\n\n\t\t\t\t    7\t:\tRETURN TO MAIN MENU\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t\tEnter Your Choice : ";	
		SetConsoleTextAttribute(h,12);
		cin>>ch;
		SetConsoleTextAttribute(h,14);
		switch(ch)
		{
			case '1':
				cout<<endl;
				l.print_lib();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '2':
				cout<<endl;
				l.issue_book();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '3':
				cout<<endl;
			    l.add_book();
			    cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '4':
				cout<<endl;
			    l.view_books();
			    cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '5':
				cout<<endl;
				char t[30];
				SetConsoleTextAttribute(h,14);
				cout<<"\n\n\t\t\tEnter the Book Name : ";
				cin.ignore();
				SetConsoleTextAttribute(h,12);
				cin.getline(t,29);
				SetConsoleTextAttribute(h,14);
				l.search_book(t);
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case '6':
				cout<<endl;
			    l.change_password();
			    cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '7':
				break;
		    default: ;
		    	//cout<<endl;
		    	//cout<<"You have entered Invalid option";
		    	//cout<<endl;
				//system("pause");
				    
				}		
        }
        ofstream o("lib.dat",ios::out|ios::binary);
		templ->x=l;
		templ=topl;
        while(templ)
        {
        	l=templ->x;
		o.write((char*)&l,sizeof(l));
		templ=templ->next;
	}
		o.close();
}





//All admin related functions and classes
//class admin contains all admin info
class admin
{
	
	
	//student s[100];
	
	public:
	char admin_no[20];
	char name[20];
	char password[20];
	
	void get_admin()
	{
		cout<<"Admin no:";	cin>>admin_no;
		cout<<"Name:";	cin>>name;
		cout<<"password:";	cin>>password;
	}
	
	/* void change_password(){
		char current_pass[20];
		char new_pass[20];
		cout<<"Enter the current password:";
		cin>>current_pass;
		cout<<"Enter the new password:";
		cin>>new_pass;
		if(strcmpi(current_pass,password)==0){
			if(strcmpi(new_pass,password)==0){
				cout<<"You have entered the same password."<<endl;
				return;				
			}
			strcpy(password,new_pass);
			cout<<"Password Saved."<<endl;
		}
		else{
			cout<<"Password doesnot match"<<endl;
		}
	} */
	
	void print_admin()
	{
		cout<<"\n\t\t\t\t    Admin No :\t";
		SetConsoleTextAttribute(h,12);
		cout<<admin_no<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Name     :\t";
		SetConsoleTextAttribute(h,12);
		cout<<name<<endl;
		SetConsoleTextAttribute(h,14);	
	}
	
	void add_student(){
		ofstream o("student.dat",ios::out|ios::binary|ios::app);
		student s1;
		s1.get_student();
		o.write((char*)&s1,sizeof(s1));
		o.close();
	}
	
	void add_faculty(){
		ofstream o("faculty.dat",ios::out|ios::binary|ios::app);
		faculty f;
		f.get_faculty();
		o.write((char*)&f,sizeof(f));
		o.close();
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,10);
		cout<<"Faculty Added Successfully";
		SetConsoleTextAttribute(h,14);
	}
	
	void add_warden(){
		ofstream o("warden.dat",ios::out|ios::binary|ios::app);
		warden w;
		w.get_warden();
		o.write((char*)&w,sizeof(w));
		o.close();
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,10);
		cout<<"Warden Added Successfully";
		SetConsoleTextAttribute(h,14);
	}
	
	void add_librarian(){
		ofstream o("lib.dat",ios::out|ios::binary|ios::app);
		librarian l;
		l.get_lib();
		o.write((char*)&l,sizeof(l));
		o.close();
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,10);
		cout<<"Librarian Added Successfully";
		SetConsoleTextAttribute(h,14);
	}
	
	
//	void add_book(){
//		book b;
//		b.get_book();
//		if(b.bookid == 0 && b.penalty == 0 && strcpy(b.title,"no title")){
//			return;
//		}
//		else{
//			ofstream fout;
//			fout.open("book.dat",ios::binary|ios::app);
//			fout.write((char*)&b,sizeof(b));
//			fout.close();
//			cout<<"\n\n\t\t\t";
//			SetConsoleTextAttribute(h,10);
//			cout<<"Book Added Successfully";
//			SetConsoleTextAttribute(h,14);
//		}
//	}
	/* void admin_search()
	{
		student s[s_size];
		extract_to(s);
		for(int i=0;i<s_size;i++)
		{
			cout<<"Reg no: "<<s[i].reg<<"\tName :"<<s[i].p.name<<endl;
		}
		cout<<endl<<"Enter the reg no of the student whose profile you want to view: ";
		char temp_reg[20];
		cin>>temp_reg;
		cout<<endl;
		for(int i=0;i<s_size;i++)
		{
			if(strcmp(s[i].reg,temp_reg)==0)
			{
				s[i].p.print_profile();
				cout<<"Room no: "<<s[i].room_no<<endl;
				s[i].print_attendence();
			}
		}
		
	} */
};



struct nodea
{
	admin m;
	nodea *next;
}*topa=NULL;
//the warden login page(asks for password and shows the warden menu) 
void a_login()
{
	char r[20];char p[20];
	admin a;
	SetConsoleTextAttribute(h,14);
	cout<<"\n\t\t\t\tAdmin No : ";
	SetConsoleTextAttribute(h,12);
	cin>>r;
	SetConsoleTextAttribute(h,14);
	nodea *tempa;
	ifstream in("admin.dat",ios::in|ios::binary);
	in.seekg(ios::beg);
	int i;
	for(i=0;i<a_size;i++)
	{
		tempa=new nodea;
		in.read((char*)&a,sizeof(a));
		tempa->m=a;
		tempa->next=topa;
		topa=tempa;
			}
	in.close();
	
	while(tempa)
	{
		if(strcmp(r,tempa->m.admin_no)==0)
		{
			a=tempa->m;
			break;
		}
		tempa=tempa->next;
			
	}
	SetConsoleTextAttribute(h,14);
	cout<<"\n\t\t\t\tPassword : ";
	SetConsoleTextAttribute(h,12);
	cin>>p;
	SetConsoleTextAttribute(h,14);
	if(strcmp(p,a.password)!=0)
	{
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,4);
		cout<<"Wrong Reg no/Password combination!!"<<endl;
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,6);
		system("pause");
		SetConsoleTextAttribute(h,14);
		return;
	}

		char ch='0';
		
		while(ch!='6')
		{
		
		system("cls");
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n";
		SetConsoleTextAttribute(h,6);
		cout<<"\t\t\t\t            WELCOME "<<a.name;
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
//		cout<<"\n\t\t\t\tADMIN LOGIN\n"<<endl;
		SetConsoleTextAttribute(h,14);
//		cout<<"\t\tWelcome "<<a.name<<endl<<endl;
		cout<<"\n\n\t\t\t\t    1\t:\tVIEW PROFILE\n\n\t\t\t\t    2\t:\tADD STUDENT\n\n\t\t\t\t    3\t:\tADD FACULTY\n\n\t\t\t\t    4\t:\tADD WARDEN\n\n\t\t\t\t    5\t:\tADD LIBRARIAN\n\n\t\t\t\t    6\t:\tRETURN TO MAIN MENU\n\n"<<endl;
//		cout<<"1-View Profile \n2-Add Student \n3-Add Faculty \n5-Return to main menu\n\nEnter your choice : ";
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t\tEnter Your Choice : ";	
		SetConsoleTextAttribute(h,12);
		cin>>ch;
		SetConsoleTextAttribute(h,14);
		switch(ch)
		{
			case '1':
				cout<<endl;
				a.print_admin();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '2':
				cout<<endl;
				a.add_student();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '3':
				cout<<endl;
			    a.add_faculty();
			    cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
			    break;
			case '4':
				cout<<endl;
			    a.add_warden();
			    cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
			    break;
			case '5':
				cout<<endl;
			    a.add_librarian();
			    cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
			    break;
			case '6':
				break;
		    default: ;
		    	//cout<<endl;
		    	//cout<<"You have entered Invalid option";
		    	//cout<<endl;
				//system("pause");
				    
				}		
        }
        ofstream o("admin.dat",ios::out|ios::binary);
		tempa->m=a;
		tempa=topa;
        while(tempa)
        {
        	a=tempa->m;
		o.write((char*)&a,sizeof(a));
		tempa=tempa->next;
	}
		o.close();
}


//The main function shows initial menu to login as stud, fac or warden
int main()
{
	
	student s[s_size];
	extract_to(s);
	
	//To input student data to file

	/* ofstream o("student.dat",ios::out|ios::binary);
	int i;
	for(i=0;i<s_size;i++)
	{
		student s1;
		s1.get_student();
		o.write((char*)&s1,sizeof(s1));
	}
	o.close(); */
	
	/*	 student ss[2];
		ifstream f("student.dat",ios::in|ios::binary);
		for(int i=0;i<2;++i)
		{
			f.read((char*)&ss[i],sizeof(ss[i]));
		}
		f.close();
		ss[0].pcount=0;
		ss[0].acount=0;
		ss[1].pcount=0;
		ss[1].acount=0;	
		ofstream o("student.dat",ios::out|ios::binary);
		for(int i=0;i<2;++i)
		{
			o.write((char*)&ss[i],sizeof(ss[i]));
		}
		o.close(); */
	//to view contents of student file
	
	/* student s;
	ifstream in("student.dat",ios::in|ios::binary);
	in.seekg(ios::beg);
	for(int i=0;i<s_size;i++)
	{
		in.read((char*)&s,sizeof(s));
		cout<<s.reg<<endl;
		cout<<s.password<<endl;
		s.p.print_profile();
	}
	in.close();
	system("pause"); */
	
	
	//To input faculty data to file
	/* ofstream o("faculty.dat",ios::out|ios::binary);
	for(int i=0;i<f_size;i++)
	{
		faculty f;
		f.get_faculty();
		o.write((char*)&f,sizeof(f));
	}
	o.close(); */

	
	//To view contents of faculty file
	
	/* fstream in("faculty.dat",ios::in|ios::binary);
	faculty f;
	in.seekg(ios::beg);
	for(int i=0;i<f_size;i++)
	{
		in.read((char*)&f,sizeof(f));
		f.print_faculty();
	}
	in.close();
	system("pause"); */
	
	//To input warden data to file
	
	/* ofstream o("warden.dat",ios::out|ios::binary);
		warden w;
		w.get_warden();
		o.write((char*)&w,sizeof(w));
	o.close(); */ 
	
	
	//To view contents of warden file
	
	/* ifstream in("warden.dat",ios::in|ios::binary);
	warden w;
	in.seekg(ios::beg);
		in.read((char*)&w,sizeof(w));
		w.print_warden();
	in.close(); */

	//To input admin data to file
	
	/* ofstream o("admin.dat",ios::out|ios::binary);
		admin a;
		a.get_admin();
		o.write((char*)&a,sizeof(a));
	o.close(); */ 
	
	
	//To view contents of warden file
	
	/* ifstream in("admin.dat",ios::in|ios::binary);
	admin a;
	in.seekg(ios::beg);
	in.read((char*)&a,sizeof(a));
	a.print_admin();
	in.close(); */
	
	char choice='0';
	while(choice!=6)
	{
		system("cls");
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n";
		SetConsoleTextAttribute(h,6);
		cout<<"\t\t\t\t               WELCOME";
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------\n";
		SetConsoleTextAttribute(h,14);
		cout<<"\n\n\t\t\t\t    1\t:\tADMIN LOGIN\n\n\t\t\t\t    2\t:\tSTUDENT LOGIN\n\n\t\t\t\t    3\t:\tFACULTY LOGIN\n\n\t\t\t\t    4\t:\tWARDEN LOGIN\n\n\t\t\t\t    5\t:\tLIBRARIAN LOGIN\n\n\t\t\t\t    6\t:\tEXIT\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------\n";
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t\t\tChoose Your Login Portal : ";	
		SetConsoleTextAttribute(h,12);
		cin>>choice;
		SetConsoleTextAttribute(h,15);
		switch(choice)
		{
			case '1':
				system("cls");
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n";
				SetConsoleTextAttribute(h,6);
				cout<<"\t\t\t\t            ADMIN LOGIN";
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
				SetConsoleTextAttribute(h,15);
				cout<<"\t\t-----------------------------------------------------------------\n"<<endl;
//				cout<<"\n\t\t\t\tADMIN LOGIN\n"<<endl;
				a_login();
				break;
			case '2':
				system("cls");
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n";
				SetConsoleTextAttribute(h,6);
				cout<<"\t\t\t\t          STUDENT LOGIN";
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
				SetConsoleTextAttribute(h,15);
				cout<<"\t\t-----------------------------------------------------------------\n"<<endl;
//				cout<<"\n\t\t\t\tSTUDENT LOGIN\n"<<endl;
				s_login();
				break;
			case '3':
				system("cls");
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n";
				SetConsoleTextAttribute(h,6);
				cout<<"\t\t\t\t          FACULTY LOGIN";
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
				SetConsoleTextAttribute(h,15);
				cout<<"\t\t-----------------------------------------------------------------\n"<<endl;				
//				cout<<"\n\t\t\t\tFACULTY LOGIN\n"<<endl;
				f_login();
				system("cls");
				break;
			case '4':
				system("cls");
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n";
				SetConsoleTextAttribute(h,6);
				cout<<"\t\t\t\t          WARDEN LOGIN";
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
				SetConsoleTextAttribute(h,15);
				cout<<"\t\t-----------------------------------------------------------------\n"<<endl;
//				cout<<"\n\t\t\t\tWARDEN LOGIN\n"<<endl;
				w_login();
				system("cls");
				break;
			case '5':
				system("cls");
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n";
				SetConsoleTextAttribute(h,6);
				cout<<"\t\t\t\t         LIBRARIAN LOGIN";
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
				SetConsoleTextAttribute(h,15);
				cout<<"\t\t-----------------------------------------------------------------\n"<<endl;
//				cout<<"\n\t\t\t\tLIBRARIAN LOGIN\n"<<endl;
				l_login();
				system("cls");
				break;			
			case '6': exit(0);
				break;
			default: ;
			//	cout<<"You have entered an invalid option."<<endl;
			//	system("pause");
		}
	}
}
