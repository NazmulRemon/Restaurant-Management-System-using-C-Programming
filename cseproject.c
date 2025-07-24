#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user{
    char name[50];
    char cellphone[20];
    char item[30][50];
    float price[10];
    int quantity[10];
}details[50];

float bill(float price[], int quantity){

    if(quantity<=0)
        return 0;
    else{
        return bill(price,quantity-1)+price[quantity-1];
    }

}

int main(){

    int i=1,c,j,k,f;
    float itemprice[50],totalbill;
    char menu;
    FILE *file1, *file2;

    if((file2=fopen("details.txt", "w"))==NULL){
        printf("Couldn't write the file.");
        exit(1);
        }

    for(c=0;c<50;c++){
        printf("Enter your name please: \n");
        fflush(stdin);
        gets(details[c].name);
        printf("Enter your cell phone no.: \n");
        fflush(stdin);
        scanf("%s", details[c].cellphone);
        printf("Here's the menu: \n");
        if((file1=fopen("menu.txt", "r"))==NULL){
        printf("Couldn't read the file.");
        exit(1);
        }
        while((menu=fgetc(file1))!=EOF){
            printf("%c", menu);
        }

        printf("\n");

        for(j=0; i==1;j++){
            printf("Item? ");
            fflush(stdin);
            fgets(details[c].item[j], sizeof(details[c].item[j]), stdin);
            printf("price? ");
            fflush(stdin);
            scanf("%f", &details[c].price[j]);
            printf("Quantity? ");
            fflush(stdin);
            scanf("%d", &details[c].quantity[j]);
            printf("Want to buy more items (For Yes: press 1, For No: press 0): ");
            scanf("%d", &i);
        }

        printf("All details are: \n");
        printf("Name: %s\n", details[c].name);
        printf("Cell phone: %s\n", details[c].cellphone);

        for(k=0;k<j;k++){
            printf("%s\n", details[c].item[k]);
            printf("%10.2f", details[c].price[k]);
            printf("%10d\n", details[c].quantity[k]);
            itemprice[k]=details[c].price[k]*details[c].quantity[k];
        }

        totalbill=bill(itemprice,j);

        printf("Your bill is: %10.2f\n",totalbill);
        printf("Want to devide in friends (press 1 for yes): ");
        scanf("%d", &i);
        if(i==1){
        printf("How many friends? ");
        scanf("%d", &f);
        printf("Each friend will have to pay: %.2f\n", totalbill/f);
        }
        printf("Your food will be served within 10-15 minutes. Have a happy meal!!!\n");

        fprintf(file2,"All details are: \n");
        fprintf(file2,"Name: %s\n", details[c].name);
        fprintf(file2,"Cell phone: %s\n", details[c].cellphone);

        for(k=0;k<j;k++){
            fprintf(file2,"%s\n", details[c].item[k]);
            fprintf(file2,"%10.2f", details[c].price[k]);
            fprintf(file2,"%10d\n", details[c].quantity[k]);

        }

        fprintf(file2,"Bill : %10.2f\n", totalbill);
        fprintf(file2,"Each friend will have to pay: %.2f\n", totalbill/f);

        printf("New customer? (Press 1 for yes or 0 for no): ");
        scanf("%d", &i);
        if(i==0)
            break;
    }

    fclose(file1);
    fclose(file2);

return 0;
}
