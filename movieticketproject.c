#include<stdio.h>
#include <stdbool.h>
#include<string.h>

struct showTime{
    char seats[7][10];
};
char seatNames[50];

void allocateSeat(char seat[7][10]){
    char seatRow = 'A';
    for(int i=0;i<7;i++){
		for(int j=0;j<10;j++){
			if(j==0){
				seat[i][j] = seatRow;
				seatRow++;
			}
			else{
				seat[i][j] = (48+j);
			}
		}
	}
}

void generateTicket(int nos, char seatName[], char timing[10]){
    printf("\n\t           Your Ticket           \n");
    printf("\n\t --------------------------------");
    printf("\n\t|          ABC CINEMAS           |");
    printf("\n\t|--------------------------------|");
    printf("\n\t|                                |");
    printf("\n\t| Movie name      : XYZ          |");
    printf("\n\t| Show Time       : %s      |",timing);
    printf("\n\t| No. of Seats    : %d            |",nos);
    printf("\n\t| Seat Numbers    : %s",seatName);
    printf("\n\t| Ticket amount   : %d.00       |",nos * 120);
    if(nos == 1)
    printf("\n\t| Gst amount(5%%)  :   %d.00       |",(nos * 120 * 5)/100);
    else
    printf("\n\t| Gst amount(5%%)  :  %d.00       |",(nos * 120 * 5)/100);
    printf("\n\t| -------------------------      |");
    printf("\n\t| Total amount    : %d.00       |",((nos * 120 * 105)/100));
    printf("\n\t|                                |");
    printf("\n\t -------------------------------- \n");
}

char* bookSeats(char seat[7][10], int nos){
    int num = 1;
    while(nos){
        char seatNo[2]="";
        printf("Seat number %d : ",num++);
        scanf("%s",seatNo);
        strcat(seatNames,seatNo);
        if(nos!=1)
        strcat(seatNames,", ");
        int row = (int)seatNo[0]-65;
        int col = (int)seatNo[1]-48;
        seat[row][col]= '-';
        nos--;
    }
    printf("\n");
    return seatNames;
}

int payment(int nos, char seat[7][10]){
    int amount = nos * 120, payment;
    float gst = (amount * 5)/100;
    printf("\n\tTicket  amount  : \t%d.00",amount);
    if(amount == 120)
        printf("\n\tGst amount(5%%)  :   \t  %.2f",gst);
    else
        printf("\n\tGst amount(5%%)  :  \t %.2f",gst);
    printf("\n\t------------------------------");
    printf("\n\tTotal   amount  : \t%.2f",amount + gst);
    printf("\n\n\tConfirm Payment :\n\t[1] OK\t\t[2] Cancel\n");
    scanf("%d",&payment);
    if(payment == 1){
        printf("\n\tPayment Success\n");
        return 1;
    }
    else{
        allocateSeat(seat);
        printf("\n\tPayment Cancelled\n\n");
        return 0;
    }
}

// void receipt(int nos, )

void displaySeats(char seat[7][10]){
    for(int i=0;i<7;i++){
        printf("\t");
		for(int j=0;j<10;j++){
		    if(j==0)
		        printf("%c  ",seat[i][j]);
		    else
    			printf("%c ",seat[i][j]);
		}
		printf("\n");
	}
	printf("\n\t --- Screen Here ---\n\n");
}

void main(){
    
	struct showTime foreNoon;
	struct showTime afterNoon;
	struct showTime evening;
	struct showTime night;
	allocateSeat(foreNoon.seats);
	allocateSeat(afterNoon.seats);
	allocateSeat(evening.seats);
	allocateSeat(night.seats);

	start:
	printf("Welcome to Ticket Booking\n\n");
    int show,nos;
    char* seatName;
    char timing[10] ;
	while(1){
	    printf("Select your show time :- \n\n");
	    printf("\t(1) 10.30AM\t (2) 2.00PM\n\t(3) 5.30PM\t (4) 9.00PM\n\n");
	    printf("Enter your option : ");
	    scanf("%d",&show);
	    printf("\n");
	    
	    switch(show){
	        case 1:
	            printf("Showtime : 10.30AM\n\n");
	            displaySeats(foreNoon.seats);
	            printf("Enter number of seats : ");
	            scanf("%d",&nos);
	            seatName =  bookSeats(foreNoon.seats, nos);
	            displaySeats(foreNoon.seats);
	            if(payment(nos, foreNoon.seats)){
	                generateTicket(nos, seatName, "10.30AM");
	                goto finish;
	            }
	            else{
	                goto start;
	            }
	            
	            
	        case 2:
	            printf("Showtime : 02.00PM\n\n");
	            displaySeats(afterNoon.seats);
	            printf("Enter number of seats : ");
	            scanf("%d",&nos);
	            seatName =  bookSeats(afterNoon.seats, nos);
	            displaySeats(afterNoon.seats);
	            if(payment(nos, afterNoon.seats)){
	                generateTicket(nos, seatName, "02.00PM");
	                goto finish;
	            }
	            else{
	                goto start;
	            }
	        case 3:
	            printf("Showtime : 05.30PM\n\n");
	            displaySeats(evening.seats);
	            printf("Enter number of seats : ");
	            scanf("%d",&nos);
	            seatName =  bookSeats(evening.seats, nos);
	            displaySeats(evening.seats);
	            if(payment(nos, evening.seats)){
	                generateTicket(nos, seatName, "05.30PM");
	                goto finish;
	            }
	            else{
	                goto start;
	            }
	        case 4:
	            printf("Showtime : 09.00PM\n\n");
	            displaySeats(night.seats);
	            printf("Enter number of seats : ");
	            scanf("%d",&nos);
	            seatName =  bookSeats(night.seats, nos);
	            displaySeats(night.seats);
	            if(payment(nos, night.seats)){
	                generateTicket(nos, seatName, "09.00PM");
	                goto finish;
	            }
	            else{
	                goto start;
	            }
	       default:
	            printf("\nIncorrect option !!!\n\n");
	            continue;
	    }
	}
	finish:
	    printf("\n\tContinue booking ?\n\t[1] YES\t\t[2] NO\n");
	    int cont;
	    scanf("%d",&cont);
	    if(cont==1)
	        goto start;
	   else{
	       printf("\n\tThank you for booking");
	   }

}
