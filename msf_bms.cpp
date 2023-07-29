#include<iomanip>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<string> 
#include<time.h>
#include<windows.h>
#define fage 20
using namespace std;
//variables decleared here
int opt1=0;
int count2=0;
string bf1;     //string of our buffer to -->
int count1=0;    // used later ,optional
int count_2=0;
char sep1='@';    //our separetar
char bf1a[50];  //array of buffer 
bool dontclose=true;   // VARIABLE FOR FEATURE USE . NOT USING NOW !
bool lowb=false;
bool otra=false;
//****************************************
char accn[14];
char fname[14];
char 	lname[14];
int  balla=0;
char balll[15];
char facc[14];
char accn2[14];
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
string msg11="eYZd?Zd?R?^VddRXV?Wc`^?R?UVgV]`aVc?^c?WZc`?eYV?W`SjSfdvVUZeZ_X?eYV?T`UV?U`Vd?_`e?^R\V?j`f?eYV?T`UVc?^j?d^Rce?Yf^R_??";
string msg12="X]`cj?W`c?X`U??[Vdfd?Zd?RhVd`^V?^j?d^Rce?^V_vdfcgZgVU?_`e?SVTRfdV?`W?^V?v?[Vdfd?Zd?XcVRev?\]j`f?TR_e?Z^RXZ_V????????";
string msg13="a]VRdV?U`_e?VUZe?eYV?T`UV?YVcV?VgV_?ZW?j`f?VUZe?[fde?cV^V^SVc?e`?afe?^j?_R^V?^j?S]VddVU?Yf^R_?v????/WZc````?eYV?^R_";
string msg14="eYZd?Zd?R?\Vj?W`c?TR_eRTeZ_X?eYV?UVgV]`aVc?^c?WZc`?dVRcTY?W`c?W`SjSfd?R_U?^VddRXV?R_jeYZ_X?Z_?deRT\`gVcW]`h?W`c?Taa";
string msg15="?1^dWPcZXYe?cVdVcgVU?W`c?^Z_Z?d`We?W^f]Re`c??#!#";
char msg1[115];
char pak[7]={'W','Z','c','R','`',']'};
//for additional purpose!

char accn1[14];
char fname1[14];
char 	lname1[14];
int  balla1=0;
char balll1[15];
char facc1[14];

////////////////////////////////////////////////////
//functions here
///////////////////////////////

bool checkan();
void create1();
void depo();
void whithd();
void enqi();
void Modif();
void tran();
void clos1();
void readin();
void st2c(string a,char *b);       //string to a
void clch(char *a,int b);          // clear the array 
void finder1(char *xx ,int b,char *yy,int c);    //search a data in the text file !
void loada(char *xx,int b,char *yy);
void loadre(char *xx ,int b,char *yy,char *aa,char *zz);
void clall();
void elimn(char *xx,int b);
void hinterf();
void yopa(char* ,int=51 );
void yopa1(char* ,int );
void mtime();
//////---------------------------------------------------------

int main()
{	//function definition here 
	//interface style 
	system("color f1");
	system("cls");		
/////////////////////////////////	//
	do
	{
		system("cls");
	cout<<"1.create an account"<<endl;
	cout<<"2.Deposit amount"<<endl;
	cout<<"3.whithdraw amount"<<endl;
	cout<<"4.balance enquiry"<<endl;
	cout<<"5.modify an account"<<endl;
	cout<<"6.transfer an amount"<<endl; 
	cout<<"7.close an account!"<<endl;
	cout<<"8.exit the program"<<endl;
	cin>>opt1;	
	} while(opt1<1);
	
	//user has choosen the options  
	switch(opt1)
	{
		case 1 : system("cls");
		create1();
		break;
       case 2 :system("cls");
		depo();
		break;
		 case 3 :system("cls");
        whithd();
 			break;
			 case 4 :system("cls");
	enqi();
		break;
	 case 5 :system("cls");
	        Modif();
		     break;
	 case 6 :system("cls");
	   tran();
		break;
	case 7 :system("cls");
	   clos1();
		break;
	case 8 : dontclose=false;
	break;
    case fage+979 : hinterf();
    break;
   default : system("cls");
   system ("color c0");
   cout<<"invalid option error! can't proceed!"<<endl;
   system("pause");
   break;
	}   

  return 0;
}


