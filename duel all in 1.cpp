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
void my_duel(int a,int b,int armor1,int armor2,int i,int g,int hp1,int hp2,int A,int B,int INvalue,int INv,int c,int INar2,int AR1,int j,int w,int d2,int d,int d3,int red,int str,int sb,int sabbath,int cond,int v1[150000],int v2[150000],int v3[150000],int cancel_result,int target_m)
{
    int target_array_power[10000];int target_array_armor[10000];int target_array[10000];
    // changing power while saving B's power //
    for(i=1;i<2*d*A;i++)
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
                if(cancel_result!=1)
                {
                    int ign=0; //ignoring armor
                    if(d3!=1)
                    {
                        printf("\nignore armor? yes=1 no=other, #=");
                        scanf("%d",&ign);
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
                                if(ign!=1)
                                {
                                        if(d3==1)
                                        {
                                            if(v2[w]!=0)
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
                                        else
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
                                if(ign==1)
                                {
                                        if(v2[w]==0)
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
                            }
                        }
                        if(o1==1) // return to line only if there was a value
                        {
                            printf("\n\n");
                        }

                    }
                }

                if(cancel_result==1)
                {
                    bool there_is_a_unit=false;
                    printf("\nhere are the units to duel for %d PTS : ",target_m);
                    for(w=0;w<j+1;w++)
                    {
                        if(v3[w]==target_m && d3!=1)
                        {
                            printf("\n ( %d , %d )",v1[w],v2[w]);
                            there_is_a_unit=true;
                        }
                        if(v3[j]==target_m && d3==1)
                        {
                            if(target_array_armor[w]!=0)
                            {
                                printf(" ( %d , %d )\n",v1[w],v2[w]);
                                there_is_a_unit=true;
                            }
                        }
                    }
                    if(there_is_a_unit==false)
                    {
                        printf("\n Can't be done :(");
                    }
                }
}
void his_duel(int a,int b,int armor1,int armor2,int i,int g,int hp1,int hp2,int A,int B,int INvalue,int INv,int c,int INar2,int AR1,int s,int AR2,int w,int d3,int d4,int red2,int red1,int cond1,int cond2,int v1[150000],int v2[150000],int v4[150000],int cancel_result,int target_h)
{
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
                if(cancel_result!=1)
                {
                    int ign=0; // whether to ignore armored units
                    if(d4!=1)
                    {
                        printf("\nignore armor? yes=1 no=other, #=");
                        scanf("%d",&ign);
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
                                if(ign!=1)
                                {
                                        if(d4==1)
                                        {
                                            if(v2[w]!=0)
                                                {
                                                    o2+=1;
                                                    if(o1==0) //to print a single if
                                                    {
                                                        printf(" %d PTS",v4[w]);
                                                        o1+=1; // to break if statement
                                                    }
                                                    if(o2%6==0 && o2!=0) // formatting : return to line every 5 cases
                                                    {
                                                        if(v4[w]>=100) // makes the parentheses on same line
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
                                        else
                                        {
                                            o2+=1;
                                            if(o1==0) //to print a single if
                                            {
                                                printf(" %d PTS",v4[w]);
                                                o1+=1; // to break if statement
                                            }
                                            if(o2%6==0 && o2!=0) // formatting : return to line every 5 cases
                                            {
                                                if(v4[w]>=100) // makes the parentheses on same line
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
                                if(ign==1)
                                {
                                        if(v2[w]==0)
                                        {
                                            o2+=1;
                                            if(o1==0) //to print a single if
                                            {
                                                printf(" %d PTS",v4[w]);
                                                o1+=1; // to break if statement
                                            }
                                            if(o2%6==0 && o2!=0) // formatting : return to line every 5 cases
                                            {
                                                if(v4[w]>=100) // makes the parentheses on same line
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
                            }
                        }
                        if(o1==1) // return to line only if there was a value
                        {
                            printf("\n\n");
                        }
                    }
                }
                if(cancel_result==1)
                {
                    bool there_is_a_unit=false;
                    printf("\nhere are the units to duel for %d PTS : ",target_h);
                    for(w=0;w<s+1;w++)
                    {
                        if(v4[w]==target_h && d3!=1)
                        {
                            printf("\n ( %d , %d )",v1[w],v2[w]);
                            there_is_a_unit=true;
                        }
                        if(v4[w]==target_h && d3==1)
                        {
                            if(v2[w]!=0)
                            {
                                printf("\n ( %d , %d )",v1[w],v2[w]);
                                there_is_a_unit=true;
                            }
                        }
                    }
                    if(there_is_a_unit==false)
                    {
                        printf("\n Can't be done :(");
                    }
                }
}
void hduel(int k)
{
    // reading //
        int a,b,armor1,armor2,i,g,hp1,hp2,A,B,INvalue,INv,OUTv,c,INar2,OUTar2;int AR1=0;int s=0; int j=0;int w=0;int red1,red2,cond1,cond2,d3,d4,D3,D4=0;
        INvalue=0;
        INar2=0;
        c=0;
        int AR2=0;int target_h=0;int cancel_result=0;
        printf("\ngive the *SECOND* attacking unit details \n");
        printf("\ngive power= ");
        scanf(" %i",&b);
        printf("\n\ngive armor= ");
        scanf(" %i",&armor2);
        printf("\nis this unit a Redanian Elite? yes=1 , no=other ,   #= ");
        scanf("%d",&d3);
        if(armor2==0)
                  {
                      d3=0;
                  }
        hp2=b+armor2;B=b;AR2=armor2;i=0;
        printf("\ndueling Redanian Elite?( if yes it only shows redanian elites values ) yes=1 , no=other ,   #= ");
        scanf(" %i",&d4);
        if(d3==1) // B
        {
            red2=5;
        }
        if(d4==1) // A
        {
            red1=5;
        }
        int v1[150000];int v2[150000];int v4[150000];
        his_duel(a,b,armor1,armor2,i,g,hp1,hp2,A,B,INvalue,INv,c,INar2,AR1,s,AR2,w,d3,d4,red2,red1,cond1,cond2,v1,v2,v4,cancel_result,target_h);
}

void mduel(int k)
{
    // reading //
               int a,b,armor1,armor2,i,g,hp1,hp2,A,B,INvalue,INv,c,INar2;int AR1=0;int s=0;int w=0;int d2=0;int d=1;int d3=0;int red=0;int target_m=0;int cancel_result=0;
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
              int v1[150000];int v2[150000];int v3[150000];
              my_duel(a,b,armor1,armor2,i,g,hp1,hp2,A,B,INvalue,INv,c,INar2,AR1,s,w,d2,d,d3,red,str,sb,sabbath,cond,v1,v2,v3,cancel_result,target_m);

}
void can_it_be_done(int k)
{
    printf("\nyour unit duels (1) or his side ( eg:meditation)? (2) #= ");int side=0;
    scanf("%d",&side);
    //mduel without my_duel()

    if(side==1)
    {
                  int cancel_result=1;int target_m=0;
                  printf("\nwhat's the target PTS you're looking for? #=");
                  scanf("%d",&target_m);
                  // mduel()
                  int a,b,armor1,armor2,i,g,hp1,hp2,A,B,INvalue,INv,c,INar2;int AR1=0;int s=0;int w=0;int d2=0;int d=1;int d3=0;int red=0;
                  INvalue=0;
                  INar2=0;
                  int str=5; // sabbath
                  c=0;
                  int sb=0;int sabbath=0;int cond=1;
                  printf("\ngive the FIRST attacking unit details \n");
                  printf("give power= ");
                  scanf(" %i",&a);
                  printf("\ngive armor= ");
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
                int v1[150000];int v2[150000];int v3[150000];
                my_duel(a,b,armor1,armor2,i,g,hp1,hp2,A,B,INvalue,INv,c,INar2,AR1,s,w,d2,d,d3,red,str,sb,sabbath,cond,v1,v2,v3,cancel_result,target_m);
    }
    if(side==2)
    {
    // reading //
        int cancel_result=1;int target_h=0;
        printf("\nwhat's the target PTS you're looking for? #=");
        scanf("%d",&target_h);
        // hduel ()
        int a,b,armor1,armor2,i,g,hp1,hp2,A,B,INvalue,INv,OUTv,c,INar2,OUTar2;int AR1=0;int s=0; int j=0;int w=0;int red1,red2,cond1,cond2,d3,d4,D3,D4=0;
        INvalue=0;
        INar2=0;
        c=0;
        int AR2=0;
        printf("\ngive the *SECOND* attacking unit details \n");
        printf("\ngive power= ");
        scanf(" %i",&b);
        printf("\n\ngive armor= ");
        scanf(" %i",&armor2);
        printf("\nis this unit a Redanian Elite? yes=1 , no=other ,   #= ");
        scanf("%d",&d3);
        if(armor2==0)
        {
            d3=0;
        }
        hp2=b+armor2;B=b;AR2=armor2;i=0;
        printf("\ndueling Redanian Elite?( if yes it only shows redanian elites values ) yes=1 , no=other ,   #= ");
        scanf(" %i",&d4);
        if(d3==1) // B
        {
            red2=5;
        }
        if(d4==1) // A
        {
            red1=5;
        }
        int v1[150000];int v2[150000];int v4[150000];
        his_duel(a,b,armor1,armor2,i,g,hp1,hp2,A,B,INvalue,INv,c,INar2,AR1,s,AR2,w,d3,d4,red2,red1,cond1,cond2,v1,v2,v4,cancel_result,target_h);
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
                    printf("if your unit is dueling ( 1 ), if it's your opponents units dueling (eg:meditation) ( 2 ) to see if it can be done ( 3 ), #=");
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
                    while(K==3)
                    {
                        can_it_be_done(K);
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

