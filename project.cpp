//**************************************************HEADER FILES***************************************************
#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
//**************************************************HEADER FILES***************************************************

using namespace std;

//************************************************STRUCTURE FOR DATE***********************************************
struct Date 
{ 
    int d, m, y; 
}dt1,dt2;  
//************************************************END****************************************************************

const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

//*********************************************COUNTLEAP YEAR*******************************************************
int countLeapYears(Date d) 
{ 
    int years = d.y; 
    if (d.m <= 2) 
        years--;  
    return years / 4 - years / 100 + years / 400; 
} 

//*******************************************END********************************************************************

//*****************************************************DIFFERENCE BETWEEN TWO DATE************************************
int getDifference(Date dt1, Date dt2) 
{ 
    long int n1 = dt1.y*365 + dt1.d;  
    for (int i=0; i<dt1.m - 1; i++) 
        n1 += monthDays[i]; 
    n1 += countLeapYears(dt1);
    long int n2 = dt2.y*365 + dt2.d; 
    for (int i=0; i<dt2.m - 1; i++) 
        n2 += monthDays[i]; 
    n2 += countLeapYears(dt2);  
    return (n2 - n1); 
} 

//*****************************************************DIFFERENCE BETWEEN TWO DATE END************************************
class book
{
	
	private:
		
		int counter,countbook;
		
		public:
			
			//**********************************************************FOR COUNT TOTALBOOK ****************************************
			void bookcount()
			{ 
				countbook=0;
				ifstream file1("book.txt",ios::app);
				while(!file1.eof()) 
				{ 	
					string ch; 
					file1>>ch;
					countbook++;
				
				}
				file1.close();
				cout<<" Totalbook "<<countbook-1;
			}
			//**********************************************************FOR COUNT TOTALBOOK  END****************************************
			
			//**********************************************************FOR SHOW TOTALBOOK ****************************************
			void bookshow()
			{
				
				ifstream file1("book.txt",ios::app);
				while(!file1.eof()) 
				{ 	
					string ch; 
					file1>>ch;
					
					cout<<ch<<"\n"; 
				}
				file1.close();
			}
			//**********************************************************FOR SHOW TOTALBOOK  END****************************************
			
			//**********************************************************FOR ADD BOOK ****************************************
			void addbook()
			{
				char ch[10],auth[30];
				int num;
				string price;
				ofstream file("book.txt",ios::app);
				ofstream file1("book1.txt",ios::app);
				do{
					cout<<" Enter the name of the book "<<endl;
				
					cin.getline(ch,10);
					cin.ignore();
					cout<<" Enter the writer of the book "<<endl;
					cin.getline(auth,30);
					
					cout<<" Enter the price of the book "<<endl;
					cin>>price;
					file<<ch<<endl;
					file1<<ch<<endl;
					file1<<auth<<endl;
					file1<<price<<endl;	
					cout<<" Enter 0 for end";
					cin>>num;
					cin.ignore();
				}while(num!=0);
				file.close();
				file1.close();
			}
			//**********************************************************FOR ADD BOOK END****************************************
			
			//**********************************************************FOR SEARCH BOOK ****************************************
			void searchbook()
			{
				int count;
				string rol,rolen;
	       		string user,pass,u,p;
	        	system("cls");
	        	cout<<"please enter the following details"<<endl;
	        	cout<<"BOOK NAME :";
	        	cin>>user;
		        ifstream input("book.txt", ios::in);
		        while(input>>u)
		        {
		                if(u==user)
		                {
		                        count=1;
		                        counter++;
		                        system("cls");				
						}
		        }
		        input.close();
				if(count==1)
				{
					cout<<" Book is present "<<endl;
					
				}
				else{
					cout<<" BOOK IS NOT HERE "<<endl;
				}	
			}
			//**********************************************************FOR SEARCH BOOK END ****************************************
			
			//**********************************************************FOR DELETE BOOK END ****************************************
			void deletebook()
			{
			
			  string line, name,writer,line1,price;
			  cout << "Please Enter the name of book you want to delete: "<<endl;
			  cin >> name;
			  cout << "Please Enter the name of writer "<<endl;
			  cin >> writer;
			  cout<<" please enter the price of book "<<endl;
			  cin>>price;
			  ifstream myfile;
			  ofstream temp;
			  myfile.open("book.txt");
			  temp.open("temp.txt");
			  while (getline(myfile, line))
			  {
			    if (line != name)
			      temp << line << endl;
			    if(line==name)
			    	counter++;
			  }
			  if(counter==1)
			  	cout << "The book with the name " << name << " has been deleted" << endl;
				else
				 cout<<" no book found ";
			  myfile.close();
			  temp.close();
			  
			  remove("book.txt");
			  rename("temp.txt", "book.txt"); 
			}
			//**********************************************************FOR DELETE BOOK END ****************************************
			