//function that handle the  account creation.	

void create1()  //create account 
{
	system("cls");
	cout<<"please input the name of the user:"<<endl;
	cin.ignore();  //this ignores last used \n in cin and cout & help to avoid some errors !
	cin.getline(fname,14);
	system("cls");
	cout<<endl<<"please input the father name or the last name of the user:"<<endl;
    cin.getline(lname,14);
	do
	{
		system("cls");
		cout<<endl<<"please input the intiaL VALUE or deposit:"<<endl<<"*note: please dont use value less than 50: ";
		cin>>balla;
				
	} while(balla<=50);
	system("cls");
	cout<<endl<<"dont use existing account number!"<<endl<<"please input the account number:";
	cin.ignore();
cin.getline(accn,14);
bool isval=false;
isval=checkan();
if(isval==false)
{
	fstream vimm;
	vimm.open("bank",ios::out|ios::app);
	vimm<<accn<<sep1<<fname<<'$'<<lname<<'#'<<balla<<'^'<<endl;
	vimm.close();
	cout<<endl<<endl<<endl;
	system("color f3");
	cout<<"the account  successfully created"<<endl<<endl;
	system("pause");
	system("color f1");
	} else {
		system("cls");
system("color c0");
	cout<<endl<<"error the account you have entered is already in msf_database!"<<endl;
	system("pause");
	system("color f1");
	}	
		if(dontclose==true)
	 main();   
}	 
//--------------------------------------------------------------------
//function that check for the validy of the account number
//--------------------------------------------------------------------
bool checkan()  //check the validity of the account number 
{	
count1=0;
bool bolr=0;    // the funnction return this  one 
	fstream vimm;
	vimm.open("bank",ios::in);
	if(vimm.is_open())
	   {
vimm.seekg(0,ios::beg);	
while(!vimm.eof())
{
getline(vimm,bf1);
count1+=1;
 clch(bf1a,sizeof(bf1a));  // function to clear the arrays
 clch(facc,sizeof(facc));
st2c(bf1,bf1a);    //converting the string to the array form string 
finder1(bf1a,sizeof(bf1a),facc,sizeof(facc));  //separate and find only account number!.
int bol=strcmp(accn,facc);   //compare whith user defiend one 
if(bol==0)  
{
	bolr=true;
	break;                  //if he got a much break out of the loop.
}
cout<<"please wait! searching for_records........."<<endl;  //looping if not end of the file 
}
// for the first time if there is no database excute this one 
		} else{
 vimm.open("bank",ios::out | ios::app);
 bolr=false;
 }
 vimm.close();
 return bolr;	
}
//___________________-----------------------------------------------------
//____________________---------------------------------------------------
//_________________________________________________________________
//function that deposit an amount.
void depo()
{
int am1=0;
system("cls");
cout<<"please input the account number to be deposited:"<<endl;
cin.ignore();  
cin.getline(accn,14);
bool isval=checkan();
if(isval==true)
{
system("cls");
	cout<<"please input the amount you want to deposit: ";
	cin>>am1;
		if(am1<=0)
	{
		system("cls");
		cout<<"the program incountered key injection or invalid value !"<<endl<<"you cant proceed!"<<endl;
		system("pause");
		goto label_10;
	}
//---------------------------------------
	fstream vimm;
	vimm.open("bank",ios::in);
    vimm.seekg(0,ios::beg);
	//--------------
	fstream vimm2;
	vimm2.open("temp",ios::out);
	int senti=1;	
while(!vimm.eof())
{
getline(vimm,bf1);
 clch(bf1a,sizeof(bf1a));  // function to clear the arrays
 clch(facc,sizeof(facc));
st2c(bf1,bf1a);    //converting the string to the array form string
clch(fname,sizeof(fname));
clch(lname ,sizeof(lname));
clch(balll,sizeof(balll));
loadre(bf1a,sizeof(bf1a),fname,lname,balll);
balla+=am1;
if(senti==count1) 
{
vimm2<<accn<<'@'<<fname<<'$'<<lname<<'#'<<balla<<'^'<<endl;
cout<<"dear customer your account number "<<" "<<accn<<" is credited by: "<<am1<<" ETB"<<endl;
system("pause");
} else {
	vimm2<<bf1<<endl;
	}
++senti;
}
vimm2.close();
vimm.close();
vimm.open("temp",ios::in);
 vimm.seekg(0,ios::beg);
 vimm2.open("bank",ios::out);
 while(!vimm.eof())
 {
 	getline(vimm,bf1);
   vimm2<<bf1<<endl;
 }
 vimm2.close();
 vimm.close();
       }	else {
 system("cls");
system("color c0");
cout<<"error! the account doent exist"<<endl;
system("pause");
system("color f1");	
    }
label_10:
    	if(dontclose==true)
	 main();   
}
//--------------------------------------------------------------------------------
//________________--
//________________----
//----=====================================
//=--=====***8888888996688556787667========-
//***************************************=========
//whithdraw it 
void whithd()
{
	int am1=0;
system("cls");
cout<<"please input the account number : "<<endl;
cin.ignore();  
cin.getline(accn,14);
bool isval=checkan();
if(isval==true)
{
system("cls");
	cout<<"please input the amount you want to whithdraw: ";
	cin>>am1;
	if(am1<=0)
	{
		system("cls");
		cout<<"the program incountered key injection or invalid value !"<<endl<<"you cant proceed!"<<endl;
		system("pause");
		goto label_11;
	}
		
//---------------------------------------
	fstream vimm;
	vimm.open("bank",ios::in);
    vimm.seekg(0,ios::beg);
	//--------------
	fstream vimm2;
	vimm2.open("temp",ios::out);
	int senti=1;	
while(!vimm.eof())
{
getline(vimm,bf1);
 clch(bf1a,sizeof(bf1a));  // function to clear the arrays
 clch(facc,sizeof(facc));
st2c(bf1,bf1a);    //converting the string to the array form string
clch(fname,sizeof(fname));
clch(lname ,sizeof(lname));
clch(balll,sizeof(balll));
loadre(bf1a,sizeof(bf1a),fname,lname,balll);
if(am1>balla)
{
	if(senti==count1)  //only print if the user is current user!
cout<<"your balance is insufficient !"<<endl;
} else balla-=am1;
if(senti==count1)      //only modify current users!
{
vimm2<<accn<<'@'<<fname<<'$'<<lname<<'#'<<balla<<'^'<<endl;
cout<<"dear customer your account number : "<<" "<<accn<<" is debited whith "<<am1<<" ETB"<<endl;
system("pause");
} else {
	vimm2<<bf1<<endl;
}  
senti++;
}
 vimm2.close();
vimm.close();
//---copy to original file
vimm.open("temp",ios::in);
 vimm.seekg(0,ios::beg);
 vimm2.open("bank",ios::out);
 while(!vimm.eof())
 {
 	getline(vimm,bf1);
   vimm2<<bf1<<endl;
 }
 vimm2.close();
 vimm.close();
} else {
	system("cls");
system("color c0");
cout<<"error! the account doent exist"<<endl;
system("pause");
system("color f1");	
}
label_11:	if(dontclose==true)
	 main();   
   }	
