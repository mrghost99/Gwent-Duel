#include <stdio.h>
#include <time.h>
void ds(int q)
{
    // reading //
    int a,b,c,i,armor1,armor2,A,B,hp1,hp2;c=0;int d=1;int A1=0;int d2=0;int sabbath=0;int sb=0;int str=5;int d3=0;int d4=0;int red1=0;int red2=0;int cond1=1;int cond2=1;
        printf("\ngive first attacking unit  power= ");
          scanf(" %i",&a);
          printf("\ngive armor= ");
          scanf(" %i",&armor1);
          printf("\nis it this unit sabbath? yes=1 no=other #=");
          scanf("%d",&sb);
          if(sb==1)
              {
                  printf("\nit's strength (default is 5) ? =");
                  scanf("%d",&str);
              }
          if(sb!=1)
              {
                  printf("\ndoes the unit deal double dammage? yes=1 , no=other ,   #= ");
                  scanf(" %i",&d2);
                  printf("\nis this unit a Redanian Elite? yes=1 , no=other ,   #= ");
                  scanf("%d",&d3);
                  if(armor1==0)
                  {
                      d3=0;
                  }
              }
            printf("\ndueling Redanian Elite? yes=1 , no=other ,   #= ");
            scanf(" %i",&d4);
            if(d3==1) // A redanian elite
            {
            red1=5;
            }
            if(d4==1) // B redanian elite
            {
            red2=5;
            }
          printf("\ngive second attacking unit power= ");
          scanf(" %i",&b);
          printf("\ngive armor= ");
          scanf(" %d",&armor2);
          if(armor2==0)
                  {
                      d4=0;
                  }
          printf("\n RESULTS: \n");
          hp1=a+armor1; // defiening units health and saving their powers to calculate results
          hp2=b+armor2;
          B=b;
          A=a;
          if(d2==1) // double dammage
          {
              d=2;
          }

    // duel calc //
        while(hp1>0 && hp2>0)
        {
         c=c+1;
         if(hp1>a)
         {
             hp2=hp2-d*a;
         }
         else
         {
             a=hp1;
             armor1=0;
             hp2=hp2-d*a;
         }

        if(hp2>b)
        {
            armor2=armor2-d*a;
            hp1=hp1-b;
        }
        else
        {
            armor2=0;
            b=hp2;
            if(d4==1 && b>0 && cond2==1)
            {
                b=hp2+red2;
                hp2=b;
                cond2=0;
            }
            if(b>0)
            {
                hp1=hp1-b;
            }
        }
         if(hp1>a && b>0)
         {
             armor1=armor1-b;
         }
         else
         {
             if(hp1<a)
             {
                a=hp1;
                armor1=0;
                if(d3==1 && a>0 && cond1==1)
                  {
                    a=hp1+red1;
                    hp1=a;
                    cond1=0;
                  }
             }
         }
         if(b<=0)
         {
             hp2=0;
             b=0;
             if(sb==1)
             {
                 armor1=2;
             }
             if(a<str && sb==1)
             {
                sabbath=1;
                 if (a<str-1)
                 {
                     sabbath=2;
                 }
             }
         }
         if(a<=0)
         {
             hp1=0;
             a=0;
         }

          printf("DUEL %d a=%d armor=%d and b=%d armor=%d \n",c,a+sabbath,armor1,b,armor2);

        }
        printf("\nyour unit duels PTS = %d - Sabbath = %d , his side (eg:meditation) PTS = %d",a+B-b,a+sabbath+B-b,A+B-a-b);

}
void hduel(int k)
{
    // reading //
        int a,b,armor1,armor2,i,g,hp1,hp2,A,B,INvalue,INv,OUTvalue,OUTv,c,INar2,OUTar2;int AR1=0;int s=0; int j=0;int w=0;int red1,red2,cond1,cond2,d3,d4,D3,D4=0;
        INvalue=0;
        INar2=0;
        OUTvalue=0;
        c=0;
        int AR2=0;
        int ign=0;
        printf("\ngive the *SECOND* attacking unit details \n  ");
        printf("give power= ");
        scanf(" %i",&b);
        printf("\n give armor= ");
        scanf(" %i",&armor2);
        printf("\nis this unit a Redanian Elite? yes=1 , no=other ,   #= ");
        scanf("%d",&d3);
        hp2=b+armor2;B=b;AR2=armor2;i=0;
        printf("\ndueling Redanian Elite?( if yes it only shows redanian elites values ) yes=1 , no=other ,   #= ");
        scanf(" %i",&d4);
        if(d3==1) // B
        {
            red2=5;
            D3=d3;
        }
        if(d4==1) // A
        {
            red1=5;
            D4=d4;
        }
        long int v1[150000];long int v2[150000];long int v4[150000];
        // changing power and saving a's power for reset inside second loop //
        for(i=1;i<2*B;i++)
              {
                  a=i;A=i;
                  hp1=a;
                  // changing armor and ressetting powers //
                  for(g=0;g<10;g++)
                  {


                        b=B;c=0;a=A;armor2=AR2;hp2=B+AR2;
                        hp1=a+g;
                        armor1=g;cond2=1;cond1=1;
                        // duel calc //
                        while(hp1>0 && hp2>0)
                            {
                                 c=c+1;
                                 if(hp1>a)
                                     {
                                         hp2=hp2-a;

                                     }
                                 else
                                     {
                                         a=hp1;
                                         armor1=0;
                                         hp2=hp2-a;
                                     }

                                if(hp2>b)
                                     {
                                        armor2=armor2-a;
                                        hp1=hp1-b;

                                     }
                                else
                                     {
                                        armor2=0;
                                        b=hp2;
                                        if(d3==1 && b>0 && cond2==1) // redElits
                                        {
                                            b=b+red2;
                                            hp2=b;
                                            cond2=0;
                                        }
                                        if(b>0)
                                        {
                                            hp1=hp1-b;
                                        }
                                     }
                                if(hp1>a)
                                     {
                                         if(b>0)
                                         {
                                             armor1=armor1-b;
                                         }

                                     }
                                 else
                                     {
                                         a=hp1;
                                         armor1=0;
                                         if(d4==1 && a>0 && cond1==1) // redElits
                                            {
                                                a=hp1+red1;
                                                hp1=a;
                                                cond1=0;
                                            }
                                     }
                                 if(b<=0)
                                     {
                                         b=0;
                                     }
                                 if(a<0)
                                     {
                                         a=0;
                                     }

                                // saving duel results //
                                if(a==0 || b==0)
                                {
                                    INv=A+B-a-b;
                                    v4[s]=INv;
                                    v2[s]=g;
                                    if(d4==1 && g==0) // to ignore non armor units for redanian elites
                                    {
                                        v4[s]=-1;
                                        INv=-1;
                                    }
                                    v1[s]=i;
                                    s=s+1;
                                    if(INv>=INvalue)
                                      {
                                          INvalue=INv;
                                      }
                                }

                            }
                    }

                }
                // giving results //
                ign=0; // whether to ignore armored units
                if(d4!=1)
                {
                    printf("\nignore armor? yes=1 no=other, #=");
                    scanf("%d",&ign);
                }
                if(ign==1)
                {
                    for(w=0;w<s+1;w++)
                    {
                        if(v4[w]!=0 && v2[w]!=0)
                        {
                            v4[w]=0;
                        }
                    }
                }
                int n;int o1,o2; // formatting variables
                printf("\n here's the best units to duel for value = %d, to %d (power,armor) :",INvalue,INvalue-(B%10)-(B/10)-5); // changes search range based on unit's power
                float x=(B%10)+(B/10)+5+1; // changes search range based on unit's power
                printf("\n");
                for(n=0;n<x;n++)
                {
                    o1=0;o2=0;
                    for(w=0;w<s+1;w++)
                    {
                        if(v4[w]==INvalue-n && v4[w]>=0)
                        {
                            o2+=1;
                            if(o1==0) //to print a single "PTS" msg
                            {
                                printf(" %d PTS",v4[w]);
                                o1+=1; // to break if statement
                            }
                            if(o2%6==0 && o2!=0) // better formatting if too much cases
                            {
                                if(v4[w]>=100)
                                {
                                    printf("\n        ");
                                    o2+=1; // so the mod only goes to a new line every 5 cases
                                }
                                else if (v4[w]>=10)
                                {
                                    printf("\n       ");
                                    o2+=1; // so the mod only goes to a new line every 5 cases
                                }
                                else
                                {
                                    printf("\n      ");
                                    o2+=1; // so the mod only goes to a new line every 5 cases
                                }
                            }
                            printf("  ( %d, %d )",v1[w],v2[w]);
                        }
                    }
                    if(o1==1) // return to line only if there was a value
                    {
                        printf("\n\n");
                    }




                }


}

