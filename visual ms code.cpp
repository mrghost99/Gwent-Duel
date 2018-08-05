void my_duel(int a,int b,int armor1,int armor2,int i,int g,int hp1,int hp2,int A,int B,int INvalue,int INv,int c,int INar2,int AR1,int j,int w,int d2,int d,int d3,int red,int str,int sb,int sabbath,int cond,int v1[150000],int v2[150000],int v3[150000],int cancel_result,int target_m)
{
    int max_power_array[60000];int a_last_value=0;int b_last_value=0;int last_sabbath=0;
    // changing power while saving B's power //
    for(i=1;i<2*d*A;i++)
              {
                  b=i;B=b;
                  hp2=b;
                  // changing armor and resetting powers //
                  for(g=0;g<=10;g++)
                  {
                        // resetting all necessary values
                        a_last_value=a;last_sabbath=sabbath;
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
                                         if(a<str && sb==1) // sabbath
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
                                    if(g!=0) // equation is wrong if g!=0 (B[j-1}!=B[j]
                                    {
                                        b_last_value=v3[j]-v3[j-1]+b+a_last_value-a+last_sabbath;
                                    }
                                    else
                                    {
                                        b_last_value=v3[j]-v3[j-1]+b+a_last_value-a-1;
                                    }
                                    if(a==0 && b_last_value==0) // it takes the highest beatable unit with X power
                                    {
                                        if(d3==1)
                                        {
                                            if(g!=0)
                                            {
                                                max_power_array[j]=1;
                                            }
                                        }
                                        else
                                        {
                                            max_power_array[j]=1;
                                        }
                                    }
                                    else
                                    {
                                        max_power_array[j]=0;
                                    }
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
                if(canit.Checked==false)
                {
                    int ign=0;
                    if(ignore.Checked==true)
                    {
                        ign=1; //ignoring armor
                    }
                    int n;int o1,o2; // formatting variables
                    txt.Text+="\n here's the best units to duel for value = " + INvalue.ToString() + ", to " +((INvalue-(A%10)-(A/10)-5)).ToString() + "  (power,armor) :";
                    float x=(A%10)+(A/10)+5+1; // changes search range based on unit's power
                    txt.Text+=Environment.Newline+Environment.Newline;
                    for(n=0;n<x;n++)
                    {
                        o1=0;o2=0;
                        for(w=0;w<j+1;w++)
                        {
                            if(v3[w]==INvalue-n)
                            {
                                if(ignore.Checked==false)
                                {
                                        if(Red1.Checked==true)
                                        {
                                            if(v2[w]!=0)
                                                {
                                                    o2+=1;

                                                }
                                        }
                                        else
                                        {
                                            o2+=1;
                                            if(o1==0) //to print a single if
                                                {
                                                    txt.Line+=" "+v3[w].ToString()+" PTS";
                                                    o1+=1; // to break if statement
                                                }
                                                if(o2%12==0 && o2!=0) // formatting : return to line every 5 cases
                                                {
                                                    if(v3[w]>=100) // makes the parentheses on same line
                                                    {
                                                        txt.Text+=Environment.Newline+"        ";
                                                        o2+=1; // so the mod only goes to a new line every 5 cases
                                                    }
                                                    else if (v3[w]>=10)
                                                    {
                                                        txt.Text+=Environment.Newline+"       ";
                                                        o2+=1; // so the mod only goes to a new line every 5 cases
                                                    }
                                                    else
                                                    {
                                                        txt.Text+=Environment.Newline+"       ";
                                                        o2+=1; // so the mod only goes to a new line every 5 cases
                                                    }
                                                }
                                                txt.Text+="  ( "+v1[w].ToString()+", "+v2[w].ToString()+" )";
                                        }
                                }
                                if(ignore.Checked==true)
                                {
                                        if(v2[w]==0)
                                        {
                                            o2+=1;
                                            if(o1==0) //to print a single if
                                                {
                                                    txt.Line+=" "+v3[w].ToString()+" PTS";
                                                    o1+=1; // to break if statement
                                                }
                                                if(o2%12==0 && o2!=0) // formatting : return to line every 5 cases
                                                {
                                                    if(v3[w]>=100) // makes the parentheses on same line
                                                    {
                                                        txt.Text+=Environment.Newline+"        ";
                                                        o2+=1; // so the mod only goes to a new line every 5 cases
                                                    }
                                                    else if (v3[w]>=10)
                                                    {
                                                        txt.Text+=Environment.Newline+"       ";
                                                        o2+=1; // so the mod only goes to a new line every 5 cases
                                                    }
                                                    else
                                                    {
                                                        txt.Text+=Environment.Newline+"       ";
                                                        o2+=1; // so the mod only goes to a new line every 5 cases
                                                    }
                                                }
                                                txt.Text+="  ( "+v1[w].ToString()+", "+v2[w].ToString()+" )";
                                        }
                                }
                            }
                        }
                        if(o1==1) // return to line only if there was a value
                        {
                            txt.Text+=Environment.Newline+Environment.Newline;
                        }
                    }
                txt.Text+="The biggest units it can beat are :";
                for(w=0;w<j+1;w++)
                {
                    if(max_power_array[w]!=0)
                    {
                        if(redcond1==1)
                        {
                            if(v2[w-1]>=1)
                            {
                                txt.Text+=Environment.Newline+"( "+v1[w-1].ToString()+" , " +v2[w-1].ToString()+" ) for "+v3[w-1].ToString()+" PTS";

                            }
                        }
                        else
                        {
                            txt.Text+=Environment.Newline+"( "+v1[w-1].ToString()+" , " +v2[w-1].ToString()+" ) for "+v3[w-1].ToString()+" PTS";
                        }

                    }
                }
            }
            if(canit.Checked==true)
            {
                    bool there_is_a_unit=false;
                    txt.Text+=Environment.Newline+"here are the units to duel for "+target_m.ToString()+" PTS : ";
                    for(w=0;w<j+1;w++)
                    {
                        if(v3[w]==target_m && d3!=1)
                        {
                            txt.Text+=Environment.Newline+" ( "+v1[w].ToString+" , "+v2[w].ToString()+" )";
                            there_is_a_unit=true;
                        }
                        if(v3[w]==target_m && d3==1)
                        {
                            if(v2[w]!=0)
                            {
                                txt.Text+=Environment.Newline+" ( "+v1[w].ToString+" , "+v2[w].ToString()+" )";
                                there_is_a_unit=true;
                            }
                        }
                    }
                    if(there_is_a_unit==false)
                    {
                        txt.Text+=Environment.Newline+"it can't be done :(";
                    }
            }


}

void his_duel(int a,int b,int armor1,int armor2,int i,int g,int hp1,int hp2,int A,int B,int INvalue,int INv,int c,int INar2,int AR1,int s,int AR2,int w,int d3,int d4,int red2,int red1,int cond1,int cond2,int v1[150000],int v2[150000],int v4[150000],int cancel_result,int target_h,int who_kills_cond)
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
                                    if(who_kills_cond==1)
                                    {
                                        if(b==0)
                                        {
                                            INv=1;
                                            v4[s]=INv;
                                            v2[s]=g;
                                            v1[s]=i;
                                        }
                                        else
                                        {
                                            INv=0;
                                            v4[s]=INv;
                                            v2[s]=g;
                                            v1[s]=i;
                                        }

                                    }
                                    else
                                    {
                                        INv=A+B-a-b;
                                        v4[s]=INv;
                                        v2[s]=g;
                                        v1[s]=i;
                                    }

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
                if(canit.Checked==false && who.Checked==false)
                {
                    int n;int o1,o2; // formatting variables
                    txt.Text+="\n here's the best units to duel for value = " + INvalue.ToString() + ", to " +((INvalue-(A%10)-(A/10)-5)).ToString() + "  (power,armor) :";// changes search range based on unit's power
                    float x=(B%10)+(B/10)+5+1; // changes search range based on unit's power
                    txt.Text+=Environment.Newline+Environment.Newline;
                    for(n=0;n<x;n++)
                    {
                        o1=0;o2=0;
                        for(w=0;w<s+1;w++)
                        {
                            if(v4[w]==INvalue-n && v4[w]>=0)
                            {
                                if(ignore.Checked==false)
                                {
                                        if(red1.Checked==false)
                                        {
                                            if(v2[w]!=0)
                                                {
                                                    o2+=1;
                                                }
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
                if(cancel_result==1 && who_kills_cond!=1)
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
                if(who_kills_cond==1)
                {
                    int o2=0;
                    printf("This unit dies to :\n");
                    for(w=0;w<=s+1;w++)
                    {
                        if(v4[w]==1 && v1[w]<=B)
                        {
                            o2+=1;
                            if(o2%6==0 && o2!=0) // formatting : return to line every 5 cases
                            {
                                printf("\n");
                                o2+=1; // so the mod only goes to a new line every 5 cases
                            }
                            printf(" ( %d , %d )",v1[w],v2[w]);
                        }
                    }
                }
}
