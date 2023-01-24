#include<rlutil.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define BUFFER_SIZE 1000
#define NR1 20

/// Book-A-Flight-Inator

void create();
void read1(); //aici nu ar fi mers doar read de la rlutil.h
void update();
void delete();
void search();
void auth();
void menu();
void signup();

struct Customer{
	char fname[23], lname[23], phonenumber[23], email[23], id[23], from[23], to[23];// class[20];
};

enum {
    ecreate=1,
    eread=2,
    esearch=3,
    edelete=4,
    eupdate=5
};


int main()
{

    int var;
    printf("\t\tWelcome:\n");
    printf("\n\n\t\t1 for Log in:\n");
    printf("\t\t2 for Sign up:\n");
    printf("\n\t\tYour choice:\t");
    scanf(" %d", &var);
    switch(var)
    {
        case 1: auth(); break;
        case 2: signup(); break;
    }

}


typedef struct userr
{
    char nume[NR1];
    char parola[NR1];
} user;

void signup()
{
    FILE *g= fopen("accounts.txt", "r+");

     int n;
     fscanf(g,"%d",&n);
     int m;
     m=n;
     m++;

     user *v = malloc(m * sizeof(*v));
     int i=0;
     while(i<m)
     {
         fscanf(g,"%10s", v[i].nume);
         fscanf(g,"%10s", v[i].parola);
         i++;
     } fseek(g,0,SEEK_SET);
     fprintf(g,"%d",m);
     printf("\n\n\t\tName (minimum 3 characters): ");
     scanf("%10s", v[i].nume);

    printf("\t\tPassword (minimum 3 characters): ");
	scanf("%10s", v[i].parola);
     /*for(i=0; i <NR1-1;i++)
    {
        char c;
        c = getch(); printf("%d %c \n", c, c);
        v[i].parola[i] = c;
        if ( v[i].parola[i] == '\b' && i!=0)
        {
            printf("\b \b");
            i-= 2;
            continue;
        }
        else if ( v[i].parola[i] == '\b' && i == 0)
        {
            i--;
            printf("\b \b");
            printf(" ");
            continue;
        }
        else if( v[i].parola[i] != '\r')
            printf("*");
        else
            break;
    }
    v[i].parola[i]='\0';

     for (i=0; i<m+1; ++i)
     {
         fprintf(g,"%10s",v[i].nume);
         fprintf(g,"%10s",v[i].parola);
         printf("%10s",v[i].parola);
     }*/
     /*char nam[NR1], pa[NR1];
     scanf("%10s", nam);
     scanf("%10s", pa);
     fprintf(f,"%10s",nam);
     fprintf(f,"%10s",pa);*/

     fclose(g);
}

int login()
{
        FILE* f = fopen("accounts.txt","r");
        int n;
        fscanf(f,"%d",&n);

        user *v = malloc(n * sizeof(*v));
        char nume1[NR1],parola[NR1];
        int i=0;
        while(i<n)
        {
            fscanf(f,"%10s", v[i].nume);
            fscanf(f,"%10s", v[i].parola);
            i++;
        }
        printf("\n\n\t\tName: ");
        scanf("%10s", nume1);
        for(i=0;i<n;i++)
        if (strcmp(nume1,v[i].nume)==0)
            break;
        if(i==n)
            return 0;
        int j=i;
        printf("\t\tPassword: ");
    for(i=0; i <NR1-1;i++)
    {
        char c;
        c = getch();
        parola[i] = c;
        if ( parola[i] == '\b' && i!=0)
        {
            printf("\b \b");
            i-= 2;
            continue;
        }
        else if ( parola[i] == '\b' && i == 0)
        {
            i--;
            printf("\b \b");
            printf(" ");
            continue;
        }
        else if( parola[i] != '\r')
            printf("*");
        else
            break;
    }
    parola[i]='\0';
    if(strcmp(parola,v[j].parola) == 0)
        {
            free(v);
            return 1;
        }
    else
        {
            free(v);
            return -1;
        }

        fclose(f);

}

void auth()
{
	int ok=1;
    while(ok==1)
    {
        cls();
		if (login()==1) ok=0;
		else printf("Wrong username or password!\n");
        
    } menu();
}