//--------------------------------------------------------------------------------


//388383838383939393939939393838383888448833
//9383839339939393939393993939393939384488484
//393993399393399339test838883383848484488484
//8888888888888888888888888888888888888888888888
//balance inquery 

void enqi()
{
	system("cls");
	cout<<"please input the account number: "<<endl;
	cin.ignore();  
cin.getline(accn,14);
bool isval=checkan();
if(isval==true)
{
system("cls");
 int i=1; 
 fstream vimm;
 vimm.open("bank",ios::in);
	while(!vimm.eof())
{
getline(vimm,bf1);
if(i==count1)
{
	clch(bf1a,sizeof(bf1a));  // function to clear the arrays
 clch(facc,sizeof(facc));
st2c(bf1,bf1a);    //converting the string to the array form string
clch(fname,sizeof(fname));
clch(lname ,sizeof(lname));
clch(balll,sizeof(balll));
loadre(bf1a,sizeof(bf1a),fname,lname,balll);
system("cls");
cout<<setw(10)<<"first name:"<<setw(15)<<fname<<endl;
cout<<setw(10)<<" last name:"<<setw(15)<<lname<<endl;
cout<<setw(30)<<"current balance: "<<balla<<endl;
system("pause");
}
++i;
}
vimm.close();
} else {
	system("cls");
	system("color c0");
	cout<<"the account does not exist"<<endl;
	system("pause");
	system("color f1");
	
	}
	if(dontclose==true)
	 main();   
}
//8888888888888888888888888888888888888888888
//function that transfer the money; 
//uuuuuuuuuuuuuwwwwwwwwwwwiiiiiiiiiiiiioooooooooppppppppssssssss
//wiwiwiwiwiwiwiwiwwwiwiowwowwwowowo
//frobest383838389293939393939393939329292939
//thelifeofthelight83939229922992929292922992929292
void tran()
{
	//variables
	int amm=0;
system("cls");
	cout<<"please input the sender account number: "<<endl;
	clch(accn,sizeof(accn));
	cin.ignore();
	cin.getline(accn,14);
	bool isval=checkan();
	count2=count1;  //copying line count of the first account!
		clch(accn1,sizeof(accn1));
	strcpy(accn1,accn);
	if(isval==true)
{
system("cls");
clch(accn,sizeof(accn));
cout<<"please input the receivant account number: "<<endl;
		cin.getline(accn,14);
     	bool isval1=checkan();
		count_2=count1;
		clch(accn2,sizeof(accn2));
		strcpy(accn2,accn);
	if(isval1==true)
	{
		system("cls");
	cout<<"please input the amount you want to transfer: ";
	cin>>amm;
			if(amm<=0)
	{
		system("cls");
		cout<<"the program incountered key injection or invalid value !"<<endl<<"you cant proceed!"<<endl;
		system("pause");
		goto label_12;
	}
//---------------------------------------
	fstream vimm;
	vimm.open("bank",ios::in);
    vimm.seekg(0,ios::beg);
	//--------------
	fstream vimm2;
	vimm2.open("temp",ios::out);
	int senti=1;	
	count1=count2;
			clch(accn,sizeof(accn));
			strcpy(accn,accn1);
while(!vimm.eof())
{
getline(vimm,bf1);
 clch(bf1a,sizeof(bf1a));  // function to clear the arrays
 clch(facc,sizeof(facc));
st2c(bf1,bf1a);    //converting the string to the array form string
clch(fname,sizeof(fname));
clch(lname ,sizeof(lname));
clch(balll,sizeof(balll));
loadre(bf1a,sizeof(bf1a),fname,lname,balll);
if(senti==count1) 
{
	if(amm>balla)
{
lowb=true;
	} else {
		 balla-=amm;
		 lowb=false;
		}
	vimm2<<accn<<'@'<<fname<<'$'<<lname<<'#'<<balla<<'^'<<endl;
     	} else {
       	vimm2<<bf1<<endl;
			}
               senti++;
            }  //do-while end 

/////////////////////////////           
vimm.close();
vimm2.close();
//---------------------8383939399222929299999229
//-------------------===----==== send the balance now !
//-----------=========-----===== this is it!.
//------fman can you send it right now?
//---of course bro iam on it lets do it !

vimm.open("temp",ios::in);
vimm.seekg(0,ios::beg);
//-------------------------------------------------------
	vimm2.open("bank",ios::out);
 senti=1;	
	count1=count_2; 
		clch(accn,sizeof(accn));
		strcpy(accn,accn2);
while(!vimm.eof())
{
getline(vimm,bf1);
 clch(bf1a,sizeof(bf1a));  // function to clear the arrays
 clch(facc,sizeof(facc));
st2c(bf1,bf1a);    //converting the string to the array form string
clch(fname,sizeof(fname));
clch(lname ,sizeof(lname));
clch(balll,sizeof(balll));
loadre(bf1a,sizeof(bf1a),fname,lname,balll);
if(lowb==false)
balla+=amm;
int bol1=strcmp(accn1,accn2);
if(bol1==0)
otra=true;
if(senti==count1) 
{
	if(lowb==false)
	{
		vimm2<<accn<<'@'<<fname<<'$'<<lname<<'#'<<balla<<'^'<<endl;
		system("cls");
		 if(otra!=true)
		{
cout<<"you have sent a payment from account number"<<" "<<accn1<<" to "<<fname<<" "<<lname<<" an amount of "<<amm<<" on "<<endl;
mtime();
system("pause");
} else {
	 system("cls");
		system("color c0"); 
		cout<<setw(20)<<"illegal operation!"<<endl<<"you cannot transfer for your self!"<<endl;
		system("pause");
		system("color f1");
	}
	} else {
			vimm2<<accn<<'@'<<fname<<'$'<<lname<<'#'<<balla<<'^'<<endl;
				system("cls");
		system("color c0"); 
		cout<<"your balance is insufficient sorry!"<<endl;
		system("pause");
		system("color f1");
	}

            } else vimm2<<bf1<<endl;
            senti++;
            }  //do-while end 
   	vimm.close();
vimm2.close();
//end
   		}    else {
   	system("cls");
   	system("color c0");
cout<<"error the account you inserted does not exist!"<<endl;
system("pause");
system("color f1");
				} 
				}else {
   	system("cls");
   	system("color c0");
   cout<<"account number does not exist!"<<endl;
   system("pause");
   system("color f1");
   	}
   	label_12:
	   	if(dontclose==true)
	 main();   
}
//0000000000--------------000000000000000
////0000000000--------------000000000000000
//0000000000000000000000000000000000000000000000
void clos1()
{
	
	system("cls");
	cout<<"please input the account number: "<<endl;
	cin.ignore();  
cin.getline(accn,14);
bool isval=checkan();
if(isval==true)
{
system("cls");
 int i=1; 
 fstream vimm;
 fstream vimm2;
 vimm.open("bank",ios::in);
 vimm2.open("temp",ios::out);
	while(!vimm.eof())
{
getline(vimm,bf1);
if(i!=count1)
{
	vimm2<<bf1<<endl;
}
++i;
}
vimm.close();
vimm2.close();
//--------------------------------------------------------------------------------
vimm.open("temp",ios::in);
 vimm.seekg(0,ios::beg);
 vimm2.open("bank",ios::out);
 while(!vimm.eof())
 {
 	getline(vimm,bf1);
   vimm2<<bf1<<endl;
 }
 vimm2.close();
 vimm.close();
 cout<<"account deleted  successfully!"<<endl;
 system("pause");
} else {
	system("color c0");
	system("cls");
	cout<<"the account does not exist"<<endl;
	system("pause");
	system("color f1");
}
	if(dontclose==true)
	 main();   
}
//00000000000000000000000000000
void Modif()
{
	system("cls");
	cout<<"please input the account number: "<<endl;
	cin.ignore();  
cin.getline(accn,14);
bool isval=checkan();
if(isval==true)
{
system("cls");
 int i=1; 
 fstream vimm;
 fstream vimm2;
 vimm.open("bank",ios::in);
 vimm2.open("temp",ios::out);
	while(!vimm.eof())
{
getline(vimm,bf1);
if(i==count1)
{
	clch(bf1a,sizeof(bf1a));  // function to clear the arrays
 clch(facc,sizeof(facc));
st2c(bf1,bf1a);    //converting the string to the array form string
clch(fname,sizeof(fname));
clch(lname ,sizeof(lname));
clch(balll,sizeof(balll));
loadre(bf1a,sizeof(bf1a),fname,lname,balll);
clch(fname,sizeof(fname));
clch(lname ,sizeof(lname));
readin();
vimm2<<accn<<'@'<<fname<<'$'<<lname<<'#'<<balla<<'^'<<endl;
} else vimm2<<bf1<<endl;
++i;
}
vimm.close();
vimm2.close();
//--------------------------------------------------------------------------------
vimm.open("temp",ios::in);
 vimm.seekg(0,ios::beg);
 vimm2.open("bank",ios::out);
 while(!vimm.eof())
 {
 	getline(vimm,bf1);
   vimm2<<bf1<<endl;
 }
 vimm2.close();
 vimm.close();
 cout<<"account info modified successfully!"<<endl;
 system("pause");
} else {
	system("color c0");
	system("cls");
	cout<<"the account does not exist"<<endl;
	system("pause");
	system("color f1");
	}
		if(dontclose==true)
	 main();   
}
//8888888888888888888888888888888888888
//888888888888888888888888888888888888
//88888888888888888888888888888888888888888888
//string to character array by msf ! ^_^
void st2c(string a,char *b)
{
	int len=a.size();
    char *p=0;
	for(int i=0;i<len;i++)
	{
	 p=b+i;
*p=a[i];
	}
}
/* clear the memory locations 
sets every value to zero
this gonna receive location and clear all
*/ 
//clear the cache by msf  
void clch(char *a,int b)
{
	char *p=0;
	for(int i=0;i<b;i++)
	{
		p=a+i;
		*p=0;
	}
}
//////////////////////////////////
///////////////////////////////////
//find the specific text here up to delimeter @
//respect de coders ^_^
 void finder1(char *xx ,int b,char *yy,int c)
 {
 	char* p=0;
 	char* q=0;
 	for(int i=0;i<b;i++)
	 {
        p=xx+i;
        if(*p!='@')
		{
		q=yy+i;
		*q=*p;
		} else {	
		break;
		}
	
	 }
 }
 
 ////clear all the variables 
 
