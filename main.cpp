#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

typedef struct
{
    char name[20];         //名字
    char number[20];       //学号
    float Usualgrades;     //平时成绩
    float Experimentalscore;//实验成绩
    float Finalgrade;      //期末成绩
    float Overallresult;    //总成绩
}SS;

SS* stu;

void sortScore(SS stu[], int N);
SS* readdatafromthefile(int *N);        //读取学生基本数据
void Calculatinggrades(SS stu[], int N);//计算N个学生各自总成绩
void Ranking(SS stu[], int N);          //根据总评成绩排名
void Putout(SS stu[], int N);           //按照一定的格式输出N个学生的完整信息
void searchstudent(SS stu[], int N);    //通过学号找到学生的基本信息
void Meanandstandarddeviation(SS stu[],int N);
void searchfor(SS stu[],int N);

int main()
{
	cout << "       Student achievement management analysis system      " << endl;
	cout << "-----------------------------------------------------------" << endl;
	int N=0;
	SS  *mate=NULL;
	mate=readdatafromthefile(&N);
	Calculatinggrades(mate,N);
	sortScore(mate,N);
	Putout(mate,N);
	Meanandstandarddeviation(mate,N);
	searchfor(mate,N);
	free(mate);
	system("pause");
	return 0;
}

SS* readdatafromthefile(int *N)
{
    int n=0;
	cout << "\nStep 1: Read the student's grade information from the file\n" << endl;
    SS *stu;
	FILE *fp=NULL;
	fp=fopen("score.txt", "r");
	stu=(SS*)malloc(sizeof(SS));
	while((!feof(fp)))//读取每条学生的信息,其中feof的作用是:文件结束：返回非0值，文件未结束，返回0值
	{
		fscanf(fp,"%s%s%f%f%f\n",(stu[n].name),(stu[n].number),&stu[n].Usualgrades,&stu[n].Experimentalscore,&stu[n].Finalgrade);
		printf("name:%s number:%s   Usual grades:%4.2f  Experimental score:%4.2f    Final grade:%4.2f \n", (stu[n].name),(stu[n].number), stu[n].Usualgrades, (stu[n].Experimentalscore),stu[n].Finalgrade);
		n++;
	}
	*N=n;
	printf("The number of the students are %d\n", n);
	fclose(fp);
	return stu;
}

void Calculatinggrades(SS stu[], int N)//计算N个学生各自的总评成绩
{
    int i;
	cout << "\nStep 2: Calculate the total score of each student\n" << endl;
	for(i=0;i<N;i++)
	{
        stu[i].Overallresult=0.2*stu[i].Usualgrades+0.2*stu[i].Experimentalscore+0.6*stu[i].Finalgrade;
		printf("name:%s     number:%s     Overall result:%4.2f\n",(stu[i].name),(stu[i].number),stu[i].Overallresult);
	}
}

int Ranking(const void *a, const void *b)//根据总评成绩排名
{

	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);
	if ((*aa).Overallresult < (*bb).Overallresult)
    {
        return 1;
    }
	else if ((*aa).Overallresult > (*bb).Overallresult)
    {
        return -1;
	}
	else
    {
        return 0;
    }
}

void sortScore(SS stu[], int N)
{

	qsort(&(stu[0]), N, sizeof(stu[0]), Ranking);

}

void Putout(SS stu[], int N)
{
    int i;
    cout << "\nStep 3: Output student ranking information based on the total score!\n" << endl;
    for (i=0;i<N;i++)
	{
		printf("The number of the student:%d    number:%s   name:%s Overall result:%4.2f \n",i+1,&(stu[i].number),&(stu[i].name),stu[i].Overallresult);
	}
}
void Meanandstandarddeviation(SS stu[],int N)
{
    int i;
    int project[N];
    int mean;
    int cum1=0;
    int cum2=0;
    for(i=0;i<N;i++)
    {
        cum1=cum1+stu[i].Overallresult;
    }
    mean=cum1/N;
    for(i=0;i<N;i++)
    {
        project[i]=(stu[i].Overallresult-mean)*(stu[i].Overallresult-mean);
        cum2=cum2+project[i];
    }
    int sorty=0;
    sorty=sqrt(cum2)/N;
    cout << "The average score of these students is:" << mean << endl;
    cout << "The standard deviation of these students’ grades is:" << sorty << endl;
}
void searchfor(SS stu[],int N)
{
    int i;
    char num[20];
    cout << "Please enter the student number of the student's grade you waqent to find." << endl;
    cin >> num;
    for(i=0;i<N;i++)
    {
        if(strcmp(stu[i].number,num)==0)
        {
            printf("name:%s number:%s   Usual grades:%4.2f  Experimental score:%4.2f    Final grade:%4.2f Overall result:%4.2f \n", (stu[i].name),(stu[i].number), stu[i].Usualgrades, (stu[i].Experimentalscore),stu[i].Finalgrade,stu[i].Overallresult);
            return;
        }
    }
    cout << "If there is no output, it means the input is wrong!" << endl;
}