			//**********************************************************FOR MODIFY BOOK  ****************************************
			void modifybook()
			{
			
			  string line,name1, name,writer,line1,price;
			  cout << "Please Enter the name of book you want to modify: "<<endl;
			  cin >> name;
			  cout << "Please Enter the name of writer "<<endl;
			  cin >> writer;
			  cout<<" please enter the price of book "<<endl;
			  cin>>price;
			  cout << "Please Enter the alternate name of book : "<<endl;
			  cin >> name1;
			  ifstream myfile;
			  ofstream temp;
			  myfile.open("book.txt");
			  temp.open("temp.txt");
			  while (getline(myfile, line))
			  {
			    if (line == name)
			      temp << name1 << endl;
			    else
			    	temp<< line<<endl;
			    if(line==name)
			    	counter++;
			  }
			  if(counter==1)
			  	cout << "The book with the name " << name << " has been modified" << endl;
				else
				 cout<<" no book found ";
			  myfile.close();
			  temp.close();
			  
			  remove("book.txt");
			  rename("temp.txt", "book.txt"); 
			}
			//**********************************************************FOR MODIFY BOOK END ****************************************
			
}b1;

class project:public book
{
	
	private:
		char stuname[30] ,facname[30],Admname[30];
		int  stureg,facreg,Admreg,counter,countstudent;
		
		public:	
			
			//*********************************************************LOGIN PAGE AND REGISTER PAGE ****************************************
			void loginpage()
			{
				  int choice;
				  	system("cls");
			        cout<<"***********************************************************************\n";
			        cout<<"*                  Welcome to login page                              *\n";
			        cout<<"*******************       MENU        *********************************\n";
			        cout<<"*                       1.LOGIN                                       *"<<endl;
			        cout<<"*                       2.REGISTER                                    *"<<endl;
			        cout<<"*                       3.FORGOT PASSWORD (or) USERNAME               *"<<endl;
			        cout<<"*                       4.Exit                                        *"<<endl;
			        cout<<"***********************************************************************\n\n\n";
			        cout<<"\nEnter your choice :";
			        cin>>choice;
			        cout<<endl;
			        switch(choice)
			        {
			                case 1:
			                        login();
			                        break;
			                case 2:
			                        registr();
			                        break;
			                case 3:
			                        forgot();
			                        break;
			                case 4:
			
			                        cout<<"Thanks for using this program\n\n";
			                        break;
			                default:
			                        system("cls");
			                        cout<<"You've made a mistake , give it a try again\n"<<endl; 
			                        loginpage();
			        }
			        
			}
			
			//*********************************************************LOGIN PAGE END ****************************************
			
			//**********************************************************LOGIN SECTION ****************************************
		void login()
		{
	        int count;
			string rol,rolen;
	        string user,pass,u,p;
	        system("cls");
	        cout<<"please enter the following details"<<endl;
	        cout<<"USERNAME :";
	        cin>>user;
	        cout<<"PASSWORD :";
	        cin>>pass;
	
	        ifstream input("data.txt", ios::in);
	        while(input>>u>>p>>rol)
	        {
	                if(u==user && p==pass)
	                {
	                        count=1;
	                        system("cls");
	                				rolen=rol;
	                				break;
									}
	                
	                
	        }
	        input.close();
	        
	        if(count == 1 && rolen == "S")
	        {
	                cout<<"\nHello"<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
	                cout<<"*************************************************************"<<endl;
	                cout<<"                    WELLCOME TO STUDENT SECTION              "<<endl;
	                cout<<"*************************************************************"<<endl;
	                student();
	                cin.get();
	                cin.get();
	                loginpage();
	        }else if(count==1&&rolen=="F"){
	        	
	        	cout<<"\nHello"<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
	            cout<<"*************************************************************"<<endl;
	            cout<<"                    WELLCOME TO FACULTY SECTION              "<<endl;
	            cout<<"*************************************************************"<<endl;
	            faculty();
	            cin.get();
	            cin.get();
				loginpage();
			}else if(count==1&&rolen=="A"){
				cout<<"\nHello"<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
	            cout<<"*************************************************************"<<endl;
	            cout<<"                    WELLCOME TO ADMIN SECTION              "<<endl;
	            cout<<"*************************************************************"<<endl;
	            admin();
	            cin.get();
	            cin.get();
				loginpage();
			}
	        else
	        {
	                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
	                loginpage();
	        }
		}
			//**********************************************************LOGIN SECTION END ****************************************
			
