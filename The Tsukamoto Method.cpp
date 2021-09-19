#include <iostream.h>
#include <iomanip.h>>
#include <conio.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>


float gpa, gpa_L, gpa_m, gpa_h;
float income, income_s, income_m, income_L;
float dependent, dependent_e, dependent_m, dependent_Many;
double jum_a,jum_az,ztot,beayes,beano;;
int i,k;
double g[100],min,a[100],z[100],az[100];

void beasyes(double gpa,double income,double dependent);
void beasno(double gpa,double income,double dependent);

void main;
{

cout<<"THE DETERMINATION OF THE CATEGORY OF SCHOLARSHIP ACCEPTANCE"<<endl;
cout<<"  WITH TSUKAMOTO METHOD"<<endl;
cout<<endl;

cout<<"1. Input GPA                   : "; cin>>gpa;
cout<<"2. Input Income every month    : "; cin>>income;
cout<<"3. Input dependent every month : "; cin>>dependent;


//gpa=3.20; income=3000000; dependent=2800000;
//MEMBERSHIP FUNCTION OF GPA
//FIS

if (gpa<0 || income<0 || dependent<0 || gpa>4)
	{cout<<"The data you input outside the domain of fuzzy variables";}
else
	{ if(gpa <= 2)
 		{
 		gpa_L=1;
 		gpa_m=0;
 		gpa_h=0;
 		}
 	else if(gpa >= 2 && gpa <= 2.75)
 		{
 		gpa_L=(2.75-gpa)/0.75;
 		gpa_m=(gpa-2)/0.75;
 		gpa_h=0;
      }
 	else if(gpa >= 2.75 && gpa <= 3.25)
 		{
 		gpa_L=0;
 		gpa_m=(3.25-gpa)/0.5;
 		gpa_h=(gpa-2.75)/0.5;
 		}
 	else if(gpa >= 3.25)
 		{
 		gpa_L=0;
 		gpa_m=0;
 		gpa_h=1;
 		}

 //MEMBERSHIP FUNCTION OF INCOME

if(income<= 2000000)
	{
	income_s=1;
	income_m=0;
	income_L=0;
	}
	else if(income>= 2000000 && income<= 4000000)
 		{
 		income_s=(4000000-income)/2000000;
 		income_m=(income-2000000)/2000000;
 		income_L=0;
 		}
 	else if(income>= 4000000 && income<= 6000000)
 		{
 		income_s=0;
 		income_m=1;
 		income_L=0;
 		}
 	else if(income>= 6000000 && income<= 8000000)
 		{
 		income_s=0;
 		income_m=(8000000-income)/2000000;
 		income_L=(income-6000000)/2000000;
 		}
   else if(income>= 8000000)
 		{
 		income_s=0;
 		income_m=0;
 		income_L=1;
 		}

 //MEMBERSHIP FUNCTION OF DEPENDENT

if(dependent <= 2000000)
	{
 	dependent_e=1;
 	dependent_m=0;
 	dependent_Many=0;
 	}
 	else if(dependent >= 2000000 && dependent <= 4000000)
 		{
 		dependent_e=(4000000-dependent)/2000000;
 		dependent_m=(dependent-2000000)/2000000;
 		dependent_Many=0;
 		}
 	else if(dependent >= 4000000 && dependent <= 6000000)
 		{
 		dependent_e=0;
 		dependent_m=1;
 		dependent_Many=0;
 		}
 	else if(dependent >= 6000000 && dependent <= 8000000)
 		{
 		dependent_e=0;
 		dependent_m=(8000000-dependent)/2000000;
 		dependent_Many=(dependent-6000000)/2000000;
 		}
 	else if(dependent >= 8000000)
 		{
 		dependent_e=0;
 		dependent_m=0;
 		dependent_Many=1;
 		}

 cout<<endl;
 cout<<"MEMBERSHIP VALUE FROM A LOW GPA            = "<<gpa_L<<endl;
 cout<<"MEMBERSHIP VALUE FROM A MODERATE GPA       = "<<gpa_m<<endl;
 cout<<"MEMBERSHIP VALUE FROM A HIGH GPA           = "<<gpa_h<<endl;
 cout<<"MEMBERSHIP VALUE FROM A SMALL INCOME       = "<<income_s<<endl;
 cout<<"MEMBERSHIP VALUE FROM A MEDIUM INCOME      = "<<income_m<<endl;
 cout<<"MEMBERSHIP VALUE FROM LARGE INCOME         = "<<income_L<<endl;
 cout<<"MEMBERSHIP VALUE FROM A ENOUGH DEPENDENT   = "<<dependent_e<<endl;
 cout<<"MEMBERSHIP VALUE FROM A MODERATE DEPENDENT = "<<dependent_m<<endl;
 cout<<"MEMBERSHIP VALUE FROM A MANY DEPENDENT     = "<<dependent_Many<<endl;

 k=1; jum_a=0; jum_az=0;
 cout<<endl;
 cout<<setw(16)<<"alpha"<<setw(10)<<"z"<<setw(17)<<"alpha*z"<<endl;
 cout<<endl;

 //R1
 // GPA J and INCOME K and Dependent K then Scholarship T
 beasno(gpa_L,income_s,dependent_e);
 k++;

 //R2
 // GPA J and INCOMEK and Dependent S then Scholarship T
 beasno(gpa_L,income_s,dependent_m);
 k++;

 //R3
 // GPA J and INCOMEK and Dependent B then Scholarship T
 beasno(gpa_L,income_s,dependent_Many);
 k++;

 //R4
 // GPA J and INCOMES and Dependent K then Scholarship T
 beasno(gpa_L,income_m,dependent_e);
 k++;

 //R5
 // GPA J and INCOMES and Dependent S then Scholarship T
 beasno(gpa_L,income_m,dependent_m);
 k++;

 //R6
 // GPA J and INCOMES and Dependent B then Scholarship T
 beasno(gpa_m,income_L,dependent_Many);
 k++;

 //R7
 // GPA J and INCOMEB and Dependent K then Scholarship T
 beasno(gpa_L,income_L,dependent_e);
 k++;

 //R8
 // GPA J and INCOMEB and Dependent S then Scholarship T
 beasno(gpa_L,income_L,dependent_m);
 k++;

 //R9
 // GPA J and INCOMEB and Dependent B then Scholarship T
 beasno(gpa_L,income_L,dependent_Many);
 k++;

 //R10
 // GPA S and INCOMEK and Dependent K then Scholarship T
 beasno(gpa_m,income_s,dependent_e);
 k++;

 //R11
 // GPA S and INCOMEK and Dependent S then Scholarship D
 beasyes(gpa_m,income_s,dependent_m);
 k++;

 //R12
 // GPA S and INCOMEK and Dependent B then Scholarship D
 beasyes(gpa_m,income_s,dependent_Many);
 k++;

 //R13
 // GPA S and INCOMES and Dependent K then Scholarship T
 beasno(gpa_m,income_m,dependent_e);
 k++;

 //R14
 // GPA S and INCOMES and Dependent S then Scholarship T
 beasno(gpa_m,income_m,dependent_m);
 k++;

 //R15
 // GPA S and INCOMES and Dependent B then Scholarship D
 beasyes(gpa_m,income_m,dependent_Many);
 k++;

 //R16
 // GPA S and INCOMEB and Dependent K then Scholarship T
 beasno(gpa_m,income_L,dependent_e);
 k++;

 //R17
 // GPA S and INCOMEB and Dependent S then Scholarship T
 beasno(gpa_m,income_L,dependent_m);
 k++;

 //R18
 // GPA S and INCOMEB and Dependent B then Scholarship T
 beasno(gpa_m,income_L,dependent_Many);
 k++;

 //R19
 // GPA B and INCOMEK and Dependent K then Scholarship D
 beasyes(gpa_h,income_s,dependent_e);
 k++;

 //R20
 // GPA B and INCOMEK and Dependent S then Scholarship D
 beasyes(gpa_h,income_s,dependent_m);
 k++;

 //R21
 // GPA B and INCOMEK and Dependent B then Scholarship D
 beasyes(gpa_h,income_s,dependent_Many);
 k++;

 //R22
 // GPA B and INCOMES and Dependent K then Scholarship D
 beasyes(gpa_h,income_m,dependent_e);
 k++;

 //R23
 // GPA B and INCOMES and Dependent S then Scholarship D
 beasyes(gpa_h,income_m,dependent_m);
 k++;

 //R24
 // GPA B and INCOMES and Dependent B then Scholarship D
 beasyes(gpa_h,income_m,dependent_Many);
 k++;

 //R25
 // GPA B and INCOMEB and Dependent K then Scholarship T
 beasno(gpa_h,income_L,dependent_e);
 k++;

 //R26
 // GPA B and INCOMEB and Dependent S then Scholarship D
 beasyes(gpa_h,income_L,dependent_m);
 k++;

 //R27
 // GPA B and INCOMEB and Dependent B then Scholarship D
 beasyes(gpa_h,income_L,dependent_Many);
 k++;

 for(i=1;i<=27;i++)
   {
 	jum_a=jum_a+a[i];
 	jum_az=jum_az+az[i];
   }
  cout<<"Total"<<setw(10)<<jum_a<<setw(28)<<jum_az<<endl;

 //student categories
 ztot=jum_az/jum_a;

 //defuzzyfikasi

 if (ztot<=4)
 	beano=1;
 else if (ztot>4 && ztot<7)
 	beano=(7-ztot)/3;
 else if (ztot>=7)
 	beano=0;

 if (ztot<=5)
 	beayes=0;
 else if (ztot>5 && ztot<8)
 	beayes=(ztot-5)/3;
 else if (ztot>=8)
 	beayes=1;

	 cout<<endl;
 cout<<endl;
 cout<<"Z VALUE OF STUDENT CATEGORIES  : "<<ztot<<endl;
 cout<<"MIU GET A SCHOLARSHIP          : "<<beayes<<endl;
 cout<<"MIU DIDN'T GET A SHOLARSHIP    : "<<beano<<endl;
 cout<<endl;
 cout<<endl;

 if (beayes>beano)
   {
 	cout<<"So, Z Category Scholarship with Value "<<ztot<<" including"<<endl;
   cout<<"in the category of GET SCHOLARSHIP"<<endl;
   }
 else
   {
 	cout<<"So, Z Category Scholarship with Value "<<ztot<<" including"<<endl;
   cout<<"In the Category DOES NOT GET SCHOLARSHIP"<<endl;
   }

 }

 getch();
 }


void beasyes(double gpa,double income,double dependent)
{
  g[1]=gpa;
 g[2]=income;
 g[3]=dependent;
 min=g[1];
 for (i=1;i<=3;i++)
 	if (g[i]<min)
   	min=g[i];
 a[k]=min;
 z[k]=5+min*3;
 az[k]=a[k]*z[k];
 cout<<"R"<<k<<setw(12)<<a[k]<<setw(12)<<z[k]<<setw(15)<<az[k];
 cout<<endl;
}

void beasno(double gpa,double income,double dependent)
{
 g[1]=gpa;
 g[2]=income;
 g[3]=dependent;
 min=g[1];
 for (i=1;i<=3;i++)
 	if (g[i]<min)
   	min=g[i];
 a[k]=min;
 z[k]=7-min*3;
 az[k]=a[k]*z[k];
 cout<<"R"<<k<<setw(12)<<a[k]<<setw(12)<<z[k]<<setw(15)<<az[k];
 cout<<endl;
}