void menu ()
{
	
	int i=0;
	time_t t;
	time(&t);
	int choice;

        printf("\n\n");
		printf("\n\t\t\tBook-A-Flight-Inator!\n");
		for(i=0;i<80;i++) {
			printf("-");
		} printf("\n");
		printf("\t\t *Enter your choice from the menu*:");
		printf("\n\n");
		printf(" \n \t\tEnter '1' >>to Book a flight");
		printf(" \n \t\tEnter '2' >>to View All Booked Flights");
		printf(" \n \t\tEnter '3' >>to Search For A Specific Booked Flight");
		printf(" \n \t\tEnter '4' >>to Delete a flight");
		printf(" \n \t\tEnter '5' >>to Edit Record");
		printf("\n\n\n");
		printf("\t\t%s", ctime(&t));

		printf("\t\tYour choice:\t"); scanf("%d",&choice);
	switch(choice){
		case ecreate:
			create(); break;
		case eread:
			read1(); break;
		case esearch:
			search(); break;
		case edelete:
			delete(); break;
		case eupdate:
			update(); break;
		default: puts("Incorrect input\n");
	}
	
	printf("\n\n");

}



void create()
{
    struct Customer s;
    FILE* f = fopen("record.txt", "a+");
    //FILE* g = fopen("record.txt", "r");
    FILE* h = fopen("flights.txt", "r"); 
    //n++; fseek(f,0, SEEK_SET); fprintf(f,"%d",n);
    
    int n;
	char singleline[1023]; fscanf(f,"%d",&n);
    int obs=0;
    while (!feof(f))
    {
        fgets(singleline, 1023, f);
        obs++;
    }fprintf(f,"\n%d  ", obs); 
    //fprintf(f,"\n ");

    fseek(f,0,SEEK_SET);
    
    printf("\nCustomer Details:");
	printf("\n-------------------------------\n");
	printf("\nFirst Name:");
	scanf("\n %20s", s.fname);
	fputs(s.fname,f);fprintf(f," ");
	printf("\nSur-Name:");
	scanf("\n %20s", s.lname);
	fputs(s.lname,f);fprintf(f,"\t\t  ");
	printf("\nPhone Number:");
	scanf("\n %20s", s.phonenumber);
	fputs(s.phonenumber,f);fprintf(f,"\t  ");
    printf("\nEmail:");
	scanf("\n %20s", s.email);
	fputs(s.email,f);fprintf(f,"\t\t  ");
	printf("\nID Number:");
	scanf("\n %20s", s.id);
	fputs(s.id,f);fprintf(f,"\t\t");
	printf("\n\tFlight Details");
	printf("\n-------------------------------\n");
	printf("\nFrom:");
	scanf("\n %20s", s.from);
	fputs(s.from,f);fprintf(f,"\t  ");
	printf("\nTo:");
	scanf("\n %20s", s.to);
	fputs(s.to,f);fprintf(f,"\t");
	char dela[100], la[100];
	int cand; int v[100], r=0;
	while(!feof(h)){
	    fscanf(h,"%99s", dela); 
	    fscanf(h,"%99s",la); //printf("%s//",dela);
	    if(strcmp(s.from,dela)){ 
	        if(strcmp(s.to,la)){
	            
	        }
	    } else {fscanf(h,"%d",&cand); v[++r]=cand;
	            }; 
	    
	}
	
	printf("\n");
	   printf("*Flight Hours*:");
	   int j=1;
	   for(j=1; j<=r; j++){
	       int ora, minut;
	       ora=v[j]/100; minut=v[j]%100;
	       printf(" \n '%d' >> %d:%d",j,ora,minut); if(minut==0) printf("0");
	   }
		printf("\n");
	            
	   printf("Your choice: "); int nrc; scanf("%d", &nrc);
	   printf("\n");
	   if(nrc<=r && nrc>=1) {
	       fprintf(f,"%d",v[nrc]);fprintf(f,"\t  ");
	   }; 
	printf("\n-------------------------------\n");
	printf("\nYour Flight Number is:\t %d", obs); 

    fclose(f);
    fclose(h);

}

void read1()
{
	FILE* g = fopen("record.txt", "r"); int n;
	char singleline[1023]; fscanf(g,"%d",&n);
	printf("Flights: ");
	printf("\n-----------------------------------------------------------------------------------------------------\n");
	printf("Nr |Name\t\t| Phone Number  | Email\t\t\t| Id Number      ||\tFrom\t| To\n");
	while (!feof(g))
	{
	    fgets(singleline, 1023, g);
	    printf("%s ",singleline);
	 }

	fclose(g);
}

