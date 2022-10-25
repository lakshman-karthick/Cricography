#include<iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;

void nullCreate();
int hashIndexFind(int a,int NoP);
void databaseContent(char fileName[]);
void bestBatsman(char fileName[],struct player heap[]);
void bestBowler(char fileName[],struct player heap[]);
void bestPerformers(char fileName[]);
void personalInfo(struct player p[],int playerNo);
void teamInfo(struct player p[],int playerNo);
void matchesNo(struct player p[],int playerNo);
void role(struct player p[],int playerNo);
void batStat(struct player p[],int playerNo);
void bowlStat(struct player p[],int playerNo);
int parent(int i);
void swap(struct player *x,struct player *y);
void createDatabase(char fileName[]);
void printPlayers(char fileName[]);
void printDatabase(char fileName[]);
void modifyDatabase(char fileName[]);
void searchPlayers(char fileName[]);
void modifyContent(struct player hashTable[],int i);
void insertOrangeCap(struct player heap[], int& n, struct player Key);
void orangeCap(struct player heap[]);
void insertBestBatAverage(struct player heap[], int& n, struct player Key);
void bestBatAverage(struct player heap[]);
void insertBestBatStrike(struct player heap[], int& n, struct player Key);
void bestBatStrike(struct player heap[]);
void insertPurpleCap(struct player heap[], int& n, struct player Key);
void purpleCap(struct player heap[]);
void insertBestBowlAverage(struct player heap[], int& n, struct player Key);
void bestBowlAverage(struct player heap[]);
void insertBestBowlStrike(struct player heap[], int& n, struct player Key);
void bestBowlStrike(struct player heap[]);
void insertBestBowlEconomy(struct player heap[], int& n, struct player Key);
void bestBowlEconomy(struct player heap[]);
void writeTo_File(char fileName[]);
void readFrom_File(char fileName[]);


struct player
{
   int jerseyNo;
   char pName[50];
   char tName[50];
   int age;
   int NoM;
   char role[50];
   char batStyle[50];
   char bowlStyle[50];
   int runs;
   int timesOut;
   int ballsFaced;
   int wickets;
   int runsConceded;
   int oversBowled;
   int ballsBowled;
   float batAverage;
   float batStrikeRate;
   float bowlAverage;
   float bowlStrikeRate;
   float bowlEconomy;
};
struct player hashTable[50];
struct player temp;
void nullCreate()
{
   temp.jerseyNo = 0;
   temp.NoM = 0;
   temp.runs =0;
   temp.ballsFaced = 0;
   temp.timesOut = 0;
   temp.wickets = 0;
   temp.runsConceded =0;
   temp.oversBowled = 0;
   temp.ballsBowled =0;
   temp.batAverage =0;
   temp.batStrikeRate =0;
   temp.bowlAverage=0;
   temp.bowlEconomy=0;
   temp.bowlStrikeRate=0;
}

int hashIndexFind(int a,int NoP)
{
 	return a % 12;
}


void databaseContent(char fileName[])
{
	int ch;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tCRICOGRAPHY"<<endl;
	
	while(1)
	{
		cout<<endl<<endl;
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tCONTENTS"<<endl<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t1)Create Database"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t2)Print Database"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t3)Modify Database"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t4)Search Players"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t5)Quit"<<endl<<endl;
		cout<<"\n\t\t\t\t\t\tChoose option...."<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				getchar();
				createDatabase(fileName);
				getchar();
				break;
			case 2:
				getchar();
				printDatabase(fileName);
				getchar();
				break;
			case 3:
				modifyDatabase(fileName);
				getchar();
				break;
			case 4:
				getchar();
				searchPlayers(fileName);
				getchar();
				break;
			case 5:
				return;
			default:
				cout<<"\n\nGive Valid Input !!!";
		}
    }
}

