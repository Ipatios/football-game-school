#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 struct   omada {
	
	char name [30];
	char xwra [30];
	int xwr_stadiou;
	int pith; 
	int score_ebale; 
	int score_efage;
	int sun_score;
	int sum_score; 
	
};


	void  ektos_scor (omada omad [] ,int num, FILE *fpres);//sinartisi ektos gipedoy kai entos ghpedou  pontoi
			 void sel_sort(omada omad [] , int size);//sinartisi katanomi
 				void prok(omada oxt [],omada nikoites [],FILE *fpres);//sinartisi gia tous agones gia na bgei i oxtada
 					void two(omada nikoites [],omada megalo  [],omada mikro [],FILE *fpres);//sinartisi me ta match ton 4aron gia na bgoyn oi dio nikites kai oi dio xamenoi
 						void  telikos (omada megalo  [],omada first[] ,omada fisrt[],FILE *fpres);//sinartisi gia ta match ton nikiton
 							void  mikr_telikos (omada megalo  [],omada third[] ,omada four[],FILE *fpres);//sinartisi gia ta match ton ittimenon
 						
int main()
{
	int i,j;
		FILE *fp;
			struct omada omad 			[18];	 	//sunolikes omades 
			struct omada  oxt		    [8]; 			//oxtades 
				struct omada  nikoites  [4];				//nikoites apo tis 8ades (final 4)
				struct omada 	megalo  [2];					//oi nikoites apo final 4 
				struct omada  mikro		[2]; 						// oi xamenoi apo  final 4 	
				struct omada first	    [1];					// Prwtos  
				struct omada sec	    [1];				//deuteros 
				struct omada third      [1];			//tritos 
				struct omada four	    [1];		//Tetartos 
			
			
			int num=18 ,dr;
				fp=fopen ("teams.txt","r");
    i=0; 
			while (!feof(fp))        //gia na parei to programma ta stoixeia apo ton arxeio
    { 	
    	fscanf(fp, "%s" ,&omad[i].name); 
    		fscanf(fp, "%s" , &omad[i].xwra);
    			fscanf(fp, "%d" ,&omad[i].xwr_stadiou);
    				fscanf(fp, "%d" ,&omad[i].pith);
    					omad[i].score_ebale=0; 
 							omad[i].score_efage=0;
	 							omad[i].sun_score=0;
	 								omad[i].sum_score=0; 
					i++;
	}
	fclose (fp);
		
	FILE *fpres;	
		fpres=fopen ("Results.txt","w");
		
	 		ektos_scor(omad ,num , fpres); //kaloume th sunarthsh gia tous agwnes entos kai ektos ghpedou 
	 
	 
	  sel_sort( omad,num); //kaloume th sunarthsh gia na taxinomisoume tis omades.
	  fprintf( fpres,"\n(============================================)\n");//gia na ta baloyme mesa ston arxeio
	 fprintf(fpres, "	    Apotelesmata 1h Fash");
	fprintf(fpres, "\n(=============================================)\n");
	printf( "\n(============================================)\n");
	 printf( "	    Apotelesmata 1h Fash");
	printf( "\n(=============================================)\n");// gia na ta balei mesa sto programma
	 	for (i=0; i<num; i++){
		   	printf(  "\n Apotelesmata {%d} %s  %s  %d %d %d  ",i + 1, omad[i].name ,omad[i].xwra, omad[i].xwr_stadiou, omad[i].pith ,omad[i].sum_score);
     			printf( "\n\n_________________________________________________________________");
     		
			 fprintf(fpres,"\n Apotelesmata {%d} %s  %s  %d %d %d  ",i + 1, omad[i].name ,omad[i].xwra, omad[i].xwr_stadiou, omad[i].pith ,omad[i].sum_score);
     			fprintf(fpres,"\n\n_________________________________________________________________");
     				
	}
	
int s=0;
for(i=0; i<8; i++)  //epilegoume tous 8 me th megalhterh bathmologia gia thn 8ada.
	{
	oxt[s]=omad[i];
 	
	s++;
}

	
		fprintf( fpres,"\n(==========================================================================================================================)\n");//gia na ta baloyme mesa ston arxeio
 fprintf( fpres,"	  				Apotelesmata 2h Fash |OXTADES|        ");
	fprintf( fpres,"\n(==========================================================================================================================)\n");
	
	printf( "\n(=============================================)\n");
 printf( "	  Apotelesmata 2h Fash |OXTADES|       ");
	printf( "\n(=============================================)\n"); // gia na ta bgalei mesa sto programma
s=0;
	for(i=0; i<8; i++)
	
{ s++;
		printf( "\n Apotelesmata {%d} %s  %s  %d %d %d  ", s , oxt[i].name ,oxt[i].xwra, oxt[i].xwr_stadiou, oxt[i].pith , oxt[i].sum_score );// gia na ta balei tis oxtades mesa sto programma
		printf( "\n_____________________________________________________________________\n");
			fprintf( fpres,"\n Apotelesmata {%d} %s  %s  %d %d %d  ", s , oxt[i].name ,oxt[i].xwra, oxt[i].xwr_stadiou, oxt[i].pith , oxt[i].sum_score );//gia na ta baloyme tis oxtades mesa ston arxeio
		fprintf(fpres, "\n_____________________________________________________________________\n");
		


}



	prok (omad,nikoites,fpres); //Paizoun oi 1 – 8, 2 – 7 3 – 6 ,  4 – 5
 
 



	fprintf( fpres,"\n(==========================================================================================================================)\n");// gia na ta bgalei mesa sto arxeio
 fprintf( fpres,"	  Apotelesmata  FINAL FOUR        ");
	fprintf( fpres,"\n(==========================================================================================================================)\n");
	printf( "\n(=================================)\n");// gia na ta bgalei mesa sto programma 
 printf( "    Apotelesmata  FINAL FOUR");
	printf( "\n(=================================)\n");
for(i=0; i<4; i++)
	{
		printf(  "\n Apotelesmata  %s  %s  %d %d %d  ", nikoites[i].name ,nikoites[i].xwra, nikoites[i].xwr_stadiou, nikoites[i].pith ,nikoites[i].sum_score); // gia na ta bgalei mesa sto programma tous 4eris nikites
		printf( "\n_____________________________________________________________________\n");

	 fprintf( fpres, "\n Apotelesmata  %s  %s  %d %d %d  ", nikoites[i].name ,nikoites[i].xwra, nikoites[i].xwr_stadiou, nikoites[i].pith ,nikoites[i].sum_score); // gia na ta bgalei mesa sto arxeio tous 4eris nikites 
		fprintf( fpres,"\n_____________________________________________________________________________________\n");

}

		two(nikoites,megalo,mikro,fpres ); //kaloume th sunartish  1 – 8 vs 4– 5 ------  2 – 7vs 3– 6 kai bgainoun 2 nikhtes duo hthmenoi.
		
	fprintf( fpres,"\n(==========================================================================================================================)\n");// gia na ta balei mesa sto arxeio
 fprintf( fpres,"	  					MEGALOS TELIKOS        ");
	fprintf( fpres,"\n(==========================================================================================================================)\n");
		
	
	 fprintf(fpres,"\n  %s  %s  %d %d %d  ", megalo[0].name ,megalo[0].xwra, megalo[0].xwr_stadiou, megalo[0].pith ,megalo[0].sum_score); // gia na ta balei mesa sto arxeio tous nikhtes  

		fprintf( fpres, "	VS	"); 

	 fprintf(fpres,"  %s  %s  %d %d %d  \n", megalo[1].name ,megalo[1].xwra, megalo[1].xwr_stadiou, megalo[1].pith ,megalo[1].sum_score);// gia na ta balei mesa sto arxeio tous nikhtes  

		
	fprintf( fpres,"\n(==========================================================================================================================)\n");
 fprintf( fpres,"	 					 MIKROS TELIKOS        ");
	fprintf( fpres,"\n(==========================================================================================================================)\n");
		
	fprintf( fpres, "\n  %s  %s  %d %d %d   ", mikro[0].name ,mikro[0].xwra, mikro[0].xwr_stadiou, mikro[0].pith ,mikro[0].sum_score);  // gia na ta balei mesa sto arxeio tous xamenous   

	 fprintf( fpres, "	VS	"); 


	 fprintf( fpres, "  %s  %s  %d %d %d   \n", mikro[1].name ,mikro[1].xwra, mikro[1].xwr_stadiou, mikro[1].pith ,mikro[1].sum_score); // gia na ta balei mesa sto arxeio tous xamenous   


		

telikos(megalo,first,sec,fpres);
mikr_telikos(mikro,third,four,fpres);

  i=0;						//apo dw kai katw emfanizei tis telikes vathmologies mia sto programma kai mia sto arxeio  mias kai eiani protathima prepei na bgei enas nikhths 2h thesh 3h kai 4h.  
	fprintf( fpres,"\n(==========================================================================================================================)\n");
 fprintf( fpres,"	  			TELIKH BATHMOLOGIA       ");
	fprintf( fpres,"\n(==========================================================================================================================)\n");
		printf( "\n(========================================)\n");
 printf( "		TELIKH BATHMOLOGIA");
	printf( "\n(============================================)\n");
		printf("\n 1os  %s  %s  %d %d %d  ", first[i].name ,first[i].xwra, first[i].xwr_stadiou, first[i].pith ,first[i].sum_score);
				printf("\n_____________________________________________________________________________________\n");
 
		printf("\n 2os  %s  %s  %d %d %d  ", sec[i].name ,sec[i].xwra, sec[i].xwr_stadiou, sec[i].pith ,sec[i].sum_score);
			printf( "\n_____________________________________________________________________________________\n");
 
		printf("\n 3os  %s  %s  %d %d %d  ", third[i].name ,third[i].xwra, third [i].xwr_stadiou, third[i].pith ,third[i].sum_score); 
				printf( "\n_____________________________________________________________________________________\n");

		printf("\n 4os  %s  %s  %d %d %d  ", four[i].name ,four[i].xwra, four[i].xwr_stadiou, four[i].pith ,four[i].sum_score); 
		printf( "\n_____________________________________________________________________________________\n");

	
	fprintf(fpres,"\n			 1os  %s  %s  %d %d %d  ", first[i].name ,first[i].xwra, first[i].xwr_stadiou, first[i].pith ,first[i].sum_score);
				fprintf( fpres,"\n_____________________________________________________________________________________\n");
 
	fprintf(fpres,"\n			 2os  %s  %s  %d %d %d  ", sec[i].name ,sec[i].xwra, sec[i].xwr_stadiou, sec[i].pith ,sec[i].sum_score);
				fprintf( fpres,"\n_____________________________________________________________________________________\n");
 
	fprintf(fpres,"\n			 3os  %s  %s  %d %d %d  ", third[i].name ,third[i].xwra, third [i].xwr_stadiou, third[i].pith ,third[i].sum_score); 
				fprintf( fpres,"\n_____________________________________________________________________________________\n");

	fprintf(fpres,"\n			 4os  %s  %s  %d %d %d  ", four[i].name ,four[i].xwra, four[i].xwr_stadiou, four[i].pith ,four[i].sum_score); 
			fprintf( fpres,"\n_____________________________________________________________________________________\n");

fclose(fpres);







	}