			//**********************************************************REGISTER SECTION ****************************************
			void registr()
			{
			        
			        string reguser,regpass,ru,rp,role;
			        system("cls");
			        cout<<"Enter the username :";
			        cin>>reguser;
			        cout<<"\nEnter the password :";
			        cin>>regpass;
			        cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
                	cout<<"||||||||||||||||||||Press S. Student||||||||||||||||||||||"<<endl;
                	cout<<"||||||||||||||||||||Press F. Faculty||||||||||||||||||||||"<<endl;
                	cout<<"||||||||||||||||||||Press A. Admin  ||||||||||||||||||||||"<<endl;
					cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
                	cout<<"                   Enter your role                        "<<endl;
		        	cin>>role;
	                if(role=="S")
	                {
	                	cout<<"*************************************************************"<<endl;
	                	cout<<"                    WELLCOME TO STUDENT SECTION              "<<endl;
	                	cout<<"*************************************************************"<<endl;
	                	createstudent();
					}else if(role=="F")
					{
						cout<<"*************************************************************"<<endl;
	                	cout<<"                    WELLCOME TO FACULTY SECTION              "<<endl;
	                	cout<<"*************************************************************"<<endl;
	                	createfaculty();
					}else{
						
						cout<<"*************************************************************"<<endl;
	                	cout<<"                    WELLCOME TO ADMIN SECTION              "<<endl;
	                	cout<<"*************************************************************"<<endl;
	                	createadmin();
					}
			        ofstream reg("data.txt",ios::app);
			        reg<<reguser<<' '<<regpass<<' '<<role<<endl;
			        system("cls");
			        cout<<"\nRegistration Sucessful\n";
			        loginpage();    
			}
			
			//**********************************************************REGISTER SECTION END ****************************************
			
			//**********************************************************FORGOT PASSWORD SECTION ****************************************
			
			void forgot()
			{
			        int ch;
			        system("cls");
			        cout<<"Forgotten ? We're here for help\n";
			        cout<<"1.Search your id by username"<<endl;
			        cout<<"2.Search your id by password"<<endl;
			        cout<<"3.Main menu"<<endl;
			        cout<<"Enter your choice :";
			        cin>>ch;
			        switch(ch)
			        {
			                case 1:
			                {
			                        int count=0;
			                        string searchuser,su,sp;
			                        cout<<"\nEnter your remembered username :";
			                        cin>>searchuser;
			                        
			                        ifstream searchu("data.txt");
			                        while(!searchu.eof())
			                        {
			                        		searchu>>su>>sp;
			                                if(su==searchuser)
			                                {
			                                        count=1;
			                                        break;
			                                }
			                        }
			                        searchu.close();
			                        if(count==1)
			                        {
			                                cout<<"\n\nHurray, account found\n";
			                                cout<<"\nYour password is "<<sp;
			                                cin.get();
			                                cin.get();
			                                system("cls");
			                               loginpage();
			                        }
			                        else
			                        {
			                                cout<<"\nSorry, Your userID is not found in our database\n";
			                                cout<<"\nPlease kindly contact your system administrator for more details \n";
			                                cin.get();
			                                cin.get();
			                                loginpage();
			                        }
			                        break;
			                }
			                case 2:
			                {
			                        int count=0;
			                        string searchpass,su2,sp2;
			                        cout<<"\nEnter the remembered password :";
			                        cin>>searchpass;
			                        
			                        ifstream searchp("data.txt");
			                        while(!searchp.eof())
			                        {
			                        	searchp>>su2>>sp2;
			                                if(sp2==searchpass)
			                                {
			                                        count=1;
			                                        break;
			                                }       
			                        }
			                        searchp.close();
			                        if(count==1)
			                        {
			                                cout<<"\nYour password is found in the database \n";
			                                cout<<"\nYour Id is : "<<su2;
			                                cin.get();
			                                cin.get();
			                                system("cls");
			                                loginpage();
			                        }
			                        else
			                        {
			                                cout<<"Sorry, We cannot found your password in our database \n";
			                                cout<<"\nkindly contact your administrator for more information\n";
			                                cin.get();
			                                cin.get();
			                                loginpage();
			                        }
			                
			                        break;
			                }
			                
			                case 3:
			                {
			                        cin.get();
			                       loginpage();
			                       break;
			                }
			                default:
			                {
			                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
			                        forgot();   
			                }
			                     
			        }
			}
			
			//**********************************************************FORGOT PASSWORD SECTION END ****************************************
			
			//**********************************************************CREATE STUDENT PROFILE SECTION****************************************
			void createstudent()
			{
				ofstream file("student.txt",ios::app);
				ofstream file1("stu.txt",ios::app);  
			
					cout<<"\n Enter the Name of Student "<<endl;
					cin.ignore();
					cin.getline(stuname,30); 
					file<<stuname<<" ";
					file1<<stuname<<"\n";
					cout<<"\n Enter the Registration Number "<<endl;
					cin>>stureg;
					file<<stureg<<" ";
				file.close();  
				file1.close();
				
			}
			//**********************************************************CREATE STUDENT PROFILE SECTION END ****************************************
			