void bestBatsman(char fileName[],struct player heap[])
{
	int ch;
	cout<<endl<<endl;
	while(1)
	{
		getchar();
		system("cls");
		getchar();
	    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tBATTING FIELDS"<<endl<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t1)Orange Cap"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t2)Best Average"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t3)Best Strike Rate"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t4)Back"<<endl<<endl;
		cout<<"\n\t\t\t\t\t\tChoose option....";
		cin>>ch;
		switch(ch)
		{
			case 1:
				getchar();
				orangeCap(heap);
				getchar();
				break;
			case 2:
				getchar();
				bestBatAverage(heap);
				getchar();
				break;
			case 3:
				getchar();
				bestBatStrike(heap);
				getchar();
				break;
			case 4:
				return;
			default:
				cout<<"\n\nGive Valid Input !!!";
		}
	}   	
}
		


void bestBowler(char fileName[],struct player heap[])
{
	int ch;
	cout<<endl<<endl;
	while(1)
	{
		getchar();
		system("cls");
		getchar();
	    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tBOWLING FIELDS"<<endl<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t1)Purple Cap"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t2)Best Average"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t3)Best Strike Rate"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t4)Best Economy"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t5)Back"<<endl<<endl;
		cout<<"\n\t\t\t\t\t\tChoose option....";
		cin>>ch;
		switch(ch)
		{
			case 1:
				getchar();
				purpleCap(heap);
				getchar();
				break;
			case 2:
				getchar();
				bestBowlAverage(heap);
				getchar();
				break;
			case 3:
				getchar();
				bestBowlStrike(heap);
				getchar();
				break;
			case 4:
				getchar();
				bestBowlEconomy(heap);
				getchar();
				break;
			case 5:
				return;
			default:
				cout<<"\n\nGive Valid Input !!!";
		}
    }	
}
		


void bestPerformers(char fileName[])
{
	int ch;
	readFrom_File(fileName);
	struct player heap[50];
	nullCreate();
	while(1)
	{
		getchar();
		system("cls");
		getchar();
		cout<<endl<<endl;
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tFIELDS"<<endl<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t1)Best Batsman"<<endl;
		cout<<"\n\t\t\t\t\t\t\t2)Best Bowler"<<endl;
		cout<<"\n\t\t\t\t\t\t\t3)Back"<<endl;
		cout<<"\n\t\t\t\t\t\tChoose option....";
		cin>>ch;
		switch(ch)
		{
			case 1:
				bestBatsman(fileName,heap);
				break;
			case 2:
				bestBowler(fileName,heap);
				break;
			case 3:
				return;
			default:
				cout<<"\n\nGive Valid Input !!!";
		}
    }
}

void personalInfo(struct player p[],int playerNo)
{
	cout<<endl;
	fflush(stdin);
	cout<<"\n\nEnter Player Name          :";
	gets(p[playerNo].pName);
	cout<<endl;
	fflush(stdin);
	cout<<"\nEnter Age of Player        :";
	cin>>p[playerNo].age;
	cout<<endl;	
}

void teamInfo(struct player p[],int playerNo)
{
	fflush(stdin);
	cout<<"\n\nEnter Team Name            :";
	gets(p[playerNo].tName);
	cout<<endl;
}

void matchesNo(struct player p[],int playerNo)
{
	fflush(stdin);
	cout<<"\n\nEnter No. of matches played  :";
	cin>>p[playerNo].NoM;
	fflush(stdin);
	cout<<endl;
}

void role(struct player p[],int playerNo)
{
	fflush(stdin);
	cout<<"\n\nEnter Role of Player       :";
	gets(p[playerNo].role);
	cout<<endl;
}

