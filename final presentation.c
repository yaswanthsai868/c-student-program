#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
struct college
{
    char cname[30];
    char ccode[10];
    struct student *s,*p;
};

struct student
{
    char name[20];
    char gender[10];
    char rollno[20];
    char branch[20];
    char bcode[20];
    char father[20];
    char address[30];
    long long int snumber;
    long long int pnumber;
    float attendance;
    int mid1marks[6];
    int mid2marks[6];
    int extmarks[6];
    int mid1total;
    int mid2total;
	int as1[6];
	int as2[6];
    int externaltotal;
    float externalper;
    float internalper;
    float mid1per;
    float mid2per;
    float totalper;
    char grade[10];
	float avg[6];
};
char sub[6][10]={"C.P","E.P","E.C","ENG","E.S","A.C"};

void main()
{
	void brl(struct student *,char []);
	void ma1s(struct student *,int);
	void mbranch(struct student *);
	void stdetails(struct student *);
	void ma2s(struct student *,int);
	void condonation(struct student *);
	void detain(struct student *);
	void ndetain(struct student *);
	void mm1(struct student *,int);
	void mm2(struct student *,int);
	void top1(struct student *,int);
	void top2(struct student *,int);
	void topsem(struct student *,int);
	void mrollno(struct student *);
	void mfname(struct student *);
	void mext(struct student *,int);
	void msno(struct student *);
	void mpno(struct student *);
	void mattendance(struct student *);
	void mgender(struct student *);
	void maddress(struct student *);
	void mname(struct student *);
	int search(struct student *,char []);
	void topm1(struct student *);
	void topm2(struct student *);
	int choice,ch,ch1,ch11;
    char opt,op,opt1,opt2;
    struct college *c= (struct college*)malloc(1*sizeof(struct college));
    c->p = (struct student*) malloc(20*sizeof(struct student));
    system("COLOR B5");
    int i,j,index;
    printf("Enter the college name\n");
    scanf("%s",c->cname);
    printf("Enter the college code press $ to stop\n");
    scanf("%[^$]",c->ccode);
    for(i=0;i<10;i++)
    {
        printf("Enter student details\n");
        printf("Enter the name of student\n");
		fflush(stdin);
	    scanf("%s",c->p[i].name);
	    printf("Enter the roll no of student and press $ to stop\n");
		fflush(stdin);
        scanf("%[^$]",c->p[i].rollno);
        printf("Enter the gender of student\n");
		fflush(stdin);
        scanf("%s",c->p[i].gender);
        printf("Enter the branch and branch code and press $ to stop input\n");
		fflush(stdin);
        gets(c->p[i].branch);
		fflush(stdin);
        scanf("%[^$]",c->p[i].bcode);
        printf("Enter the father name\n");
		fflush(stdin);
        gets(c->p[i].father);
        printf("Enter the address of student and press $ to stop input\n");
		fflush(stdin);
        scanf("%[^$]",c->p[i].address);
        printf("Enter the student phone number and parents number\n");
		fflush(stdin);
        scanf("%lld%lld",&c->p[i].snumber,&c->p[i].pnumber);
        printf("Enter the attendance percentage of student\n");
		fflush(stdin);
        scanf("%f",&c->p[i].attendance);
		printf("Enter first assignment marks\n");
		for(j=0;j<6;j++)
		{
			printf("Enter the assignment marks of subject %s\t",sub[j]);
			fflush(stdin);
			scanf("%d",&c->p[i].as1[j]);
		}
        printf("Enter the 1 st mid marks\n");
        for(j=0;j<6;j++)
        {
            printf("Enter the marks of %s\t",sub[j]);
            scanf("%d",&c->p[i].mid1marks[j]);
        }
		printf("Enter second assignment marks\n");
		for(j=0;j<6;j++)
		{
			printf("Enter the assignment marks of subject %s\t",sub[j]);
			fflush(stdin);
			scanf("%d",&c->p[i].as2[j]);
		}
        printf("Enter the mid 2 exam marks\n");
        for(j=0;j<6;j++)
        {
            printf("Enter the marks of %s\t",sub[j]);
            scanf("%d",&c->p[i].mid2marks[j]);
        }
		printf("Enter external marks\n");
        for(j=0;j<6;j++)
        {
            printf("Enter the marks of %s\t",sub[j]);
            scanf("%d",&c->p[i].extmarks[j]);
        }
		for(j=0,c->p[i].mid1total=0,c->p[i].externaltotal=0,c->p[i].mid2total=0;j<6;j++)
		{
			c->p[i].mid1total+=c->p[i].mid1marks[j]+c->p[i].as1[j];
			c->p[i].mid2total+=c->p[i].mid2marks[j]+c->p[i].as2[j];
			c->p[i].externaltotal+=c->p[i].extmarks[j];
		}
		c->p[i].mid1per=(float)(c->p[i].mid1total)*5/12;
        c->p[i].mid2per=(float)(c->p[i].mid2total)*5/12;
        for(j=0;j<6;j++)
		{
			if((c->p[i].mid1marks[j]+c->p[i].as1[j])>(c->p[i].mid2marks[j]+c->p[i].as2[j]))
			{
				c->p[i].avg[j]=((c->p[i].mid1marks[j]+c->p[i].as1[j])*((float)4/5))+((c->p[i].mid2marks[j]+c->p[i].as2[j])*((float)1/5));
			}
			else
			{
				c->p[i].avg[j]=((c->p[i].mid1marks[j]+c->p[i].as1[j])*((float)1/5))+((c->p[i].mid2marks[j]+c->p[i].as2[j])*((float)4/5));
			}
		}
		for(j=0,c->p[i].internalper=0;j<6;j++)
		{
			c->p[i].internalper+=c->p[i].avg[j];
		}
		c->p[i].internalper=c->p[i].internalper*(float)5/12;
        c->p[i].externalper=c->p[i].externaltotal*(float)5/18;
        c->p[i].totalper=((c->p[i].internalper)*((float)2/5))+((c->p[i].externalper)*((float)3/5));
        index=(c->p[i].totalper)/10;
        switch(index)
        {
        case 10:
        case 9:
        case 8:
            strcpy(c->p[i].grade,"honour");
            break;
        case 7:
        case 6:
            strcpy(c->p[i].grade,"first");
            break;
        case 5:
            strcpy(c->p[i].grade,"second");
            break;
        case 4:
            strcpy(c->p[i].grade,"third");
            break;
        default:
            strcpy(c->p[i].grade,"fail");
		break;
        }
	}///input completed
home:
do
{
printf("Enter 1 for rank list\n");
printf("Enter 2 for attendance list\n");
printf("Enter 3 for details modification\n");
printf("Enter 4 for student details\n");
scanf("%d",&choice);
switch(choice)
{
  case 1:
	 prev:
	 do
	 {
	   printf("Enter 1 for mid 1 subject wise rank list\n");
	   printf("Enter 2 for mid 2 subject wise rank list\n");
	   printf("Enter 3 for branch wise rank list\n");
	   printf("Enter 4 for semester rank list\n");
	   printf("To go to home menu press 5\n");
	   scanf("%d",&ch);
	   if(ch==5)
	     goto home;
	   switch(ch)
	   {
	     case 1:
		    do
		    {
		      printf("Enter 1 for C.P rank list\n");
		      printf("Enter 2 for E.P rank list\n");
		      printf("Enter 3 for E.c rank list\n");
		      printf("Enter 4 for ENG rank list\n");
		      printf("Enter 5 for E.S rank list\n");
		      printf("Enter 6 for A.C rank list\n");
			  printf("Enter 7 for mid 1 rank list\n");
		      printf("Enter 8 for more options\n");
		      fflush(stdin);
		      scanf("%d",&ch1);
		      switch(ch1)
		      {
			case 1:
			       top1(c->p,0);
			       break;
			case 2:
			       top1(c->p,1);
			       break;
			case 3:
			       top1(c->p,2);
			       break;
			case 4:
			       top1(c->p,3);
			       break;
			case 5:
			       top1(c->p,4);
			       break;
			case 6:
			       top1(c->p,5);
			       break;
			case 7:
			       topm1(c->p);
			       break;
			default:
			       printf("Thank You\n");
		      }
		      printf("To know any other Mid 1 subject ranks press y\n");
		      printf("To go to previous menu press p\n");
		      printf("To go to home menu press h\n");
		      fflush(stdin);
		      opt1=getchar();
		      if(opt1=='h')
			goto home;
		      if(opt1=='p')
			goto prev;
		      }while(opt1=='y');
		    break;
	     case 2:
		    do
		    {
		      printf("Enter 1 for C.P rank list\n");
		      printf("Enter 2 for E.P rank list\n");
		      printf("Enter 3 for E.C rank list\n");
		      printf("Enter 4 for ENG rank list\n");
		      printf("Enter 5 for E.S rank list\n");
		      printf("Enter 6 for A.C rank list\n");
			  printf("Enter 7 for mid 2 rank list\n");
		      printf("Enter 8 for more options\n");
		      fflush(stdin);
		      scanf("%d",&ch1);
		      switch(ch1)
		      {
			case 1:
			       top2(c->p,0);
			       break;
			case 2:
			       top2(c->p,1);
			       break;
			case 3:
			       top2(c->p,2);
			       break;
			case 4:
			       top2(c->p,3);
			       break;
			case 5:
			       top2(c->p,4);
			       break;
			case 6:
			       top2(c->p,5);
			       break;
			case 7:
			       topm2(c->p);
			       break;
			default:
			       printf("Thank You\n");
		      }
		      printf("To know any other Mid 2 subject ranks press y\n");
		      printf("To go to previous menu press p\n");
		      printf("To go to home menu press h\n");
		      fflush(stdin);
		      opt1=getchar();
		      if(opt1=='h')
			goto home;
		      if(opt1=='p')
			goto prev;
		      }while(opt1=='y');
		      break;
	     case 3:
		    do
		    {
		      printf("Enter 1 for CSE rank list\n");
		      printf("Enter 2 for ECE rank list\n");
		      printf("Enter 3 for EEE rank list\n");
		      printf("Enter 4 for IT rank list\n");
		      printf("Enter 5 for ME rank list\n");
		      printf("Enter 6 for more options\n");
		      fflush(stdin);
		      scanf("%d",&ch1);
		      switch(ch1)
		      {
			case 1:
			       brl(c->p,"cse");
			       break;
			case 2:
			       brl(c->p,"ece");
			       break;
			case 3:
			       brl(c->p,"eee");
			       break;
			case 4:
			       brl(c->p,"it");
			       break;
			case 5:
			       brl(c->p,"me");
			       break;
			default:
			       printf("Thank You\n");
		      }
		      printf("To know any other branch ranks press y\n");
		      printf("To go to previous menu press p\n");
		      printf("To go to home menu press h\n");
		      fflush(stdin);
		      opt1=getchar();
		      if(opt1=='h')
			goto home;
		      if(opt1=='p')
			goto prev;
		      }while(opt1=='y');
		      break;
	     case 4:
		    topsem(c->p,10);
		    break;
	     default:
		    printf("Thank You\n");
	   }
	   printf("To know any other rank details press y\n");
	   printf("To go to home menu press h\n");
	   fflush(stdin);
	   op=getchar();
	   if(op=='h')
	     goto home;
	 }while(op=='y');
	 break;
  case 2:
	 do
	 {
	 printf("Enter 1 for list of students having percentage greater than 75\n");
	 printf("Enter 2 for list of students having percentage between 65 to 75\n");
	 printf("Enter 3 for list of students having percentage less than 65\n");
	 printf("Enter 4 for more options\n");
	 scanf("%d",&ch);
	 switch(ch)
	 {
	   case 1:
	      ndetain(c->p);
		  break;
	   case 2:
	      condonation(c->p);
		  break;
	   case 3:
	      detain(c->p);
		  break;
	   default:
		  printf("Thank You\n");
	 }
	 printf("To know any other attendance details press y\n");
	 printf("To go to home menu press h\n");
	 fflush(stdin);
	 op=getchar();
	 if(op=='h')
	   goto home;
	 }while(op=='y');
	 break;
  case 3:
	 previous:
	 do
	 {
	 printf("Enter 1 to change name\n");
	 printf("Enter 2 to change rollno\n");
	 printf("Enter 3 to change father's name\n");
	 printf("Enter 4 to change student's mobile number\n");
	 printf("Enter 5 to change parent's mobile number\n");
	 printf("Enter 6 to change marks\n");
	 printf("Enter 7 to change attendance\n");
	 printf("Enter 8 to change gender\n");
	 printf("Enter 9 to change address\n");
	 printf("Enter 10 to change branch and branch code\n");
	 printf("Enter 11 for more options\n");
	 fflush(stdin);
	 scanf("%d",&ch);
	 switch(ch)
	 {
	   case 1:
	      mname(c->p);
		  break;
	   case 2:
	      mrollno(c->p);
		  break;
	   case 3:
	      mfname(c->p);
		  break;
	   case 4:
	      msno(c->p);
		  break;
	   case 5:
	      mpno(c->p);
		  break;
	   case 6:
		    do
		    {
		      printf("Enter 1 for changing mid 1 marks\n");
		      printf("Enter 2 for changing mid 2 marks\n");
		      printf("Enter 3 for changing external marks\n");
			  printf("Enter 4 for changing assignment 1 marks\n");
			  printf("Enter 5 for changing assignment 2 marks\n");
		      printf("Enter 6 for more details\n");
		      fflush(stdin);
		      scanf("%d",&ch1);
		      switch(ch1)
		      {
		      case 1:
			     do
			     {
			     printf("Enter 1 for changing C.P marks\n");
			     printf("Enter 2 for changing E.P marks\n");
			     printf("Enter 3 for changing E.C marks\n");
			     printf("Enter 4 for changing ENG marks\n");
			     printf("Enter 5 for changing E.S marks\n");
			     printf("Enter 6 for changing A.C marks\n");
			     fflush(stdin);
			     scanf("%d",&ch11);
			     switch(ch11)
			     {
				case 1:
				       mm1(c->p,0);
				       break;
				case 2:
				       mm1(c->p,1);
				       break;
				case 3:
				       mm1(c->p,2);
				       break;
				case 4:
				       mm1(c->p,3);
				       break;
				case 5:
				       mm1(c->p,4);
				       break;
				case 6:
				       mm1(c->p,5);
				       break;
				default:
				       printf("Thank You\n");
			     }
				 printf("do you want to change any other Mid 1 marks:press y/n\n");
			     fflush(stdin);
			     opt2=getchar();
			     }while(opt2!='n');
			     break;
		      case 2:
			     do
			     {
			     printf("Enter 1 for changing C.P marks\n");
			     printf("Enter 2 for changing E.P marks\n");
			     printf("Enter 3 for changing E.C marks\n");
			     printf("Enter 4 for changing ENG marks\n");
			     printf("Enter 5 for changing E.S marks\n");
			     printf("Enter 6 for changing A.C marks\n");
			     fflush(stdin);
			     scanf("%d",&ch11);
			     switch(ch11)
			     {
				case 1:
				       mm2(c->p,0);
				       break;
				case 2:
				       mm2(c->p,1);
				       break;
				case 3:
				       mm2(c->p,2);
				       break;
				case 4:
				       mm2(c->p,3);
				       break;
				case 5:
				       mm2(c->p,4);
				       break;
				case 6:
				       mm2(c->p,5);
				       break;
			     }
			     printf("do you want to change any other Mid 2 marks:press y/n\n");
			     fflush(stdin);
			     opt2=getchar();
			     }while(opt2!='n');
			     break;
		      case 3:
			     do
			     {
			     printf("Enter 1 for changing C.P marks\n");
			     printf("Enter 2 for changing E.P marks\n");
			     printf("Enter 3 for changing E.C marks\n");
			     printf("Enter 4 for changing ENG marks\n");
			     printf("Enter 5 for changing E.S marks\n");
			     printf("Enter 6 for changing A.C marks\n");
			     fflush(stdin);
			     scanf("%d",&ch11);
			     switch(ch11)
			     {
				case 1:
				       mext(c->p,0);
				       break;
				case 2:
				       mext(c->p,1);
				       break;
				case 3:
				       mext(c->p,2);
				       break;
				case 4:
				       mext(c->p,3);
				       break;
				case 5:
				       mext(c->p,4);
				       break;
				case 6:
				       mext(c->p,5);
				       break;
			     }
			     printf("do you want to change any other External marks:press y/n\n");
			     fflush(stdin);
			     opt2=getchar();
			     }while(opt2!='n');
			     break;
			case 4:
			    do
				{
					printf("Enter 1 for changing C.P assignment marks\n");
					printf("Enter 2 for changing E.P assignment marks\n");
					printf("Enter 3 for changing E.C assignment marks\n");
					printf("Enter 4 for changing ENG assignment marks\n");
					printf("Enter 5 for changing E.S assignment marks\n");
					printf("Enter 6 for changing A.C assignment marks\n");
					fflush(stdin);
					scanf("%d",&ch11);
					switch(ch11)
					{
						case 1:
						      ma1s(c->p,0);
							  break;
						case 2:
						      ma1s(c->p,1);
							  break;
						case 3:
						      ma1s(c->p,2);
						      break;
						case 4:
						      ma1s(c->p,3);
							  break;
						case 5:
						      ma1s(c->p,4);
							  break;
						case 6:
						      ma1s(c->p,5);
							  break;
					}
					printf("do you want to change any another assignment marks press:y/n\n");
					fflush(stdin);
					opt2=getchar();
				}while(opt2!='n');
				break;
			case 5:
			do
				{
					printf("Enter 1 for changing C.P assignment marks\n");
					printf("Enter 2 for changing E.P assignment marks\n");
					printf("Enter 3 for changing E.C assignment marks\n");
					printf("Enter 4 for changing ENG assignment marks\n");
					printf("Enter 5 for changing E.S assignment marks\n");
					printf("Enter 6 for changing A.C assignment marks\n");
					fflush(stdin);
					scanf("%d",&ch11);
					switch(ch11)
					{
						case 1:
						      ma2s(c->p,0);
							  break;
						case 2:
						      ma2s(c->p,1);
							  break;
						case 3:
						      ma2s(c->p,2);
						      break;
						case 4:
						      ma2s(c->p,3);
							  break;
						case 5:
						      ma2s(c->p,4);
							  break;
						case 6:
						      ma2s(c->p,5);
							  break;
					}
					printf("do you want to change any another assignment marks press:y/n\n");
					fflush(stdin);
					opt2=getchar();
				}while(opt2!='n');
		      default:
			     printf("Thank You\n");
		      }
		    printf("To change any other marks press y\n");
		    printf("To go to previous menu press p\n");
		    printf("To go to home menu press h\n");
		    fflush(stdin);
		    opt1=getchar();
		    if(opt1=='h')
		      goto home;
		    if(opt1=='p')
		      goto previous;
		    }while(opt1=='y');
		    break;
	   case 7:
	      mattendance(c->p);
		  break;
	   case 8:
	      mgender(c->p);
		  break;
	   case 9:
	      maddress(c->p);
		  break;
	   case 10:
          mbranch(c->p);
		  break;
	   default:
		  printf("Thank You\n");
	 }
	 printf("To modify any other details press y\n");
	 printf("To go to home menu press h\n");
	 fflush(stdin);
	 op=getchar();
	 if(op=='h')
	   goto home;
	 }while(op=='y');
	 break;
  case 4:
	 stdetails(c->p);
	 break;
  default:
	 printf("Thank You\n");
}
printf("Do you want to know any more details:Press y/n\n");
fflush(stdin);
opt=getchar();
}while(opt!='n');
}
void condonation(struct student *p1)
{
int i,flag=0;
for(i=0;i<10;i++)
{
if(p1[i].attendance<(float)75&&p1[i].attendance>(float)65)
{
  printf("-25%s %s %f \n",p1[i].name,p1[i].rollno,p1[i].attendance);
  flag=1;
}
}
if(flag==0)
	printf("No student has to pay condonation\n");
}
void detain(struct student *p1)
{
int i,flag=0;
for(i=0;i<10;i++)
{
if(p1[i].attendance<(float)65)
{
  printf("%-25s %s %f \n",p1[i].name,p1[i].rollno,p1[i].attendance);
  flag=1;
}
}
if(flag==0)
   printf("No student is detained\n");
}
void ndetain(struct student *p1)
{
int i,flag=0;
for(i=0;i<10;i++)
{
if(p1[i].attendance>(float)75)
{
  printf("%-25s %s %f \n",p1[i].name,p1[i].rollno,p1[i].attendance);
  flag=1;
}
}
if(flag==0)
	printf("No student has minimum attendance\n");
}
void top1(struct student *p1,int k)
{
int i,j;
struct student t;
for(i=0;i<10;i++)
{
  for(j=i;j<10;j++)
   {
     if(p1[i].mid1marks[k]<p1[j].mid1marks[k])
     {
       t=p1[i];
       p1[i]=p1[j];
       p1[j]=t;
     }
   }
}
for(i=0;i<10;i++)
printf(" %d %-25s %s %d\n",i+1,p1[i].name,p1[i].rollno,p1[i].mid1marks[k]);
}

