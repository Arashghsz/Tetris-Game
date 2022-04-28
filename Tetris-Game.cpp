#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <fstream>
#define TypeShape 7
#define Rows 30
#define Colums 25
#define RowsShape 4
#define ColumsShape 2

using namespace std;





int ArrayScreen[Rows][Colums]={0};
int ShapeRandome ;
int ChoiceShape;
int MoveRows;
bool PauseGame;
int RatingUser;
int PositionX=17,PositionY=0;
int PrimShape[RowsShape][ColumsShape];
char profile_name[20]={"Player"};
char profile_email[40]={"Player@gmail.com"};
int  profile_age=0;




void FuncShowShape(char);
void FuncCheckKye(char);
void FuncMenuMain();
void FuncGameStart();
void FuncGameStart_M();
void FuncGameStart_E();
void FuncAboutGame();
void FuncMenuPause();
void FuncGotoPosition(int,int);
void FuncFinshGame();
void FuncChoiceShape(int);
void FuncEraseRow();
void FuncEraseRow_M();
void FuncEraseRow_E();
void FuncUpdateScreen();
void FuncUpdateArrayScreen();
bool FuncNotCollision();
bool FuncNotCollisionUnder();
bool FuncNotCollisionRight();
bool FuncNotCollisionLeft();
bool FuncNotCollisionRotate();
void FuncRotetShape();
void FuncShowTable();
void FuncEsm();
void Funcload();
void Funcsave();
void Funccreate_profile();
void Functime();
void Funcshow_profile();
void FuncColor_main_menu();
void FuncColor_Gameover();
void FuncColor_Hard();
void FuncColor_Medium();
void FuncColor_Easy();




int main(){
    ShapeRandome = rand()%TypeShape;
    ChoiceShape=0;
    MoveRows=0;
    PauseGame=false;
    RatingUser=0;

    HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	
	FuncColor_main_menu();
    FuncMenuMain();
}


void FuncGotoPosition(int PointX, int PointY){
	HANDLE stdOutput;
    COORD Pos;
    stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    Pos.X = PointX;
    Pos.Y = PointY;
    SetConsoleCursorPosition(stdOutput, Pos);
	return;
}


void FuncShowShape(char CharIn)
{
  	for(int i=0;i<RowsShape;i++)
   {

		FuncGotoPosition(PositionX+PrimShape[i][0],PositionY+PrimShape[i][1]);
        cout<<CharIn;
   }
}


void FuncCheckKye(char CharIn){
	if(CharIn<0)
        CharIn=getch();
   	if(CharIn==80)
    {
        if(FuncNotCollisionUnder()){
				FuncShowShape(' ');
				PositionY++;
		  }

    }
    else if (CharIn==75)
    {
        if(FuncNotCollisionLeft())
        {
            FuncShowShape(' ');
            PositionX--;
        }
    }
    else if( CharIn==77)
    {
        if(FuncNotCollisionRight())
        {
            FuncShowShape(' ');
            PositionX++;
        }
    }
    else if(CharIn==32)
    {
        if (FuncNotCollisionRotate())
        {
			FuncShowShape(' ');
			FuncRotetShape();
        }
    }
    else if(CharIn==27)
    {
        PauseGame=true;
        while(PauseGame)
        {
            FuncMenuPause();
        }
        PauseGame=false;
    }
}