void mduel(int k)
{
    // reading //
               int a,b,armor1,armor2,i,g,hp1,hp2,A,B,INvalue,INv,c,INar2;int AR1=0;int s=0; int j=0;int w=0;int d2=0;int d=1;int d3=0;int red=0;
                INvalue=0;
                INar2=0;
                int str=5; // sabbath
                c=0;
                int sb=0;int sabbath=0;int cond=1;
              printf("\ngive the FIRST attacking unit details \n  ");
              printf("give power= ");
              scanf(" %i",&a);
              printf("\n give armor= ");
              scanf(" %i",&armor1);
              printf("\nis this unit sabbath? yes=1 no=other #=");
              scanf("%d",&sb);
              if(sb==1)
              {
                  printf("\nit's strength (default is 5) ? =");
                  scanf("%d",&str);
              }
              if(sb!=1)
              {
                  printf("\ndoes the unit deal double dammage? yes=1 , no=other ,   #= ");
                  scanf(" %i",&d2);
              }
              printf("\ndueling Redanian Elite?( if yes it only shows redanian elites value ) yes=1 , no=other ,   #= ");
              scanf(" %i",&d3);
              if(d3==1)
               {
                    red=5;
               }
              if(d2==1)
              {
                  d=2;
              }
              hp1=a+armor1;A=a;AR1=armor1;i=0; // defining powers and saving power for future reset
              long int v1[150000];long int v2[150000];long int v3[150000];
              // changing power while saving B's power //
              for(i=1;i<2*d*A*5;i++)
              {
                  b=i;B=b;
                  hp2=b;
                  // changing armor and resetting powers //
                  for(g=0;g<=10;g++)
                  {

                        // resetting all necessary values
                        b=B;c=0;a=A;armor1=AR1;hp1=a+armor1;
                        hp2=b+g;
                        armor2=g;sabbath=0;cond=1;
                        // duel calc
                        while(hp1>0 && hp2>0)
                            {
                                 c=c+1;
                                 if(hp1>a)
                                     {
                                         hp2=hp2-d*a;

                                     }
                                 else
                                     {
                                         a=hp1;
                                         armor1=0;
                                         hp2=hp2-d*a;
                                     }

                                if(hp2>b)
                                     {
                                        armor2=armor2-d*a;
                                        hp1=hp1-b;

                                     }
                                else
                                     {
                                        armor2=0;
                                        b=hp2;
                                        if(d3==1 && b>0 && cond==1) // RedElits
                                            {
                                            b+=red;
                                            hp2=b;
                                            cond=0;
                                            }
                                        if(b>0)
                                            {
                                                hp1=hp1-b;
                                            }
                                     }
                                if(hp1>a)
                                     {
                                         if(b>0)
                                         {
                                             armor1=armor1-b;
                                         }

                                     }
                                 else
                                     {
                                         a=hp1;
                                         armor1=0;
                                     }
                                 if(b<=0)
                                     {
                                         b=0;
                                         if(a<str) // sabbath
                                         {
                                            sabbath=1;
                                             if (a<str-1)
                                             {
                                                 sabbath=2;
                                             }
                                         }
                                     }
                                 if(a<0)
                                     {
                                         a=0;
                                     }
                                 // saving results //
                                 if(a==0 || b==0)
                                 {
                                    if(sb==1)
                                    {
                                        INv=a+sabbath+B-b;
                                    }
                                    else
                                    {
                                        INv=a+B-b;
                                    }
                                    v3[j]=INv;
                                    v2[j]=g;
                                    if(d3==1 && g==0) // ignore non armored units if dueling RE
                                    {
                                        v3[j]=-1;
                                        INv=-1;
                                    }
                                    v1[j]=i;
                                    j=j+1;
                                 if(INv>=INvalue)
                                      {

                                          INvalue=INv;

                                      }
                                 }

                            }
                    }

                }
                // results //
                int ign=0; //ignoring armor
                if(d3!=1)
                {
                    printf("\nignore armor? yes=1 no=other, #=");
                    scanf("%d",&ign);
                }
                if(ign==1)
                {
                    for(w=0;w<j+1;w++)
                    {
                        if(v3[w]!=0 && v2[w]!=0)
                        {
                            v3[w]=0;
                        }
                    }
                }
                int n;int o1,o2; // formatting variables
                printf("\n here's the best units to duel for value = %d, to %d (power,armor) :",INvalue,INvalue-(A%10)-(A/10)-5); // changes search range based on unit's power
                float x=(A%10)+(A/10)+5+1; // changes search range based on unit's power
                printf("\n\n");
                for(n=0;n<x;n++)
                {
                    o1=0;o2=0;
                    for(w=0;w<j+1;w++)
                    {
                        if(v3[w]==INvalue-n)
                        {
                            o2+=1;
                            if(o1==0) //to print a single if
                            {
                                printf(" %d PTS",v3[w]);
                                o1+=1; // to break if statement
                            }
                            if(o2%6==0 && o2!=0) // formatting : return to line every 5 cases
                            {
                                if(v3[w]>=100) // makes the parentheses on same line
                                {
                                    printf("\n        ");
                                    o2+=1; // so the mod only goes to a new line every 5 cases
                                }
                                else if (v3[w]>=10)
                                {
                                    printf("\n       ");
                                    o2+=1; // so the mod only goes to a new line every 5 cases
                                }
                                else
                                {
                                    printf("\n      ");
                                    o2+=1; // so the mod only goes to a new line every 5 cases
                                }
                            }
                            printf("  ( %d, %d )",v1[w],v2[w]);
                        }
                    }
                    if(o1==1) // return to line only if there was a value
                    {
                        printf("\n\n");
                    }

                }

}