void  ektos_scor (omada omad [] ,int num , FILE *fpres)  //ta match olwn entos kai ektos gipedoy

{	fprintf( fpres,"\n				   |PRWTH FASH|					"); 
	fprintf(fpres, "\n\n(==========================================================================================================================)"); 
	fprintf( fpres,"\n\n 				   Agwnes Ektos					");
	fprintf(fpres, "\n\n(==========================================================================================================================)"); 
int da,fa;
   srand(time(NULL)); // kanei xrhsh tou rologiou tou upologisth gia thn epilgh tou arithmou.
	int first,sec, is_first , is_sec; int i,j;
		for (i=0; i<num; i++){
			omad[i].score_ebale=0; omad[i].score_efage=0;  omad[i].sun_score=0;
		
				for (j=num-1; j>=0; j--){
					omad[i].score_ebale=0; 
							omad[i].score_efage=0;  
								omad[i].sun_score=0;
									omad[j].score_ebale=0; 
							omad[j].score_efage=0;  
								omad[j].sun_score=0;
								
								
								
						first= 50 + rand() % (1 + omad[i].pith/2) ;
							sec= 50 + rand() % (1 + omad[j].pith/2) ;
							if ( omad[i].name != omad[j].name  && omad[i].xwra != omad[j].xwra  && omad[i].xwr_stadiou != omad[j].xwr_stadiou  && omad[i].pith != omad[j].pith )
		{

	 		if (first>sec)          // se periptwh pou h kuria  omada  sthn periptwsh mas paizei me tis upolipes exei  megalhterh bathmologia mesw rand  ara pairnei pontous  
				{
	 				omad[i].score_ebale+=2;
	 				 omad[j].score_efage+=1;   
				}
				else if  (first<sec ) // se periptwh pou h kuria  omada  sthn periptwsh mas paizei me tis upolipes exei  mikroterh  bathmologia mesw rand  ara pairnei pontous 
						{	
			 				omad[j].score_ebale+=2;
							 	omad[i].score_efage+=1;
			 			}
						else           // seperiptwsh pou einai ises h bathmologies mesw ths rand 
							{
								is_first= 1 + rand( ) % 2;
									is_sec= 1 + rand( ) % 2;
							
							if (is_first>is_sec)
												{
													omad[i].score_ebale+=1;
	 							 						omad[j].score_efage+=2; 
												 }		 	
												 else {
	
															omad[j].score_ebale+=1;
																omad[i].score_efage+=2;	 
				 									  }
													   }
										}
									omad[i].sum_score += omad[i].score_ebale+omad[i].score_efage +omad[i].sun_score; //kanoume sum gia na kratame to sunoliko score gia thn katataxh .
							 omad[j].sum_score =omad[j].sum_score+ omad[j].score_ebale+omad[j].score_efage +omad[j].sun_score;	
				fprintf( fpres,"\n	-Omades-	%s %d Score:%d ",   omad[i].name ,omad[j].pith, (omad[i].score_ebale + omad[i].score_efage + omad[i].sun_score), omad[i].sum_score ); //topothtoume sto arxeio ta kathe match pou ginetai  
		fprintf( fpres," --------	%s %d Score:%d  ", omad[j].name ,omad[j].pith, (omad[j].score_ebale+omad[j].score_efage +omad[j].sun_score )   ); 
		fprintf(fpres, "\n______________________________________________________________________________________________________________________"); 
						
						 	
							 
							
																					}
										
																								}
	fprintf(fpres, "\n\n(==========================================================================================================================)"); 
		fprintf( fpres,"\n				Agwnes Entos					");
	fprintf(fpres, "\n\n(==========================================================================================================================)"); 

	for (i=0; i<num; i++){
		omad[i].score_ebale=0; omad[i].score_efage=0;  omad[i].sun_score=0;omad[i].score_ebale=0; omad[i].score_efage=0;  omad[i].sun_score=0;

}
	for (i=0; i<num; i++){
		omad[i].score_ebale=0; //mhdenizoume ta scores gia na baloume ta nea scores 
							omad[i].score_efage=0;  
								omad[i].sun_score=0;

			for (j=num-1; j>=0; j--){
					omad[i].score_ebale=0; 
							omad[i].score_efage=0;  
								omad[i].sun_score=0;							//mhdenizoume ta scores gia na mpoune tou epomenou match. 
									omad[j].score_ebale=0; 
							omad[j].score_efage=0;  
								omad[j].sun_score=0;
								
	

				first= 50 + rand() % (1 + omad[i].pith/2) ;
						sec= 50 + rand() % (1 + omad[j].pith/2) ;
	if ( omad[i].name != omad[j].name  && omad[i].xwra != omad[j].xwra  && omad[i].xwr_stadiou != omad[j].xwr_stadiou  && omad[i].pith != omad[j].pith )
			{
				if(omad[i].xwr_stadiou>=10  && omad[i].xwra != omad[j].xwra ) //se periptwsh pou exei xwristikothta stadiou to  Bonus 
					{
						if	(omad[i].xwr_stadiou>15)
								omad[i].sun_score+=5;
			
						else	
								omad[i].sun_score+=3;
		
					}
	if (first>sec)                          	// se periptwh pou h kuria  omada  sthn periptwsh mas paizei me tis upolipes exei  megalhterh bathmologia mesw rand  ara pairnei pontous  
		{		
		omad[i].score_ebale+=2;
		 	 omad[j].score_efage+=1;   
		}
	else if  (first<sec ){					// se periptwh pou h kuria  omada  sthn periptwsh mas paizei me tis upolipes exei  mikroterh  bathmologia mesw rand  ara pairnei pontous 
	 
			 omad[j].score_ebale+=2;
				 omad[i].score_efage+=1;
			 }
	else {                  					// se periptwh pou einai ises oi pithanitites mesw ths rand 
	
	is_first= 1 + rand( ) % 2;
	is_sec= 1 + rand( ) % 2;		 
	if (is_first>is_sec){
	
			omad[i].score_ebale+=1;
	 			 omad[j].score_efage+=2; 
				  
						 }		 	
	else {
	
			omad[j].score_ebale+=1;
			omad[i].score_efage+=2;	 
				 
				 
	}		

				 
				 
				 
				 }
	
				
							
								}		
			omad[i].sum_score +=omad[i].score_ebale+omad[i].score_efage +omad[i].sun_score;	 //kanoume sum gia na kratame to sunoliko score gia thn katataxh .
				omad[j].sum_score +=omad[j].score_ebale+omad[j].score_efage +omad[j].sun_score;
					fprintf( fpres,"\n	-Omades-	%s %d Score:%d ",   omad[i].name ,omad[j].pith, (omad[i].score_ebale + omad[i].score_efage + omad[i].sun_score) ); //topothtoume sto arxeio ta kathe match pou ginetai 
						fprintf( fpres," --------	%s %d Score:%d  ", omad[j].name ,omad[j].pith, (omad[j].score_ebale+omad[j].score_efage +omad[j].sun_score) ); 
							fprintf(fpres, "\n______________________________________________________________________________________________________________________"); 
											

							}
		 
		 	}
			


}