void FuncMenuMain()
{
	
    
    char ChoiseMenu;
    system("cls");

    FuncGotoPosition(40,8);
	Sleep(350);
 
	cout<<"[==================================]"<<endl;
		
		
 	FuncGotoPosition(40,10);
	Sleep(350);
 
	cout<<"[==================================]"<<endl;     
	
	
	FuncGotoPosition(40,12);
	Sleep(350);
  
	cout<<"[==================================]"<<endl;  
	
	
	FuncGotoPosition(40,14);
	Sleep(350);

	cout<<"[==================================]"<<endl;
	
	
	FuncGotoPosition(40,16);
	Sleep(350);

	cout<<"[==================================]"<<endl;
	
		
	FuncGotoPosition(40,18);
    Sleep(350);

	cout<<"[==================================]"<<endl;
	

	FuncGotoPosition(40,17);
	Sleep(200);

	cout<<"     Press 5:   Exit";

	
	FuncGotoPosition(40,15);
	Sleep(200);

	cout<<"     Press 4:   About!";

	
	FuncGotoPosition(40,13);
	Sleep(200);

	cout<<"     Press 3:   Game Load "<<endl;


	FuncGotoPosition(40,11);
	Sleep(200);

	cout<<"     Press 2:   Start New Game"<<endl;
    FuncGotoPosition(40,9);
	Sleep(200);
    cout<<"     Press 1:   Create Profile"<<endl;
	
	   first:;
    ChoiseMenu=getch();
      if(ChoiseMenu=='1'){
		 system("cls");
		 Funccreate_profile();
		 system("cls");
		 FuncMenuMain();
		 
      }

	else if(ChoiseMenu=='2')
    {       system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
   			
		 
			 FuncGotoPosition(40,10);
		     Sleep(350);
 
			cout<<"[==================================]"<<endl;     
	
	
			FuncGotoPosition(40,12);
			Sleep(350);
  
			cout<<"[==================================]"<<endl;  
   
  		    FuncGotoPosition(40,14);
			Sleep(350);

			cout<<"[==================================]"<<endl;
		
			
			FuncGotoPosition(40,16);
			Sleep(350);

			cout<<"[==================================]"<<endl;
  		 
  		    FuncGotoPosition(40,15);
			Sleep(200);

			cout<<"     Press 3:   Easy";

			
			FuncGotoPosition(40,13);
			Sleep(200);

			cout<<"     Press 2:   Medium"<<endl;


			FuncGotoPosition(40,11);
			Sleep(200);

			cout<<"     Press 1:   Hard "<<endl;
   
		   	FuncGotoPosition(60,30);
		   
		   	Sleep(500);
			cout<<"  Press Esc : Main Menu";
		   
		   	ChoiseMenu=getch();
   
    				if(ChoiseMenu=='1'){
   					system("cls");
					Functime();
				   	system("cls");
    				FuncGameStart();
    	
  				}
  					else if(ChoiseMenu=='2'){
					system("cls");
					Functime();
					system("cls");
    				FuncGameStart_M();

    	
    			}
   
    				else if(ChoiseMenu=='3'){
    				system("cls");
					Functime();
					system("cls");
					FuncGameStart_E();

    	
    			}
   	
	  				else if(ChoiseMenu==27){
    				system("cls");
					FuncMenuMain();

    			}
	   
	   
	   
	   	else{
   	
		   	   system("cls");
			   FuncMenuMain();
 
    			}	}
   	else  if(ChoiseMenu=='3')
    {	
		system("cls");
		
		
    }
	
	
	else if(ChoiseMenu=='4')
    {
	 	system("cls");
        
        FuncAboutGame();
    }
    else if(ChoiseMenu=='5')
    {
         system("cls");
          exit(0);  
    }
    else
        {        system("cls");

            	FuncGotoPosition(40,11);

			cout<<"invalid input ";
           
		    getch();
        }

}