			//**********************************************************(FOR USING ADMIN) STUDENT PROFILE SECTION  ****************************************
			void createstudentdetails()
			{
				int ch;
				ofstream file("student.txt",ios::app);
				ofstream file1("stu.txt",ios::app);  
				system("cls");
				do
				{ 
					cout<<"\n Enter the Name of Student "<<endl;
					cin.ignore();
					cin.getline(stuname,30); 
					file<<stuname<<" ";
					file1<<stuname<<"\n";
					cout<<"\n Enter the Registration Number "<<endl;
					cin>>stureg;
					file<<stureg<<" ";
					cout<<"\n Input More Student Information (0/1)"<<endl; 
					cin>>ch;			 
				} while(ch!=0);
				file.close();  
				file1.close();
			}
			//**********************************************************(FOR USING ADMIN) STUDENT PROFILE SECTION END ****************************************
			
			//**********************************************************(FOR USING ADMIN) FACULTY PROFILE SECTION  ****************************************
			void createfacultydetails()
			{
				int ch;
				ofstream file1("faculty.txt",ios::app);
				system("cls");
				do
				{ 
					cout<<"\n Enter the Name of Faculty "<<endl;
					cin.ignore();
					cin.getline(facname,30); 
					file1<<facname<<"";
					cout<<"\n Enter the Registration Number "<<endl;
					cin>>facreg;
					file1<<facreg<<" ";
					cout<<"\n Input More Student Information (0/1)"<<endl; 
					cin>>ch;			 
				} while(ch!=0);
				file1.close();
			}
			//**********************************************************(FOR USING ADMIN) FACULTY PROFILE SECTION END ****************************************
			
			//**********************************************************CREATE FACULTY PROFILE SECTION****************************************
			void createfaculty()
			{
				ofstream file1("faculty.txt",ios::app);
				
					cout<<"\n Enter the Name of Faculty "<<endl;
					cin.ignore();
					cin.getline(facname,30); 
					file1<<facname<<" ";
					cout<<"\n Enter the Registration Number "<<endl;
					cin>>facreg;
					file1<<facreg<<" ";		 
				file1.close();
			}
			//**********************************************************CREATE FACULTY PROFILE SECTION END ****************************************
			
			//**********************************************************CREATE ADMIN PROFILE SECTION****************************************
			void createadmin()
			{
				ofstream file2("admin.txt",ios::app);
				
					cout<<"\n Enter the Name of Admin "<<endl;
					cin.ignore();
					cin.getline(Admname,30); 
					file2<<Admname<<" ";
					cout<<"\n Enter the Registration Number "<<endl;
					cin>>Admreg;
					file2<<Admreg<<" ";
				file2.close();
			}
			//**********************************************************CREATE ADMIN PROFILE SECTION END ****************************************
			
			//**********************************************************FOR MODIFY STUDENT INFORMATION****************************************
			void modifystudent()
			{
			
			  string line,name1, name,writer,line1,price;
			  cout << "Please Enter the name of student you want to modify: "<<endl;
			  cin >> name;
			  cout << "Please Enter the registration No "<<endl;
			  cin >> writer;
			  cout << "Please Enter the Correct name of student : "<<endl;
			  cin >> name1;
			  ifstream myfile;
			  ofstream temp;
			  myfile.open("stu.txt");
			  temp.open("temp.txt");
			  while (getline(myfile, line))
			  {
			    if (line == name)
			      temp << name1 << endl;
			    else
			    	temp<< line<<endl;
			    if(line==name)
			    	counter++;
			  }
			  if(counter==1)
			  	cout << "The student with the name " << name << " has been modified" << endl;
				else
				 cout<<" no student found ";
			  myfile.close();
			  temp.close();
			  
			  remove("stu.txt");
			  rename("temp.txt", "stu.txt"); 
			}
			//**********************************************************FOR MODIFY STUDENT INFORMATION END****************************************
			
			//**********************************************************FOR COUNT TOTALSTUDENT ****************************************
			void studentcount()
			{ 
				countstudent=0;
				ifstream file1("stu.txt",ios::app);
				while(!file1.eof()) 
				{ 	
					string ch; 
					file1>>ch;
					countstudent++;
				
				}
				file1.close();
				cout<<" Totalstudent "<<countstudent-1;
			}
			//**********************************************************FOR COUNT TOTALSTUDENt  END****************************************
			
			//**********************************************************FOR DELETE STUDENT ****************************************
			void deletestudent()
			{
			
			  string line, name,line1,price;
			  cout << "Please Enter the name of student you want to delete: "<<endl;
			  cin >> name;
			  cout<<" please enter the  Registration No "<<endl;
			  cin>>price;
			  ifstream myfile;
			  ofstream temp;
			  myfile.open("stu.txt");
			  temp.open("temp.txt");
			  while (getline(myfile, line))
			  {
			    if (line != name)
			      temp << line << endl;
			    if(line==name)
			    	counter++;
			  }
			  if(counter==1)
			  	cout << "The student with the name " << name << " has been deleted" << endl;
				else
				 cout<<" no student found ";
			  myfile.close();
			  temp.close();
			  
			  remove("stu.txt");
			  rename("temp.txt", "stu.txt"); 
			}
			//**********************************************************FOR DELETE STUDENT END ****************************************
			