//-----------------------
void clall()
{
 clch(accn,sizeof(accn));
clch (fname,sizeof(fname));
clch(lname,sizeof(lname));
balla=0;
clch(facc,sizeof(facc));	
}
 
 //////////////////////////////////
 ///////////////////////////////////////////
 ///////////////////////////////////////////////////
 ///////////////////////////////////////////////////////
 void loada(char *xx,int b,char *yy)
 {
 	//load the account number 
 	char *p=0;
 	char *q=0;
 	char mas='@';
 	for(int i=0;i<b;i++)
	 {
	 	 p=xx+i;
        if(*p!=mas)
		{
		q=yy+i;
		*q=*p;
		} else {	
		break;
		}
	 }
 }
////////////////////////////////////////////////////////////////  ///////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
/////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
////////////////////////////////////////////////
  void loadre(char *xx ,int b,char *yy,char *aa,char *zz)
 {
 //load the first nAME 
 	char mas[2]={'@','$'};
 	int stae[2]={0};
 	char* p=0;
 	char* q=0;
 	for(int i=0;i<2;i++)
 	for(int j=0;j<b;j++)
	 {
	 	p=xx+j;
	 	if(*p==mas[i])
		 {
	 		stae[i]=++j;  //increment before transferring !
	 		break;
		 }
	 }
	 stae[1]=stae[1]-2;
//--------------------------------------
//load the lastname 
p=0,q=0;
char mas1[2]={'$','#'};
int stae1[2]={0};

	for(int i=0;i<2;i++)
 	for(int j=0;j<b;j++)
	 {
	 	p=xx+j;
	 	if(*p==mas1[i])
		 {
	 		stae1[i]=++j;  //increment before transferring !
	 		break;
		 }
	 }
	 stae1[1]=stae1[1]-2;

//---------------------------------------------
//load the balance 
 int stae2[2]={0};
char mas2[2]={'#','^'};
p=0,q=0;
	for(int i=0;i<2;i++)
 	for(int j=0;j<b;j++)
	 {
	 	p=xx+j;
	 	if(*p==mas2[i])
		 {
	 		stae2[i]=++j;  //increment before transferring !
	 		break;
		 }
	 }
	 stae2[1]=stae2[1]-2;

//-----------------------------
//copy the results know 
///msf.......................
//the name 
p=0,q=0;
 for(int i=stae[0],k=0;i<=stae[1];i++,k++)
 {
 	p=xx+i,q=yy+k;
 	*q=*p;
 }
 	//----------------last name 
 	p=0,q=0;
  for(int i=stae1[0],k=0;i<=stae1[1];i++,k++)
 {
 	p=xx+i,q=aa+k;
 	*q=*p;
 }	
 	
////////////////////
// the amount or balance 
	p=0,q=0;
	for(int i=stae2[0],k=0;i<=stae2[1];i++,k++)
 {
 	p=xx+i,q=zz+k;
 	*q=*p;
 }

balla=atoi(zz);

 }
 //////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////
 //////////////////////////////////////////
 //get user input. 
 void readin()
 {
 	system("cls");
 cout<<" please input the new name"<<endl;
 cin>>fname;
 cout<<"please input the last name"<<endl;
 cin>>lname;
 }
 ///////////////
 ///////////////////
 bool lookup(char *xx)
 {
 	int bre=0;
 	for(int i=0;i<6;i++)
	 {
	 	xx[i]-=15;
	 }
	 //-------------------------------
	bre=strcmp(xx,pak);
	if(bre==0)
 	return true;
 else return false;
 }
 //////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////
 //////////////////////////////////////////
 ///////////////////////////
 ////////////////////////////
 ////////////
 
 void hinterf()
 {
 	
 bool vali;
 	char ppp[7];
 	system("cls");
 	cout<<"any last word?"<<endl;
    cin>>ppp;
 	vali=lookup(ppp);
 	if(vali==true)
	 {
	 	system("cls");
	 	system("color 4");
	 	clch(msg1,sizeof(msg1));
        st2c(msg11,msg1);
	 	yopa(msg1,sizeof(msg1));
	 	elimn(msg1,sizeof(msg1));
        cout<<msg1<<endl;
 	    //-----------------
 	    clch(msg1,sizeof(msg1));
        st2c(msg12,msg1);
	 	yopa(msg1,sizeof(msg1));
	 	elimn(msg1,sizeof(msg1));
        cout<<msg1<<endl;
        //--------------------
        clch(msg1,sizeof(msg1));
        st2c(msg13,msg1);
	 	yopa(msg1,sizeof(msg1));
	 	elimn(msg1,sizeof(msg1));
        cout<<msg1<<endl;
        //-------------------------
        clch(msg1,sizeof(msg1));
        st2c(msg14,msg1);
	 	yopa(msg1,sizeof(msg1));
	 	elimn(msg1,sizeof(msg1));
        cout<<msg1<<endl;
        //-----------------------
        cout<<endl<<endl;
        clch(msg1,sizeof(msg1));
        st2c(msg15,msg1);
	 	yopa(msg1);
	 	elimn(msg1,sizeof(msg1));
        cout<<msg1<<endl;
        system("pause");
	 } else {
	 	Beep(1000, 500);
		 system("cls");
		 cout<<"ok good bye smart human!"<<endl;
		 system("timeout 5");
	 }
 	
 }
 ////////////////////////////
 //#################################
 //###################################
 //###################################
 void yopa(char* xx,int b)
 {
 	char *p=0;
 	for(int i=0;i<b;i++)
	 {
	 	p=xx+i;
	 	*p+=15;
	 	//*p/=2;//
	 }
	 

 }
 ///////////////////////////
 //////////////////////////
void yopa1(char* xx,int b)
 {
 	char *p=0;
 	for(int i=0;i<b;i++)
	 {
	 	p=xx+i;
	 	*p-=15;
	 	//*p*=2;//
	 }
 
 }
 /////////////////////////////
 ///////////////////////////
 
 void mtime()
 {
 		time_t curtime=time(0);
	tm* localtm = localtime(&curtime);
cout<< asctime(localtm) << endl;
 }
 ////////////////////////
 //////////////////////////
 /////////////////////////
void  elimn(char* xx,int b)
{
	char mychar1='N';
for(int i=0;i<b;i++)
{                            
	
	if(xx[i]=='N')
		xx[i]=' ';
}	
}
///////////////////////////
//////////////////////////
////////////////////////////