void sel_sort(omada omad [] , int size)  //sinartisi katanomis 
{
int i, j ,diaf1,diaf2;
struct omada temp;
for (i = 0; i < size; i++)
{
for (j = i + 1; j <size; j++)
{
if (omad[i].sum_score > omad[j].sum_score)
	{
temp = omad[i];
omad[i] = omad[j];
omad[j] = temp;
	}
if (omad[i].sum_score==omad[j].sum_score)	
	{
	diaf1=omad[i].score_ebale-omad[i].score_efage;
	diaf2=omad[j].score_ebale-omad[j].score_efage;
	}
	
	if (diaf1<diaf2)
	{temp = omad[i];
omad[i] = omad[j];
omad[j] = temp;	
	
}
	
	else 
	{
temp = omad[j];
omad[j] = omad[i];
omad[i] = temp;

		}



}
}
}


 	void prok(omada oxt [],omada nikoites[] , FILE *fpres) //sinartisi oxtadas 
			
{

	fprintf(fpres, "\n\n(==========================================================================================================================)"); 
		fprintf( fpres,"\n				PROKRIMATIKOI GIA FINAL FOUR 					");
	fprintf(fpres, "\n\n(==========================================================================================================================)"); 
   srand(time(NULL)); 

int i,j=7,first,sec,is_first,is_sec; 
			  
	for(i=0; i<4; i++)
	{  
		
		if(oxt[i].xwr_stadiou>=10  && oxt[i].xwra != oxt[j].xwra ) // bonus pontoi gia tou prwtous me xwritikothta stadiou 
 	{
		if	(oxt[i].xwr_stadiou>15)
			oxt[i].sun_score+=5;
		
		else	
		oxt[i].sun_score+=3;
	
			} 
			first= 50 + rand() % (1 + oxt[i].pith/2) ;
					sec= 50 + rand() % (1 + oxt[j].pith/2) ;
					
	if (first>sec)
				{
	 			 		nikoites[i]=oxt[i];
						  	  
				}
				else if  (first<sec )
						{	
			 				nikoites[i] =oxt[j];	
			 			}
						else 
							{
								is_first= 1 + rand( ) % 2;
									is_sec= 1 + rand( ) % 2;
							}
							if (is_first>is_sec)
												{
											nikoites[i]=oxt[j];	 
												 }		 	
												 else {
													nikoites[i]=oxt[i] ;
															
				 									  }
		 									  
				 									  
				 									  
				 									  
				 									  
		fprintf( fpres,"\n		Omada [%d]	%s	%d  ", i+1,  oxt[i].name  , oxt[i].pith ); 
		fprintf( fpres,"	Omada [%d] --------   %d	%s ", j+1,   oxt[j].pith , oxt[j].name  ); 
		fprintf(fpres, "\n______________________________________________________________________________________________________________________"); 
					 									  
	j--;
			
	}
		
}		











 void two (omada nikoites [],omada megalo  [],omada mikro [] , FILE *fpres)//sinartisi gia na doyme poioi einai oi nikites kai poioi oi ittimenoi
			