			//**********************************************************FOR SEARCH STUDENT ****************************************
			void searchstudent()
			{
				int count;
				string rol,rolen;
	       		string user,pass,u,p;
	        	system("cls");
	        	cout<<"please enter the following details"<<endl;
	        	cout<<"STUDENT NAME :";
	        	cin>>user;
		        ifstream input("stu.txt", ios::in);
		        while(input>>u)
		        {
		                if(u==user)
		                {
		                        count=1;
		                        counter++;
		                        system("cls");				
						}
		        }
		        input.close();
				if(count==1)
				{
					cout<<" STUDENT is present "<<endl;
					
				}
				else{
					cout<<" STUDENT IS NOT HERE "<<endl;
				}	
			}
			//**********************************************************FOR SEARCH STUDENT END ****************************************
			
			//**********************************************************FOR SEARCH STUDENT ****************************************
			void searchfaculty()
			{
				int count;
				string rol,rolen;
	       		string user,pass,u,p;
	        	system("cls");
	        	cout<<"please enter the following details"<<endl;
	        	cout<<"FACULTY NAME :";
	        	cin>>user;
		        ifstream input("faculty.txt", ios::in);
		        while(input>>u)
		        {
		                if(u==user)
		                {
		                        count=1;
		                        counter++;
		                        system("cls");				
						}
		        }
		        input.close();
				if(count==1)
				{
					cout<<" FACULTY is present "<<endl;
					
				}
				else{
					cout<<" FACULTY IS NOT HERE "<<endl;
				}	
			}
			//**********************************************************FOR SEARCH STUDENT END ****************************************
			
			//**********************************************************FOR SHOW TOTALSTUDENT ****************************************
			void studentshow()
			{
				
				ifstream file1("student.txt",ios::app);
				while(!file1.eof()) 
				{ 	
					string ch; 
					file1>>ch;
					
					cout<<ch<<"\n"; 
				}
				file1.close();
			}
			//**********************************************************FOR SHOW TOTALSTUDENT  END****************************************
			
			//**********************************************************FOR SHOW TOTALFACULTY ****************************************
			void facultyshow()
			{
				
				ifstream file1("faculty.txt",ios::app);
				while(!file1.eof()) 
				{ 	
					string ch; 
					file1>>ch;
					
					cout<<ch<<"\n"; 
				}
				file1.close();
			}
			//**********************************************************FOR SHOW TOTALFACULTY  END****************************************
			
