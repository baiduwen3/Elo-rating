#include<iostream>
#include<fstream>
#include<math.h>
#include<conio.h>

using namespace std;

int const strings = 8;   // колич. девочек
int const Num = strings;
int const K = 40;   // коэф. некрутости

void RatingsDisp ( char Names [  ] [ 300 ], float Ratings [ strings ] );

int main()
{    
  srand(time (NULL));



char Names [ strings ][ 300 ];
char Temp [10];
float Ratings [ strings ];
char fNames [ ] = "Names.txt";
char fRatings [ ] = "Ratings.txt";

 //while ( true ) {
	for ( int times = 0; times < 1500 ; times++){
	 clrscr( ); 
	 cout << times<<endl << endl;
	 

 ifstream fN(fNames);
 ifstream fR(fRatings);
  
   
   for (int c = 0; c < Num; c++){
   	fN.getline( Names[ c ], 200 );	
   }	
   fN.close();
   
    for (int c = 0; c < Num; c++){
   	fR.getline( Temp, 10 );	
   	Ratings [ c ] = atoi (Temp );
   }	
   fR.close();
  
   // подбор пар девочек
   int a = rand()% Num;
   int b;
   do {
   	b = rand()% Num;
   } while ( b == a );
   
   // данные девочек:
   float Ra = Ratings [ a ];
   float Rb = Ratings [ b ];
   
   // мат. ожидание победы девочки
   float Ea = 1 / ( 1 + pow ( 10, ( ( Rb - Ra)/ 400 ) ));
   float Eb = 1  - Ea;
   

   
            // результаты:
            cout << "~~~~~~ Мисс ЭЛМ ~~~~~~" <<endl << endl;
	   RatingsDisp(Names, Ratings);
	   cout << endl;
       
        
         // голосование 
     /*   
   float Sa, Sb;
   int ans;
   cout << "Выбери свою Мисс с помощью цифры: "<<endl<< endl;
   cout <<"1 - мисс "<< Names [ a ] << " "<<Ra<<endl<<"2 - мисс "<< Names [ b ]<<" "<<Rb<<endl;
   cin >> ans;
   if (ans == 1) { Sa=1;Sb=0; }
  else if ( ans == 2) { Sb=1;Sa=0; }
   else { cout<<"Wrong input!"<<endl; }
*/

   // голосование компьютерное
   
   float Sa, Sb;
 if ( a > b ) { Sa = 0; Sb = 1; }
 else { Sa = 1; Sb = 0;}

   
   // рейтинг после голосования
   float RRa = Ra + K * ( Sa - Ea );
   if ( RRa < 0 ) RRa = 0;
 float  RRb = Rb + K * ( Sb - Eb );
 if ( RRb < 0 ) RRb = 0;
 
 //обновляем рейтинги
 Ratings [ a ] = RRa;
 Ratings [ b ] = RRb;
 
 // записываем новые рейтинги
 ofstream foR(fRatings);
 
    for (int c = 0; c < Num; c++){
    	foR << Ratings [ c ] << endl;
   }	
   foR.close();
   
}
   
   // вывод  
   /*
     cout <<Names [ a ] <<"   " << Names [ b ]<<endl;
     cout << Ra<<"   " << Rb<<endl;
     cout << Ea<<"   " << Eb<<endl;
      cout << RRa<<"   " << RRb<<endl;
 
 */
 
 // Показать всех девочек с рейтингами
//  RatingsDisp(Names, Ratings);

        return 0;
}

void RatingsDisp ( char Names [  ] [ 300 ], float Ratings [ strings ] ) {
	
  for (int c = 0; c < Num; c++){
   	cout << Names [ c ] << " - Rating: "<< Ratings [ c ] << endl;
   }
}
  