int main()
{
        int y=1;int K=0;int L=0;int Q=0;
        while(y==1)
        {
            printf("calculate duel ( 1 ) or search for best units to duel? ( 2 ) , exit = other, #= ");
            scanf("%d",&Q);
            L=Q;
            while(Q==1 || L==1) // "L" is to eliminate ambiguities between the two modes
                {
                    ds(L);
                    printf("\n+++++++++++++++++++++++++++++++\n");
                    printf("\n again? yes=1 no=other, #=");
                    scanf("%d",&L);
                    printf("\n+++++++++++++++++++++++++++++++\n");
                    Q=0;
                }
            while(Q==2)
                {
                    printf("\n+++++++++++++++++++++++++++++++\n");
                    printf("if your unit is dueling type 1, if it's your opponents units dueling (eg:meditation) type 2, #=");
                    scanf("%d",&K);
                    printf("\n+++++++++++++++++++++++++++++++\n");
                    while(K==1)
                    {
                        mduel(K);
                        K=0;
                    }
                    while(K==2)
                    {
                        hduel(K);
                        K=0;
                    }
                    printf("\n+++++++++++++++++++++++++++++++\n");
                    printf("\n again? yes=2 no=other, #=");
                    scanf("%d",&Q);
                    printf("\n+++++++++++++++++++++++++++++++\n");
                }
           printf("\n **************************** \n");
           printf("\n continue? yes=1 ,exit=other #=");
           scanf("%d",&y);
           printf("\n **************************** \n");


        }

}