void FuncGameStart()
{	 
	    Funcshow_profile();
      
	    int k;
	for(k=5;k<Rows-1;k++)
		ArrayScreen[k][Colums-1]=1;
	for(k=1;k<Colums;k++){
		ArrayScreen[5][k]=1;
		ArrayScreen[Rows-1][k]=1;
	}
	srand((0));
    FuncShowTable();
	char key;
	FuncChoiceShape(ChoiceShape);
	FuncShowShape(219);
    FuncGotoPosition(Rows+8,Colums-10);
	 while(true){


		if(FuncNotCollision()){
		  FuncShowShape(' ');
		  PositionY++;
		  FuncShowShape(219);
		}
		else
		{
			FuncColor_Hard();
            FuncUpdateArrayScreen();
			FuncEraseRow();
			FuncGotoPosition(Rows+4,Colums-20);
			cout<<profile_name<<"'s Point : "<<RatingUser;
			FuncUpdateScreen();
            ChoiceShape = ShapeRandome;
            ShapeRandome = rand() % 7;
            FuncGotoPosition(Rows+9,Colums-16);
            cout<<"      ";
            FuncGotoPosition(Rows+9,Colums-15);
            cout<<"      ";
            FuncGotoPosition(Rows+9,Colums-14);
            cout<<"      ";
            FuncGotoPosition(Rows+9,Colums-13);
            cout<<"      ";
            PositionY=Colums-15;
            PositionX=Rows+12;
            FuncChoiceShape(ShapeRandome);
			FuncChoiceShape(ChoiceShape);
			PositionY = 0;
			PositionX = 18;
		 }
		   Sleep(85);
		if(kbhit()){
      		  	key=getch();
         	  	FuncCheckKye(key);
      	}
            for(int i=6;i<28;i++)
            if(ArrayScreen[i][1]==1)
               FuncFinshGame();
	}
}


 void FuncGameStart_M() {
        
		Funcshow_profile();
		
		int k;
	for(k=5;k<Rows-1;k++)
		ArrayScreen[k][Colums-1]=1;
	for(k=1;k<Colums;k++){
		ArrayScreen[5][k]=1;
		ArrayScreen[Rows-1][k]=1;
	}
	srand((0));
    FuncShowTable();
	char key;
	FuncChoiceShape(ChoiceShape);
	FuncShowShape(219);
    FuncGotoPosition(Rows+8,Colums-10);
	 while(true){


		if(FuncNotCollision()){
		  FuncShowShape(' ');
		  PositionY++;
		  FuncShowShape(219);
		}
		else
		{
            FuncColor_Medium();
		    FuncUpdateArrayScreen();
			FuncEraseRow_M();
			FuncGotoPosition(Rows+4,Colums-20);
			cout<<profile_name<<"'s Point : "<<RatingUser;
			FuncUpdateScreen();
            ChoiceShape = ShapeRandome;
            ShapeRandome = rand() % 7;
            FuncGotoPosition(Rows+9,Colums-16);
            cout<<"      ";
            FuncGotoPosition(Rows+9,Colums-15);
            cout<<"      ";
            FuncGotoPosition(Rows+9,Colums-14);
            cout<<"      ";
            FuncGotoPosition(Rows+9,Colums-13);
            cout<<"      ";
            PositionY=Colums-15;
            PositionX=Rows+12;
            FuncChoiceShape(ShapeRandome);
			FuncChoiceShape(ChoiceShape);
			PositionY = 0;
			PositionX = 18;
		 }
		   Sleep(250);
		if(kbhit()){
      		  	key=getch();
         	  	FuncCheckKye(key);
      	}
            for(int i=6;i<28;i++)
            if(ArrayScreen[i][1]==1)
               FuncFinshGame();
	}
}