void batStat(struct player p[],int playerNo)
{
	fflush(stdin);
    cout<<"\n\nEnter Batting Style          :";
	gets(p[playerNo].batStyle);
	cout<<endl;
	fflush(stdin);
	cout<<"Enter Total Runs Scored      :";
	cin>>p[playerNo].runs;
	cout<<endl;
	fflush(stdin);
	cout<<"\nEnter No. of Times Out     :";
	cin>>p[playerNo].timesOut;
	cout<<endl;
	fflush(stdin);
	cout<<"Enter No. of Balls Faced     :";
	cin>>p[playerNo].ballsFaced;
	cout<<endl;
	fflush(stdin);
	p[playerNo].batAverage =(float) p[playerNo].runs/(float)p[playerNo].timesOut;
	cout<<"\nBatting Average:"<<p[playerNo].batAverage;
	cout<<endl;
	fflush(stdin);
	p[playerNo].batStrikeRate = (((float)p[playerNo].runs/(float)p[playerNo].ballsFaced)*100);
	cout<<"\nBatting Strike Rate:"<<p[playerNo].batStrikeRate;
	cout<<endl;	
	fflush(stdin);
}

void bowlStat(struct player p[],int playerNo)
{
	fflush(stdin);
	cout<<"\n\nEnter Bowling Style        :";
	gets(p[playerNo].bowlStyle);
	cout<<endl;
	fflush(stdin);
	cout<<"\nEnter No. of Wickets Taken :";
	cin>>p[playerNo].wickets;
	cout<<endl;
	fflush(stdin);
	cout<<"Enter No. of Runs Conceded   :";
	cin>>p[playerNo].runsConceded;
	cout<<endl;
	fflush(stdin);
	cout<<"\nEnter No. of Balls Bowled    :";
	cin>>p[playerNo].ballsBowled;
	cout<<endl;
	fflush(stdin);
	p[playerNo].oversBowled = p[playerNo].ballsBowled / 6;
	cout<<"\nNo. of Overs Bowled  :"<<p[playerNo].oversBowled;
	cout<<endl;
	fflush(stdin);   
	p[playerNo].bowlAverage = (float)p[playerNo].runsConceded/(float)p[playerNo].wickets;
	cout<<"\nBowling Average:"<<p[playerNo].bowlAverage;
	cout<<endl;
	fflush(stdin);
	p[playerNo].bowlStrikeRate = (float)p[playerNo].ballsBowled/(float)p[playerNo].wickets;
	cout<<"\nBowling Strike Rate:"<<p[playerNo].bowlStrikeRate;
	cout<<endl;
	fflush(stdin);
	p[playerNo].bowlEconomy = (float)p[playerNo].runsConceded/(float)p[playerNo].oversBowled;
	cout<<"\nBowling Economy Rate:"<<p[playerNo].bowlEconomy;
	cout<<endl;
}

void modifyContent(struct player hashTable[],int i)
{
    int choose;
		while(1)
		{
			cout<<"\n\n\t\t\t\t\t\t\tChoose Specific Info To Modify:"<<endl<<endl;
			cout<<"\n1) Personal Info"<<endl;
			cout<<"2) Team Info"<<endl;
			cout<<"3) Matches Played"<<endl;
			cout<<"4) Role of player"<<endl;
			cout<<"5) Batting Stats"<<endl;
			cout<<"6) Bowling Stats"<<endl;
			cout<<"7) Back"<<endl<<endl;
			cout<<"=>";
			cin>>choose;
			switch(choose)
			{
				case 1:
					personalInfo(hashTable,i);
					break;
				case 2:
					teamInfo(hashTable,i);
					break;
				case 3:
					matchesNo(hashTable,i);
					break;
				case 4:
					role(hashTable,i);
					break;
				case 5:
					batStat(hashTable,i);
					break;
				case 6:
					bowlStat(hashTable,i);
					break;
				case 7:
					return;
				default:
					cout<<"Give valid choice";
			}
	   }	
}

void readFrom_File(char fileName[])
{
	char file[20];
	strcpy(file,fileName);
	strcat(file,".dat");
	ifstream f(file,ios::in);
	f.read((char *)hashTable,sizeof(hashTable));
	f.close();
}