			//**********************************************************FOR ISSUEBOOK ****************************************
			void issuebook()
			{
				char name[30],name1[30];
				int reg,reg1,ch,ch1,ch2,b1,b2;
				float charge,charge1;
				charge=charge1=0;
				string date,date1,bookd,bookd1;
				cout<<" ENter 1 for student "<<endl;
				cout<<" Enter 2 for faculty "<<endl;
				cout<<" Enter your Role "<<endl;
				cin>>ch;
				if(ch==1){
					ofstream file2("student.txt",ios::app);
						cout<<" Enter your Full Name "<<endl;
						cin.ignore();
						cin.getline(name,30); 
						file2<<"\n ISSUE OF BOOK "<<endl;
						file2<<"NAME-"<<name<<"\n";
						cout<<"\n Enteryour Registration Number "<<endl;
						cin>>reg;
						file2<<"REG-"<<reg<<"\n";
						cout<<" Enter present date(xx-YY-ZZZZ) "<<endl;
						cin>>date;
						file2<<"DATEOFISSUE-"<<date<<"\n";
						cout<<" Enter 1 For Semester basis book issue(PER BOOK-50rs) "<<endl;
						cout<<" Enter 2 For Weekly basis book issue(PER BOOK -30rs) "<<endl;
						cout<<" Enter 3 For Daily basis book issue(FREE) "<<endl;
						cout<<" FOR LATE SUBMISSION CHARGES 10rs/day "<<endl;
						cout<<" Enter your choice "<<endl;
						cin>>ch1;
						file2<<"BOOKISSUE-(whichbasis)"<<ch1<<"\n";
						cout<<" Enter the total no of book "<<endl;
						cin>>b1;
						file2<<"TOTALBOOK-"<<b1<<"\n";
						cout<<" Enter the book details "<<endl;
						cin>>bookd;
						file2<<"BOOKDETAILS-"<<bookd<<"\n";
						if(ch1==1)
						{
							charge=50*b1;
						}else if(ch1==2)
						{
							charge=30*b1;
						}
						else {
							cout<<" FREE "<<endl;
							charge=0;
						}
						cout<<" YOUR TOTAL CHARGES = "<<charge<<endl;
						file2<<"TOTALCHARGES-"<<charge<<"\n";
						file2<<" END "<<endl; 
					file2.close();
				}
				else{
					ofstream file2("faculty.txt",ios::app);
						cout<<" Enter your Full Name "<<endl;
						cin.ignore();
						cin.getline(name1,30);
						file2<<"\nISSUE OF BOOK "<<endl; 
						file2<<"NAME-"<<name1<<"\n";
						cout<<"\n Enter your Registration Number "<<endl;
						cin>>reg1;
						file2<<"REG-"<<reg1<<"\n";
						cout<<" Enter present date(dd-mm-yyyy) "<<endl;
						cin>>date1;
						file2<<"DATEOFISSUE-"<<date1<<"\n";
						cout<<" Enter 1 For Semester basis book issue(PER BOOK-50rs) "<<endl;
						cout<<" Enter 2 For Weekly basis book issue(PER BOOK -30rs) "<<endl;
						cout<<" Enter 3 For Daily basis book issue(FREE) "<<endl;
						cout<<" FOR LATE SUBMISSION CHARGES 10rs/day "<<endl;
						cout<<" Enter your choice "<<endl;
						cin>>ch2;
						file2<<"BOOKISSUE-(whichbasis)"<<ch2<<"\n";
						cout<<" Enter the total no of book "<<endl;
						cin>>b2;
						file2<<"TOTALBOOK-"<<b2<<"\n";
						cout<<" Enter the book details "<<endl;
						cin>>bookd1;
						file2<<"BOOKDETAILS-"<<bookd1<<"\n";
						if(ch2==1)
						{
							charge1=50*b2;
						}else if(ch2==2)
						{
							charge1=30*b2;
						}
						else {
							cout<<" FREE "<<endl;
							charge1=0;
						}
						cout<<" YOUR TOTAL CHARGES = "<<charge1<<endl;
						file2<<"TOTALCHARGES-"<<charge1<<"\n";
						file2<<" END "<<endl; 
					file2.close();
				}
				
			
				
			}
			//**********************************************************FOR ISSUEBOOK  END****************************************
			//**********************************************************FOR DEPOSITEBOOK ****************************************
			void depositebook()
			{
				char name[30],name1[30];
				int reg,reg1,ch,ch1,ch2,b1,b2;
				float charge,charge1,totaltime;
				charge=charge1=totaltime=0;
				string bookd,bookd1;
				
				cout<<" ENter 1 for student "<<endl;
				cout<<" Enter 2 for faculty "<<endl;
				cout<<" Enter your Role "<<endl;
				cin>>ch;
				if(ch==1){
					ofstream file2("student.txt",ios::app);
						cout<<" Enter your Full Name "<<endl;
						cin.ignore();
						cin.getline(name,30); 
						file2<<"\n DEPOSITE OF BOOK "<<endl;
						file2<<"NAME-"<<name<<"\n";
						cout<<"\n Enteryour Registration Number "<<endl;
						cin>>reg;
						file2<<"REG-"<<reg<<"\n";
						cout<<" Enter DATE OF ISSUE(dd-mm-yyyy) "<<endl;
						cout<<" Enter date "<<endl;
						cin>>dt1.d;
						cout<<" Enter month "<<endl;
						cin>>dt1.m;
						cout<<" Enter year "<<endl;
						cin>>dt1.y;
						file2<<"DATEOFISSUE-"<<dt1.d<<"-"<<dt1.m<<"-"<<dt1.y<<"\n";
						cout<<" Enter DATE OF DEPOSITE(dd-mm-yyyy) "<<endl;
						cout<<" Enter date "<<endl;
						cin>>dt2.d;
						cout<<" Enter month "<<endl;
						cin>>dt2.m;
						cout<<" Enter year "<<endl;
						cin>>dt2.y;
						file2<<"DATEOFDEPOSITE-"<<dt2.d<<"-"<<dt2.m<<"-"<<dt2.y<<"\n";
						system("cls");
						cout<<" Enter 1 For Semester basis book issue(PER BOOK-50rs) "<<endl;
						cout<<" Enter 2 For Weekly basis book issue(PER BOOK -30rs) "<<endl;
						cout<<" Enter 3 For Daily basis book issue(FREE) "<<endl;
						cout<<" FOR LATE SUBMISSION CHARGES 10rs/day "<<endl;
						cout<<" Enter your choice "<<endl;
						cin>>ch1;
						file2<<"BOOKISSUE-(whichbasis)"<<ch1<<"\n";
						cout<<" Enter the total no of book "<<endl;
						cin>>b1;
						file2<<"TOTALBOOK-"<<b1<<"\n";
						cout<<" Enter the book details "<<endl;
						cin>>bookd;
						file2<<"BOOKDETAILS-"<<bookd<<"\n";
						if(ch1==1)
						{
							charge=50*b1;
						}else if(ch1==2)
						{
							charge=30*b1;
						}
						else {
							cout<<" FREE "<<endl;
							charge=0;
						}
						totaltime=getDifference(dt1, dt2);
//						cout<<totaltime;
						if(ch1==1&&totaltime>=184)
						{
							totaltime=totaltime-184;
							charge=charge+(totaltime*10);
						}else if(ch1==2&&totaltime>=8)
						{
							totaltime=totaltime-8;
							charge=charge+(totaltime*10);
						}else{
							totaltime=totaltime-2;
							charge=charge+(totaltime*10);
						}
//						cout<<totaltime;
						cout<<" YOUR TOTAL CHARGES = "<<charge<<endl;
						file2<<"TOTALCHARGES-"<<charge<<"\n";
						file2<<" END "<<endl; 
					file2.close();
				}
				else{
					ofstream file2("faculty.txt",ios::app);
						cout<<" Enter your Full Name "<<endl;
						cin.ignore();
						cin.getline(name1,30);
						file2<<"\nDEPOSITE OF BOOK "<<endl; 
						file2<<"NAME-"<<name1<<"\n";
						cout<<"\n Enter your Registration Number "<<endl;
						cin>>reg1;
						file2<<"REG-"<<reg1<<"\n";
						cout<<" Enter DATE OF ISSUE(dd-mm-yyyy) "<<endl;
						cout<<" Enter date "<<endl;
						cin>>dt1.d;
						cout<<" Enter month "<<endl;
						cin>>dt1.m;
						cout<<" Enter year "<<endl;
						cin>>dt1.y;
						file2<<"DATEOFISSUE-"<<dt1.d<<"-"<<dt1.m<<"-"<<dt1.y<<"\n";
						cout<<" Enter DATE OF DEPOSITE(dd-mm-yyyy) "<<endl;
						cout<<" Enter date "<<endl;
						cin>>dt2.d;
						cout<<" Enter month "<<endl;
						cin>>dt2.m;
						cout<<" Enter year "<<endl;
						cin>>dt2.y;
						file2<<"DATEOFDEPOSITE-"<<dt2.d<<"-"<<dt2.m<<"-"<<dt2.y<<"\n";
						system("cls");
						cout<<" Enter 1 For Semester basis book issue(PER BOOK-50rs) "<<endl;
						cout<<" Enter 2 For Weekly basis book issue(PER BOOK -30rs) "<<endl;
						cout<<" Enter 3 For Daily basis book issue(FREE) "<<endl;
						cout<<" Enter your choice "<<endl;
						cin>>ch2;
						file2<<"BOOKISSUE-(whichbasis)"<<ch2<<"\n";
						cout<<" Enter the total no of book "<<endl;
						cin>>b2;
						file2<<"TOTALBOOK-"<<b2<<"\n";
						cout<<" Enter the book details "<<endl;
						cin>>bookd1;
						file2<<"BOOKDETAILS-"<<bookd1<<"\n";
						if(ch2==1)
						{
							charge1=50*b2;
						}else if(ch2==2)
						{
							charge1=30*b2;
						}
						else {
							cout<<" FREE "<<endl;
							charge1=0;
						}
						totaltime=getDifference(dt1, dt2);
						if(ch1==1&&totaltime>=184)
						{
							totaltime=totaltime-184;
							charge=charge+(totaltime*10);
						}else if(ch1==2&&totaltime>=8)
						{
							totaltime=totaltime-8;
							charge=charge+(totaltime*10);
						}else{
							totaltime=totaltime-2;
							charge=charge+(totaltime*10);
						}
						cout<<" YOUR TOTAL CHARGES = "<<charge1<<endl;
						file2<<"TOTALCHARGES-"<<charge1<<"\n";
						file2<<" END "<<endl; 
					file2.close();
				}
				
			
				
			}
			//**********************************************************FOR DEPOSITEBOOK  END****************************************
			