void FuncGameStart_E(){
       
	   Funcshow_profile();
	   
	    int k;
	for(k=5;k<Rows-1;k++)
		ArrayScreen[k][Colums-1]=1;
	for(k=1;k<Colums;k++){
		ArrayScreen[5][k]=1;
		ArrayScreen[Rows-1][k]=1;
	}
	srand((0));
    FuncShowTable();
	char key;
	FuncChoiceShape(ChoiceShape);
	FuncShowShape(219);
    FuncGotoPosition(Rows+8,Colums-10);
	 while(true){


		if(FuncNotCollision()){
		  FuncShowShape(' ');
		  PositionY++;
		  FuncShowShape(219);
		}
		else
		{
		    FuncColor_Easy();
			FuncUpdateArrayScreen();
			FuncEraseRow_E();
			FuncGotoPosition(Rows+4,Colums-20);
			cout<<profile_name<<"'s Point : "<<RatingUser;
			FuncUpdateScreen();
            ChoiceShape = ShapeRandome;
            ShapeRandome = rand() % 7;
            FuncGotoPosition(Rows+9,Colums-16);
            cout<<"      ";
            FuncGotoPosition(Rows+9,Colums-15);
            cout<<"      ";
            FuncGotoPosition(Rows+9,Colums-14);
            cout<<"      ";
            FuncGotoPosition(Rows+9,Colums-13);
            cout<<"      ";
            PositionY=Colums-15;
            PositionX=Rows+12;
            FuncChoiceShape(ShapeRandome);
			FuncChoiceShape(ChoiceShape);
			PositionY = 0;
			PositionX = 18;
		 }
		   Sleep(550);
		if(kbhit()){
      		  	key=getch();
         	  	FuncCheckKye(key);
      	}
            for(int i=6;i<28;i++)
            if(ArrayScreen[i][1]==1)
               FuncFinshGame();
	}
}        
 
 
void FuncAboutGame(void)
{
    
	system("color 61");
	char esc;
    system("cls");
    FuncEsm();
    
	FuncGotoPosition(40,12);
			Sleep(500);
  
			cout<<"[==================================]"<<endl;  
   
  		    FuncGotoPosition(40,14);
			Sleep(1000);

			cout<<"[==================================]"<<endl;
		FuncGotoPosition(40,13);
    Sleep(2000);

	cout<<"  Press Esc : Main Menu";
    
    esc=getch(); 
    if(esc==27)
    {
        system("cls");
        FuncMenuMain();
    
	}
    else
    {
        system("cls");
        FuncAboutGame();
    }
}

void FuncMenuPause()
{

 	FuncGotoPosition(70,10);
	Sleep(150);
 
	cout<<"[==================================]"<<endl;     
	
	
	FuncGotoPosition(70,12);
	Sleep(150);
  
	cout<<"[==================================]"<<endl;  
	
	
	FuncGotoPosition(70,14);
	Sleep(150);

	cout<<"[==================================]"<<endl;
	
	
	FuncGotoPosition(70,16);
	Sleep(150);

	cout<<"[==================================]"<<endl;
	
		
	FuncGotoPosition(70,18);
    Sleep(150);

	cout<<"[==================================]"<<endl;
	


	FuncGotoPosition(70,17);
	Sleep(50);

	cout<<"     Press 4:   Exit";

	
	FuncGotoPosition(70,15);
	Sleep(50);

	cout<<"     Press 3:   Main Menu";

	
	FuncGotoPosition(70,13);
	Sleep(50);

	cout<<"     Press 2:   Change Game to Hard "<<endl;


	FuncGotoPosition(70,11);
	Sleep(50);

	cout<<"     Press 1:   Continue"<<endl;
  
	
    
    char ChoiseMenu=getch();
    if(ChoiseMenu=='1')
    {	
        for(int i=55;i<80;i++)
                    {
                        for(int j=0;j<25;j++)
                        {
                            FuncGotoPosition(i,j);
                            cout<<" ";
                        }
                    }
                    PauseGame=false;
    }
  else if (ChoiseMenu=='2'){

	system("cls");
	FuncGameStart();
	}
  
  
    else if(ChoiseMenu=='3')
    {
        system("cls");
        for(int i=0;i<30;i++)
        {
            for(int j=0;j<25;j++)
                ArrayScreen[i][j]={0};
        }
        RatingUser=0;
        FuncMenuMain();
    }
    else if(ChoiseMenu=='4')
    {
        system("cls");
        exit(0);
    }

	else if (ChoiseMenu=='5'){

	system("cls");
	Funcsave ();
	}
}


