
#include<stdio.h>
struct Patient{
int ID;
char names[25];
char address[15];
char gender[8];
int age;
char results[15];
};
void RecordPatient(void);
void DisplayPatient(void);
void Display_AllPatient(void);
void Display_PositivePatient(void);
void Display_NegativePatient(void);
void ResearchPatient(void);

void main()
{
    int c;
    printf("name of the project\n==== == === =======");
    do
    {

        printf("\nChoose Action you want to perform\n_________________________________\n");
        printf("Press\n1.Record\n2.Display\n3.Research\n0.Exit\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            RecordPatient();
            break;
        case 2:
            DisplayPatient();
            break;
        case 3:
            SearchPatient();
            break;
        case 0:
            printf("Good Job");
            break;
        default:
            printf("Invalid Choice. Choose again.");
        }
        }while(c!=0);
}
void RecordPatient(){
    struct Patient P;
    FILE *r;
    r=fopen("Patient.txt","a");
    printf("\n\tRecording information about the patient\n");
    printf("\t_______________________________________\n");
    printf("\nEnter ID of a Patient\n");
    scanf("%d",&P.ID);
    printf("\nEnter Names of a Patient\n");
    scanf("%s",&P.names);
    printf("\nEnter Address of a Patient\n");
    scanf("%s",P.address);
    printf("\nEnter Age of a Patient\n");
    scanf("%d",&P.age);
    printf("\nEnter Gender of a Patient\n");
    scanf("%s",P.gender);
    printf("\nEnter Result of a Patient\n");
    scanf("%s",P.results);
    fprintf(r,"%d\t%s\t%s\t%d\t%s\t%s\t\n",P.ID,P.names,P.address,P.age,P.gender,P.results);
    fclose(r);

}
void DisplayPatient(){

    int d;
    do
    {
        printf("\n\n\tDISPLAY SECTION \n\t_______________\n");
        printf("Press\n1.Display All Patient\n2.Display Positive Patient\n3.Display Negative Patient\n0.Exit Display\n");
        scanf("%d",&d);
        switch(d)
        {
        case 1:
            Display_AllPatient();
            break;
        case 2:
            Display_PositivePatient();
            break;
        case 3:
            Display_NegativePatient();
            break;
        case 0:
            printf("Good Job");
            break;
        default:
            printf("Invalid Choice. Choose again.");
        }
    }while(d!=0);
}
void Display_AllPatient(){
    struct Patient P;
    FILE *p;
    p=fopen("Patient.txt","r");
    printf("\n\t\tList of all Patient Tested\n\t\t==== == === ======= ======\n");
    printf("%-10s%-10s%-15s%-10s%-10s%-10s\n","ID","Names","Address","Age","Gender","Results");
    printf("%-10s%-10s%-15s%-10s%-10s%-10s\n","==","=====","=======","===","======","=======");
    //printf("==\t\t=====\t\t=======\t\t===\t\t======\t\t=======\n");
    while(!feof(p)){
        fscanf(p,"%d\t%s\t%s\t%d\t%s\t%s\t\n",&P.ID,P.names,P.address,&P.age,P.gender,P.results);
        printf("%-10d%-10s%-15s%-10d%-10s%-10s\n",P.ID,P.names,P.address,P.age,P.gender,P.results);
    }
    fclose(p);


}
void Display_PositivePatient(){
    struct Patient P;
    FILE *p;
    p=fopen("Patient.txt","r");
    printf("\n\tList of Positive Patient Tested\n\t==== == ======== ======= ======\n");
    printf("%-10s%-10s%-15s%-10s%-10s%-10s\n","ID","Names","Address","Age","Gender","Results");
    printf("%-10s%-10s%-15s%-10s%-10s%-10s\n","==","=====","=======","===","======","=======");
    while(!feof(p)){
        fscanf(p,"%d\t%s\t%s\t%d\t%s\t%s\t\n",&P.ID,P.names,P.address,&P.age,P.gender,P.results);
        if(strcmp(P.results, "positive")==0){
            printf("%-10d%-10s%-15s%-10d%-10s%-10s\n",P.ID,P.names,P.address,P.age,P.gender,P.results);
        }
    }
    fclose(p);

}
void Display_NegativePatient(){
    struct Patient P;
    FILE *n;
    n=fopen("Patient.txt","r");
    printf("\n\tList of Negative Patients Tested\n\t________________________________\n");
    printf("%-10s%-10s%-15s%-10s%-10s%-10s\n","ID","Names","Address","Age","Gender","Results");
    printf("%-10s%-10s%-15s%-10s%-10s%-10s\n","==","=====","=======","===","======","=======");
    while(!feof(n)){
        fscanf(n,"%d\t%s\t%s\t%d\t%s\t%s\t\n",&P.ID,P.names,P.address,&P.age,P.gender,P.results);
        if(strcmp(P.results, "negative")==0){
            printf("%-10d%-10s%-15s%-10d%-10s%-10s\n",P.ID,P.names,P.address,P.age,P.gender,P.results);
        }
    }
    fclose(n);

}
void SearchPatient(){
    struct Patient P;
    int a;
    printf("\nSEARCH SECTION\n");
    printf("****** *******\n");
    printf("Enter an ID\n");
    scanf("%d",&a);
    FILE *s;
    s=fopen("Patient.txt","r");

    while(!feof(s)){
        fscanf(s,"%d\t%s\t%s\t%d\t%s\t%s\t\n",&P.ID,P.names,P.address,&P.age,P.gender,P.results);
        if(P.ID==a){
            printf("%-10s%-10s%-15s%-10s%-10s%-10s\n","ID","Names","Address","Age","Gender","Results");
            printf("%-10s%-10s%-15s%-10s%-10s%-10s\n","==","=====","=======","===","======","=======");
            printf("%-10d%-10s%-15s%-10d%-10s%-10s\n",P.ID,P.names,P.address,P.age,P.gender,P.results);
        }
    }
    fclose(s);

}