void writeTo_File(char fileName[])
{
	char file[20];
	strcpy(file,fileName);
	strcat(file,".dat");
	ofstream f(file,ios::out);
	f.write((char *)hashTable,sizeof(hashTable));
	f.close();
}


void printPlayers(int i)
{
	
	cout<<"------------------------------------------------------------------"<<endl;
    cout<<"\t\tPLAYERS DETAILS"<<endl;
	cout<<"------------------------------------------------------------------"<<endl;
	cout<<"Jersey No.   :"<<hashTable[i].jerseyNo<<endl;
	cout<<"Player Name  :"<<hashTable[i].pName<<endl;
	cout<<"Age          :"<<hashTable[i].age<<endl;
	cout<<"Team Name    :"<<hashTable[i].tName<<endl;
	cout<<"Role         :"<<hashTable[i].role<<endl;
	cout<<"No.Of Matches:"<<hashTable[i].NoM<<endl;
	cout<<"---------------------Batting-------------------------------------"<<endl;
	cout<<"Batting Style:"<<hashTable[i].batStyle<<endl;
	cout<<"Total Runs   :"<<hashTable[i].runs<<endl;
	cout<<"Times Outs   :"<<hashTable[i].timesOut<<endl;
	cout<<"Balls Faced  :"<<hashTable[i].ballsFaced<<endl;
	cout<<"Average      :"<<hashTable[i].batAverage<<endl;
	cout<<"Strike Rate  :"<<hashTable[i].batStrikeRate<<endl;
	cout<<"---------------------Bowling-------------------------------------"<<endl;
	cout<<"Bowling Style:"<<hashTable[i].bowlStyle<<endl;
	cout<<"Total Wickets:"<<hashTable[i].wickets<<endl;
	cout<<"Runs Conceded:"<<hashTable[i].runsConceded<<endl;
	cout<<"Balls Bowled :"<<hashTable[i].ballsBowled<<endl;
	cout<<"Overs Bowled :"<<hashTable[i].oversBowled<<endl;
	cout<<"Average      :"<<hashTable[i].bowlAverage<<endl;
	cout<<"Strike Rate  :"<<hashTable[i].bowlStrikeRate<<endl;
	cout<<"Economy Rate :"<<hashTable[i].bowlEconomy<<endl;	
	cout<<"-----------------------------------------------------------------"<<endl;
	getchar();
}


void searchPlayers(char fileName[])
{
    int jersey;
    printDatabase(fileName);
	cout<<"\n\nEnter the jersey number to be Searched: ";
	cin>>jersey;
	int flag = 0;
	readFrom_File(fileName);
	int i = hashIndexFind(jersey,7);
	if(jersey == hashTable[i].jerseyNo)
	{
		printPlayers(i);
	}
	else
	{
		for(int j=i;j<7;j++)
		{
			if(jersey == hashTable[j].jerseyNo)
			{
				flag=1;
			    printPlayers(j);
			}
		}
		if(flag == 0)
		{
			for(int j=0;j<i;j++)
			{
				if(jersey == hashTable[j].jerseyNo)
				{
					printPlayers(j);
				}
			}
		}
	}
	writeTo_File(fileName);
		
}

void modifyDatabase(char fileName[])
{
	int jersey;
	system("cls");
	getchar();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter the jersey number to be modified: ";
	cin>>jersey;
	int flag = 0;
	readFrom_File(fileName);
	int i = hashIndexFind(jersey,7);
	if(jersey == hashTable[i].jerseyNo)
	{
		modifyContent(hashTable,i);
	}
	else
	{
		for(int j=i;j<7;j++)
		{
			if(jersey == hashTable[j].jerseyNo)
			{
				flag=1;
			    modifyContent(hashTable,j);	
			}
		}
		if(flag == 0)
		{
			for(int j=0;j<i;j++)
			{
				if(jersey == hashTable[j].jerseyNo)
				{
					modifyContent(hashTable,j);
				}
			}
		}
	}
	writeTo_File(fileName);
	
	
}