void FuncFinshGame(){
          
		 cout<<"\a";
		 Sleep(200);
		 cout<<"\a";
		 Sleep(200);
		 cout<<"\a";
		 
		 
		 system("cls");
		 FuncColor_Gameover();		  
            FuncGotoPosition(30,11);
    cout << " #####     #    #     # ####### ####### #     # ####### ######\n" ;
	
	FuncGotoPosition(30,12);
	Sleep(200);
    
	
	cout << "#     #   # #   ##   ## #       #     # #     # #       #     #\n";
	
	FuncGotoPosition(30,13);
	Sleep(200);
    
	
	cout << "#        #   #  # # # # #       #     # #     # #       #     #\n";
	
	FuncGotoPosition(30,14);
	Sleep(200);
    
	
	cout << "#  #### #     # #  #  # #####   #     # #     # #####   ######\n";
	
	FuncGotoPosition(30,15);
	Sleep(200);
    
	
	cout << "#     # ####### #     # #       #     #  #   #  #       #   #\n";
	
	FuncGotoPosition(30,16);
	Sleep(200);
    
	
	cout << "#     # #     # #     # #       #     #   # #   #       #    #\n";
	
	FuncGotoPosition(30,17);
	Sleep(200);
    
	cout << " #####  #     # #     # ####### #######    #    ####### #     #\n";
	
	
            Sleep(4500);
            system("cls");
            exit (0);
}


void FuncChoiceShape(int NumShape)
{
    int ArrayShape[TypeShape][RowsShape][ColumsShape]={


                           {{0,-1},{0,0},{-1,0},{-1,1}},
                           {{0,-1},{0,0},{1,0},{1,1}},
						   {{0,-1},{0,0},{0,1},{0,2}},
                           {{-1,0},{0,0},{1,0},{0,1}},
                           {{0,0},{1,0},{0,1},{1,1}},
                           {{-1,-1},{0,-1},{0,0},{0,1}},
                           {{1,-1},{0,-1},{0,0},{0,1}}
                        };
   for(int i=0;i<RowsShape;i++)
   	for(int j=0;j<ColumsShape;j++)
      	PrimShape[i][j]=ArrayShape[NumShape][i][j];
}



void FuncEraseRow(){
   
    int RewardScore=1;
	for (int i=Colums-2;i>1;i--){
		for (int j=6;j<Rows-1;j++){
			if(ArrayScreen[j][i]==true)
				MoveRows++;
		}
		if (MoveRows==Colums-2){
			cout<<"\a";
				for (int n=i;n>1;n--){
					for (int t=1;t<=Rows-1;t++){
						ArrayScreen[t][n]=ArrayScreen[t][n-1];
					}
				}
			RatingUser=RatingUser+15*RewardScore;
			RewardScore++;
			i++;
		}
		MoveRows=0;
	}
}


 void FuncEraseRow_M() {
   
    int RewardScore=1;
	for (int i=Colums-2;i>1;i--){
		for (int j=6;j<Rows-1;j++){
			if(ArrayScreen[j][i]==true)
				MoveRows++;
		}
		if (MoveRows==Colums-2){
				cout<<"\a";
				for (int n=i;n>1;n--){
					for (int t=1;t<=Rows-1;t++){
						ArrayScreen[t][n]=ArrayScreen[t][n-1];
					}
				}
			RatingUser=RatingUser+10*RewardScore;
			RewardScore++;
			i++;
		}
		MoveRows=0;
	}
} 
  
          
void FuncEraseRow_E()	{
   
    int RewardScore=1;
	for (int i=Colums-2;i>1;i--){
		for (int j=6;j<Rows-1;j++){
			if(ArrayScreen[j][i]==true)
				MoveRows++;
		}
		if (MoveRows==Colums-2){
				cout<<"\a";
				for (int n=i;n>1;n--){
					for (int t=1;t<=Rows-1;t++){
						ArrayScreen[t][n]=ArrayScreen[t][n-1];
					}
				}
			RatingUser=RatingUser+5*RewardScore;
			RewardScore++;
			i++;
		}
		MoveRows=0;
	}
}
	

void FuncUpdateScreen(){

    FuncGotoPosition(6,3);
    for(int i=6;i<Rows-1;i++){
        for(int j=0;j<Colums-1;j++){
            FuncGotoPosition(i,j);
            if(ArrayScreen[i][j]==1){
               char c=219;
			   cout<<c;            }

			else
				cout<<" ";
        }
    }
}