void top2(struct student *p1,int k)
{
int i,j;
struct student t;
for(i=0;i<10;i++)
{
  for(j=i;j<10;j++)
   {
     if(p1[i].mid2marks[k]<p1[j].mid2marks[k])
     {
       t=p1[i];
       p1[i]=p1[j];
       p1[j]=t;
     }
   }
}
for(i=0;i<10;i++)
printf(" %d %-25s %s %d\n",i+1,p1[i].name,p1[i].rollno,p1[i].mid2marks[k]);
}

void topsem(struct student *p1,int k)
{
int i,j;
struct student t;
for(i=0;i<k;i++)
{
  for(j=i;j<k;j++)
   {
     if(p1[i].totalper<p1[j].totalper)
     {
       t=p1[i];
       p1[i]=p1[j];
       p1[j]=t;
     }
   }
}
for(i=0;i<k;i++)
printf("%d %-25s %s %f\n",i+1,p1[i].name,p1[i].rollno,p1[i].totalper);
}
void mrollno(struct student *p1)
{
  int i;
  char c[20];
  int search(struct student *,char []);
  printf("Enter the roll no which is to be modified\n");
  fflush(stdin);
  gets(c);
  i=search(p1,c);
  printf("Enter the correct roll no\n");
  fflush(stdin);
  gets(p1[i].rollno);
}
void mfname(struct student *p1)
{
  int i;
  char c[20];
  int search(struct student *,char []);
  printf("Enter the roll no of student whose father's name is to be modified\n");
  fflush(stdin);
  gets(c);
  i=search(p1,c);
  printf("Enter the correct father's name\n");
  fflush(stdin);
  gets(p1[i].father);
}
void msno(struct student *p1)
{
  int i;
  char c[20];
  int search(struct student *,char []);
  printf("Enter the roll no of student whose student p.h number is to be modified\n");
  fflush(stdin);
  gets(c);
  i=search(p1,c);
  printf("Enter the correct student p.h number\n");
  fflush(stdin);
  scanf("%lld",&p1[i].snumber);
}
void mpno(struct student *p1)
{
  int i;
  char c[20];
  int search(struct student *,char []);
  printf("Enter the roll no of student whose parent p.h number is to be modified\n");
  fflush(stdin);
  gets(c);
  i=search(p1,c);
  printf("Enter the correct parent p.h number\n");
  fflush(stdin);
  scanf("%lld",&p1[i].pnumber);
}
void mattendance(struct student *p1)
{
  int i;
  char c[20];
  int search(struct student *,char []);
  printf("Enter the roll no of student whose attendance percentage is to be modified\n");
  fflush(stdin);
  gets(c);
  i=search(p1,c);
  printf("Enter the correct attendance percentage\n");
  fflush(stdin);
  scanf("%f",&p1[i].attendance);
}
void mgender(struct student *p1)
{
  int i;
  char c[20];
  int search(struct student *,char []);
  printf("Enter the roll no of student whose gender is to be modified\n");
  fflush(stdin);
  gets(c);
  i=search(p1,c);
  printf("Enter the correct gender\n");
  fflush(stdin);
  gets(p1[i].gender);
}
void maddress(struct student *p1)
{
  int i;
  char c[20];
  int search(struct student *,char []);
  printf("Enter the roll no of student whose address is to be modified\n");
  fflush(stdin);
  gets(c);
  i=search(p1,c);
  printf("Enter the correct address and press $ to stop\n");
  fflush(stdin);
  scanf("%[^$]",p1[i].address);
}
void mname(struct student *p1)
{
  int i;
  char c[20];
  int search(struct student *,char []);
  printf("Enter the roll no of student whose name is to be modified\n");
  fflush(stdin);
  gets(c);
  i=search(p1,c);
  printf("Enter the correct name of student\n");
  fflush(stdin);
  gets(p1[i].name);
}
int search(struct student *p1,char c[20])
{
  int i;
  for(i=0;i<10;i++)
  {
    if(strcmp(p1[i].rollno,c))
	  continue;
	else
	{
	  return i;
	  break;
	}
   }
}
void topm1(struct student *p1)
{
	int i,j;
	struct student t;
	for(i=0;i<10;i++)
	{
		for(j=i;j<10;j++)
		{
			if(p1[i].mid1per<p1[j].mid1per)
			{
				t=p1[i];
				p1[i]=p1[j];
				p1[j]=t;
			}

		}

	}
	for(i=0;i<10;i++)
        printf("%d %-25s %s %f\n",i+1,p1[i].name,p1[i].rollno,p1[i].mid1per);
}
void topm2(struct student *p1)
{
	int i,j;
	struct student t;
	for(i=0;i<10;i++)
	{
		for(j=i;j<10;j++)
		{
			if(p1[i].mid2per<p1[j].mid2per)
			{
				t=p1[i];
				p1[i]=p1[j];
				p1[j]=t;
			}
		}
	}
    for(i=0;i<10;i++)
        printf("%d %-25s %s %f\n",i+1,p1[i].name,p1[i].rollno,p1[i].mid2per);
}
void mm1(struct student *p1,int k)
{
	int i;
	void mcal(struct student *,int);
	char c[20];
	int search(struct student *,char []);
	printf("Enter the roll no of student whose marks are to be modified\n");
	fflush(stdin);
	gets(c);
	i=search(p1,c);
	printf("Enter the correct marks\n");
	fflush(stdin);
	scanf("%d",&p1[i].mid1marks[k]);
	mcal(p1,i);
}
void mm2(struct student *p1,int k)
{
	int i;
	void mcal(struct student *,int);
	char c[20];
	int search(struct student *,char []);
	printf("Enter the roll no of student whose marks are to be modified\n");
	fflush(stdin);
	gets(c);
	i=search(p1,c);
	printf("Enter the correct marks\n");
	fflush(stdin);
	scanf("%d",&p1[i].mid2marks[k]);
	mcal(p1,i);
}
void stdetails(struct student *p1)
{
	int search(struct student *,char []);
	int i,j;
	char c[20];
	printf("Enter rollno of student to get details\n");
	fflush(stdin);
	gets(c);
	i=search(p1,c);
	printf("The name of student is %s\n",p1[i].name);
	printf("The rollno of student is %s\n",p1[i].rollno);
	printf("The gender of student is %s\n",p1[i].gender);
	printf("The	branch of student is %s and branch code is %s\n",p1[i].branch,p1[i].bcode);
	printf("Student's father's name is %s\n",p1[i].father);
	printf("The address of student is %s\n",p1[i].address);
	printf("The phone number of student is %lld\nThe phone number of parent is %lld\n",p1[i].snumber,p1[i].pnumber);
	printf("The attendance percentage of student is %f\n",p1[i].attendance);
	printf("The first mid marks of student are\n");
	for(j=0;j<6;j++)
	{
		printf("The marks in %s subject is %d\n",sub[j],p1[i].mid1marks[j]);
		printf("The marks in %s assignment is %d\n",sub[j],p1[i].as1[j]);
	}
	printf("The second mid marks and second assignment marks of student are\n");
	for(j=0;j<6;j++)
	{
		printf("The marks in %s subject is %d\n",sub[j],p1[i].mid2marks[j]);
		printf("The marks in %s assignment is %d\n",sub[j],p1[i].as2[j]);

	}
	printf("The external marks of student are\n");
	for(j=0;j<6;j++)
	{
		printf("The marks in %s subject is %d\n",sub[j],p1[i].extmarks[j]);
	}
	printf("The mid 1 percentage of student is %f\n",p1[i].mid1per);
	printf("The mid 2 percentage of student is %f\n",p1[i].mid2per);
	printf("The internal percentage of student is %f\n",p1[i].internalper);
	printf("The external percentage of student is %f\n",p1[i].externalper);
	printf("The Total sem percentage of student is %f\n",p1[i].totalper);
	printf("The grade of student is %s\n",p1[i].grade);
}
void ma1s(struct student *p1,int k)
{
	char c[20];
	int search(struct student *,char []);
	int i;
	void mcal(struct student *,int);
	printf("Enter the rollno of student whose first assignment marks are to be modified\n");
	fflush(stdin);
	gets(c);
	i=search(p1,c);
	printf("Enter the correct assignment marks\n");
	scanf("%d",&p1[i].as1[k]);
	mcal(p1,i);
}
void ma2s(struct student *p1,int k)
{
	char c[20];
	int search(struct student *,char []);
	int i;
	void mcal(struct student *,int);
	printf("Enter the rollno of student whose second assignment marks are to be modified\n");
	fflush(stdin);
	gets(c);
	i=search(p1,c);
	printf("Enter the correct assignment marks\n");
	scanf("%d",&p1[i].as2[k]);
	mcal(p1,i);
}
void mext(struct student *p1,int k)
{
	int search(struct student *,char []);
	void mcal(struct student *,int);
	char c[20];
	int i;
	printf("Enter the rollno of student whose external marks are to be modified\n");
	fflush(stdin);
    gets(c);
    i=search(p1,c);
	printf("Enter the correct external marks\n");
	fflush(stdin);
	scanf("%d",&p1[i].extmarks[k]);
	mcal(p1,i);
}
void mbranch(struct student *p1)
{
    int i;
    char c[20];
    int search(struct student *,char []);
    printf("Enter the rollno of student whose branch is entered wrong\n");
    fflush(stdin);
    gets(c);
    i=search(p1,c);
    printf("Enter the correct branch and branch code\n");
    fflush(stdin);
    scanf("%s%s",p1[i].branch,p1[i].bcode);
}
void mcal(struct student *p1,int k)
{
	int j,index;
	for(j=0,p1[k].mid1total=0,p1[k].externaltotal=0,p1[k].mid2total=0;j<6;j++)
		{
			p1[k].mid1total+=p1[k].mid1marks[j]+p1[k].as1[j];
			p1[k].mid2total+=p1[k].mid2marks[j]+p1[k].as2[j];
			p1[k].externaltotal+=p1[k].extmarks[j];
		}p1[k].mid1per=(float)(p1[k].mid1total)*5/12;
        p1[k].mid2per=(float)(p1[k].mid2total)*5/12;
        for(j=0;j<6;j++)
		{
			if((p1[k].mid1marks[j]+p1[k].as1[j])>(p1[k].mid2marks[j]+p1[k].as2[j]))
			{
				p1[k].avg[j]=((p1[k].mid1marks[j]+p1[k].as1[j])*((float)4/5))+((p1[k].mid2marks[j]+p1[k].as2[j])*((float)1/5));
			}
			else
			{
				p1[k].avg[j]=((p1[k].mid1marks[j]+p1[k].as1[j])*((float)1/5))+((p1[k].mid2marks[j]+p1[k].as2[j])*((float)4/5));
			}
		}
		for(j=0,p1[k].internalper=0;j<6;j++)
		{
			p1[k].internalper+=p1[k].avg[j];
		}
		p1[k].internalper=p1[k].internalper*(float)5/12;
        p1[k].externalper=p1[k].externaltotal*(float)5/18;
        p1[k].totalper=((p1[k].internalper)*((float)2/5))+((p1[k].externalper)*((float)3/5));
        index=(p1[k].totalper)/10;
        switch(index)
        {
        case 10:
        case 9:
        case 8:
            strcpy(p1[k].grade,"honour");
            break;
        case 7:
        case 6:
            strcpy(p1[k].grade,"first");
            break;
        case 5:
            strcpy(p1[k].grade,"second");
            break;
        case 4:
            strcpy(p1[k].grade,"third");
            break;
        default:
            strcpy(p1[k].grade,"fail");
		break;
        }
}
void brl(struct student *p1,char c[20])
{
	int i,k,j,flag=0;
	float bp[10];
	char bn[10][20],br[10][20];
	for(i=0,j=0;i<10;i++)
	{
		if(strcmpi(p1[i].branch,c)==0)
		{
			strcpy(bn[j],p1[i].name);
			strcpy(br[j],p1[i].rollno);
			bp[j]=p1[i].totalper;
			j++;
			flag=1;
		}
	}
	for(i=0;i<j;i++)
	{
		for(k=i;k<j;k++)
		{
			if(bp[i]<bp[j])
			{
				bp[j]=(bp[j]+bp[i])-(bp[i]=bp[j]);
			}
		}
	}
	if(flag==1)
	{
	  for(i=0;i<j;i++)
		printf("%d %-25s %s %f\n",i+1,bn[i],br[i],bp[i]);
	}
	else
		printf("There is no student in the branch");
}