void search()
{
    FILE *f= fopen("record.txt", "r"); int line, count=0;

    printf("\n\tFlight number: ");
    scanf("%d", &line);

    char singleline[1023];

    printf("Flight nr #%d: ", line);
	printf("\n-----------------------------------------------------------------------------------------------------\n");
	printf("\tNr\t|Name\t\t| Phone Number  | Email\t\t| Adress\t | Id Number\t| From\t| To\n");
	while (!feof(f))
	{
	    count++;
	    fgets(singleline, 1023, f);
	    if (count==line+1) printf("%s ",singleline);

	 }

    fclose(f);

}

void update()
{
    FILE* h = fopen("flights.txt", "r");
    
    struct Customer s;
    FILE* file, *tempfile;
    char buffer[BUFFER_SIZE];
    int line, count;

    printf("\n\tFlight number: ");
    scanf("%d", &line);
    int ogline=line;
    line++;

    file = fopen("record.txt", "r");
    tempfile = fopen("replace.tmp", "w+");


    count = 0; 
	int c;
	while ((c = getchar()) != '\n' && c != EOF){};
    while ((fgets(buffer, BUFFER_SIZE, file)) != NULL)
    {
        count++; 
        if (count == line){ fprintf(tempfile,"%d ",ogline);
            printf("\nNew Customer Details:");
            printf("\n-------------------------------\n");
            printf("\nFirst Name:");
            scanf("\n %20s", s.fname);
            fputs(s.fname,tempfile);fprintf(tempfile,"  ");
            printf("\nSur-Name:");
            scanf("\n %20s", s.lname);
            fputs(s.lname,tempfile);fprintf(tempfile,"\t");
            printf("\nPhone Number:");
            scanf("\n %20s", s.phonenumber);
            fputs(s.phonenumber,tempfile);fprintf(tempfile,"\t");
            printf("\nEmail:");
            scanf("\n %20s", s.email);
            fputs(s.email,tempfile);fprintf(tempfile,"\t");
            printf("\nID Number:");
            scanf("\n %20s", s.id);
            printf("\n\tFlight Details");
            printf("\n-------------------------------\n");
            fputs(s.id,tempfile);fprintf(tempfile,"\t");
            printf("\nFrom:");
            scanf("\n %20s", s.from);
            fputs(s.from,tempfile);fprintf(tempfile,"\t");
            printf("\nTo:");
            scanf("\n %20s", s.to);
            fputs(s.to,tempfile);fprintf(tempfile,"\n");
            char dela[100], la[100];
            int cand; int v[100], r=0;
            while(!feof(h)){
                fscanf(h,"%99s", dela);
                fscanf(h,"%99s",la);
                if(strcmp(s.from,dela)){
                    if(strcmp(s.to,la)){
                        
                    }
                } else {fscanf(h,"%d",&cand); v[++r]=cand;}
            }
            printf("\n");
            printf("*Flight Hours*:"); int j;
            for(j=1; j<=r; j++){
                int ora, minut;
                ora=v[j]/100; minut=v[j]%100;
                printf(" \n '%d' >> %d:%d",j,ora,minut); if(minut==0) printf("0");
            } printf("\n");
            printf("Your choice: "); int nrc; scanf("%d", &nrc);
            if(nrc<=r && nrc>=1){
                fprintf(tempfile,"%d",v[nrc]);fprintf(tempfile,"\t  ");
            }
        }
        else
            fputs(buffer, tempfile);
    } fprintf(tempfile,"\b\b");

    fclose(file);
    fclose(tempfile);

    remove("record.txt");
    rename("replace.tmp", "record.txt");
    printf("\nSuccessfully updated flight #%d", ogline);
}

void delete()
{
    FILE* file, *tempfile;
    char buffer[BUFFER_SIZE];
    char newline[BUFFER_SIZE]={};
    int line, count;

    printf("\n\tFlight number: ");
    scanf("%d", &line);
    int ogline=line;
    line++;

    file = fopen("record.txt", "r");
    tempfile = fopen("replace.tmp", "w+");

    count = 0; 
    while ((fgets(buffer, BUFFER_SIZE, file)) != NULL)
    {
        count++;
        if (count == line)
            fputs(newline, tempfile);
        else
            fputs(buffer, tempfile);
    }

    fclose(file);
    fclose(tempfile);

    remove("record.txt");
    rename("replace.tmp", "record.txt");
    printf("\nSuccessfully erased flight #%d", ogline);

}