void FuncUpdateArrayScreen(){
    for(int i=0;i<RowsShape;i++)
        ArrayScreen[PositionX+PrimShape[i][0]][PositionY+PrimShape[i][1]]=1;


}



bool FuncNotCollision(){
    for(int i=0;i<RowsShape;i++)
        if(ArrayScreen[PositionX+PrimShape[i][0]][PositionY+PrimShape[i][1]+1]==1)
            return false;
    return true;
}



bool FuncNotCollisionUnder(){
    for(int i=0;i<RowsShape;i++)
        if(ArrayScreen[PositionX+PrimShape[i][0]][PositionY+PrimShape[i][1]+2]==1)
            return false;
    return true;
}



bool FuncNotCollisionRight(){
    for(int i=0;i<RowsShape;i++)
        if(ArrayScreen[PositionX+PrimShape[i][0]+1][PositionY+PrimShape[i][1]]==1)
            return false;
    return true;
}


bool FuncNotCollisionLeft(){
    for(int i=0;i<RowsShape;i++)
        if(ArrayScreen[PositionX+PrimShape[i][0]-1][PositionY+PrimShape[i][1]]==1)
            return false;
    return true;
}



bool FuncNotCollisionRotate(){
	int z;
	int shapeprim[RowsShape][ColumsShape];
	for (int i=0;i<RowsShape;i++){
		for (int j=0;j<ColumsShape;j++){
			shapeprim[i][j]=PrimShape[i][j];
		}
	}
	for(int i=0;i<RowsShape;i++){
   		z=shapeprim[i][1];
		shapeprim[i][1]=-shapeprim[i][0];
		shapeprim[i][0]=z;
   }
	for(int i=0;i<RowsShape;i++)
    	if(ArrayScreen[PositionX+shapeprim[i][0]][PositionY+shapeprim[i][1]]==true)
			return false;
	return true;
}



void FuncRotetShape(void){
	int z;
	for(int i=0;i<RowsShape;i++)
   {
   	  z=PrimShape[i][1];
      PrimShape[i][1]=-PrimShape[i][0];
      PrimShape[i][0]=z;
   }
}



void FuncShowTable(){


        char CharShowTbl1=200;
        char CharShowTbl2=200;
             for(int i=1;i<=Colums-1;i++){
                  FuncGotoPosition(5,i);
                    cout<<CharShowTbl1;
                  FuncGotoPosition(Rows-1,i);
                    cout<<CharShowTbl1;
                }
              for(int j=5;j<Rows-1;j++){
                  FuncGotoPosition(j,Colums-1);
                    cout<<CharShowTbl2;
                }
          }
          
          
       
  void FuncEsm(){
  
  string bubbles;
  bubbles=" Arash Ghasemzadeh / Contact : Ghasemzadehh.arash@gmail.com";
  int len=bubbles.length();
  for(int i = 0; i <= len+(len)+1; i++)
  {
      cout<<"-";
  }
  cout<<endl<<"|";
  for(int k = 0; k < (len/2); k++ )
  {
  cout<<" ";
  }
  cout<<bubbles;
  for(int a=1;a<len-len/2+1;a++)
  {
  cout<<" ";
  }
  cout<<"|\n";
  for(int i = 0; i<=len+(len)+1;i++)
  {
  cout<<"-";
  }

  
  }     
          

          