void createDatabase(char fileName[])
{
    int NoP;
    int playerNo;
    int hashIndex;
    struct player p[50];
    system("cls");
    cout<<"\n\nCREATING DATABASE ...";
	cout<<"\n\nEnter number of players: ";
	cin>>NoP;
	for(playerNo=0;playerNo<NoP;playerNo++)
	{
		cout<<"\n\nPLAYER "<<playerNo+1<<endl<<endl;
		cout<<"\nEnter Jersey No.             :";
	    cin>>p[playerNo].jerseyNo;
		personalInfo(p,playerNo);
		teamInfo(p,playerNo);
		matchesNo(p,playerNo);
		role(p,playerNo);
		batStat(p,playerNo);
		bowlStat(p,playerNo);
		
		
		hashIndex = hashIndexFind(p[playerNo].jerseyNo,NoP);
		if(hashIndex < 0)
		{
		    hashIndex = 0;	
		}
		while(hashTable[hashIndex].jerseyNo != 0)
		{
			hashIndex++;
			hashIndex = hashIndex % NoP;
		}
		hashTable[hashIndex] = p[playerNo];
		
    }
    writeTo_File(fileName);		
}

void printDatabase(char fileName[])
{
	int playerNo;
	readFrom_File(fileName);
	system("cls");
	getchar();
	cout<<endl;
	cout<<"\n\n\tJersey No\t\tName\t\tAge\t\tTeam\t\t\tRole\t\t\tBatting Style\t\tBowling Style\t\t\n";
	cout<<"\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    for(playerNo = 0;playerNo < 7; playerNo++)
    {
    	cout<<setw(10)<<hashTable[playerNo].jerseyNo<<setw(30)<<hashTable[playerNo].pName<<setw(10)<<hashTable[playerNo].age<<setw(17)<<hashTable[playerNo].tName<<setw(30)<<hashTable[playerNo].role<<setw(30)<<hashTable[playerNo].batStyle<<setw(30)<<hashTable[playerNo].bowlStyle<<endl<<endl<<endl;
	}
	getchar();
}

int parent(int i) { return (i-1)/2; }

void swap(struct player *x,struct player *y)
{
	struct player temp = *x;
	*x = *y;
	*y = temp;
}