			//*********************************************************STUDENT PROFILE***********************************************
			
			
			void student()
			{
				int ch;
				cout<<"  1:CREATE A STUDENT PROFILE "<<endl;
				cout<<"  2:MODIFY STUDENT NAME  "<<endl;
				cout<<"  3:BOOK SHOW "<<endl;
				cout<<"  4:SEARCH BOOK "<<endl;
				cout<<"  5:ISSUE BOOK "<<endl;
				cout<<"  6:DEPOSITE BOOK "<<endl;
				cout<<"  7:RETURN TO MAIN MENU "<<endl;
				cout<<"  8:EXIT  "<<endl;
				cout<<" ENTER YOUR CHOICE "<<endl;
				cin>>ch;
				switch(ch)
				{
					case 1:
						system("cls");
						createstudent();
						break;
					case 2:
						system("cls");
						modifystudent();
						break;
					case 3:
						system("cls");
						bookshow();
						break;
					case 4:
						system("cls");
						searchbook();
						break;
					case 5:
						system("cls");
						issuebook();
						break;
					case 6:
						system("cls");
						depositebook();
						break;
					case 7:
						system("cls");
						loginpage();
						break;
					case 8:
						exit(0);
					default:
						cout<<"you enter a wrong choice "<<endl;
						student();
				}
				student();
			}
			//********************************************************STUDENT PROFILE END********************************************
			
