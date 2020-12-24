//
//  main.c
//  Student achievement management system for middle schools
//
//  Created by HakuBill on 2020/10/22.
//

//Attention!! There are 3 places you need to pay attention to and change if you don not use macOS!!

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // ##If you use Windows, change here into <windows.h>. ## (If you use macOS or Linux, you don't need to.)
#include <time.h>
#include <stdbool.h>
#define MAXN 100000
#define INTMAX 2147481647
#define INTMIN -2147481647
#define SCOREMAX 100

struct student {
    struct score {
        int choiceQuestion;
        int completion;
        int answerQuestion;
        int tot;
        char grade;
    } sc[10][105];   //parameter1: 1 to 6 is for chinese, math, english, physics, chemstry and biology. parameter2: the times of one subject
    int totalScore[105];  //total score
    char name[20];
}stu[MAXN];
int allStudentNumber;    //the number of students
char userName[MAXN];
int userNameLength=1;
int userType;   //1 for yes and 0 for no
int classNumber;
int allTestTime;
int hourType;
int currentHour, currentMin;
FILE *fp;

bool IsLegal(int n, int minn, int maxn) {
    if(n<=maxn&&n>=minn)
        return true;
    else
        return  false;
}

void IsFirstUse() {
    time_t now;
    struct tm *tm_now;
    time(&now);
    tm_now = localtime(&now);
    int hour = tm_now->tm_hour;
    currentHour=hour;
    currentMin=tm_now->tm_min;
    if(hour>=0&&hour<=6)
        hourType=1;
    else if(hour>=7&&hour<=11)
        hourType=2;
    else if(hour>=12&&hour<=13)
        hourType=3;
    else if(hour>=14&&hour<=18)
        hourType=4;
    else if(hour>=19&&hour<=23)
        hourType=5;
    
    printf("Welcome to the Student Achievement management System for Middle Schools.\n");
    sleep(1);   //Change the integer into 1000 if there is no obvious pause in the windows. Same to the blew (in line 71 and line 116).
    printf("This is a program developed by Bai Jiajun in Octember, 2020.\n");
    sleep(1);
    printf("First of all, please enter your name here and end with an Enter: ");
    int i=1;
    while(scanf("%c",&userName[i])) {
        if(userName[i]=='\n')
            break;
        i++;
        userNameLength=i-1;
    }
    
    printf("Are you the administrator? Enter 1 for yes or 0 for no. :");
    scanf("%d", &userType);
    while(!IsLegal(userType, 0, 1)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Are you the administrator? Enter 1 for yes or 0 for no. :");
        scanf("%d", &userType);
        getchar();
    }
    getchar();
    
    printf("And then please enter your class number here and end with an Enter: ");
    scanf("%d",&classNumber);
    while(!IsLegal(classNumber, 1, INTMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("And then please enter your class number here and end with an Enter: ");
        scanf("%d",&classNumber);
        getchar();
    }
    getchar();
    
    printf("Nice!\nAnd then enter the number of students in your class here: ");
    scanf("%d",&allStudentNumber);
    while(!IsLegal(allStudentNumber, 1, INTMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Now enter the number of students in your class here: ");
        scanf("%d",&allStudentNumber);
        getchar();
    }
    getchar();
    
    fp=fopen("isFirstUse.txt","w");
    fprintf(fp, "%s %d %d %d %d", userName, userNameLength, userType, classNumber, allStudentNumber);
    fclose(fp);
    
    printf("Nice! You have finished all the work you need to do before using this system\n");
    sleep(1);
    printf("Enjoy using it from now on!\n\n");
}

void add_new_for_all() {
    printf("How many times is this test?    :");
    int testTime;
    scanf("%d",&testTime);
    getchar();
    if(allTestTime==0&&testTime!=1) {
        printf("Testtime must start from 1!\nTest time has been set into 1!\n");
    }
    while(!IsLegal(testTime, 1, allTestTime+1)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("How many times is this test?    :");
        scanf("%d",&testTime);
        getchar();
    }
    if(testTime==allTestTime+1) {
        allTestTime++;
    }
    
    for(int j=1;j<=allStudentNumber;j++) {
        printf("Student %d:\n",j);
        printf("Now enter the choice question score, the completion score, the answer question score of his/her Chinese in the order.\n");
        printf("Tips: the system will calculate the total score automatically.\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[j].sc[1][testTime].choiceQuestion);
        getchar();
        while(!IsLegal(stu[j].sc[1][testTime].choiceQuestion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
            printf("Choice question score:  ");
            scanf("%d",&stu[j].sc[1][testTime].choiceQuestion);
            getchar();
        }
        
        printf("Completion score:  ");
        scanf("%d",&stu[j].sc[1][testTime].completion);
        getchar();
        while(!IsLegal(stu[j].sc[1][testTime].completion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
            printf("Completion score:  ");
            scanf("%d",&stu[j].sc[1][testTime].completion);
            getchar();
        }
        
        printf("Answer question score:  ");
        scanf("%d",&stu[j].sc[1][testTime].answerQuestion);
        getchar();
        while(!IsLegal(stu[j].sc[1][testTime].answerQuestion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
            printf("Answer question score:  ");
            scanf("%d",&stu[j].sc[1][testTime].answerQuestion);
            getchar();
        }
        
        
        printf("\nNow the Math scores.\n");
        printf("Tips: the system will calculate the total score automatically.\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[j].sc[2][testTime].choiceQuestion);
        getchar();
        while(!IsLegal(stu[j].sc[2][testTime].choiceQuestion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
            printf("Choice question score:  ");
            scanf("%d",&stu[j].sc[2][testTime].choiceQuestion);
            getchar();
        }
        
        printf("Completion score:  ");
        scanf("%d",&stu[j].sc[2][testTime].completion);
        getchar();
        while(!IsLegal(stu[j].sc[2][testTime].completion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
            printf("Completion score:  ");
            scanf("%d",&stu[j].sc[2][testTime].completion);
            getchar();
        }
        
        printf("Answer question score:  ");
        scanf("%d",&stu[j].sc[2][testTime].answerQuestion);
        getchar();
        while(!IsLegal(stu[j].sc[2][testTime].answerQuestion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
            printf("Answer question score:  ");
            scanf("%d",&stu[j].sc[2][testTime].answerQuestion);
            getchar();
        }
        
        
        printf("\nNow the English scores.\n");
        printf("Tips: the system will calculate the total score automatically.\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[j].sc[3][testTime].choiceQuestion);
        getchar();
        while(!IsLegal(stu[j].sc[3][testTime].choiceQuestion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
            printf("Choice question score:  ");
            scanf("%d",&stu[j].sc[3][testTime].choiceQuestion);
            getchar();
        }
        
        printf("Completion score:  ");
        scanf("%d",&stu[j].sc[3][testTime].completion);
        getchar();
        while(!IsLegal(stu[j].sc[3][testTime].completion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
        	printf("Completion score:  ");
        	scanf("%d",&stu[j].sc[3][testTime].completion);
            getchar();
        }
        
        printf("Answer question score:  ");
        scanf("%d",&stu[j].sc[3][testTime].answerQuestion);
        getchar();
        while(!IsLegal(stu[j].sc[3][testTime].answerQuestion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
        	printf("Answer question score:  ");
        	scanf("%d",&stu[j].sc[3][testTime].answerQuestion);
            getchar();
        }
        
        
        printf("\nNow the Physics scores.\n");
        printf("Tips: the system will calculate the total score automatically.\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[j].sc[4][testTime].choiceQuestion);
        getchar();
        while(!IsLegal(stu[j].sc[4][testTime].choiceQuestion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
        	printf("Choice question score:  ");
        	scanf("%d",&stu[j].sc[4][testTime].choiceQuestion);
            getchar();
        }
        
        printf("Completion score:  ");
        scanf("%d",&stu[j].sc[4][testTime].completion);
        getchar();
        while(!IsLegal(stu[j].sc[4][testTime].completion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
        	printf("Completion score:  ");
       		scanf("%d",&stu[j].sc[4][testTime].completion);
            getchar();
        }
        
        printf("Answer question score:  ");
        scanf("%d",&stu[j].sc[4][testTime].answerQuestion);
        getchar();
        while(!IsLegal(stu[j].sc[4][testTime].answerQuestion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
       	 	printf("Answer question score:  ");
        	scanf("%d",&stu[j].sc[4][testTime].answerQuestion);
            getchar();
        }
        
        
        printf("\nNow the Chemistry scores.\n");
        printf("Tips: the system will calculate the total score automatically.\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[j].sc[5][testTime].choiceQuestion);
        getchar();
        while(!IsLegal(stu[j].sc[5][testTime].choiceQuestion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
            printf("Choice question score:  ");
        	scanf("%d",&stu[j].sc[5][testTime].choiceQuestion);
            getchar();
        }
        
        printf("Completion score:  ");
        scanf("%d",&stu[j].sc[5][testTime].completion);
        getchar();
    	while(!IsLegal(stu[j].sc[5][testTime].completion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
            printf("Completion score:  ");
        	scanf("%d",&stu[j].sc[5][testTime].completion);
            getchar();
        }
        
        printf("Answer question score:  ");
        scanf("%d",&stu[j].sc[5][testTime].answerQuestion);
        getchar();
        while(!IsLegal(stu[j].sc[5][testTime].answerQuestion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
            printf("Answer question score:  ");
        	scanf("%d",&stu[j].sc[5][testTime].answerQuestion);
            getchar();
        }
        
        
        printf("\nNow the Biology scores.\n");
        printf("Tips: the system will calculate the total score automatically.\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[j].sc[6][testTime].choiceQuestion);
        getchar();
        while(!IsLegal(stu[j].sc[6][testTime].choiceQuestion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
            printf("Choice question score:  ");
        	scanf("%d",&stu[j].sc[6][testTime].choiceQuestion);
            getchar();
        }
        
        printf("Completion score:  ");
        scanf("%d",&stu[j].sc[6][testTime].completion);
        getchar();
        while(!IsLegal(stu[j].sc[6][testTime].completion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
            printf("Completion score:  ");
        	scanf("%d",&stu[j].sc[6][testTime].completion);
            getchar();
        }
        
        printf("Answer question score:  ");
        scanf("%d",&stu[j].sc[6][testTime].answerQuestion);
        getchar();
        while(!IsLegal(stu[j].sc[6][testTime].answerQuestion, 0, SCOREMAX)) {
            printf("INPUT ILLEGAL! Try again!\n");
            printf("Answer question score:  ");
        	scanf("%d",&stu[j].sc[6][testTime].answerQuestion);
            getchar();
        }
        
        for(int i=1;i<=6;i++) {
            stu[j].sc[i][testTime].tot=stu[j].sc[i][testTime].choiceQuestion+stu[j].sc[i][testTime].answerQuestion+stu[j].sc[i][testTime].completion;
        
            if(stu[j].sc[i][testTime].tot>=85)
                stu[j].sc[i][testTime].grade='A';
            else if(stu[j].sc[i][testTime].tot>=70&&stu[j].sc[i][testTime].tot<85)
                stu[j].sc[i][testTime].grade='B';
            else if(stu[j].sc[i][testTime].tot>=60&&stu[j].sc[i][testTime].tot<70)
                stu[j].sc[i][testTime].grade='C';
            else if(stu[j].sc[i][testTime].tot<60)
                stu[j].sc[i][testTime].grade='F';
        }
        
        for(int i=1;i<=6;i++)
            stu[j].totalScore[testTime]+=stu[j].sc[i][testTime].tot;
        
        printf("\n");
    }
    printf("Work done!\n\n");
}

void add_new_for_one() {
    printf("How many times is this test?    :");
    int testTime;
    scanf("%d",&testTime);
    getchar();
    if(allTestTime==0&&testTime!=1) {
        printf("Testtime must start from 1!\nTest time has been set into 1!\n");
    }
    while(!IsLegal(testTime, 1, allTestTime+1)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("How many times is this test?    :");
        scanf("%d",&testTime);
        getchar();
    }
    if(testTime==allTestTime+1) {
        allTestTime++;
    }
 
    int studentNumber;
    printf("Enter the student number of the student :");
    scanf("%d",&studentNumber);
    getchar();
    while(!IsLegal(studentNumber, 1, allStudentNumber)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Enter the student number of the student :");
        scanf("%d",&studentNumber);
        getchar();
    }
    
    printf("Now enter the choice question score, the completion score, the answer question score of his/her Chinese in the order.\n");
    printf("Tips: the system will calculate the total score automatically.\n");
    printf("Choice question score:  ");
    scanf("%d",&stu[studentNumber].sc[1][testTime].choiceQuestion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[1][testTime].choiceQuestion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[studentNumber].sc[1][testTime].choiceQuestion);
        getchar();
    }
    
    printf("Completion score:  ");
    scanf("%d",&stu[studentNumber].sc[1][testTime].completion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[1][testTime].completion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Completion score:  ");
        scanf("%d",&stu[studentNumber].sc[1][testTime].completion);
        getchar();
    }
    
    printf("Answer question score:  ");
    scanf("%d",&stu[studentNumber].sc[1][testTime].answerQuestion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[1][testTime].answerQuestion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Answer question score:  ");
        scanf("%d",&stu[studentNumber].sc[1][testTime].answerQuestion);
        getchar();
    }
    
    
    printf("\nNow the Math scores.\n");
    printf("Tips: the system will calculate the total score automatically.\n");
    printf("Choice question score:  ");
    scanf("%d",&stu[studentNumber].sc[2][testTime].choiceQuestion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[2][testTime].choiceQuestion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[studentNumber].sc[2][testTime].choiceQuestion);
        getchar();
    }
    
    printf("Completion score:  ");
    scanf("%d",&stu[studentNumber].sc[2][testTime].completion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[2][testTime].choiceQuestion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[studentNumber].sc[2][testTime].choiceQuestion);
        getchar();
    }
    
    printf("Answer question score:  ");
    scanf("%d",&stu[studentNumber].sc[2][testTime].answerQuestion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[2][testTime].answerQuestion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Answer question score:  ");
        scanf("%d",&stu[studentNumber].sc[2][testTime].answerQuestion);
        getchar();
    }
    
    
    printf("\nNow the English scores.\n");
    printf("Tips: the system will calculate the total score automatically.\n");
    printf("Choice question score:  ");
    scanf("%d",&stu[studentNumber].sc[3][testTime].choiceQuestion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[3][testTime].choiceQuestion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[studentNumber].sc[3][testTime].choiceQuestion);
        getchar();
    }
    
    printf("Completion score:  ");
    scanf("%d",&stu[studentNumber].sc[3][testTime].completion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[3][testTime].completion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Completion score:  ");
        scanf("%d",&stu[studentNumber].sc[3][testTime].completion);
        getchar();
    }
    
    printf("Answer question score:  ");
    scanf("%d",&stu[studentNumber].sc[3][testTime].answerQuestion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[3][testTime].answerQuestion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Answer question score:  ");
        scanf("%d",&stu[studentNumber].sc[3][testTime].answerQuestion);
        getchar();
    }
    
    
    printf("\nNow the Physics scores.\n");
    printf("Tips: the system will calculate the total score automatically.\n");
    printf("Choice question score:  ");
    scanf("%d",&stu[studentNumber].sc[4][testTime].choiceQuestion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[4][testTime].choiceQuestion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[studentNumber].sc[4][testTime].choiceQuestion);
        getchar();
    }
    
    printf("Completion score:  ");
    scanf("%d",&stu[studentNumber].sc[4][testTime].completion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[4][testTime].completion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Completion score:  ");
        scanf("%d",&stu[studentNumber].sc[4][testTime].completion);
        getchar();
    }
    
    printf("Answer question score:  ");
    scanf("%d",&stu[studentNumber].sc[4][testTime].answerQuestion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[4][testTime].answerQuestion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Answer question score:  ");
        scanf("%d",&stu[studentNumber].sc[4][testTime].answerQuestion);
        getchar();
    }
    
    
    printf("\nNow the Chemistry scores.\n");
    printf("Tips: the system will calculate the total score automatically.\n");
    printf("Choice question score:  ");
    scanf("%d",&stu[studentNumber].sc[5][testTime].choiceQuestion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[5][testTime].choiceQuestion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[studentNumber].sc[5][testTime].choiceQuestion);
        getchar();
    }
    
    printf("Completion score:  ");
    scanf("%d",&stu[studentNumber].sc[5][testTime].completion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[5][testTime].completion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Completion score:  ");
        scanf("%d",&stu[studentNumber].sc[5][testTime].completion);
        getchar();
    }
    
    printf("Answer question score:  ");
    scanf("%d",&stu[studentNumber].sc[5][testTime].answerQuestion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[5][testTime].answerQuestion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Answer question score:  ");
        scanf("%d",&stu[studentNumber].sc[5][testTime].answerQuestion);
        getchar();
    }
    
    
    printf("\nNow the Biology scores.\n");
    printf("Tips: the system will calculate the total score automatically.\n");
    printf("Choice question score:  ");
    scanf("%d",&stu[studentNumber].sc[6][testTime].choiceQuestion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[6][testTime].choiceQuestion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[studentNumber].sc[6][testTime].choiceQuestion);
        getchar();
    }
    
    printf("Completion score:  ");
    scanf("%d",&stu[studentNumber].sc[6][testTime].completion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[6][testTime].completion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Completion score:  ");
        scanf("%d",&stu[studentNumber].sc[6][testTime].completion);
        getchar();
    }
    
    printf("Answer question score:  ");
    scanf("%d",&stu[studentNumber].sc[6][testTime].answerQuestion);
    getchar();
    while(!IsLegal(stu[studentNumber].sc[6][testTime].answerQuestion, 1, SCOREMAX)) {
        printf("INPUT ILLEGAL! Try again!\n");
        printf("Answer question score:  ");
        scanf("%d",&stu[studentNumber].sc[6][testTime].answerQuestion);
        getchar();
    }
    
    for(int i=1;i<=6;i++) {
        stu[studentNumber].sc[i][testTime].tot=stu[studentNumber].sc[i][testTime].choiceQuestion+stu[studentNumber].sc[i][testTime].answerQuestion+stu[studentNumber].sc[i][testTime].completion;
        if(stu[studentNumber].sc[i][testTime].tot>=85)
            stu[studentNumber].sc[i][testTime].grade='A';
        else if(stu[studentNumber].sc[i][testTime].tot>=70&&stu[studentNumber].sc[i][testTime].tot<85)
            stu[studentNumber].sc[i][testTime].grade='B';
        else if(stu[studentNumber].sc[i][testTime].tot>=60&&stu[studentNumber].sc[i][testTime].tot<70)
            stu[studentNumber].sc[i][testTime].grade='C';
        else if(stu[studentNumber].sc[i][testTime].tot<60)
            stu[studentNumber].sc[i][testTime].grade='F';

    }
    printf("Work done!\n\n");
}

void look_up_all() {
    printf("Enter the time of the class you want to look up :   ");
    int testTime;
    scanf("%d",&testTime);
    getchar();
    
    printf("\nClass %d Test %d :\n",classNumber,testTime);
    printf("Num  Total  Chinese  Math  English  Physics  Chemistry  Biology\n");
    for(int i=1;i<=allStudentNumber;i++) {
        printf("%3d  %5d  %7d  %4d  %7d  %7d  %9d  %7d\n", i,stu[i].totalScore[testTime],stu[i].sc[1][testTime].tot,stu[i].sc[2][testTime].tot,stu[i].sc[3][testTime].tot,stu[i].sc[4][testTime].tot,stu[i].sc[5][testTime].tot,stu[i].sc[6][testTime].tot);
    }
    
    printf("\n");
    printf("For specific scores, please look up the record of one specifc student.\n");
    printf("\n");
}

void look_up_one() {
    printf("Enter the student number of the student you want to look up :");
    int studentNumber;
    scanf("%d",&studentNumber);
    getchar();
    printf("Enter the time of the test you want to look up  :");
    int testTime;
    scanf("%d",&testTime);
    getchar();
    
    printf("\nThe score of student %d is:\n",studentNumber);
    printf("Subject    Total  Choice Question  Completion  Answer Question  Grade\n");
    printf("  Chinese  %5d  %15d  %10d  %15d  %5c\n", stu[studentNumber].sc[1][testTime].tot,stu[studentNumber].sc[1][testTime].choiceQuestion,stu[studentNumber].sc[1][testTime].completion,stu[studentNumber].sc[1][testTime].answerQuestion,stu[studentNumber].sc[1][testTime].grade);
    printf("     Math  %5d  %15d  %10d  %15d  %5c\n", stu[studentNumber].sc[2][testTime].tot,stu[studentNumber].sc[2][testTime].choiceQuestion,stu[studentNumber].sc[2][testTime].completion,stu[studentNumber].sc[2][testTime].answerQuestion,stu[studentNumber].sc[2][testTime].grade);
    printf("  English  %5d  %15d  %10d  %15d  %5c\n", stu[studentNumber].sc[3][testTime].tot,stu[studentNumber].sc[3][testTime].choiceQuestion,stu[studentNumber].sc[3][testTime].completion,stu[studentNumber].sc[3][testTime].answerQuestion,stu[studentNumber].sc[3][testTime].grade);
    printf("  Physics  %5d  %15d  %10d  %15d  %5c\n", stu[studentNumber].sc[4][testTime].tot,stu[studentNumber].sc[4][testTime].choiceQuestion,stu[studentNumber].sc[4][testTime].completion,stu[studentNumber].sc[4][testTime].answerQuestion,stu[studentNumber].sc[4][testTime].grade);
    printf("Chemistry  %5d  %15d  %10d  %15d  %5c\n", stu[studentNumber].sc[5][testTime].tot,stu[studentNumber].sc[5][testTime].choiceQuestion,stu[studentNumber].sc[5][testTime].completion,stu[studentNumber].sc[5][testTime].answerQuestion,stu[studentNumber].sc[5][testTime].grade);
    printf("  Biology  %5d  %15d  %10d  %15d  %5c\n", stu[studentNumber].sc[6][testTime].tot,stu[studentNumber].sc[6][testTime].choiceQuestion,stu[studentNumber].sc[6][testTime].completion,stu[studentNumber].sc[6][testTime].answerQuestion,stu[studentNumber].sc[6][testTime].grade);
    
    printf("\n");
}

void print_out() {
    FILE *fileOutput;
    printf("Enter the output file name and path:\n");
    printf("Example: 'C:\\user\\output.txt'(Windows) or '/users/username/output.txt'(macOS)\n");
    printf("Please make sure your input is valid before press enter!\nEnter here:   ");
    char outputFilePath[100];
    scanf("%s", outputFilePath);
    getchar();
    fileOutput=fopen(outputFilePath, "w");
    
    for(int i=1;i<=allTestTime;i++) {
        fprintf(fileOutput,"Class %d Test %d :\n",classNumber,allTestTime);
        fprintf(fileOutput,"Num  Total  Chinese  Math  English  Physics  Chemistry  Biology\n");
        for(int j=1;j<=allStudentNumber;j++) {
            fprintf(fileOutput, "%3d  %5d  %7d  %4d  %7d  %7d  %9d  %7d\n", j,stu[j].totalScore[i],stu[j].sc[1][i].tot,stu[j].sc[2][i].tot,stu[j].sc[3][i].tot,stu[j].sc[4][i].tot,stu[j].sc[5][i].tot,stu[j].sc[6][i].tot);
        }
        
        fprintf(fileOutput, "\n");

    }
    fclose(fileOutput);
    
    printf("Work done!\n\n");

}

void FileSaveLoad(int type) {   //1 for save and 0 for load
    FILE *fileOutput;
    FILE *fileLoad;
    switch (type) {
        case 1:
            fileOutput=fopen("~/SAMSsave.txt", "w");    //change the path into "C:\\Program Files\\SAMS\\SAMSsave.txt", same to the below in line 674
            
            fprintf(fileOutput, "%d %d ", allTestTime, classNumber);
            for(int i=1;i<=allTestTime;i++) {
                for(int j=1;j<=allStudentNumber;j++) {
                    fprintf(fileOutput, "%d %d %d %d %d %d %d ", stu[j].totalScore[i],stu[j].sc[1][i].tot,stu[j].sc[2][i].tot,stu[j].sc[3][i].tot,stu[j].sc[4][i].tot,stu[j].sc[5][i].tot,stu[j].sc[6][i].tot);
                }
            }
            fclose(fileOutput);
            break;
        case 2:
            fileLoad=fopen("~/SAMSsave.txt","r");
            fscanf(fileLoad, "%d%d", &allTestTime, &classNumber);
            for(int i=1;i<=allTestTime;i++) {
                for(int j=1;j<=allStudentNumber;j++) {
                    fscanf(fileLoad, "%d%d%d%d%d%d%d",&stu[j].totalScore[i],&stu[j].sc[1][i].tot,&stu[j].sc[2][i].tot,&stu[j].sc[3][i].tot,&stu[j].sc[4][i].tot,&stu[j].sc[5][i].tot,&stu[j].sc[6][i].tot);
                }
            }
            fclose(fileLoad);
            break;
    }
}

int main(int argc, const char * argv[]) {
    int isFirstUse = 0;
    if ((fp = fopen("isFirstUse.txt","w"))==NULL) {
        if ((fp=fopen("isFirstUse.txt", "r"))==NULL) {
            IsFirstUse();
            isFirstUse=1;
        }
    }
    
    if(!isFirstUse) {
        fscanf(fp,"%s %d %d %d %d", userName, &userNameLength, &userType, &classNumber, &allStudentNumber);
        FileSaveLoad(0);
    }
    fclose(fp);
    
    int task;
    char IsExit;
    switch (hourType) {
        case 1:
            printf("Go to sleep please! It's AM %d : %d now.\n", currentHour, currentMin);
            break;
        case 2:
            printf("Good morning, %s! It's AM %d : %d now.\n", userName,currentHour, currentMin);
            break;
        case 3:
            printf("Have a good lunch, %s! It's PM %d : %d now.\n",userName, currentHour, currentMin);
            break;
        case 4:
            printf("Gooding afternoon, %s! It's PM %d : %d now.\n", userName, currentHour, currentMin);
            break;
        case 5:
            printf("Good evening, %s! It's PM %d : %d now.\n", userName, currentHour, currentMin);
            break;
    }
    while(1) {
        printf("What do you want to do?\nEnter the code before the description!\n");
        printf("1   Add a new record for all students. (Administrator only!)\n");
        printf("2   Add a new record for a specific student. (Administrator only!)\n");
        printf("3   Look up the record of all students.\n");
        printf("4   Look up the record of one specific student.\n");
        printf("5   Export a txt form of the records.\n");
        printf("6   Exit the system.\n");
        scanf("%d",&task);
        getchar();
        switch (task) {
            case 1:
                if(userType) {
                    add_new_for_all();
                }
                else {
                    printf("YOU HAVE NO RIGHTS!\n\n");
                    continue;
                }
                break;
            case 2:
                if(userType) {
                    add_new_for_one();
                }
                else {
                    printf("YOU HAVE NO RIGHTS!\n\n");
                    continue;
                }
                break;
            case 3:
                look_up_all();
                break;
            case 4:
                look_up_one();
                break;
            case 5:
                print_out();
                break;
            case 6:
            ask:printf("Are you sure to exit? (Y/N)\n");
                scanf("%c",&IsExit);
                getchar();
                if(IsExit=='Y'||IsExit=='y') {
                    FileSaveLoad(1);
                    return 0;
                }
                else if(IsExit=='N'||IsExit=='n')
                    continue;
                else {
                    printf("Your input is invalid, please enter again\n");
                    goto ask;
                }
                break;
            default:
                printf("Your input is invalid, please enter again!\n");
                break;
        }
    }
    return 0;
}