void heapifyOrange(struct player heap[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
 
    if (l < n && heap[l].runs < heap[largest].runs)
        largest = l;
 
    
    if (r < n && heap[r].runs < heap[largest].runs)
        largest = r;
 
    
    if (largest != i) {
        swap(heap[i], heap[largest]);
 
        heapifyOrange(heap, n, largest);
    }
}
 

void heapSortOrange(struct player heap[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyOrange(heap, n, i);
 
    
    for (int i = n - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
 
        heapifyOrange(heap, i, 0);
    }
}
 

void insertOrangeCap(struct player heap[], int& n, struct player Key)
{
	if (n == 7)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}
	n++;
	int i = n - 1;
	heap[i] = Key;	
	while (i != 0 && heap[parent(i)].runs < heap[i].runs)
	{
	  swap(&heap[i], &heap[parent(i)]);
	  i = parent(i);
	}
} 

void orangeCap(struct player heap[])
{
	int indHeap = 0;
	for(int i=0;i<7;i++)
	{
	    insertOrangeCap(heap,indHeap,hashTable[i]);
	}
	cout<<"Orange Cap winner :"<<heap[0].pName<<endl;
	cout<<"\n\nTop List"<<endl<<endl;
	heapSortOrange(heap,7);
	for(int k=0;k<7;k++)
	{
		cout<<k+1<<"."<<heap[k].pName<<"("<<heap[k].runs<<")"<<endl;
	}
	for(int j=0;j<7;j++)
	{
		heap[j] = temp;
	}
	
}

void heapifyBatAverage(struct player heap[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
 
    if (l < n && heap[l].batAverage < heap[largest].batAverage)
        largest = l;
 
    
    if (r < n && heap[r].batAverage < heap[largest].batAverage)
        largest = r;
 
    
    if (largest != i) {
        swap(heap[i], heap[largest]);
 
        heapifyBatAverage(heap, n, largest);
    }
}
 

void heapSortBatAverage(struct player heap[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyBatAverage(heap, n, i);
 
    
    for (int i = n - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
 
        heapifyBatAverage(heap, i, 0);
    }
}
 

void insertBestBatAverage(struct player heap[], int& n, struct player Key)
{
	if (n == 7)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}
	n++;
	int i = n - 1;
	heap[i] = Key;	
	while (i != 0 && heap[parent(i)].batAverage < heap[i].batAverage)
	{
	swap(&heap[i], &heap[parent(i)]);
	i = parent(i);
	}
} 

void bestBatAverage(struct player heap[])
{
	int indHeap = 0;
	for(int i=0;i<7;i++)
	{
	    insertBestBatAverage(heap,indHeap,hashTable[i]);
	}
	cout<<"Best Batting Average winner :"<<heap[0].pName<<endl;
	cout<<"\n\nTop List"<<endl<<endl;
	heapSortBatAverage(heap,7);
	for(int k=0;k<7;k++)
	{
		cout<<k+1<<"."<<heap[k].pName<<"("<<heap[k].batAverage<<")"<<endl;
	}
	for(int j=0;j<7;j++)
	{
		heap[j] = temp;
	}
}


void heapifyBatStrike(struct player heap[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
 
    if (l < n && heap[l].batStrikeRate < heap[largest].batStrikeRate)
        largest = l;
 
    
    if (r < n && heap[r].batStrikeRate < heap[largest].batStrikeRate)
        largest = r;
 
    
    if (largest != i) {
        swap(heap[i], heap[largest]);
 
        heapifyBatStrike(heap, n, largest);
    }
}
 

void heapSortBatStrike(struct player heap[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyBatStrike(heap, n, i);
 
    
    for (int i = n - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
 
        heapifyBatStrike(heap, i, 0);
    }
}
 

void insertBestBatStrike(struct player heap[], int& n, struct player Key)
{
	if (n == 7)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}
	n++;
	int i = n - 1;
	heap[i] = Key;	
	while (i != 0 && heap[parent(i)].batStrikeRate < heap[i].batStrikeRate)
	{
	  swap(&heap[i], &heap[parent(i)]);
	  i = parent(i);
	}
} 

void bestBatStrike(struct player heap[])
{
	int indHeap = 0;
	for(int i=0;i<7;i++)
	{
	    insertBestBatStrike(heap,indHeap,hashTable[i]);
	}
	cout<<"Best Batting Strike Rate Winner :"<<heap[0].pName<<endl;
	cout<<"\n\nTop List"<<endl<<endl;
	heapSortBatStrike(heap,7);
	for(int k=0;k<7;k++)
	{
		cout<<k+1<<"."<<heap[k].pName<<"("<<heap[k].batStrikeRate<<")"<<endl;
	}
	for(int j=0;j<7;j++)
	{
		heap[j] = temp;
	}
}

void heapifyPurple(struct player heap[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
 
    if (l < n && heap[l].wickets < heap[largest].wickets)
        largest = l;
 
    
    if (r < n && heap[r].wickets < heap[largest].wickets)
        largest = r;
 
    
    if (largest != i) {
        swap(heap[i], heap[largest]);
 
        heapifyPurple(heap, n, largest);
    }
}
 

void heapSortPurple(struct player heap[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyPurple(heap, n, i);
 
    
    for (int i = n - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
 
        heapifyPurple(heap, i, 0);
    }
}
 

void insertPurpleCap(struct player heap[], int& n, struct player Key)
{
	if (n == 7)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}
	n++;
	int i = n - 1;
	heap[i] = Key;	
	while (i != 0 && heap[parent(i)].wickets < heap[i].wickets)
	{
	  swap(&heap[i], &heap[parent(i)]);
	  i = parent(i);
	}
} 

void purpleCap(struct player heap[])
{
	int indHeap = 0;
	for(int i=0;i<7;i++)
	{
	    insertPurpleCap(heap,indHeap,hashTable[i]);
	}
	cout<<"Purple Cap Winner :"<<heap[0].pName<<endl;
	cout<<"\n\nTop List"<<endl<<endl;
	heapSortPurple(heap,7);
	for(int k=0;k<7;k++)
	{
		cout<<k+1<<"."<<heap[k].pName<<"("<<heap[k].wickets<<")"<<endl;
	}
	for(int j=0;j<7;j++)
	{
		heap[j] = temp;
	}
}


void heapifyBowlAverage(struct player heap[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
 
    if (l < n && heap[l].bowlAverage > heap[largest].bowlAverage)
        largest = l;
 
    
    if (r < n && heap[r].bowlAverage > heap[largest].bowlAverage)
        largest = r;
 
    
    if (largest != i) {
        swap(heap[i], heap[largest]);
 
        heapifyBowlAverage(heap, n, largest);
    }
}
 

void heapSortBowlAverage(struct player heap[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyBowlAverage(heap, n, i);
 
    
    for (int i = n - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
 
        heapifyBowlAverage(heap, i, 0);
    }
}
 

void insertBestBowlAverage(struct player heap[], int& n, struct player Key)
{
	if (n == 7)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}
	n++;
	int i = n - 1;
	heap[i] = Key;	
	while (i != 0 && heap[parent(i)].bowlAverage > heap[i].bowlAverage)
	{
	  swap(&heap[i], &heap[parent(i)]);
	  i = parent(i);
	}
} 

void bestBowlAverage(struct player heap[])
{
	int indHeap = 0;
	int flag=0;
	for(int i=0;i<7;i++)
	{
		if(strcmp(hashTable[i].role,"Batsman")==0 || strcmp(hashTable[i].role,"WK Batsman")==0)
		{
		  continue;  	
		}
	    insertBestBowlAverage(heap,indHeap,hashTable[i]);
	    flag++;
	}
	cout<<"Best Bowling Average Winner :"<<heap[0].pName<<endl;
	cout<<"\n\nTop List"<<endl<<endl;
	heapSortBowlAverage(heap, flag);
	for(int k=0;k<flag;k++)
	{
		cout<<k+1<<"."<<heap[k].pName<<"("<<heap[k].bowlAverage<<")"<<endl;
	}
	for(int j=0;j<7;j++)
	{
		heap[j] = temp;
	}
}


void heapifyBowlStrike(struct player heap[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
 
    if (l < n && heap[l].bowlStrikeRate > heap[largest].bowlStrikeRate)
        largest = l;
 
    
    if (r < n && heap[r].bowlStrikeRate > heap[largest].bowlStrikeRate)
        largest = r;
 
    
    if (largest != i) {
        swap(heap[i], heap[largest]);
 
        heapifyBowlStrike(heap, n, largest);
    }
}
 

void heapSortBowlStrike(struct player heap[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyBowlStrike(heap, n, i);
 
    
    for (int i = n - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
 
        heapifyBowlStrike(heap, i, 0);
    }
}
 

void insertBestBowlStrike(struct player heap[], int& n, struct player Key)
{
	if (n == 7)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}
	n++;
	int i = n - 1;
	heap[i] = Key;	
	while (i != 0 && heap[parent(i)].bowlStrikeRate > heap[i].bowlStrikeRate)
	{
	   swap(&heap[i], &heap[parent(i)]);
	   i = parent(i);
	}
} 

void bestBowlStrike(struct player heap[])
{
	int indHeap = 0;
	int flag=0;
	for(int i=0;i<7;i++)
	{
		if(strcmp(hashTable[i].role,"Batsman")==0 || strcmp(hashTable[i].role,"WK Batsman")==0)
		{
		  continue;  	
		}
	    insertBestBowlStrike(heap,indHeap,hashTable[i]);
	    flag++;
	}
	cout<<"Best Bowling Strike Rate Winner :"<<heap[0].pName<<endl;
	cout<<"\n\nTop List"<<endl<<endl;
	heapSortBowlStrike(heap, flag);
	for(int k=0;k<flag;k++)
	{
		cout<<k+1<<"."<<heap[k].pName<<"("<<heap[k].bowlStrikeRate<<")"<<endl;
	}
	for(int j=0;j<7;j++)
	{
		heap[j] = temp;
	}
}


void heapifyBowlEconomy(struct player heap[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
 
    if (l < n && heap[l].bowlEconomy > heap[largest].bowlEconomy)
        largest = l;
 
    
    if (r < n && heap[r].bowlEconomy > heap[largest].bowlEconomy)
        largest = r;
 
    
    if (largest != i) {
        swap(heap[i], heap[largest]);
 
        heapifyBowlEconomy(heap, n, largest);
    }
}
 

void heapSortBowlEconomy(struct player heap[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyBowlEconomy(heap, n, i);
 
    
    for (int i = n - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
 
        heapifyBowlEconomy(heap, i, 0);
    }
}
 

void insertBestBowlEconomy(struct player heap[], int& n, struct player Key)
{
	if (n == 7)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}
	n++;
	int i = n - 1;
	heap[i] = Key;	
	while (i != 0 && heap[parent(i)].bowlEconomy > heap[i].bowlEconomy)
	{
	   swap(&heap[i], &heap[parent(i)]);
	   i = parent(i);
	}
} 

void bestBowlEconomy(struct player heap[])
{
	int indHeap = 0;
	int flag=0;
	for(int i=0;i<7;i++)
	{
		if(strcmp(hashTable[i].role,"Batsman")==0 || strcmp(hashTable[i].role,"WK Batsman")==0)
		{
		  continue;  	
		}
		insertBestBowlEconomy(heap,indHeap,hashTable[i]);
		flag++;
	}
	cout<<"Best Economy Rate Winner :"<<heap[0].pName<<endl;
	cout<<"\n\nTop List"<<endl<<endl;
	heapSortBowlEconomy(heap,flag);
	for(int k=0;k<flag;k++)
	{
		cout<<k+1<<"."<<heap[k].pName<<"("<<heap[k].bowlEconomy<<")"<<endl;
	}
	for(int j=0;j<7;j++)
	{
		heap[j] = temp;
	}
}



int main()
{
	SetConsoleTitleA("Players Statistics Management");
	int ch;
	char fileName[50];
	cout<<"\n\n\t\t\t\t\t\t\tCRICOGRAPHY"<<endl<<endl;
	cout<<"\n\n\t\tEnter File Name: ";
	cin>>fileName;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLOADING PROGRAM...";
	Sleep (1500);
	cout << ".....";
	Sleep (2000);
	cout << ".....";
	while(1)
	{
		system("cls");
	    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tContents:"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t1) Players Database"<<endl;
		cout<<"\n\t\t\t\t\t\t\t2) Best Performers"<<endl;
		cout<<"\n\t\t\t\t\t\t\t3) Quit"<<endl;
		cout<<"\n\n\t\t\t\t\t\tChoose...";
		cin>>ch;
		switch(ch)
		{
			case 1:
				databaseContent(fileName);
				break;
			case 2:
				bestPerformers(fileName);
				break;
			case 3:
				exit(0);
			default:
				cout<<"Give Correct Option"<<endl;
		}	
	}
	
	      
}