{
		fprintf(fpres, "\n\n(==========================================================================================================================)"); 
		fprintf( fpres,"\n				 FINAL FOUR 					");
int i;
	fprintf(fpres, "\n\n(==========================================================================================================================)"); 
   srand(time(NULL)); 

 int j=3,first,sec,is_first,is_sec; 


	for(i=0; i<2; i++)
		
	{
			first= 50 + rand() % (1 + nikoites[i].pith/2) ;
					sec= 50 + rand() % (1 + nikoites[j].pith/2) ;
					
					
						if (first>sec)
					{	
	 				 	megalo[i]=nikoites[i];
							  mikro[i]=nikoites[j];		  
					}
				else if  (first<sec )
							{	
			 					 megalo[i]=nikoites[j];	
			 					 mikro[i]=nikoites[i];
			 				}
						else 
							{
								is_first= 1 + rand( ) % 2;
									is_sec= 1 + rand( ) % 2;
							}
							if (is_first>is_sec)
												{
							megalo[i]=nikoites[j];	
			 					 mikro[i]=nikoites[i];
												 }		 	
												 else {
														megalo[i]=nikoites[i];
															  mikro[i]=nikoites[j];		
				 																	  }
			 									  
				 									  
		fprintf( fpres,"\n		Omada [%d]	%s	%d  ", i+1,  nikoites[i].name  , nikoites[i].pith ); 
		fprintf( fpres,"	Omada [%d] --------   %d	%s ", j+1,  nikoites[j].pith , nikoites[j].name   ); 
		fprintf(fpres, "\n______________________________________________________________________________________________________________________"); 
			
	j--;
	
	}
		
}


 	void telikos (omada megalo  [],omada first [] ,omada sec [],FILE *fpres) //to match twn nikitwn
			
