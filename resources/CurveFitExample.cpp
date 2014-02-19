/*
This sample is from
http://www.dailyfreecode.com/code/fitting-straight-line-exponential-2941.aspx
edited to accomodate C++ standards.
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<cstdlib>
#define MAX 10

void slm(FILE *);
void expcurve(FILE *);
void geocurve(FILE *);
void hyperbola(FILE *);
void polynomial(FILE *);

int main()
{
    FILE *fp;
    int i,choice,number;
    float xvalue[MAX],yvalue[MAX];
    fp=fopen("curfitt.dat","w");
    system("cls"); // clrscr();
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("MAIN  MENU                      ");
    fprintf(fp,"MAIN  MENU                      ");
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("\n1.Fitting a Straight line     ");
    fprintf(fp,"\n1.Fitting a Straight line     ");
    printf("\n2.Fitting a Exponential curve ");
    fprintf(fp,"\n2.Fitting a Exponential curve ");
    printf("\n3.Fitting a Geometric curve   ");
    fprintf(fp,"\n3.Fitting a Geometric curve   ");
    printf("\n4.Fitting a Hyperbola         ");
    fprintf(fp,"\n4.Fitting a Hyperbola         ");
    printf("\n5.Fitting a Polynomial        ");
    fprintf(fp,"\n5.Fitting a Polynomial        ");
    printf("\n6.Exit                        ");
    fprintf(fp,"\n6.Exit                        ");
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("\nEnter your choice   :         ");
    fprintf(fp,"\nEnter your choice   :         ");
    scanf("%d",&choice);
    fprintf(fp,"%d",choice);
    switch(choice)
    {
        case 1 : slm(fp);
             break;
        case 2 : expcurve(fp);
             break;
        case 3 : geocurve(fp);
             break;
        case 4 : hyperbola(fp);
             break;
        case 5 : polynomial(fp);
             break;
        case 6 : exit(1);
             break;
    }
    fclose(fp);
    getch();
    return 0; // BECAUSE FUCK YOU C++
}

void slm(FILE *fp)
{
    int i,number;
    float sumx=0,sumy=0,xvalue[MAX],yvalue[MAX];
    float productxy[MAX],sumxy=0,square[MAX],sumx2=0;
    float denominator,a,b;
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("Enter how many values you want for (x,y) :   ");
    fprintf(fp,"Enter how many values you want for (x,y) :   ");
    scanf("%d",&number);
    fprintf(fp,"%d",number);
    for(i=0;i<number;i++)
    {
        printf("\nEnter value for x(%d) :  ",i);
        fprintf(fp,"\nEnter value for x(%d) :  ",i);
        scanf("%f",&xvalue[i]);
        fprintf(fp,"%f",xvalue[i]);
    }
    printf("\n\n");
    fprintf(fp,"\n\n");
    for(i=0;i<number;i++)
    {
        printf("\nEnter value for y(%d) :  ",i);
        fprintf(fp,"\nEnter value for y(%d) :  ",i);
        scanf("%f",&yvalue[i]);
        fprintf(fp,"%f",yvalue[i]);
    }
    for(i=0;i<number;i++)
    {
        sumx=sumx+xvalue[i];
    }
    for(i=0;i<number;i++)
    {
        sumy=sumy+yvalue[i];
    }
    for(i=0;i<number;i++)
    {
        productxy[i]=xvalue[i]*yvalue[i];
        sumxy=sumxy+productxy[i];
    }
    for(i=0;i<number;i++)
    {
        square[i]=xvalue[i]*xvalue[i];
        sumx2=sumx2+square[i];
    }
    system("cls"); // clrscr();
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("STRAIGHT LINE MEHTOD                        ");
    fprintf(fp,"STRAIGHT LINE MEHTOD                        ");
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("  x        y         Ex2            Exy  ");
    fprintf(fp,"  x        y         Ex2            Exy  ");
    printf("\n\n");
    fprintf(fp,"\n\n");
    for(i=0;i<number;i++)
    {
        printf( "%0.2f     %0.2f        %.2f         %.2f  ",xvalue[i],yvalue[i],square[i],productxy[i]);
        fprintf(fp, "%0.2f     %0.2f        %.2f         %.2f  ",xvalue[i],yvalue[i],square[i],productxy[i]);
        printf("\n");
        fprintf(fp,"\n");
    }
    denominator=(number*sumx2)-(sumx*sumx);
    a=(sumy*sumx2)-(sumx*sumxy)/denominator;
    b=((number*sumxy)-(sumx*sumy))/denominator;
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("The equation is             :   ");
    fprintf(fp,"The equation is             :   ");
    printf("  y = %.2fx + %.2f  ",b,a);
    fprintf(fp,"  y = %.2fx + %.2f  ",b,a);

}

void expcurve(FILE *fp)
{

    int i,number;
    float xvalue[MAX],yvalue[MAX],sumx=0,sumlogy=0;
    float productxlogy[MAX],sumxlogy=0,square[MAX],sumx2=0;
    float denominator,a,b,c;
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("Enter how many values you want for (x,y) :   ");
    fprintf(fp,"Enter how many values you want for (x,y) :   ");
    scanf("%d",&number);
    fprintf(fp,"%d",number);
    for(i=0;i<number;i++)
    {
        printf("\nEnter value for x(%d) :  ",i);
        fprintf(fp,"\nEnter value for x(%d) :  ",i);
        scanf("%f",&xvalue[i]);
        fprintf(fp,"%f",xvalue[i]);
    }
    printf("\n\n");
    fprintf(fp,"\n\n");
    for(i=0;i<number;i++)
    {
        printf("\nEnter value for y(%d) :  ",i);
        fprintf(fp,"\nEnter value for y(%d) :  ",i);
        scanf("%f",&yvalue[i]);
        fprintf(fp,"%f",yvalue[i]);
    }
    for(i=0;i<number;i++)
    {
        sumx=sumx+xvalue[i];
    }
    for(i=0;i<number;i++)
    {
        sumlogy=sumlogy+log(yvalue[i]);
    }
    printf("\nsumlogy=%.4f ",sumlogy);
    for(i=0;i<number;i++)
    {
        productxlogy[i]=xvalue[i]*log(yvalue[i]);
        sumxlogy=sumxlogy+productxlogy[i];
    }
    printf("\n%.4f ",sumxlogy);
    for(i=0;i<number;i++)
    {
        square[i]=xvalue[i]*xvalue[i];
        sumx2=sumx2+square[i];
    }
    system("cls"); // clrscr();
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("EXPONENTIAL CURVE MEHTOD                 ");
    fprintf(fp,"EXPONENTIAL CURVE MEHTOD                 ");
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("  x        y              Ex2             Exlogy  ");
    fprintf(fp,"  x        y              Ex2             Exlogy  ");
    printf("\n\n");
    fprintf(fp,"\n\n");
    for(i=0;i<number;i++)
    {
        printf( "%0.2f     %0.2f        %.2f         %.2f  ",xvalue[i],yvalue[i],square[i],productxlogy[i]);
        fprintf(fp, "%0.2f     %0.2f        %.2f         %.2f  ",xvalue[i],yvalue[i],square[i],productxlogy[i]);
        printf("\n");
        fprintf(fp,"\n");
    }
    denominator=(number*sumx2)-(sumx*sumx);
    c=((sumlogy*sumx2)-(sumx*sumxlogy))/denominator;
    b=((number*sumxlogy)-(sumx*sumlogy))/denominator;
    a=exp(c);
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("The equation is       :   ");
    fprintf(fp,"The equation is       :   ");
    printf("    y = %.4fe^%.4fx    ",a,b);
    fprintf(fp,"    y = %.4fe^%.4fx    ",a,b);

}

void geocurve(FILE *fp)
{
    int i,number;
    float sumlogx=0,sumlogy=0,xvalue[MAX],yvalue[MAX];
    float productlogxlogy[MAX],sumlogxlogy=0,square[MAX],sumlogx2=0;
    float denominator,a,b,c;
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("Enter how many values you want for (x,y) :   ");
    fprintf(fp,"Enter how many values you want for (x,y) :   ");
    scanf("%d",&number);
    fprintf(fp,"%d",number);
    for(i=0;i<number;i++)
    {
        printf("\nEnter value for x(%d) :  ",i);
        fprintf(fp,"\nEnter value for x(%d) :  ",i);
        scanf("%f",&xvalue[i]);
        fprintf(fp,"%f",xvalue[i]);
    }
    printf("\n\n");
    fprintf(fp,"\n\n");
    for(i=0;i<number;i++)
    {
        printf("\nEnter value for y(%d) :  ",i);
        fprintf(fp,"\nEnter value for y(%d) :  ",i);
        scanf("%f",&yvalue[i]);
        fprintf(fp,"%f",yvalue[i]);
    }
    for(i=0;i<number;i++)
    {
        sumlogx=sumlogx+log(xvalue[i]);
    }
    for(i=0;i<number;i++)
    {
        sumlogy=sumlogy+log(yvalue[i]);
    }
    for(i=0;i<number;i++)
    {
        productlogxlogy[i]=log(xvalue[i])*log(yvalue[i]);
        sumlogxlogy=sumlogxlogy+productlogxlogy[i];
    }
    for(i=0;i<number;i++)
    {
        square[i]=log(xvalue[i])*log(xvalue[i]);
        sumlogx2=sumlogx2+square[i];
    }
    system("cls"); // clrscr();
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("GEOMETRIC CURVE MEHTOD                 ");
    fprintf(fp,"GEOMETRIC CURVE MEHTOD                 ");
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("  x        y           Elogx2           Elogxlogy  ");
    fprintf(fp,"  x        y           Elogx2           Elogxlogy  ");
    printf("\n\n");
    fprintf(fp,"\n\n");
    for(i=0;i<number;i++)
    {
        printf( "%0.2f     %0.2f        %.2f         %.2f  ",xvalue[i],yvalue[i],square[i],productlogxlogy[i]);
        fprintf(fp, "%0.2f     %0.2f        %.2f         %.2f  ",xvalue[i],yvalue[i],square[i],productlogxlogy[i]);
        printf("\n");
        fprintf(fp,"\n");
    }
    denominator=(number*sumlogx2)-(sumlogx*sumlogx);
    c=((sumlogy*sumlogx2)-(sumlogx*sumlogxlogy))/denominator;
    b=((number*sumlogxlogy)-(sumlogx*sumlogy))/denominator;
    a=exp(c);
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("The equation is       :   ");
    fprintf(fp,"The equation is       :   ");
    printf("    y = %.2fx^%.2f    ",a,b);
    fprintf(fp,"    y = %.2fx^%.2f    ",a,b);

}

void hyperbola(FILE *fp)
{
    int i,number;
    float denominator,a,b,xvalue[MAX],yvalue[MAX];
    float sumx=0,square[MAX],sumx2=0,denomy[MAX],sumdenomy=0;
    float productxy[MAX],sumxy=0;
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("Enter how many values you want for (x,y) :   ");
    fprintf(fp,"Enter how many values you want for (x,y) :   ");
    scanf("%d",&number);
    fprintf(fp,"%d",number);
    for(i=0;i<number;i++)
    {
        printf("\nEnter value for x(%d) :  ",i);
        fprintf(fp ,"\nEnter value for x(%d) :  ",i);
        scanf("%f",&xvalue[i]);
        fprintf(fp,"%f",xvalue[i]);
    }
    printf("\n\n");
    fprintf(fp,"\n\n");
    for(i=0;i<number;i++)
    {
        printf("\nEnter value for y(%d) :  ",i);
        fprintf(fp,"\nEnter value for y(%d) :  ",i);
        scanf("%f",&yvalue[i]);
        fprintf(fp,"%f",yvalue[i]);
    }
    for(i=0;i<number;i++)
    {
        sumx=sumx+xvalue[i];
    }
    for(i=0;i<number;i++)
    {
        square[i]=xvalue[i]*xvalue[i];
        sumx2=sumx2+square[i];
    }
    for(i=0;i<number;i++)
    {
           denomy[i]=1/yvalue[i];
           sumdenomy=sumdenomy+denomy[i];
    }
    for(i=0;i<number;i++)
    {
        productxy[i]=xvalue[i]*denomy[i];
        sumxy=sumxy+productxy[i];
    }
    system("cls"); // clrscr();
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("HYPERBOLA CURVE MEHTOD                 ");
    fprintf(fp,"HYPERBOLA CURVE MEHTOD                 ");
    printf("\n\n");
    printf("  x        y          Elogx2           Elogx/y   ");
    fprintf(fp,"  x        y          Elogx2           Elogx/y   ");
    printf("\n\n");
    fprintf(fp,"\n\n");
    for(i=0;i<number;i++)
    {
        printf( "%0.2f     %0.2f        %.2f         %.2f   ",xvalue[i],yvalue[i],square[i],productxy[i]);
        fprintf(fp, "%0.2f     %0.2f        %.2f         %.2f   ",xvalue[i],yvalue[i],square[i],productxy[i]);
        printf("\n");
        fprintf(fp,"\n");
    }
    denominator=(number*sumx2)-(sumx*sumx);
    b=((number*sumxy)-(sumx*sumdenomy))/denominator;
    a=((sumdenomy*sumx2)-(sumx*sumxy))/denominator;
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("The equation is       ");
    fprintf(fp,"The equation is       ");
    printf("     y = 1/( %.3f + %.3fx )      ",a,b);
    fprintf(fp,"     y = 1/( %.3f + %.3fx )      ",a,b);

}

void polynomial(FILE *fp)
{
    int  degree,i,j,k,l,number;
    float z[MAX][MAX+1],a[MAX];
    float temp,sum;
    float denominator,b,xvalue[MAX],yvalue[MAX];
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("Enter how many values you want for (x,y) :   ");
    fprintf(fp,"Enter how many values you want for (x,y) :   ");
    scanf("%d",&number);
    fprintf(fp,"%d",number);
    for(i=0;i<number;i++)
    {
        printf("\nEnter value for x(%d) :  ",i);
        fprintf(fp,"\nEnter value for x(%d) :  ",i);
        scanf("%f",&xvalue[i]);
        fprintf(fp,"%f",xvalue[i]);
    }
    printf("\n\n");
    fprintf(fp,"\n\n");
    for(i=0;i<number;i++)
    {
        printf("\nEnter value for y(%d) :  ",i);
        fprintf(fp,"\nEnter value for y(%d) :  ",i);
        scanf("%f",&yvalue[i]);
        fprintf(fp,"%f",yvalue[i]);
    }
    printf("\nEnter the highest degree of the polynomial  :");
    fprintf(fp,"\nEnter the highest degree of the polynomial  :");
    scanf("%d",&degree);
    fprintf(fp,"%f",degree);
    for(i=0;i<=degree;i++)
    {
        for(j=0;j<=degree;j++)
        {
            z[i][j]=0;
            for(k=0;k<number;k++)
            {
                if(i==0 && j==0)
                {
                    z[i][j]=0;
                    break;
                }
                else if (j==degree+1)
                    z[i][j]=z[i][j]+pow(xvalue[k],i)*yvalue[k];
                else
                    z[i][j]=z[i][j]+pow(xvalue[k],j+1);
            }
            printf("\nz[%d][%d]=%.3f",i,j,z[i][j]);
            fprintf(fp,"\nz[%d][%d]=%.3f",i,j,z[i][j]);
        }
    }
    for(j=0;j<degree;j++)
    {
        for(i=j+1;i<=degree;i++)
        {
            temp=z[i][j]/z[j][j];
            for(k=j;k<=degree;k++)
            {
                z[i][k]=z[i][k]-(temp*z[j][k]);
            }
        }
    }
    a[degree]=z[degree][degree+1]/z[degree][degree];

    for(i=degree-1;i>=0;i--)
    {
        sum=0;
        for(j=i+1;j<=degree;j++)
        {
            sum=sum+(z[i][j]*a[j]);
        }
        a[i]=(z[i][degree+1]-sum)/z[i][i];
        printf("%.3f",a[i]);
        fprintf(fp,"%.3f",a[i]);
        if(i!=0)
        {
            printf("* X^%d + ",i);
            fprintf(fp,"* X^%d + ",i);
        }
    }
    printf("\n\n");
    fprintf(fp,"\n\n");
}