			//*********************************************************FACULTY PROFILE***********************************************
			
			
			void faculty()
			{
				int ch;
				cout<<"  1:CREATE A FACULTY PROFILE "<<endl;
				cout<<"  2:BOOK SHOW "<<endl;
				cout<<"  3:SEARCH BOOK "<<endl;
				cout<<"  4:ISSUE BOOK "<<endl;
				cout<<"  5:DEPOSITE BOOK "<<endl;
				cout<<"  6:RETURN TO MAIN MENU "<<endl;
				cout<<"  7:EXIT  "<<endl;
				cout<<" ENTER YOUR CHOICE "<<endl;
				cin>>ch;
				switch(ch)
				{
					case 1:
						system("cls");
						createfaculty();
						break;
					case 2:
						system("cls");
						bookshow();
						break;
					case 3:
						system("cls");
						searchbook();
						break;
					case 4:
						system("cls");
						issuebook();
						break;
					case 5:
						system("cls");
						depositebook();
						break;
					case 6:
						system("cls");
						loginpage();
						break;
					case 7:
						exit(0);
					default:
						cout<<"you enter a wrong choice "<<endl;
						student();
				}
				faculty();
			}
			//********************************************************FACULTY PROFILE END********************************************
			
				//*********************************************************FACULTY PROFILE***********************************************
			
			
			void admin()
			{
				int ch;
				cout<<"  1:CREATE A ADMIN PROFILE\t ";
				cout<<"  2:CREATE A STUDENT PROFILE\n "<<endl;
				cout<<"  3:CREATE A FACULTY PROFILE\t ";
				cout<<"  4:MODIFY STUDENT NAME \n"<<endl;
				cout<<"  5:DELETE STUDENT PROFILE\t ";
				cout<<"  6:SEARCH A STUDENT \n "<<endl;
				cout<<"  7:COUNT TOTAL STUDENT\t";
				cout<<" \t   8:SHOW TOTAL STUDENT DETAILS\n "<<endl;
				cout<<"  9:SEARCH A FACULTY\t ";
				cout<<"  \t   10:SHOW FACULTY DETAILS \n"<<endl;
				cout<<"  11:ISSUE OF BOOK\t";
				cout<<"  \t   12:DEPOSITE OF BOOK \n"<<endl;
				cout<<"  13:ADD BOOK  \t";
				cout<<"  \t \t   14:SEARCH BOOK \n"<<endl;
				cout<<"  15:BOOK SHOW \t";
				cout<<"  \t   \t   16:TOTAL NUMBER oF BOOK\n"<<endl;
				cout<<"  17:DELETE A BOOK\t ";
				cout<<"  \t   18:MODIFY NAME OF THE BOOK \n\n"<<endl;
				cout<<"  19:RETURN TO MAIN MENU\t ";
				cout<<"  20:EXIT \n\n "<<endl;
				cout<<" ENTER YOUR CHOICE "<<endl;
				cin>>ch;
				switch(ch)
				{
					case 1:
						system("cls");
						createadmin();
						break;
					case 2:
						system("cls");
						createstudentdetails();
						break;
					case 3:
						system("cls");
						createfacultydetails();
						break;
					case 4:
						system("cls");
						modifystudent();
						break;
					case 5:
						system("cls");
						deletestudent();
						break;
					case 6:
						system("cls");
						searchstudent();
						break;
					case 7:
						system("cls");
						studentcount();
						break;
					case 8:
						system("cls");
						studentshow();
						break;
					case 9:
						system("cls");
						searchfaculty();
						break;
					case 10:
						system("cls");
						facultyshow();
						break;
					case 11:
						system("cls");
						issuebook();
						break;
					case 12:
						system("cls");
						depositebook();
						break;
					case 13:
						system("cls");
						addbook();
						break;
					case 14:
						system("cls");
						searchbook();
						break;
					case 15:
						system("cls");
						bookshow();
						break;
					case 16:
						system("cls");
						bookcount();
						break;
					case 17:
						system("cls");
						deletebook();
						break;
					case 18:
						system("cls");
						modifybook();
						break;
					case 19:
						system("cls");
						loginpage();
						break;
					case 20:
						exit(0);
					default:
						cout<<"you enter a wrong choice "<<endl;
						student();
				}
				admin();
			}
			//********************************************************FACULTY PROFILE END********************************************
}p1;



//**********************************************************MAIN SECTION ****************************************

main()
{
//	p1.issuebook();
//	p1.depositebook();
	p1.loginpage(); 
// 	p1.admin();
//	p1.modifystudent();
//	p1.studentcount();
//	p1.deletestudent();
//	p1.searchstudent();
//	p1.searchfaculty();
//	p1.studentshow();
//	p1.facultyshow();
//	b1.bookshow();
//	b1.addbook();
//	p1.student();
// 	b1.searchbook();
//	b1.deletebook();
//	b1.bookcount();
//	b1.modifybook();
}

//**********************************************************MAIN SECTION END ****************************************