{   srand(time(NULL)); 

int i=0  , j=1 , fir, ssec, is_first,is_sec; 
	
			fir= 50 + rand() % (1 + megalo[i].pith/2) ;
					ssec= 50 + rand() % (1 + megalo[j].pith/2) ;
						if (fir>ssec)
					{
	 				 	first[i]=megalo[i];
							  sec[i]=megalo[j];		  
					}
				else if  (fir<ssec )
							{	
			 					 first[i]=megalo[j];	
			 					 sec[i]=megalo[i];
			 				}
						else 
							{
								is_first= 1 + rand( ) % 2;
									is_sec= 1 + rand( ) % 2;
							}
							if (is_first>is_sec)
												{
											first[i]=megalo[j];	
			 					 				sec[i]=megalo[i];
												 }		 	
												 else {
														first[i]=megalo[i];
															  sec[i]=megalo[j];		
				 																	  }

	

}



	void  mikr_telikos (omada mikro  [],omada third[] ,omada four[],FILE *fpres) //to match twn ittimenwn
			
{   srand(time(NULL)); 

	
	
int i=0, j=1 , fir, ssec ,is_first,is_sec; 
	
			fir= 50 + rand() % (1 + mikro[i].pith/2) ;
					ssec= 50 + rand() % (1 + mikro[j].pith/2) ;
						if (fir>ssec)
					{
	 				 	third[i]= mikro[i];
							  four[i]= mikro[j];		  
					}
				else if  (fir<ssec )
							{	
			 					 third[i]=mikro[j];	
			 					 four[i]=mikro[i];
			 				}
						else 
							{
								is_first= 1 + rand( ) % 2;
									is_sec= 1 + rand( ) % 2;
							}
							if (is_first>is_sec)
												{
											third[i]=mikro[j];	
			 					 				four[i]=mikro[i];
												 }		 	
												 else {
														third[i]=mikro[i];
															  four[i]=mikro[j];		
				 																	  }

	

}