void Functime(){
	
	
			system("color fc");
			FuncGotoPosition(40,14);
			Sleep(350);

			cout<<"[==================================]"<<endl;
		
			
			FuncGotoPosition(40,16);
			

			cout<<"[==================================]"<<endl;
			
         	FuncGotoPosition(40,15);
            Sleep(1000);
		 	cout<<"  The Game starts in 5 seconds";
	 		FuncGotoPosition(40,15);
            Sleep(1000);
		 	cout<<"  The Game starts in 4 seconds";
	 		FuncGotoPosition(40,15);
            Sleep(1000);
		 	cout<<"  The Game starts in 3 seconds";
	 		FuncGotoPosition(40,15);
            Sleep(1000);
		 	cout<<"  The Game starts in 2 seconds";		
		 	FuncGotoPosition(40,15);
            Sleep(1000);
		 	cout<<"  The Game starts in 1 seconds";
		 	FuncGotoPosition(40,15);
            Sleep(1000);
		 	cout<<"  The Game starts in 0 seconds";
			Sleep(1000);
			system("cls");
}
	
             
void Funccreate_profile(){
							
		      Sleep(350);
			  FuncGotoPosition(10,5);
			  cout<<"Please fill below information. "<<endl;
			  Sleep(700);
			  FuncGotoPosition(60,30);
			  cout<<"Application will automatically back to Main Menu."<<endl;
			 FuncGotoPosition(40,10);
		     Sleep(350);
 
			cout<<"[============================================]"<<endl;     
	
	
			FuncGotoPosition(40,13);
			Sleep(350);
  
			cout<<"[============================================]"<<endl;  
   
  		    FuncGotoPosition(40,16);
			Sleep(350);

			cout<<"[============================================]"<<endl;
		
			
			FuncGotoPosition(40,19);
			Sleep(350);

			cout<<"[============================================]"<<endl;
  		    
			FuncGotoPosition(40,11);
			Sleep(200);
			
			cout<<"   Enter your Name & Press Enter"<<endl;
			
			
			FuncGotoPosition(40,12);
			cin>>profile_name;   
		
			FuncGotoPosition(40,14);
			Sleep(200);
			
			cout<<"   Enter your Email & Press Enter"<<endl;
		
		
			FuncGotoPosition(40,15);
			cin>>profile_email;
			
			FuncGotoPosition(40,17);
			Sleep(200);
			
			cout<<"   Enter your Age & Press Enter"<<endl;
		
		
			FuncGotoPosition(40,18);
			cin>>profile_age;   
		 
}
  
  
   void Funcload()
{
    
    
    ifstream moteghaier;
    moteghaier.open("moteghaier");
    moteghaier>>RatingUser;
    moteghaier.close();
    FuncGameStart();
}



	void Funcsave ()
{
   
    

    ofstream moteghaier;
    moteghaier.open("moteghaier");
    moteghaier<<RatingUser;
    moteghaier.close();
    
}



	void Funcshow_profile(){
	
	
	FuncGotoPosition(Rows+4,Colums-19);
	cout<<"Emil:"<<profile_email;
	FuncGotoPosition(Rows+4,Colums-18);
	cout<<"Age:"<<profile_age;

	
}



	void FuncColor_main_menu(){
 
		for (int i = 1; i < 4; i++)
 
	{
 
		system("color e4");
 
			Sleep(500);
 		FuncGotoPosition(55,10);
 	cout<<"Tetris game";
			system("color 74");
	Sleep(300);
			system("color f4");
	Sleep(300);
 
			}
			
			for (int i = 1; i < 10; i++){
		
					system("cls");
					system("color e4");
 
			Sleep(200);
 				FuncGotoPosition(55,10);
 			cout<<"Enjoy!";
					system("color 84");
			Sleep(100);
					system("color f4");
			Sleep(200);
			
			
				}
			
			}
	
	
	void FuncColor_Gameover(){
 
	for (int i = 1; i < 5; i++)
 
	{
 
	system("color 4F");
 
	Sleep(300);
 
	system("color F4");
 
	Sleep(300);
 
}}
	void FuncColor_Hard(){
 
	for (int i = 1; i < 2; i++)
 
	{
 
	system("color f6");
 
	Sleep(75);
 
	system("color 4f");
 
	Sleep(75);
 
}}

void FuncColor_Medium(){
 
	for (int i = 1; i < 2; i++)
 
	{
 
	system("color 12");
 
	Sleep(150);
 
	system("color b6");
 
	Sleep(150);
 
}}
	
	void FuncColor_Easy(){
 
	for (int i = 1; i < 2; i++)
 
	{
 
	system("color f1");
 
	Sleep(200);
 
	system("color 60");
 
	Sleep(200);
 
}}
	
		
	
	
	
	
	
	
	

